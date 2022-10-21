#include <stdio.h>
#include <stdlib.h>
#include "linkedlist.h"

/*this is the linked list code used in the assignment
used to implement the undo feature*/
void insertLast(node **current)
{
     node *link = (node *)malloc(sizeof(node));

    link->prev = *current;
    *current = link;
}

void removeLast(node **current)
{
    node *tmp = *current;
    *current = (*current)->prev;
    free(tmp);
}

void freeList(node *current)
{
    node *tmp;

    while (current != NULL)
    {
        tmp = current;
        current = current->prev;
        free(tmp);

    }
}