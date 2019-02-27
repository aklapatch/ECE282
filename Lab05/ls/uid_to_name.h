#ifndef UID_TO_NAME_H
#define UID_TO_NAME_H

#include<pwd.h>
#include<grp.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<string.h>
#include<stdio.h>

char *uid_to_name( uid_t );

#endif // UID_TO_NAME
