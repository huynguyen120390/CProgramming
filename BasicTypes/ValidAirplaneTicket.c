#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>

int main(int argc, char ** argv){
   long int num, remainedNum;

    __int8_t i = 0;
    __int8_t finalDigit;
    __int8_t remainder;
    char ch ;
    char * charNum = malloc(10);
 
    //Scan
    do{ 
        scanf("%c",&ch);
        *(charNum + i) = ch;
        i++;
    }while(ch!= '\n');
    *(charNum + i) = '\0';

    printf("Collected number in character %s\n",charNum);
    num = atoll(charNum);
    printf("Number in long int %ld",num);
    //Take final digit
    finalDigit = num%10;
    //Take remain digits
    remainedNum = (num - finalDigit)/10;
    //Devide digits by 7
    remainder = remainedNum%7;
    //Compare remainder with final digit

    if(remainder == finalDigit){
        printf("\nRemained %ld Remainder %d and finalDigit %d => Valid\n",remainedNum,remainder,finalDigit);
    }else{
        printf("\nRemained %ld Remainder %d and finalDigit %d => Invalid\n",remainedNum,remainder,finalDigit);
    }

    free(charNum);

    return 0;

}