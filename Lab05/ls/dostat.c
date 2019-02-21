// dostat.c

#include "dostat.h"
#include "recursive_ls.h"

char * dostat( char *filename , char * dirname)
{
	struct stat info;

	int size = strlen(filename) + strlen(dirname);
	char * file_and_dir_name = malloc(sizeof(char)*(size+2));
	
	if (file_and_dir_name != NULL) {

		strcpy(file_and_dir_name, dirname);
		strcat(file_and_dir_name, "/");
		strcat(file_and_dir_name, filename);
		strcat(file_and_dir_name, "\0"); // add escape character
		
		if ( stat(file_and_dir_name, &info) == -1 ){		/* cannot stat	 */
			perror( filename );			/* say why	 */
			return "";

		}
		else {					/* else show info	 */
			show_file_info( filename, &info );

			DIR		*dir_ptr = opendir( file_and_dir_name );
			if( dir_ptr != NULL){
				closedir(dir_ptr);	// close directory and return path for recursive use
				return file_and_dir_name;	
			}
		}

		// free allocated memory
		free(file_and_dir_name);
	}
	else 
		fprintf(stderr, "Memory Allocation failed for file and Directory name concatenation.\n");
	
	return "";
}
