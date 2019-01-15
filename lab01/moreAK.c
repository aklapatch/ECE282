
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define	PAGELEN	24
#define	LINELEN	512

void do_more(FILE *);
int see_more(FILE *);

/// returns 1 if -o was specified on the command line, 0 otherwise
int oSpecified(int,char **);

/// dump contents of one file to another
int dumpFile(FILE *, FILE *);

int main( int ac , char *av[] )
{
    // usage message 
    if (ac == 1){
        printf("Usage %s file1 file2 file3 -o output_file\n", av[0]);
        return 1;
    }

    int file_index = oSpecified( ac, av);

    // if it can successfully get the filename, read the file and output it to the file specified
    if(file_index > 0 ){

    FILE * fp;
    // reset file to default every time
    FILE * output = fopen (av[file_index+1],"w");
    if (output == NULL)
      puts("Error: failed to clear output file.");

    fclose(output);

    output = fopen (av[file_index+1],"a");
    if( output == NULL){
        puts("Error: failed to open output file.");

        // ac will not = 1 if file_index >0
        while ( --ac != file_index && ac != file_index+1 ){
            if ( (fp = fopen( av[ac] , "r" )) != NULL ){
            do_more( fp );
            fclose( fp );

        } else
            return 1;
        }

    } else {
        FILE * fp;

        // ac will not = 1 if file_index >0
        while ( --ac != file_index && ac != file_index+1 ){
            if ( (fp = fopen( av[ac] , "r" )) != NULL )
            {
                // write the fp's contents to the output file
                if (dumpFile(fp,output) != 0)
                    puts("Error: output file was not written to.");


                do_more( fp );
                fclose( fp );

            } else {
                return 1;
            }
        }
        fclose(output);
    }

    // if no filename was specified
    } else {
        FILE * fp;

        if ( ac == 1 )
            do_more( stdin );
        else

            while ( --ac )
                if ( (fp = fopen( *++av , "r" )) != NULL )
                {
                    do_more( fp ) ;
                    fclose( fp );
                }
                else
                    return 1;
    }

    return 0;
}

// returns 1 if successful, 0 otherwise
int dumpFile(FILE * input, FILE * output){
  // get the size of the input file
  fseek(input,0,SEEK_END);
  int f_size = ftell(input);
  fseek(input,0,SEEK_SET);

  // allocate memory for the string
  char * f_contents = malloc(sizeof(char)*(f_size));
  if( f_contents == NULL)
    return 1;

    // fgets misreads the file, the misreading starts at char 150
    fread(f_contents,sizeof(char),f_size,input);

  // dump to output file
  fwrite(f_contents,sizeof(char),f_size, output);

  free(f_contents);
  fseek(input,0,SEEK_SET);
  return 0;
}

/// returns the index of -o in the argv, 0 if it is not found
int oSpecified(int ac, char **av){
  int i = ac;

  // iterate through the av and see if a -o is present
  while (--i > 0){
    // return index if it matches
    if(strcmp(av[i],"-o") == 0){
        if ( i == ac-1)
            return 0;

        return i;
    }

  }
  return 0;
}

void do_more( FILE *fp )
/*
 *  read PAGELEN lines, then call see_more() for further instructions
 */
{
    char	line[LINELEN];
    int	num_of_lines = 0;
    int	see_more(FILE *), reply;
    FILE	*fp_tty;

    fp_tty = fopen( "/dev/tty", "r" );	   /* NEW: cmd stream   */
    if ( fp_tty == NULL )			   /* if open fails     */
        exit(1);                           /* no use in running */

    while ( fgets( line, LINELEN, fp ) ){		/* more input	*/
        if ( num_of_lines == PAGELEN ) {	/* full screen?	*/
            reply = see_more(fp_tty);  /* NEW: pass FILE *  */
            if ( reply == 0 )		/*    n: done   */
                break;
            num_of_lines -= reply;		/* reset count	*/
        }
        if ( fputs( line, stdout )  == EOF )	/* show line	*/
            exit(1);			/* or die	*/
        num_of_lines++;				/* count it	*/
    }
}

int see_more(FILE *cmd)				   /* NEW: accepts arg  */
/*
 *	print message, wait for response, return # of lines to advance
 *	q means no, space means yes, CR means one line
 */
{
    int	c;

    printf("\033[7m more? \033[m");		/* reverse on a vt100	*/
    while( (c=getc(cmd)) != EOF )		/* NEW: reads from tty  */
    {
        if ( c == 'q' )			/* q -> N		*/
            return 0;
        if ( c == ' ' )			/* ' ' => next page	*/
            return PAGELEN;		/* how many to show	*/
        if ( c == '\n' )		/* Enter key => 1 line	*/
            return 1;
    }
    return 0;
}
