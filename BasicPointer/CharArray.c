#include <stdio.h>
int main(){
    char arr1[8] = "blue";
    char *arr2   = "blueberry";
    printf("Array 1 : %s\n",arr1);
    printf("Char size : %lu\n",sizeof(char));
    printf("Array1 size : %lu\n",sizeof(arr1));
    printf("Array 2 : %s\n",arr2);
    printf("Char size : %lu\n",sizeof(char));
    printf("Array2 size : %lu\n",sizeof(arr2));
    arr2 = "hennesyBlahBlah";
    printf("Array 2 : %s\n",arr2);
    return 0;
}