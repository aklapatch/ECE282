#include <stdio.h> 
#include <stdlib.h> // for exit() function
#include <sys/types.h> 
#include <sys/stat.h> 
#include <fcntl.h> 
#include<unistd.h>

int main(int argc, char *argv[]) {     
  
  // print usage message if not enough args are specified
  if ( argc < 2 ){
    printf("Usage: %s directoryName\n", argv[0]);
    
    printf("The directory might exist or not.\n");
    exit(1);
  }
  
  
  // try to change directory
  int err_code = chdir(argv[1]);
  
  // chdir will return a non-zero number if there is
  // an error
  if (err_code != 0){
  
    // notify the user that the action failed and print
    // the errorno, message
    printf("Changing to directory \"%s\" failed: \n", argv[1]);
    perror("");
    
  } else {
  
    // let the user know that the action was successful
    printf("Changed to \"%s\" w/o problem.\n", argv[1]);                 
  }
  
  return 0;
} 
