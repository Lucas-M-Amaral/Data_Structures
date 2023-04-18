#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include "doubleLinkedList.h"

doubleLinkedList init()
{
    doubleLinkedList newList = (doubleLinkedList)malloc(sizeof(doubleLinkedList));
    newList->size = 0;
    newList->first = NULL;

    return newList;
}

doubleLinkedList addNode(doubleLinkedList list, node *newNode)
{
    newNode = (node*)malloc(sizeof(node));

    if (list->first == NULL) 
    {
        list->first = newNode; 
    }
    else
    {
        node *current = list->first;

        while (current->next != NULL) 
        {                    
            current = current->next;
        }
        newNode->previous = current;
        current->next = newNode; 
    }
    list->size++;
    return list;
}

void removeNode(doubleLinkedList list, int id)
{
    if (list->first == NULL)
    {
        std::cout << "A lista tá vazia!" << std::endl;
    }
    else
    {
        if(list->first->id == id)
        {
            node *current = list->first->next;
            free(list->first);
            list->first = current;
        }
        else
        {
            node *current = list->first->next;
            do
            {
                if(current->id == id)
                {
                    if(current->next != NULL)
                    {
                        current->next->previous = current->previous;
                        current->previous->next = current->next;
                        free(current);
                        break;
                    }
                    else
                    {
                        current->previous = NULL;
                        free(current);
                        break;
                    }
                }
            } while (current != NULL);
            
        }
    }
    
}

node *findNode(doubleLinkedList list, int id)
{
    if(list->first == NULL)
    {
        return NULL;
    }
    else
    {
        node *aux = list->first;

        while (aux->id != id)
        {
            aux = aux->next;
        }
        if(aux == NULL)
        {
            return NULL;
        }
        return aux;
    }
}



int main()
{
    doubleLinkedList l1, l2;
    node n1, n2, n3, n4;
    addNode(l1, n1);
    addNode(l1, n2);
    addNode(l2, n1);
    removeNode(l1, findNode(l2, 123));
}
