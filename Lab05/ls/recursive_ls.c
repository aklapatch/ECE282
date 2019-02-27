// recursive_ls.c

#include "recursive_ls.h"

void recursive_ls( char dirname[], int dir_level )
/*
 * 	list files in directory called dirname
 */
{
	DIR		*dir_ptr;		/* the directory */	

	if ( ( dir_ptr = opendir( dirname ) ) == NULL )
		fprintf(stderr,"ls: cannot open %s\n", dirname);
	else
	{
		struct dirent	*direntp;		/* each entry	 */
		while ( ( direntp = readdir( dir_ptr ) ) != NULL ){

			// indent content according to dir_level
			int i=0;
			for(i = 0; i < dir_level; ++i) {
				printf("  ");
			}
			
			// new_dir is a directory name
			char * new_dir = dostat( direntp->d_name , dirname);

			// check if the directory is '..'
			int len = strlen(new_dir);

			// find the next dir, do not explore the parent one
			if (new_dir[len-1] == '.' && new_dir[len-2] == '.'){
				free(new_dir);
				continue;
			}

			// don't read current directory
			if (new_dir[len-1] == '.'){
				free(new_dir);
				continue;
			}

			// only run if the directory passed back was not null
			if (strcmp(new_dir, "") != 0){
				printf("%s: \n",new_dir); // let the user now what directory you are in
				recursive_ls(new_dir,dir_level+1);
        
        // inform user what directory you are in
        printf("%s: \n",dirname);
				
				free(new_dir); // free memory allocated for file name
			}
		}
		closedir(dir_ptr);
	}
}
