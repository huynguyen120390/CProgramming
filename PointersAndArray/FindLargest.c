#include <stdio.h>

int find_max(int arr[], int n){
    int max = arr[0];
    for(int i = 0; i < n; i++){
        if(arr[i]>max){
            max = arr[i];
        }
    }
    return max;
}

void store_arr(int arr[],int n){
    for(int i = 0; i < n; i++){
        scanf("%d",&arr[i]);
    }
}

void store_arr2(int * arr, int n){
    for(int i = 0; i < n; i++){
        scanf("%d",&arr[i]);
    }
}

int find_max2(int * arr, int n){
    int max = arr[0];
    for(int i = 0; i < n; i++){
        if(arr[i]>max){
            max = arr[i];
        }
    }
    return max;
}

int main(int argc, char ** argvs){
    // //Example 1
     const int n = 10;
     int arr[n] = {0,1,2,3,4,5,6,7,8,9};
    // store_arr(arr,n);
    // int max = find_max(arr,n);
    // printf("Max %d",max);
    // //Example 2
    // int * arrPtr = arr;
    // store_arr2(arr,n);
    // int max2 = find_max2(arr,n);

    // printf("Max %d", max2);
    //Example 3
    int * middle;
    int * low;
    int * high;
    low = &arr[6];
    high = &arr[8];
    middle = low + (high - low)/ 2;
    printf("High - Low, %ld", high -low);
   
   

    

    return 0;
}