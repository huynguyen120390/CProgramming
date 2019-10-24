#include <stdio.h>
#include <stdlib.h>


const int maxSize = 3;
int size = 0;
int arr[maxSize];

int push(int num);
int pop(void);
int is_empty(void);
int peek(void);
void display(void);
void extend_limit(int extra);

int main(int argc, char ** argv){
    push(1);
    push(97);
    push(96);
    display();
    pop();
    display();
    return 0;
}


int push(int num){
    if( size + 1 > maxSize){
        printf("StackOverFlow");
        exit(EXIT_FAILURE);
    }
    else{
        arr[size++] = num;
        return num;
    }
}

int pop(void){
    if(size - 1 < 0){
        printf("StackUnderFlow");
        exit(EXIT_FAILURE);
    }
    else{
        return arr[--size];
    }
}

int peek(void){
    if(is_empty()){
        printf("StackEmpty");
    }
    else{
        return arr[size-1];
    }
}

void display(void){
    printf("[");
    for(int i = 0; i < size; i++){
        printf("%d,",arr[i]);
    }
    printf("]");
}



int is_empty(void){
    if(size == 0){
        return 1;
    }
    else{
        return 0;
    }
}