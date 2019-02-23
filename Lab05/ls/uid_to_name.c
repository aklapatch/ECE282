// uid_to_name.c

#include "uid_to_name.h"

char *uid_to_name( uid_t uid )
/* 
 *  *	returns pointer to username associated with uid, uses getpw()
 *   */	
{
	struct	passwd *getpwuid(), *pw_ptr;

	if ( ( pw_ptr = getpwuid( uid ) ) == NULL ){

		static  char numstr[10];
		sprintf(numstr,"%d", uid);
		return numstr;
	}
	else
		return pw_ptr->pw_name ; // return name for the file
}
