#ifndef DOSTAT_H
#define DOSTAT_H

#include<stdlib.h>
#include<string.h>
#include<dirent.h>
#include<pwd.h>
#include<grp.h>
#include<stdio.h>
#include<sys/types.h>
#include<sys/stat.h>
#include"show_file_info.h"

char * dostat(char *,char *);

#endif // dostat
