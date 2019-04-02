/* sigdemo3.c
 *	purpose:   show answers to signal questions
 *	question1: does the handler stay in effect after a signal arrives?
 *	question2: what if a signalX arrives while handling signalX?
 *      question3: what if a signalX arrives while handling signalY?
 *      question4: what happens to read() when a signal arrives?
 */

#include	<stdio.h>
#include	<signal.h>
#include <stdlib.h>

#define	INPUTLEN	100

int main(int ac, char *av[]){
	void	inthandler(int);
	void	quithandler(int);

	signal( SIGINT,  inthandler );		/* set handler */
	signal( SIGQUIT, inthandler );		/* set handler */

	char UserIn = '\n';
	do {
		printf("\nhello\n");
		 UserIn = getchar();
	} 
	while( UserIn != 'q' );
}

void inthandler(int s){

	printf("\nInterrupted! OK to quit (y/n)? ");
	if (getchar() == 'y') {
		exit(0);
	}
}
