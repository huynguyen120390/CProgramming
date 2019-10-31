#include <stdio.h>
#include <string.h>
#define BOOL int

BOOL is_palindrome(char arr[],int n);


int main(int argc, char ** argvs){
    char theString[] = "cabbac";
    int length = strlen(theString);
    printf("%s is a palindrome : %d",theString,is_palindrome(theString,length));
    return 0;
}

BOOL is_palindrome(char arr[],int n){
    char *l ,* h;
    l = &arr[0];
    h = &arr[n-1];
    while(l<h){
        if(*l != *h){
            return 0;
        }
        l++;
        h--;
    }
    return 1;

}

