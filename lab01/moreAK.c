
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define	PAGELEN	24
#define	LINELEN	512

// overview
// three items 2^3 = 8  that means three if else statements
// -o condition, output file specified condition, and input file condition

// first: check for -o
// if -o
//      check for output file
//      if there is output file
//
//          if there is an input file
//            write the input to the output while running do_more

//          else (no input file)
//              write stdin parts to file while running do_more
//
//      else (no output file)
//            do not write to it while running do_more

//          if there is an input file
//            just run running do_more

//          else (no input file)
//              write stdin parts to stdout

//else (no -o )
//      if there is an input file
//          just run running do_more

//      else (no input file)
//          write stdin parts to stdout

void do_more(FILE *, char *);
int see_more(FILE *);

// returns 1 if -o was specified on the command line, 0 otherwise
int oSpecified(int,char **);

// dump contents of one file to another
int dumpFile(FILE *, FILE *);

int resetFile(char *);

int main( int ac , char *av[] )
{
	// will be 0 if no output file is found
	int file_index = oSpecified( ac, av);

	// if it can successfully get the filename, read the file and output it to the file specified
	if(file_index > 0 ){
	
		// make the output file blank
		resetFile(av[file_index+1]);			

		// no input file specified
		if (ac == 3){

			do_more(stdin, av[file_index+1]);

		} else {

			// ac will not = 1 if file_index >0
			while ( --ac > 0 ){

				if ( ac != file_index && ac != file_index+1 ){
					FILE * fp;
					if ( (fp = fopen( av[ac] , "r" )) != NULL )
					{
						do_more( fp, av[file_index+1]);
						fclose( fp );

					} else {
						return 1;
					}
				}
			}
		}

	// if output file was not specified
	} else {

		if ( ac == 1 )
			do_more( stdin, "NULL" );
		else

			while ( --ac ) {
				FILE * fp;
				if ( (fp = fopen( *++av , "r" )) != NULL )
				{
					do_more( fp, "NULL" ) ;
					fclose( fp );
				}
				else
					return 1;
			}
	}

	return 0;
}


int resetFile(char * file_name){

	// reset file to default every time
	FILE * tmp = fopen (file_name,"w");
	if (tmp == NULL){
		puts("Error: failed to clear output file.");
		return 1;
	}

	fclose(tmp);
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

void do_more( FILE *fp, char * output_file_name)
/*
 *  read PAGELEN lines, then call see_more() for further instructions
 */
{
	char	line[LINELEN];
	int	num_of_lines = 0;
	int	reply;


	FILE * fp_tty = fopen("/dev/tty", "r");  /* NEW: cmd stream   */

	if ( fp_tty == NULL )			   /* if open fails     */
		exit(1);                           /* no use in running */

	while ( fgets( line, LINELEN, fp ) ){		/* more input	*/
		if ( num_of_lines == PAGELEN ) {	/* full screen?	*/
			reply = see_more(fp_tty);  /* NEW: pass FILE *  */
			if ( reply == 0 )		/*    n: done   */
				break;
			num_of_lines -= reply;		/* reset count	*/
		}

		// dump if output file was specified
		if (output_file_name != "NULL"){
			// open in append mode
			FILE * output = fopen(output_file_name,"a");
			if (output != NULL){
				fputs(line, output);

				fclose(output);
			} else {
				puts("FAiled to open output file.\n");
			}
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
