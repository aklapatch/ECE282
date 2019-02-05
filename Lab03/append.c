
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

// reads file in string form and returns the files contents
char * fileToString(FILE *);

int main(int argc, char ** argv){

    // check for --help flag
    if (strcmp("--help", argv[1]) == 0){
        puts("This program reads a source file and appends it to the destination file.");
        printf("Usage: %s SourceFile FileToAppend\n",argv[0]);
        return 1;
    }

    // check for argument number
    if (argc <=2){
        // print usage message and exit
        printf("Usage: %s SourceFile FileToAppend",argv[0]);
        return 1;
    }

    // attempt to open text file
    FILE * input = fopen(argv[1],"r");
    if (input == NULL){
        // print error and exit if the file is not there
        perror("Could not open specified file: ");
        return 1;
    }

    FILE * output = fopen(argv[2], "a");
    if ( output == NULL){
        perror("Failed to open output file: ");
        fclose(input);
        return 1;
    }    

    // if the file could be opened
    char * file_contents = fileToString(input);
    fclose(input);

    // dump contents to output file
    fputs(file_contents,output);
    fclose(output);

    free(file_contents);

    return 0;
}

char * fileToString(FILE * input){
    // find the end of the file
    fseek(input,0,SEEK_END);
    size_t size = ftell(input);
    char * str_out = (char*) malloc(sizeof(char)*size);
    rewind(input);

    fread(str_out,sizeof(char),size,input);
    return str_out;
}
