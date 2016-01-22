#ifndef GBPS_LINKEDLIST_H
#define GBPS_LINKEDLIST_H
/*
LinkedList.h
handles linked list
*/

#include"common.h"

/*
structure to store one item(of any type) in the queue
*/
struct _ListItem
{
    void* Data;
    struct _ListItem *Prev,*Next;
};

typedef struct _ListItem ListItem;

/*
Queue structure that holds the items of the queue
*/
typedef struct
{
    ListItem* Head;
    ListItem* Tail;
    int NoItems;
} gbpsLinkedList;


int AddItem(gbpsLinkedList* List, void* Data);
void* PopItem(gbpsLinkedList* List);
#endif
