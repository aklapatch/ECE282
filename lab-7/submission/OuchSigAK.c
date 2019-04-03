/* sigdemo1.c - shows how a signal handler works.
 *            - run this and press Ctrl-C a few times
 */
// modified by Aaron Klapatch for Spring 2019
#include	<stdio.h>
#include	<signal.h>
#include <unistd.h>
#include <stdlib.h>
#include <ctype.h>

// convert the argument to an int, then return it.
// return -1 if the arg does not have an int.
int getIntFromSTR(char * input){
	if (isdigit(input[0])){
		return atoi(input);
	
	} else {
		return -1;
	}
}

int OuchNum = 0; // the number of times the interrupt has been called
int OuchThreshold = 1; // exit after that many interrupts have occured

// this function is called when the interrupt is called
void f(int signum){
	++OuchNum; // increment the number of interrupts

	printf("\nOOCH!");
	int i = OuchNum;
	while(--i) { // print the correct number of '!'
		printf("!");
	}	
	printf("\n");

	if (OuchNum >= OuchThreshold){ 
		exit(0); // exit if they hit the right number of interrupts
	}
}

int main(int ac, char ** av){

	signal( SIGINT, f );	// associate that signal with the f function

	// parse first argument
	if (ac > 1) {
		OuchThreshold = getIntFromSTR(av[1]);
		if ( OuchThreshold == -1){
			// argument one is not an integer
			printf("Argument 1 needs to be an integer.\n");
			return 1;
		}
	} else {
		printf("Usage: %s InterruptThreshold\n", av[0]);
		printf("Please specify the maximum number of interrupts.\n");
		return 1;
	}

	while(OuchNum < OuchThreshold) {} // wait for interrupts

	return 0;
}