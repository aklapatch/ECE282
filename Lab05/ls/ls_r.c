/* ls3.c */
 
#include	<pwd.h>
#include	<grp.h>
#include	<stdio.h>
#include	<sys/types.h>
#include	<dirent.h>
#include	<sys/stat.h>
#include <string.h>
#include <stdlib.h>
#include "do_ls.h"
#include "mode_to_letters.h"
#include "dostat.h"
#include "gid_to_name.h"
#include "uid_to_name.h"
#include "recursive_ls.h"

// goes through argv and sees if there is an -R flag
// returns the index of -R if it is found
// returns 0 if -R is not found
int indexOfR(int argc, char ** argv){
  
  while(--argc){
    if( strcmp(argv[argc],"-R") == 0){
      return argc;
    }
  }
  
  return 0;
}
  
int main(int ac, char *av[])
{
	// show the files in the current directory if no directory is specified
	if ( ac == 1 )
		do_ls( "." );
	else {
   
		// go through all subdirectories if -R is found
		int r_index=indexOfR(ac,av);
		
		// run normally if r_index == 0
		if (r_index == 0){
	
			//go through all the args and print the contents of each directory
			while ( --ac ){
				printf("%s:\n", *++av );
				do_ls( *av );
			}
		
		// run ls recursively
		} else {
			
				//go through all the args and print the contents of each directory
				while( --ac ){
					// go through every element except for the -R
					if ( ac != r_index ) {
							printf("%s:\n", *++av );
							recursive_ls( *av,0 );
					}
				}
		}
	}
		
   return 0;
}




