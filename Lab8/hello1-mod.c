/* hello1.c
 *	purpose	 show the minimal calls needed to use curses
 *	outline  initialize, draw stuff, wait for input, quit
 */

#include	<stdio.h>
#include	<curses.h>
#include <string.h>

#define SIZE 128

main(int argc, char ** argv)
{
  char  message[SIZE] = "Hello world";
  
  // grab the first argument if there is one
  if (argc > 1){
    // copy the argv into the message after making space for it
     memcpy(message, argv[1], SIZE-1);
     message[SIZE] = '\0'; // ensure string terminator
  }

	initscr() ;		/* turn on curses	*/
  clear();			/* clear screen	*/

  while (true) {
				/* send requests	*/  
     
	  move(10,20);			/* row10,col20	*/
	  addstr(message);		/* add a string	*/
    refresh();		/* update the screen	*/	 
    sleep(1); 
  	clear();
   
    refresh();
    sleep(1);
  } 
  endwin();		/* turn off curses	*/
}
