#include"linkedlist.h"

/*
Empties the queue and also deletes all the memory used by the queue
*/
void EmptyList(gbpsLinkedList* List)
{
    ListItem* i;
    while(i=PopItem(List))
        FreeItem(i);
}

/*
Deletes the memory used by the item.
*/
void FreeItem(ListItem* i)
{
    ////printf("Deleting item...\n");
    free(i);
    return;
}

/*
returns the pointer to the oldest item in the list and removes it from the list
*/
void* PopItem(gbpsLinkedList* List)
{
    void* Data;
    if(List->NoItems==0)
        return NULL;
    else if(List->NoItems==1)
    {
        Data=List->Head->Data;//if only one item, returns the item and sets head and tail to NULL
        FreeItem(List->Head);
        List->NoItems=0;
        return Data;
    }
    Data=List->Head->Data;
    List->Head=List->Head->Next;
    FreeItem(List->Head->Prev);
    List->NoItems--;
    return Data;
}

/*
Adds a new item in the linked list
*/
int AddItem(gbpsLinkedList* List, void* Data)
{
    ListItem* NewItem=malloc(sizeof(ListItem));
    NewItem->Data=Data;
    if(List->NoItems==0)
    {
        List->Head=NewItem;
        List->Tail=NewItem;
    }
    else//add the item to the tail
    {
        NewItem->Prev=List->Tail;
        List->Tail->Next=NewItem;
        List->Tail=NewItem;
    }
    return ++List->NoItems;//returns the current number of elements in the queue
}
