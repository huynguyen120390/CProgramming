#include <stdio.h>

#define BOOL int

BOOL search(int arr[] , int n, int key){
    int * p;
    p = arr;
    int i;
    for(i = 0; i < n; i++){
        printf("Temperature %d\n",*(p + i));
        if(key == *(p + i)){
            return 1;
        }
    }
    return 0;
}
int main(int argc, char ** argvs){
    int temperature[7][24];
    int w,h;
    int key = 32;
    BOOL is_found = 0;
    for(w = 0; w < 7; w++){
        for(h=0;h<24;h++){
            printf("Start with Week %d Hour %d\n", w,h);
            is_found = search(*(temperature + w),h,key);
        
            if (is_found == 1){
                printf("FOUND %d\n",key);
                break;
            }
        }
        if(is_found == 1){
            break;
        }

    }
    if(is_found == 0){
        printf("NOT FOUND %d",key);
    }
    return 0;
}