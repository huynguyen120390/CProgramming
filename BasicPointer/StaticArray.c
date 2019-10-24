#include <stdio.h>
void staticArrayInit(void){
    static int array1[3];

    puts("\nValues on entering staticArrayInit:");

    for(size_t i = 0; i <=2 ; i++){
        printf("Array1[%zu] = %d ",i,array1[i]);
    }

    puts("\nModify values on entering staticArrayInit:");

    for(size_t i = 0; i <= 2; i++){
        printf("Array1[%zu] = %d ",i, array1[i] += 5);
    }
}

int main(){
    staticArrayInit();
}