#ifndef LINKED_LIST_H
#define LINKED_LIST_H

typedef struct node
{
   int id;
   node *next;     
}node;

typedef struct aux
{
    int size;
    node *first;
}*linkedList;

linkedList init();
linkedList addItem(linkedList, node*, int);
int remove(linkedList, int);

#endif