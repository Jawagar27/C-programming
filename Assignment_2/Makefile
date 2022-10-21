##
 # File: Makefile
 # File Created: Tuesday, 18 Sep 2022 4:28:42 pm
 # Author: Jawagar Prabaharan
 # -----
 # Last Modified: Tuesday, 18 Sep 2022 4:28:42 pm
 # Modified By: Jawagar Prabaharan
 # -----
 # Purpose: A makefile to compile the c files
##


# Makefile Variables
CC		 = gcc
EXEC	 = escape
CFLAGS   = -Wall -ansi -pedantic
C        = main.c random.c terminal.c color.c map.c linkedlist.c
OBJ 	 = main.o random.o terminal.o color.o map.o linkedlist.o

# Add BORDERLESS to the CFLAGS and recompile the program
ifeq ($(BORDERLESS), 1)
CFLAGS += -D BORDERLESS=1
endif

$(EXEC) : $(OBJ)
	$(CC) $(OBJ) -o $(EXEC)
	rm $(OBJ)

$(OBJ) : $(C)
	$(CC) $(CFLAGS) $(C) -c 

clean:
	rm $(EXEC) $(OBJ)