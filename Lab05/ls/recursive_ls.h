#ifndef RECURSIVE_LS_H
#define RECURSIVE_LS_H

#include<pwd.h>
#include<grp.h>
#include<stdio.h>
#include<sys/types.h>
#include<dirent.h>
#include<sys/stat.h>
#include<string.h>
#include<stdlib.h>
#include"dostat.h"

// recursively calls ls on every directory found
void recursive_ls(char[], int );

#endif // recursive_h
