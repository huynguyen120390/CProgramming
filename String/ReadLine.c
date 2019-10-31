#include <stdio.h>

#define BOOL int

void read_line_skip_frontWhiteSpace(char * str, int n){
    char c;
    int i = 0;
    BOOL is_frontWhiteSpace = 1;
    while((c = getchar())!='\n' && i < n+1){
        if(is_frontWhiteSpace){
            if(c != ' '){
                is_frontWhiteSpace = 0;
                *str++ = c;
                i++;
            }
        }else{
            *str++ = c;
            i++;
        }
    }
    *str = '\0';
}

void read_line_skipFrontWhiteSpace_stopAtFirstWhiteSpace(char * str, int n, int maxWordNum){
    char c;
    int i = 0;
    int wordNum = 1;
    BOOL is_frontWhiteSpace = 1;
    BOOL is_firstWhiteSpace = 0;
    while((c = getchar())!='\n' && i < n+1){
        if(is_frontWhiteSpace){
            if(c != ' '){
                is_frontWhiteSpace = 0;
                is_firstWhiteSpace = 1;
                *str++ = c;
                i++;
            }
        }else{
            if(wordNum == maxWordNum){
                if(c != ' '){
                    *str++ = c;
                    i++;
                }
                else{
                    break;
                }
            }else{
                *str++ = c;
                i++;
                if(c == ' '){
                    wordNum++;
                }
            }
        }
        printf("%c\n",c);
    }
    *str = '\0';
}

int main(int argc, char ** argv){
    int n = 100;
    char str[n];
    read_line_skipFrontWhiteSpace_stopAtFirstWhiteSpace(str,n,4);
    printf("Result:-%s-",str);

}