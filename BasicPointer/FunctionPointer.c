#include <stdio.h>
int average(int x, int y) { return (x+y)/2;}


int main(){
    int (*fn) (int,int);
    fn = average;
    int z1 = average(2,4);
    int z2 = (*average)(2,4);
    int z3 = (*fn)(2,4);
    int z4 = fn(14,16);
  
    printf("%d,%d,%d,%d\n",z1,z2,z3,z4);

}
