#include <stdio.h>
#include <stdlib.h>

int sum_array(int a[], int n){
    int i, sum;
    sum = 0;
    for(i = 0; i < n; i++)
        sum += a[i];
    return sum;
}

int sum_array2(int * a, int n){
    int i, sum;
    sum = 0;
    for(i = 0; i < n; i++)
        sum += *(a + i);
    return sum;
}

void input(int * a, int n){
    printf("Please enter %d numbers",n);
    int i = 0;
    for(i = 0; i < n; i++){
        scanf("%d",a + i);
    }
}

int main(int argc, char ** argvs){
    int n = 10;
    int * arr = malloc(sizeof(int) * n);
    input(arr,n);
    //int sum = sum_array2(&(*arr),n);
    int sum = sum_array2(arr,n);
    printf("Sum is %d",sum);
    free(arr);
    return 0;
}