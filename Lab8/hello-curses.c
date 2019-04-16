/* hello5.c
 *    purpose  bounce a message back and forth across the screen
 *    compile  cc hello5.c -lcurses -o hello5
 */
#include	<curses.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#define SIZE 128
#define	LEFTEDGE	10
#define	RIGHTEDGE	30
#define	ROW		10

main(int argc, char ** argv)
{
  char  message[SIZE] = "Hello";
  
  // grab the first argument if there is one
  if (argc > 1){
    // copy the argv into the message after making space for it
     memcpy(message, argv[1], SIZE-1);
     message[SIZE] = '\0'; // ensure string terminator
  }
	
  // make sure the blanks string will still cover the input argument
  char blank[SIZE+1];
  memset(blank,' ',sizeof(char)*SIZE);
  blank[SIZE] = '\0'; // ensure string terminator

	int	dir = +1;
	int	pos = LEFTEDGE ;

	initscr();
	  clear();
	  while(1){
		move(ROW,pos);
		addstr( message );		/* draw string		*/
		move(LINES-1,COLS-1);		/* park the cursor	*/
		refresh();			/* show string		*/
		usleep(40000);  // this is about 25 hz
		move(ROW,pos);			/* erase string		*/
		addstr( blank );
		pos += dir;			/* advance position	*/
		if ( pos >= RIGHTEDGE )		/* check for bounce	*/
			dir = -1;
		if ( pos <= LEFTEDGE )
			dir = +1;
	  }
}
