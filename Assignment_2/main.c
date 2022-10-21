#include <stdio.h>
#include <stdlib.h>
#include "linkedlist.h"
#include "map.h"
#include "terminal.h"
#include "main.h"

int adjust(int var, int low, int high)
{
    if (var < low)
    {
        var = high - 1;
    }
    else if (var > high - 1)
    {
        var = low;
    }

    return var;
}

int main(int argc, char *argv[])
{
    char **map = NULL;
    int rows, cols, gCol, gRow;
    node *current = (node *)malloc(sizeof(node));
    int nextPos[2];
    int playing = 1;
    char c;

    makeMap(&map, &current, argv[1], &rows, &cols, &gCol, &gRow);
    printMap(map, rows, cols, current);

    while (playing)
    {
        disableBuffer();
        scanf(" %c", &c);
        enableBuffer();

        nextPos[0] = current->player[0];
        nextPos[1] = current->player[1];

        switch (c)
        {
        case 'w':
            nextPos[0]--;
            break;

        case 'a':
            nextPos[1]--;
            break;

        case 's':
            nextPos[0]++;
            break;

        case 'd':
            nextPos[1]++;
            break;

        case 'u':
            undo(map, &current);
            nextPos[0] = current->player[0];
            nextPos[1] = current->player[1];
            break;

        default:
            break;
        }

#if BORDERLESS
        nextPos[0] = adjust(nextPos[0], 0, rows);
        nextPos[1] = adjust(nextPos[1], 0, cols);
#endif

        if (c != 'u' && movable(map, nextPos))
        {
            insertLast(&current);
            current->player[0] = nextPos[0];
            current->player[1] = nextPos[1];
            breakFloor(map, &current, rows, cols);
        }
        updateMap(map, current, rows, cols);
        printMap(map, rows, cols, current);

        if (wonOrLost(map, rows, cols, gRow, gCol, current))
        {
            playing = 0;
        }
    }

    freeMap(map, rows);
    freeList(current);

    return 0;
}