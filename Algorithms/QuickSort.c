#include <stdio.h>
#include <ctype.h>
int partition_with_method_of_chasing_endPivot(int arr[], int low, int high);
void quicksort(int arr[], int low, int high);
void swap(int * a, int *b);
void display_array(int arr[],int size);

int main(int argc, char ** args){
    int arr[] = {7,2,49,2,734,2,3,0,2,4,6};
    int size = sizeof(arr)/sizeof(arr[0]);
    quicksort(arr,0,size-1);
    display_array(arr,size);
    return 0;
}


int partition_with_method_of_chasing_endPivot(int arr[], int low, int high){
    int lo  = low - 1;
    int pivot = arr[high];
    for(int i = 0; i < high ; i++){
        if(arr[i] <= pivot){
            lo++;
            swap(&arr[lo],&arr[i]); // try to move smaller-than-pivot items to front, low is an anchor
        }
    }
    swap(&arr[lo+1],&arr[high]);  // now smaller-than-pivot items is from low to lo , so pivot is lo + 1, put pivot at lo +1 
    return lo + 1;  // lo + 1 is the pivot position, we need it for next partitions
}

void quicksort(int arr[], int low, int high){
    if(high-low>2){
        int p = partition_with_method_of_chasing_endPivot(arr,low,high);
        quicksort(arr,low,p-1);
        quicksort(arr,p+1,high);
    }
}

void display_array(int arr[],int size){
    printf("[");
    for(int i = 0; i < size; i++){
        printf("%d,",arr[i]);
    }
    printf("]\n");
}

void swap(int * a, int * b){
    int temp = *a;
    *a = *b;
    *b = temp;
}




