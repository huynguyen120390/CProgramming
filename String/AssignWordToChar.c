#include <stdio.h>
#include <string.h>


int main(){
    char str[100] = "sup";
   // *str =0;
    //str[0] = '\0';
    strcat(str,"");

    printf("%s",str);
}