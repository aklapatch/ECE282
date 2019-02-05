#ifndef GID_TO_NAME_H
#define GID_TO_NAME_H

#include	<pwd.h>
#include	<grp.h>
#include <stdlib.h>
#include	<sys/types.h>
#include	<sys/stat.h>
#include <stdio.h>

char *gid_to_name( gid_t );

#endif // GID_TO_NAME