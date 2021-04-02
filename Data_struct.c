#include <stdlib.h>
#include <stdio.h>

struct listNode{
    char data;
    struct listNode *nextPtr;
};
typedef struct listNode ListNode;
typedef ListNode *ListNodePtr;

void insert(ListNodePtr *sPtr, char value);
void instruction(void);


int main(void){
    ListNodePtr startPtr = NULL;
    unsigned int choice;
    char item;
    instruction();





    return 0;
}
void instruction(void) {
    puts("Enter your choice:\n"
        " 1 to insert an element into the list.\n"
        " 2 to delete an element from the list.\n"
        " 3 to end.\n"
    );
}
void insert(ListNodePtr *sPtr, char value){
    ListNodePtr newPtr;
    ListNodePtr previousPtr;
    ListNodePtr currentPtr;

    newPtr = malloc(sizeof(ListNode)); //malloc 代表 memory allocation，用來配置指定大小的記憶體空間，傳回新空間第一個位元組的記憶體位址，配置的空間處於尚未初始化的狀態。
    if ( newPtr != NULL ){
        newPtr->data = value;
        newPtr->nextPtr = NULL;
        
        previousPtr = NULL;
        currentPtr = *sPtr;
        while ( currentPtr != NULL && value > currentPtr->data){
            previousPtr = currentPtr;
            currentPtr = currentPtr->nextPtr;
        }

        if (previousPtr == NULL){
            newPtr->nextPtr = *sPtr;
            *sPtr = newPtr;
        }else {
            previousPtr->nextPtr = newPtr;
            newPtr->nextPtr = currentPtr;
        }
    } //end if
    else {
        printf("%c not inserted. No memory available.\n",value);
    } //end else
}
char delete(ListNodePtr *sPtr, char value){
    ListNodePtr previousPtr;
    ListNodePtr currentPtr;
    ListNodePtr tempPtr;
    
    //delete first node
    if (value == (*sPtr)->data){
        tempPtr = *sPtr;
        *sPtr = (*sPtr)->nextPtr;
        free(tempPtr);
        return value;
    }
    
}