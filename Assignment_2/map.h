#ifndef MAP_H
#define MAP_H

void makeMap(char ***map, node **current, char *fileName, int *rows, int *cols, int *gRow, int *gCol);
void printMap(char **map, int rows, int cols, node *current);
void freeMap(char **map, int rows);
void updateMap(char **map, node *current, int rows, int cols);
void breakFloor(char **map, node **current, int rows, int cols);
int movable(char **map, int pPos[2]);
void undo(char **map, node **current);
int wonOrLost(char **grid, int rows, int cols, int gRow, int gCol, node *current);

#endif