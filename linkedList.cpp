#include <iostream>
#include <stdlib.h>
#include "linkedList.h"

linkedList init()
{
    linkedList newList = (linkedList)malloc(sizeof(linkedList));
    newList->size = 0;
    newList->first = NULL;

    return newList;
}

linkedList addItem(linkedList list, node *newItem, int newItemId)
{
    newItem = (node*)malloc(sizeof(node));

    if (list->first == NULL) // First, verify if the list is empty;
    {
        list->first = newItem; // If it is empty, just set the new item to be the first;
    }
    else
    {
        node *aux = list->first; // If it's not empty, we will need an auxiliar node to represent our first node in the list;

        while (aux->next != NULL) // while the pointer of the next element is not null,
        {                         // Our auxiliar node will update himself to the next position, untill he finds a free spot;
            aux = aux->next;
        }
        aux->next = newItem; // Then, when he finds it, it just sets the pointer that was pointing to NULL, to point to our new element;
    }
    list->size++;
    newItem->id = newItemId;
    return list;
}

int remove(linkedList list, int nodeId)
{
    if (list->first == NULL) // First, it checks if our list is empty, because if it is, there is nothing to remove;
    {
        return 1; // If it is empty, just return the list;
    }
    else
    {
        node *previous, *current;

        current = list->first;
        while (current != NULL)
        {
            if (current->id == nodeId)
            {
                if (previous != NULL)
                {
                    previous->next = current->next;
                }
                else
                {
                    list->first = NULL;
                }
            }
            else
            {
                previous = current;
                current = current->next;
            }
        }

        free(current);

        return 0;
    }
}

int main()
{
    linkedList l1 = init();

    node* n1, n2, n3;
    addItem(l1, n1, 123);
    // addItem(l1, n2, 132);
    // addItem(l1, n3, 134);

    if(remove(l1, 123) == 1)
    {
        std::cout << "lista vazia" << std::endl;
    }
    else
    {
        std::cout << "deu bom" << std::endl;
    }
}