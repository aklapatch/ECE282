/* fgets example 
 * http://www.cplusplus.com/reference/cstdio/fgets/
 */
#include <stdio.h>

int main()
{
   FILE * pFile;
   char mystring [100];

   pFile = fopen ("mylog.txt" , "r");
   if (pFile == NULL) perror ("Error opening file");
   else {
     if ( fgets (mystring , 100 , pFile) != NULL ) 	// IF data is read from the input stream (pFile), THEN
       puts (mystring); 							// print the characters read to the standard output
     fclose (pFile);
   }
   return 0;
}
