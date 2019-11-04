#include <stdio.h>
#include <math.h>
#include <string.h>

#define cube(x) (pow((x),3))
#define remainderOf(x,d) ((x)%(d))
#define product(x,y) ((x)*(y))
#define NELEMS(arr) (sizeof(arr)/sizeof(int))
#define DOUBLE(x) (2*(x))
#define AVG(x,y) ((x)+(y))/2
#define AREA(x,y)  ((x)*(y))
#define ABS(a) ((a)<0?-(a):(a))
#define TO_UPPER(c) ('a'<=(c)&&(c)<='z'?(c)-('a'-'A'):(c))
#define DISP(f,x,y) printf("%g",f(x,y));
#define M 10


int main(){
    printf(">>>>>Current line is %d in the file %s on %s at %s\n",__LINE__,__FILE__,__DATE__,__TIME__);
    printf("Cube of 3 %f\n",cube(3));
    printf("Remainder of 10%%3 is %d\n",remainderOf(10,3));

    int arr[]= {1,2,3,4};
    printf("Number of elements %lu\n",NELEMS(arr));
    printf("Double 1+2 %d\n",DOUBLE(1+2));
    printf("4/Double(2) %d\n",4/DOUBLE(2));
    printf("Average %lf\n",AVG(3.0,2.0));
    printf("Rectangle area %lf\n",AREA(3.0,2.0));
    printf("Absolute %lf\n",ABS(-2.0));
    printf("To upper %c\n",TO_UPPER('a'));
    printf("To upper %c\n",TO_UPPER('d'));

    printf(">>>>>Current line is %d in the file %s on %s at %s\n",__LINE__,__FILE__,__DATE__,__TIME__);
    // Test to upper 
    printf("Test To Upper abcd\n");
    char s[10];
    int i = 0;
    strcpy(s,"abcd");
    printf("%c\n",s[++i]);
    putchar(TO_UPPER(s[++i]));//D
    printf("%d\n",i);

    printf(">>>>>Current line is %d in the file %s on %s at %s\n",__LINE__,__FILE__,__DATE__,__TIME__);
    //Test function macro with inputs as function and its arguments
    DISP(pow,2,2) //4

    #if M
    printf("%s\n","M exists");
    #endif

    #if !defined(M)
    printf("Not define M yet\n");
    #else
    printf("Already define M\n");
    #endif



}

