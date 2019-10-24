// Example illustrating dynamic memory allocation of a nested array


#include <stdio.h>
#include <stdlib.h>

// Our nested array struct
struct NestedArray {
    int* array;
    int size;
};


int main() {

    
    struct NestedArray nested;
    struct NestedArray nested2;
    
    nested.array = NULL;
    nested.size = 0;
    
    printf("%p %d\n", nested.array, nested.size);

    // create an array of size 10;
    nested.size = 10;
    nested.array = malloc(sizeof(int) * nested.size);
    
    // Add 10 items 
    int i, j;
    for (i = 0; i < nested.size; i++) {
      nested.array[i] = i + 1;
    }

    // print the first array
    for (i = 0; i < nested.size; i++) 
      printf("%d ", nested.array[i]); 

    printf("\n");

    // copy
    nested2 = nested;

    // print the copy
    for (i = 0; i < nested2.size; i++) 
      printf("%d ", nested2.array[i]); 

    printf("\n");
 
    // change an element in either array       
    nested.array[5] = 555;

    // print the first array
    for (i = 0; i < nested.size; i++) 
      printf("%d ", nested.array[i]); 

    printf("\n");

    // print the second array
    for (i = 0; i < nested2.size; i++) 
      printf("%d ", nested2.array[i]); 
    printf("\n");
    
    free(nested.array);
    nested.array = NULL;
    nested.size = 0;

    printf("\n");
    return 0;
}

