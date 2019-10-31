#include <stdio.h>

#define N 10

int main(int argc, char ** argvs){
    int a[N], *p;

    p = a;

    for(p = a; p < a + N; p++){
        scanf("%d",p);
    }

    for(p=a+N-1; p>=a; p--){
        printf(" %d",*p);
    }


    printf("\n");

    return 0;
}