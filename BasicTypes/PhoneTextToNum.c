#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <stdbool.h>


struct charArrObj{
    char * arr;
    int size;
};

struct charArrObj read_array(char * arr);
bool belong(char ch, char * charString);
char convert(char ch);
void print_charArray(char * arr);

int main(int argc, char ** argv){
    //take chars
    printf("Enter phone number\n");
    char ch;
    int i = 0;
    u_int8_t size = 14;
    struct charArrObj charArr;
    char * phoneArr = malloc(sizeof(char)*size);
    size = 0;
    
    charArr = read_array(phoneArr);
    phoneArr = &(*charArr.arr);
    print_charArray(&(*phoneArr));
    for(int i = 0; i < charArr.size; i++){
        phoneArr[i] = convert(phoneArr[i]);
    }
    print_charArray(&(*phoneArr));


    free(phoneArr);
    return 0;
}

struct charArrObj read_array(char * arr){
    struct charArrObj charArr;
    char ch;
    int i = 0, size = 0;
    do{
        ch = getchar();
        *(arr + i) = ch;
        i++;
        size++;
    }while(ch !='\n' || size < 14);
    *(arr + i) = '\0';
    charArr.size = size;
    charArr.arr = arr;
    return charArr;
}

void print_charArray(char * charArr){
    int i = 0;
    while(charArr[i] != '\0'){
        printf("%c",charArr[i]);
        i++;
    }
    
}

bool belong(char ch, char * charString){    
    int size = 3;
    for(u_int8_t i = 0 ; i < size ; i++){
        if(ch == charString[i]){
            return true;
        }
    }
    return false;
}

char convert(char ch){
    
    char ori = ch;
    if(belong(ch,"ABC")){
        ch = '2';
    }else if(belong(ch,"DEF")){
        ch = '3';
    }else if(belong(ch,"GHI")){
        ch = '4';
    }else if(belong(ch,"JKL")){
        ch = '5';
    }else if(belong(ch,"MNO")){
        ch = '6';
    }else if(belong(ch,"PRS")){
        ch = '7';
    }else if(belong(ch,"TUV")){
        ch = '8';
    }else if(belong(ch,"WXYZ")){
        ch = '9';
    }

    return ch;
}
