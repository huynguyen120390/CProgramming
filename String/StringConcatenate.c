#include <stdio.h>

char * strconcat(char * dest, const char * src){
    // size_t destLength = strlen(dest);
   // size_t srcLength = strlen(src);
    printf("Here1\n");
    char * p ;
    p= dest;
    while(*p){
        p++;
    };
    while(*src){
       
        *p = *src;
        src++;
        p++;
        
    }
    *p = '\0';
    return dest;
}

int main(int argc, char ** argvs){
    char dest[] = "Hello I Love You";
    const char * src = "Hey";
    printf("Here\n");
    char * newDest = strconcat(dest,src);
    printf("%s",newDest);
    int i,j;
    char * s;
    scanf("%d%s%d",&i,s,&j);
    printf("%d\n",i);
    printf("%s\n",s);
    printf("%d\n",j);

}