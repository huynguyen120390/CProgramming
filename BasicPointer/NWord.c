#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char * nword(const char * word, const int n);
int main(){
    char * result = nword("Hello",4);
    printf("%s", result);
    return 0;
}

char * nword(const char * word, const int n){
    char * result = (char*)malloc(n*strlen(word)*sizeof(char));
    int size = n *strlen(word);
   
    size_t i,j;
    for(i = 0; i < n; i++){
        for(size_t j = 0; j < strlen(word); j++){
            *(result+i*strlen(word)+j) = *(word + j);
            //printf("%c\n",*(result+i*strlen(word)+j));
        }
    }

    return result;
}