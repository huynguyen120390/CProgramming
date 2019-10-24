#include <stdio.h>




int main(int argc, char ** argv){
    const int segments[10][8] = {   {1,1,1,1,1,1,0,1},//0
                                    {0,1,1,0,0,0,0,0},//1
                                    {1,1,0,1,1,0,1,1},//2
                                    {1,1,1,1,0,0,1,1},//3
                                    {0,1,1,0,0,1,1,1},//4
                                    {1,0,1,1,0,1,1,1},//5
                                    {1,0,1,1,1,1,1,1},//6
                                    {1,1,1,0,0,0,0,0},//7
                                    {1,1,1,1,1,1,1,1},//8
                                    {1,1,1,1,0,1,1,1}//9
                                };
    
    int num = 2;
    printf(" ");
    if(segments[num][0]){
        printf("_");
    }else{
        printf(" ");
    }
    printf("\n");
    if(segments[num][5]){
        printf("|");
    }else{
        printf(" ");
    }
    if(segments[num][6]){
        printf("_");
    }else{
        printf(" ");
    }
    if(segments[num][1]){
        printf("|");
    }else{
        printf(" ");
    }
    printf("\n");   
    if(segments[num][4]){
        printf("|");
    }else{
        printf(" ");
    }
    if(segments[num][3]){
        printf("_");
    }else{
        printf(" ");
    }
    if(segments[num][2]){
        printf("|");
    }else{
        printf(" ");
    }
    printf("\n");

    return 0;
}