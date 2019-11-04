#include <stdio.h>
#include <stdlib.h>

int main(int argc, char ** argv){
    double sum = 0;
    for(int i = 1; i < argc; i++){
        sum += atof(argv[i]);
    }
    printf("Result sum = %.2f",sum);

    return 0;
}