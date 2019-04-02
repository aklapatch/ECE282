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

int OuchNum = 0;

void inthandler(int);

// convert the argument to an int, then return it.
// return -1 if the arg does not have an int.
int getIntFromSTR(char * input){
	if (isdigit(input)){
		return atoi(input);
	
	} else {
		return -1;
	}
}

int main(int ac, char *av[]){

	int OuchThreshold = 1;

	// parse first argument
	if (ac > 1) {
		OuchThreshold = getIntFromSTR(av[1]);
	
	} else {
		printf("\nPlease specify the number of interrupts to tolerate.\n");
		return 1;
	}

	signal( SIGINT,  inthandler );		/* set handler */
	signal( SIGQUIT, inthandler );		/* set handler */

	printf("\nPress q then enter at any time to quit.\n");

	char UserIn = '\n';
	do {
		 UserIn = getchar();
	} 
	while( UserIn != 'q' && OuchNum < OuchThreshold );
}

// increments the interrupt counter and prints the appropriate number of 
//exclamation points for the number of interrupts recorded
void inthandler(int s){
	OuchNum += 1;
	printf("\nOOch!");
	
	int i = OuchNum;
	while(--i) {
		printf("!");
	}
	printf("\n");
}
