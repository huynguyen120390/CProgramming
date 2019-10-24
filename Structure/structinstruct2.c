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
void displayPeople(Person ppl[], int pplCount);

int main(void) {
    
    Person people[] =  {
      { "Joseph", "Miller",  { 10, "Downing", "London", "WA" } },
      { "Anne",   "Simpson", { 1600, "Pennsylvania Ave", "Columbia", "WA" } },
      { "Peter",  "Price",   { 832, "Main St.", "Dallas", "TX" } }
    };

    int peopleCount = 3;

    displayPeople(people, peopleCount);

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

void displayPeople(Person ppl[], int pplCount) {
    int i;
    for (i = 0; i < pplCount; i++) {
        printPerson(ppl[i]);
        printf("\n");
    }
}
