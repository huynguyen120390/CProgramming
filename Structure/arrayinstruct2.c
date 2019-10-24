// Example illustrating automatic allocation of a nested array


#include <stdio.h>
#include <stdlib.h>

// Our nested array struct
struct NestedArray {
    int array[10];
    int size;
};



int main() {

    struct NestedArray nested;
    struct NestedArray nested2;

    nested.size = nested2.size = 10;
    
    
    // Add 10 items 
    int i, j;
    for (i = 0; i < nested.size; i++) {
      nested.array[i] = i + 1;
    }

    // print array contents
    for (i = 0; i < nested.size; i++) 
      printf("%d ", nested.array[i]); 

    // copy structure variable
    nested2 = nested;

    // print array copy
    printf("\n");
    for (i = 0; i < nested2.size; i++) 
      printf("%d ", nested2.array[i]); 

    printf("\n");
     
    // change one element in either nested array   
    nested.array[5] = 555;

    // print both arrays after the change is made in one of them
    for (i = 0; i < nested.size; i++) 
      printf("%d ", nested.array[i]); 

    // print copy
    printf("\n");
    for (i = 0; i < nested2.size; i++) 
      printf("%d ", nested2.array[i]); 
    
   
    
    return 0;
}

