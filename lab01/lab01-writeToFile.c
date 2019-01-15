/* fputs example */
#include <stdio.h>

int main ()
{
   FILE * pFile;
   char sentence [256];

   printf ("Enter sentence to append: ");
   fgets (sentence,256,stdin); // Read 256 characters from the given input stream (stdin), and store it in the buffer (sentence)
   pFile = fopen ("mylog.txt","a"); // Open a file in append mode. The cursor will be placed at the end of the file.
   fputs (sentence,pFile); // Write the contents of the buffer (sentence) into the file
   fclose (pFile);
   return 0;
}
