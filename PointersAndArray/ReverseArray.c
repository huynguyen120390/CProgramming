#include <stdio.h>
#include <string.h>
#define N 10

void reverse_intArray(int arr[],int n);  //use int index and swap function
void reverse_intArray2(int arr[],int n); //use multiple pointers
void reverse_intArray3(int arr[],int n);//use mutiple pointers manipulate swap function
void reverse_charArray(char arr[],int n); //use multiple pointers

void swap_int(int * a, int * b);
void display_intArray(int arr[], int n);
void display_charArray(char arr[], int n);

int main(int argc, char ** argvs){
    int intArr[N] = {1,2,3,4,5,6,7,8,9,10};
    display_intArray(intArr,N);
    reverse_intArray3(intArr,N);
    display_intArray(intArr,N);
    char charArr[] = "Hello My Babe I Love You";
    int strLength = strlen(charArr);
    display_charArray(charArr,strLength);
    reverse_charArray(charArr,strLength);
    display_charArray(charArr,strLength);
    return 0;
}

void reverse_charArray(char arr[],int n){
    char * p, *q;
    char temp;
    p= &arr[0];
    q = &arr[n-1];
    while(p<q){
        temp = *q;
        *q-- = *p;
        *p++ = temp;
    }
}

void display_charArray(char arr[], int n){
    for(int i = 0; i < n ; i++){
        printf(" %c",arr[i]);
    }
    printf("\n");
}

void reverse_intArray(int arr[], int n){
    //use int index
    int p = 0,q = n - 1;
    while(p<q){
        swap_int(&arr[p],&arr[q]);
        p++;
        q--;
    }
}

void reverse_intArray2(int arr[], int n){
    //use mul pointers
    int *p = &arr[0];
    int *q = &arr[n-1];
    int temp;

    while(p<q){
        temp = *p;
        *p++ = *q;
        *q-- = temp;
    }
}

void reverse_intArray3(int arr[], int n){
    //use mul pointers
    int *p = &arr[0];
    int *q = &arr[n-1];
    int temp;

    while(p<q){
        swap_int(p++,q--);
    }
}

void swap_int(int * a, int * b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

void display_intArray(int arr[], int n){
    for(int i = 0; i < n; i++){
        printf(" %d",arr[i]);
    }
    printf("\n");
}