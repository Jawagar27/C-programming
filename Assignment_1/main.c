#include <stdio.h>
#include <stdlib.h>



/* this is the main file of the assignment, where all the code is implemented and run


author  - Jawagar Prabaharan*/

int main(int argc, char* argv[]){
    
    if ( argc!= 7 || *argv[1] <5 || *argv[2]< 5 || *argv[1] == '-'||*argv[2] == '-'||*argv[3] == '-'||*argv[4] == '-'||*argv[5] == '-'||*argv[6] == '-')
      {   printf("Error in the details entered\nplease enter 6 arguments with the following conditions\n");
         printf("Map rows and coloumns should be less than or equal to 5\n And there shoudl be 6 arguments present to proceed without errors");
      }




int maprow = atoi(argv[1]) + 2; /*we add 2 due to the borders*/ 
int mapcol = atoi(argv[2]) + 2; /*we add 2 due to the borders*/
int playerrow = atoi(argv[3]) + 1;/*we add 1 due to the borders*/
int playercol = atoi(argv[4]) + 1;/*we add 1 due to the borders*/
int goalrow = atoi(argv[5]) + 1;/*we add 1 due to the borders*/
int goalcol = atoi(argv[6])+ 1;/*we add 1 due to the borders*/

/*char** graph = draw(maprow,  mapcol,playerrow, playercol, goalrow, goalcol);

display(graph,maprow,mapcol);*/

int i,j;
char x;
  
  
char** array;
 array = (char**)malloc(sizeof(char*) * maprow); /*allocating space in the memory for an array*/

  /* making the playing area*/

  for (i = 0; i < maprow; i++) {
       
       array[i] = (char*)malloc(sizeof(char*) * mapcol); /*allocating space for coloumns and making a 2d array*/
  }
  for (i = 0; i < maprow; i++){
       for(j = 0; j<mapcol; mapcol++){
        if (i == 0 || i == maprow || j == 0 || j == mapcol)
    {
      array[i][j] = '*';
    }else if (maprow == playerrow && mapcol ==playercol)
    {
      array[playerrow][playercol] = 'p';
    }else if (maprow == goalrow && mapcol == goalcol)
    {
     array[goalrow][goalcol] = 'g';
    }else{
      array[i][j] = ' ';
    }
       
    }}
int a,b;

  for ( i = 0; i < maprow; i++)
  {
     for ( j = 0; j < mapcol; j++)
  {
   printf("%c",  array[i][j]);
  }
  }
    
     printf("Press 'w' to move up\n");
	printf("Press 's' to move down\n");
	printf("Press 'a' to move left\n");
	printf("Press 'd' to move right\n");
	printf("\n");
    return 0;
}

/*char** draw(int rows, int coloumns, int playerR, int playerC, int goalR, int goalC){
int i,j;
char x;
  
  int row = rows;
  int coloumn = coloumns;

 char**  array = (char**)malloc(sizeof(char*) * rows); 

  

  for (i = 0; i < rows; i++) {
       
       array[row] = (char*)malloc(sizeof(char*) * coloumn); 
  }
       for(j = 0; j<coloumn; coloumn++){
        if (row == 0 || row == row || coloumn == 0 || coloumn == coloumn)
    {
      array[row][coloumn] = '*';
    }else if (row == playerR && coloumn ==playerC)
    {
      array[playerR][playerC] = 'p';
    }else if (row == goalR && coloumn == goalC)
    {
     array[goalR][goalC] = 'g';
    }else{
      array[row][coloumn] = ' ';
    }
       }
   
return array; 
}*/

/*void display(char** graph, int rows, int coloumns){

  int i,j;

  for ( i = 0; i < rows; i++)
  {
     for ( j = 0; j < coloumns; j++)
  {
   printf("%c",  graph[i][j]);
  }
  }}*/