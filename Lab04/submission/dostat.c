// dostat.c

#include "dostat.h"

void dostat( char *filename , char * dirname)
{
	struct stat info;

	int size = strlen(filename) + strlen(dirname);
	char * file_and_dir_name = malloc(sizeof(char)*(size+1));
	
	if (file_and_dir_name != NULL) {


		strcpy(file_and_dir_name, dirname);
		strcat(file_and_dir_name, "/");
		strcat(file_and_dir_name, filename);
		
		if ( stat(file_and_dir_name, &info) == -1 )		/* cannot stat	 */
			perror( filename );			/* say why	 */
		else					/* else show info	 */
			show_file_info( filename, &info );

		// free allocated memory
		free(file_and_dir_name);
	}
	else 
		fprintf(stderr, "Memory Allocation failed for file and Diirectory name concatenation.\n");

}
