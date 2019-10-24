#include <stdio.h>

int store_array(int arr[], int size){
    long int value;
    printf("Input 5 numbers:\n");
    for(int i = 0; i< size; i++){
        scanf("%ld",&value);
        printf("Number :");
        arr[i]= (int)value;

        printf("Inputed %ld\n",*(arr +i));
    }
    printf("Done with inputing 5 numbers %d\n",sizeof(arr)/sizeof(arr[0]));
    for(int i = -1; i < size+1; i++){
        printf("Array[%ld] = %ld\n",i,arr[i]);
    }
    return arr;
}

void print_array(int* arr){
    int size = sizeof(*arr)/sizeof(int);
    for(int i = 0; i < size; i++){
        printf("Array i %d",arr[i]);
    }
}
int main(int argc, char ** argv){
    const int size = 10;
    int arr[size] = {0};
    int * newArr ;
    //store_array(&arr,size);
    newArr = store_array(arr,size);
    //print_array(*arr);
    return 0;
}