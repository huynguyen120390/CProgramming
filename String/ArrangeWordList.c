#include <stdio.h>
#include <string.h>
#include <stdlib.h>
void feed_wordList(char * wordList,int size){
    //in put word list without knowing its limits

}
int main(int argc, char ** argv){
    char *wordList[] = {""};
    char word[20];
    char * p, c;
    int i = -1;
    int strlength = -1;
    
    while(strlength != 0){
        //get word by using loop of getchar() and detect \0
        printf("Enter word :");
        scanf("%9s",word);

        printf("Taken word: %s at %p\n",word,&word[0]);
        //detect word length to avoid 4-letter words and words with length 20+
        if (strlen(word) == 0){
            printf("Break due to length 0\n");
            break;
        }else if(strlen(word) > 20){
            printf("Ignore due to length 20+\n");
            continue;
        }
        printf("Something");
        //add word to wordList by extending memory for one new word and assign each char to memory
        i++;
        wordList[i] = malloc(sizeof(char)*strlen(word) + 1);
        strcpy(wordList[i],word);
        printf("[");
        for(int j = 0; j <= i; j++){
            printf(" %s,",wordList[j]);
        }
        printf("]\n");
    
    }





    return 0;

}