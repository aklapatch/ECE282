// gid_to_name.c

#include "gid_to_name.h"

char *gid_to_name( gid_t gid )
/*
 *  *	returns pointer to group number gid. used getgrgid(3)
 *   */
{
	struct group *getgrgid(), *grp_ptr;

	if ( ( grp_ptr = getgrgid(gid) ) == NULL ){

		static  char numstr[10];
		sprintf(numstr,"%d", gid);
		return numstr;
	}
	else
		return grp_ptr->gr_name;
}
