#include <stdio.h>
#include <stdlib.h>
#define FILE_NAME_LENGTH 30
#define BLOCK_DIVISION 3

struct fileInfo{
    char fileInfo[FILE_NAME_LENGTH];
    int size; 
    int start;
    int length;
};
enum {ADD,DELETE,PRINT,QUIT} Desize;

//
int input_storageDeviceSize(void); //return device size
int input_blockSize(void); //return block size
void create_blockTable(int * blockTable,int * blockTableSize,int storageSize, int blockSize); // modify block table 
void print_blockTable(int *blockTable[],int blockTableSize);

//
char * input_fileName(void);
int input_fileSize(void);
struct fileInfo * create_directoryTable(void);
void print_directoryTable(struct fileInfo * directoryTable);

//
int calc_fileBlockLength(int fileSize,int blockSize); //return fileBlockLength
int find_startBlock(int * blockTable[], int fileBlockLength); //return start
void fill_fileInfo(char * fileName, int fileSize, int startBlock, int fileBlockLength);
void fill_partitions(int * blockTable[], int fileSize, int startBlock, int fileBlockLength);

//
void lookup_fileInfo(int * blockTable[],int fileSize, int start, int fileBlockLength);
void remove_partitions(int * blockTable[], int fileSize, int startBlock, int fileBlockLength);
void remove_fileInfo(char * fileInfo[], char fileName[]);


int main(){
    int storageSize;
    int blockSize;
    int blockTableSize;
    int * blockTable;
    char * fileName;

    //Create Block Table
    storageSize = input_storageDeviceSize();
    blockSize = input_blockSize();
    create_blockTable(blockTable,&blockTableSize,storageSize,blockSize);
    print_blockTable(&blockTable,blockTableSize);
    //Create Directory Table
    

    //Looping ############
    fileName = input_fileName();

    //input file nameK
    //input file size

    return 0;
}

int input_storageDeviceSize(void){
    int storageSize;
    scanf("Enter the size of your storage device : %u",&storageSize); //-> Deal with negative and float input
    printf("\n");
    return storageSize;
}

int input_blockSize(void){
    int blockSize;
    scanf("Enter the size of each block : %u", &blockSize);  //-> Deal with negative and float input
    return blockSize;
}

void create_blockTable(int * blockTable, int * blockTableSize, int storageSize, int blockSize){
    *blockTableSize = storageSize/blockSize;
    int blockTableArr[*blockTableSize][BLOCK_DIVISION];
    blockTable = blockTableArr[0];
}

void print_blockTable(int *blockTable[], int blockTableSize){
    int i,j;
    printf("Block Table:\n");
    printf("%10.s %10.s %10.s\n","Block Number","Size Used","Fragmented");

    for(int i = 0; i < blockTableSize; i++){
        printf("%10.d %10.d %10.d\n",blockTable[i][0],blockTable[i][1],blockTable[i][2]);
    }
}

struct fileInfo * create_directoryTable(void){
    struct fileInfo * directoryTable; 
    return directoryTable;
}

char * input_fileName(void){
    char c;
    int i = 0;
    char * fileName = malloc(sizeof(char)*FILE_NAME_LENGTH + 1);
    
    while((c=getchar()) != '\n' || i<FILE_NAME_LENGTH){
        fileName[i] = c;
        i++;
    }
    return fileName;
}

void print_directoryTable(struct fileInfo * directoryTable){

}