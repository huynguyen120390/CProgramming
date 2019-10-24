
	/*
	** This program is to allocate a memory dynamically, populate it, and then
	** create a new array with some of the old array's contents. However,
	** the program has several blank lines that you need to fill.
	*/

#include <stdio.h>
// 1. add a library for malloc
#include <stdlib.h> //###Solution
// 2. add a library for memcpy
#include <string.h> //###Solution

int main() {
	double *array, *new;
	double  value;
	int size, i, offset;

	printf("Enter the size of the array: ");
	scanf("%d", &size);

	// 3. dynamically allocate an array with "size" number of doubles and store into array

	if (array == NULL) {
		printf("not enough memory - exiting");
		exit(1);
	}
	
	array = malloc(sizeof(int)*size); //Array points to a chunk of heap memmory####Solution 
	/* populates array */
	for (i = 0; i < size; i++)
  		array[i] = (double) i + 10.0;	


	while (1) {
  		printf("Address(hex)\tAddress(base10)\tValue\n");
		/* prints array addresses and contents */
  		for (i = 0; i < size; i++)
		  	printf("%i",i);
    			//printf("%p\t%u\t%lf\n", &(array[i]),&(array[i]),array[i]);
  
		printf("Enter array offset and the new value for this location (0 0 to quit): ");
  		scanf("%d %lf", &offset, &value);
  		if (offset == 0  &&  value == 0.0)
    			break;			/* break out of loop */
  		if (offset < 0  ||  offset > 9) {
    			printf("Offset out of bounds\n");
    			continue;			/* go back to start of loop */
    		}
  		// 4. assign a value into an appropriate array location using pointer syntax and arithmetic
		printf("Assign a value into an appropriate array location using pointer syntax and arithmetic "); //###Solution
		for(i = 0; i < size; i++){ //###Solution
			scanf("%lf",&value); //###Solution
			*(array +i) = value; //###Solution
		}
  	}

	printf("How big of a copy of the original array would you like? ");
	scanf("%d", &i);
	
	// 5. create a new array that has i number of elements; assume 0 < i <= size will be entered

	if (new == NULL) {
		printf("not enough memory - exiting");
		exit(1);
	}
	memcpy(new, array, sizeof(double) * i);
	
	// 6. print the new array the same way the old one was printed in the loop
	for(i = 0; i< size; i++){
		value = *(new+i);
		printf("In new array, value at %i is %lf ",i,value);
	}
	
}
