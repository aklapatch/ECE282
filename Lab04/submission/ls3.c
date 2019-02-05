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

int main(int ac, char *av[])
{
	if ( ac == 1 )
		do_ls( "." );
	else
		while ( --ac ){
			printf("%s:\n", *++av );
			do_ls( *av );
		}
}




