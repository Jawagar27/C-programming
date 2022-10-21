#ifndef LINKEDLIST_H
#define LINKEDLIST_H

typedef struct node
{
    int player[2];
    int floor[2];
    struct node * prev;
} node;

void insertLast(node **current);
void removeLast(node **current);
void freeList(node *current);

#endif