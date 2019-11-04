#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define FILE_NAME_LENGTH 30
#define BLOCK_DIVISION 2

int input_storageDeviceSize(void); 
int input_blockSize(void);
void print_blockTable(int *blockTable,int blockTableSize);
void init_blockTable(int *blockTable, int blockTableSize);
int calc_fileBlockLength(int fileSize,int blockSize); 
int find_startBlock(int * blockTable, int blockTableSize, int fileBlockLength); 
void fill_partitions(int * blockTable, int fileSize, int blockSize, int startBlock);

void remove_partitions(int * blockTable, int fileSize, int startBlock, int fileBlockLength);



int main(){
    int storageSize = 40960;
    int blockSize = 4096;
    int blockTableSize;
    int fileBlockLength;
    
    char * fileName;
    int fileSize = 12000;
    int startBlock;
    int i ,j ;

//     //Create Block Table
  // storageSize = input_storageDeviceSize(); 
 //   blockSize = input_blockSize();
    
//  Create Block Table
    blockTableSize = (int)storageSize/blockSize;
    printf("%d",blockTableSize);
    int blockTable[blockTableSize][BLOCK_DIVISION];
    init_blockTable(blockTable[0],blockTableSize);

//  Fill Block Table
    fileBlockLength = calc_fileBlockLength(fileSize,blockSize);
    startBlock = find_startBlock(blockTable[0],blockTableSize, fileBlockLength);
    fill_partitions(blockTable[0],fileSize, blockSize, startBlock);
    print_blockTable(blockTable[0],blockTableSize);

    fileBlockLength = calc_fileBlockLength(fileSize,blockSize);
    startBlock = find_startBlock(blockTable[0],blockTableSize, fileBlockLength);
    fill_partitions(blockTable[0],fileSize, blockSize, startBlock);
    print_blockTable(blockTable[0],blockTableSize);

    fileBlockLength = calc_fileBlockLength(fileSize,blockSize);
    startBlock = find_startBlock(blockTable[0],blockTableSize, fileBlockLength);
    fill_partitions(blockTable[0],fileSize, blockSize, startBlock);
    print_blockTable(blockTable[0],blockTableSize);

    remove_partitions(blockTable[0],fileSize,blockSize,startBlock);
    print_blockTable(blockTable[0],blockTableSize);

    fileBlockLength = calc_fileBlockLength(fileSize,blockSize);
    startBlock = find_startBlock(blockTable[0],blockTableSize, fileBlockLength);
    fill_partitions(blockTable[0],fileSize, blockSize, startBlock);
    print_blockTable(blockTable[0],blockTableSize);
   

    return 0;
}

int input_storageDeviceSize(void){
    int storageSize;
    printf("Enter the size of your storage device : ");
    scanf("%u",&storageSize); //-> Deal with negative and float input
    printf("\n");
    return storageSize;
}

int input_blockSize(void){
    int blockSize;
    printf("Enter the size of each block : ");
    scanf("%u", &blockSize);  //-> Deal with negative and float input
    return blockSize;
}

void init_blockTable(int *blockTable, int blockTableSize){
    int i,j;
    for(i = 0; i < blockTableSize; i++){
        for(j = 0; j < BLOCK_DIVISION; j++){
            *(blockTable + i*BLOCK_DIVISION + j) = 0;
        }
    }
}

void print_blockTable(int *blockTable, int blockTableSize){
    int i,j;
    printf("Block Table:\n");
    printf("%s %20s %20s\n","Block Number","Size Used","Fragmented");

    for(int i = 0; i < blockTableSize; i++){
        printf("%d",i);
        for(int j = 0; j < BLOCK_DIVISION; j ++){
             printf("%25d",*((blockTable+i*BLOCK_DIVISION)+j));
        }
        printf("\n");
        
    }

        //printf("%10.d %10.d %10.d\n",blockTable[i][0],blockTable[i][1],blockTable[i][2]);
    //}
}

int calc_fileBlockLength(int fileSize,int blockSize){
    int fileBlockLength = (int)ceil((double)fileSize/(double)blockSize);
    return fileBlockLength;
}


void fill_partitions(int * blockTable, int fileSize, int blockSize, int startBlock){
    //calculate length of blocks, used size, fragmented size
    int fileBlockLength = (int)ceil((double)fileSize/(double)blockSize);
    int used = fileSize - blockSize*(fileBlockLength - 1);
    int fragmented = blockSize - used;
    int i;

    //fill in partitions
    for(i = startBlock; i < startBlock + fileBlockLength-1; i++){
        *(blockTable + i*BLOCK_DIVISION + 0) = blockSize;
        *(blockTable + i*BLOCK_DIVISION + 1) = 0;
    }

    //fill in the final block
    *(blockTable + (startBlock + fileBlockLength - 1)*BLOCK_DIVISION + 0) = used;
    *(blockTable + (startBlock + fileBlockLength - 1)*BLOCK_DIVISION + 1) = fragmented;

}

void remove_partitions(int * blockTable, int fileSize, int blockSize, int startBlock){
    int fileBlockLength = (int)ceil((double)fileSize/(double)blockSize);
    int i,j;

    for(i = startBlock; i < startBlock + fileBlockLength ; i++){
        for(j = 0; j < BLOCK_DIVISION; j++){
            *(blockTable + i*BLOCK_DIVISION + j) = 0;
        }
    }

}

int find_startBlock(int * blockTable, int blockTableSize, int fileBlockLength){
    int i = 0,j = 0;
    int found = 0;
    int startBlock;
    for(i = 0; i + fileBlockLength < blockTableSize;){
        //printf("\nLook at %d\n fileBlockLength %d\n",i,fileBlockLength);
        if( *(blockTable + i*BLOCK_DIVISION) == 0){
            //printf("Found free spot at %d\n ",i);
            for(j = 1; j < fileBlockLength; j++){
                //printf("Looking through %d\n",i+j);
                if(*(blockTable + (i+j)*BLOCK_DIVISION) == 0){
                    found = 1;
                }else{
                    found = 0;
                    break;
                }
            }
        }else{
            i += j+ 1;
            //printf("These spots are not free , looking at %d\n",i);
        }
        if (found == 1){
            startBlock = i;
            break;
        }else{
            startBlock = i; 
        }
    }

    if(found == 0){
        printf("Error: Device Storage is Out");
        exit(EXIT_FAILURE);
    }
    return startBlock;
}



