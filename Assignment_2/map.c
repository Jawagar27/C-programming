#include <stdio.h>
#include <stdlib.h>
#include "linkedlist.h"
#include "map.h"
#include "color.h"
#include "random.h"
#include "main.h"

void makeMap(char ***map, node **current, char *fileName, int *rows, int *cols, int *gRow, int *gCol)
{
    int pPos[2];
    int line = 0;
    int row, col;
    char c;
    char buffer[256];

    FILE *fp = fopen(fileName, "r");

    while (fgets(buffer, sizeof(buffer), fp) && fp != NULL)
    {
        if (line == 0)
        {
            sscanf(buffer, "%d %d", rows, cols);
        }
        else
        {
            sscanf(buffer, "%d %d %c", &row, &col, &c);
            switch (c)
            {
            case 'P':
                pPos[0] = row;
                pPos[1] = col;
                break;

            case 'G':
                *gRow = row;
                *gCol = col;
                break;

            default:
                break;
            }
        }
        line++;
    }
    fclose(fp);

    (*map) = (char **)malloc(sizeof(char *) * ((*rows) + 2));
    for (row = 0; row < (*rows) + 2; row++)
    {
        (*map)[row] = (char *)malloc(sizeof(char) * ((*cols) + 2));
        for (col = 0; col < (*cols) + 2; col++)
        {
            if (row == 0 || col == 0 || row == (*rows) + 1 || col == (*cols) + 1)
            {
                (*map)[row][col] = '*';
            }
            else if (row == pPos[0] + 1 && col == pPos[1] + 1)
            {
                (*map)[row][col] = 'P';
            }
            else if (row == (*gRow) + 1 && col == (*gCol) + 1)
            {
                (*map)[row][col] = 'G';
            }
            else
            {
                (*map)[row][col] = ' ';
            }
        }
    }

    fp = fopen(fileName, "r");
    line = 0;

    while (fgets(buffer, sizeof(buffer), fp) && fp != NULL)
    {
        if (line != 0)
        {
            sscanf(buffer, "%d %d %c", &row, &col, &c);

            if (c == 'X' && (*map)[row][col] == ' ')
            {
                (*map)[row][col] = 'X';
            }
        }
        line++;
    }
    fclose(fp);

    (*current)->floor[0] = -2;
    (*current)->floor[1] = -2;

    (*current)->player[0] = pPos[0];
    (*current)->player[1] = pPos[1];
}

void freeMap(char **map, int rows)
{
    int row;
    for (row = 0; row < rows + 2; row++)
    {
        free(map[row]);
    }
    free(map);
}

void printMap(char **map, int rows, int cols, node *current)
{
    int row, col;

    system("clear");

    for (row = 0; row < rows + 2; row++)
    {
        for (col = 0; col < cols + 2; col++)
        {
            if (row == current->player[0] + 1 && col == current->player[1] + 1)
            {
                setForeground("blue");
                printf("%c", map[row][col]);
                setForeground("reset");
            }
            else if (row == current->floor[0] + 1 && col == current->floor[1] + 1)
            {
                setBackground("red");
                printf("%c", map[row][col]);
                setBackground("reset");
            }
            else if (map[row][col] == 'G')
            {
                setForeground("yellow");
                printf("%c", map[row][col]);
                setForeground("reset");
            }
            else
            {
                printf("%c", map[row][col]);
            }
        }
        printf("\n");
    }
    printf("Press w to go up\nPress s to go down\nPress a to go left\nPress d to go right\nPress u to undo\n");
}

void breakFloor(char **map, node **current, int rows, int cols)
{
    int bRow, bCol;
    int condition = 1;

    while (condition)
    {
        bRow = random(0, rows - 1);
        bCol = random(0, cols - 1);

        if (bRow != (*current)->player[0] && bCol != (*current)->player[1] && map[bRow + 1][bCol + 1] == ' ')
        {
            (*current)->floor[0] = bRow;
            (*current)->floor[1] = bCol;

            map[bRow + 1][bCol + 1] = 'X';

            condition = 0;
        }
    }
}

void updateMap(char **map, node *current, int rows, int cols)
{
    int row, col;

    for (row = 0; row < rows + 2; row++)
    {
        for (col = 0; col < cols + 2; col++)
        {
            if (row == current->player[0] + 1 && col == current->player[1] + 1)
            {
                map[row][col] = 'P';
            }
            else if (map[row][col] != 'X' && map[row][col] != '*' && map[row][col] != 'G')
            {
                map[row][col] = ' ';
            }
        }
    }
}

int movable(char **map, int pPos[2])
{
    int ret = 0;
    if (map[pPos[0] + 1][pPos[1] + 1] == ' ' || map[pPos[0] + 1][pPos[1] + 1] == 'G')
    {
        ret = 1;
    }

    return ret;
}

/* undo move */
void undo(char **map, node **current)
{
    if ((*current)->prev != NULL)
    {
        map[(*current)->floor[0]+1][(*current)->floor[1]+1] = ' ';
        map[(*current)->player[0] + 1][(*current)->player[1] + 1] = ' ';
        map[(*current)->prev->player[0] + 1][(*current)->prev->player[1] + 1] = 'P';

        removeLast(current);
    }
}

int wonOrLost(char **map, int rows, int cols, int gRow, int gCol, node*current)
{
    /*this function chechks continously to see if the game is over and wether the player won the game or lost it*/
    int condition;
    int playerLeft[2], playerTop[2], playerRight[2], playerBottom[2];

    playerLeft[0] = adjust(current->player[0], 0, rows);
    playerLeft[1] = adjust(current->player[1] - 1, 0, cols);
    playerTop[0] = adjust(current->player[0] - 1, 0, rows);
    playerTop[1] = adjust(current->player[1], 0, cols);
    playerRight[0] = adjust(current->player[0], 0, rows);
    playerRight[1] = adjust(current->player[1] + 1, 0, cols);
    playerBottom[0] = adjust(current->player[0] + 1, 0, rows);
    playerBottom[1] = adjust(current->player[1], 0, cols);

    if (current->player[0] == gRow && current->player[1] == gCol)
    {
        /*these are the winning conditions*/
        condition = 1;
        printf("\nYou Win!\n");
    }
    else
    {
        if (((map[playerTop[0] + 1][playerTop[1] + 1] == 'X' || map[playerTop[0] + 1][playerTop[1] + 1] == '*') && (map[playerBottom[0] + 1][playerBottom[1] + 1] == 'X' || map[(playerBottom[0] + 1) + 1][playerBottom[1] + 1] == '*') && (map[playerLeft[0] + 1][playerLeft[1] + 1] == 'X' || map[playerLeft[0] + 1][playerLeft[1] - 1 + 1] == '*') && (map[playerRight[0] + 1][playerRight[1] + 1] == 'X' || map[playerRight[0] + 1][playerRight[1] + 1] == '*')) || ((map[(gRow - 1) + 1][gCol + 1] == 'X' || map[(gRow - 1) + 1][gCol + 1] == '*') && (map[(gRow + 1) + 1][gCol + 1] == 'X' || map[(gRow + 1) + 1][gCol + 1] == '*') && (map[gRow + 1][(gCol - 1) + 1] == 'X' || map[gRow + 1][(gCol - 1) + 1] == '*') && (map[gRow + 1][(gCol + 1) + 1] == 'X' || map[gRow + 1][(gCol + 1) + 1] == '*')))
        {
            condition = 1;
            printf("\nYou Lose!\n");
        }
        else
        {
            condition = 0;
        }
    }

    return condition;
}