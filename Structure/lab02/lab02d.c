#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

void strip_punct(char original[]);

int main(void) {
   strip_punct("hi, how are you?");  
   return 0;
}

void strip_punct(char original[]){
   int i;
   char *pRead;
   char *pWrite;
   
   pRead = original;
   pWrite = original;
   for (i = 0; i < strlen(original); i++){
      if(!ispunct(original[i])){
         *pWrite = *pRead;
         pWrite++;
      }
      pRead++;
   }
   *pWrite = 0;
   printf("%s", original);
   
}


