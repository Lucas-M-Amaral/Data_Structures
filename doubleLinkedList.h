#ifndef DOUBLE_LINKED_LIST_H
#define DOUBLE_LINKED_LIST_H

typedef struct node
{
   int id;
   node *next;
   node *previous;    
}node;

typedef struct aux
{
    int size;
    node *first;
}*doubleLinkedList;

doubleLinkedList init();
doubleLinkedList addItem(doubleLinkedList, node*);
int remove(doubleLinkedList, int);

node *findNode(doubleLinkedList, int);

#endif