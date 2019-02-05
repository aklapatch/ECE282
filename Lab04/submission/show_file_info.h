#ifndef SHOW_FILE_INFO_H
#define SHOW_FILE_INFO_H

#include <stdio.h>
#include	<pwd.h>
#include	<grp.h>
#include <stdlib.h>
#include	<sys/types.h>
#include	<sys/stat.h>

void show_file_info( char *, struct stat *);

#endif // SHOW_FILE_INFO