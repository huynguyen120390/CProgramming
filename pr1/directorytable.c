#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define FILE_NAME_LENGTH 30

struct FileInfo{
    char fileName[FILE_NAME_LENGTH];
    int size;
    int startBlock;
    int fileBlockLength;
    struct FileInfo * next;
};


//add file info to dir table
//remove file info from dir table
void append(struct FileInfo ** dirTable, char * fileName, int size, int startBlock, int fileBlockLength);
void display(struct FileInfo * dirTable);


int main(){
    struct FileInfo * dirTable;
    append(&dirTable,"pr1.c",1000,7,1);
    //dirTable = append(dirTable,"example.c",12000,1,3);
    printf("%s %20d %20d %20d\n",dirTable->fileName,dirTable->size,dirTable->startBlock,dirTable->fileBlockLength);
    display(dirTable);




    return 0;

}

void append(struct FileInfo ** dirTable, char * fileName, int size, int startBlock, int fileBlockLength){
    //Create a node of new file info
    struct FileInfo * newFileInfo = malloc(sizeof(struct FileInfo));
    struct FileInfo * cur;
    if(newFileInfo == NULL){
        printf("Error: No memory for new node");
        exit(EXIT_FAILURE);
    }
    strcpy(newFileInfo->fileName,fileName);
    newFileInfo->size = size;
    newFileInfo->startBlock = startBlock;
    newFileInfo->fileBlockLength = fileBlockLength;
    newFileInfo->next=NULL;
    printf("Just added %s\n",newFileInfo->fileName);
    
    // if(*dirTable == NULL){
    //     *dirTable = newFileInfo;
    //      cur = *dirTable;
    // }
    if(*dirTable == NULL){
        printf("Empty List");
    }
    *dirTable = newFileInfo;
   

   
    
    

   // printf("*dirTable %d\n",(*dirTable)->size);
   // printf("*dirTable %d\n",(cur)->size);






    //If no item in directory table, then add the new node to it
    // if (dirTable == NULL){
    //     *dirTable= newFileInfo;
    // // }
    // }
    // printf("*dirTable %p\n",*dirTable);
    // printf("*dirTable %s\n",(*dirTable)->fileName);
    
    //printf("%s %20d %20d %20d\n",dirTable->fileName,dirTable->size,dirTable->startBlock,dirTable->fileBlockLength);




    //If there is 1+ node in the directory table, traverse to the end, add new node to it
    // struct FileInfo * cur, * pre
    //Free pointers
   // free(cur);
   // free(newFileInfo);

}

void display(struct FileInfo * dirTable){
    if(dirTable == NULL){
        printf("Error: Nothing to display");
    }
    
    //Traverse along the directory table, and display items
    struct FileInfo * temp;
    temp = dirTable;
    int i = 0;
    while(temp!=NULL){
        printf("File %d :\n %s %20s %20s %20s\n",i,"File Name","File Size","Start Block","File Block Length");
        printf("%s %20d %20d %20d\n",temp->fileName,temp->size,temp->startBlock,temp->fileBlockLength);
        temp = temp->next;
    }
    
    //Free pointers
    free(temp);
}