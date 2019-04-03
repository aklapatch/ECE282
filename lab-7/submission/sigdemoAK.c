/* sigdemo1.c - shows how a signal handler works.
 *            - run this and press Ctrl-C a few times
 */
// modified by Aaron Klapatch for Spring 2019
#include	<stdio.h>
#include	<signal.h>
#include <unistd.h>
#include <stdlib.h>

// this function is called when the interrupt is called
void f(int signum){

	// ask the user if they want to quit
	printf("\nInterrupted! OK to quit (y/n)?");
	if (getchar() == 'y'){
		exit(0); // quit if they say yes
	}
}

int main(){

	signal( SIGINT, f );	// associate that signal with the f function

	int	i;
	for(i=0; i<5; i++ ){	// print hello five times (once per second ish)
		printf("\nhello\n");
		sleep(1);
	}
}