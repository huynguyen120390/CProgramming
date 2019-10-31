#include <stdio.h>

size_t strlen(const char * str){
    size_t length = 0;
    //this means for(;*str!='\0',str++)
    //this means for(;*str++;)
    //this measn while(*str++)
    for(;*str;str++){ 
        length++;
    }
    return length;
}
size_t strlen2(const char *str){
    const char * p = str;
    while(*str){
        str++;
    }
    return str - p;
}


int main(int argc, char ** argvs){
    char * str = "Hello";
    printf("%ld",strlen(str));
}