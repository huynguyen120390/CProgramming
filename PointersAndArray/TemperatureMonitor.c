#include <stdio.h>
#include <stdlib.h>



int * feed_temperatures(int * temperatures, const int dayRange, const int hourRange){
    //Feed a 2D array of temperatures with random temperature values
    int day, hour, temperature;
    for(day = 0; day<dayRange; day++){
        for(hour = 0; hour< hourRange; hour++){
            temperature = rand() % 200;
            *((temperatures + day*hourRange) + hour)= temperature;
            
            
        }
    }
    return temperatures;
}

void print_temperatures(int * temperatures,const int dayRange,const int hourRange){
    int day, hour, temperature;
    for(day = 0; day < dayRange; day++){
        for(hour = 0; hour < hourRange; hour++){
            temperature = *((temperatures + day*hourRange) + hour);
           // printf("Day %3.d Hour %3.d Temperature %3.d\n",day + 1,hour + 1,temperature);
        }
        
    }
}


int main(int argc, char ** argv){
    int dayRange = 7, hourRange = 24;
    int temperatures[dayRange][hourRange];
    int day, hour,temperature;
    for(day = 0; day<dayRange; day++){
        for(hour = 0; hour< hourRange; hour++){
            temperature = rand() % 200;
            //*((temperatures + day*hourRange) + hour)= temperature;
            temperatures[day][hour]= temperature;
            //printf("%d\n",*(temperatures[day] +hour));
            
        }
    }

   // twoDArrPtr = feed_temperatures(&temperatures[0][0],dayRange,hourRange);
    print_temperatures(&temperatures[0][0],dayRange,hourRange);
    

}