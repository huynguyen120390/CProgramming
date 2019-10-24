#include <stdio.h>

int read_integer(){
    long int num, sum = 0;
    while( num != 0){
        scanf("%ld",&num);
        sum += num;
    }
    return sum;
}
int main(int argc, char ** argv){
    long int n, sum;
    printf("Enter numbers press 0 to get done");
    sum = read_integer();
    printf("Sum is :%ld\n",sum);

    return 0;
}