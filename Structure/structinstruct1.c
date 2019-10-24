#include <stdio.h>

struct address_tag {
    int houseNum;
    char street[30];
    char city[30];
    char state[3];
};

typedef struct address_tag Address;

struct person_tag {
    char firstName[20];
    char lastName[20];
    Address addr;
};

typedef struct person_tag Person;

void printAddress(Address addr);
void printPerson(Person per);

int main(void) {
   
    Address add = { 10, "Downing", "London", "WA" };
    Person joe = { "Joseph", "Miller", add };

    printPerson(joe);

    return 0;

}

void printAddress(Address addr) {
    printf("%d %s\n",addr.houseNum, addr.street);

    printf("%s, %s\n",addr.city, addr.state);
}

void printPerson(Person per){
    printf("%s, %s\n",per.lastName, per.firstName);
    printAddress(per.addr);
}
