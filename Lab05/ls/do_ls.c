// do_ls.c

#include "do_ls.h"

void do_ls( char dirname[] )
/*
 * 	list files in directory called dirname
 */
{
	DIR		*dir_ptr;		/* the directory */
	struct dirent	*direntp;		/* each entry	 */

	if ( ( dir_ptr = opendir( dirname ) ) == NULL )
		fprintf(stderr,"ls1: cannot open %s\n", dirname);
	else
	{
     // open all the directories and read them
		while ( ( direntp = readdir( dir_ptr ) ) != NULL )
			dostat( direntp->d_name , dirname);  // get info for each file
		closedir(dir_ptr);
	}
}