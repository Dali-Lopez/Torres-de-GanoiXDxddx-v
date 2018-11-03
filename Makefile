CC = gcc
CFLAGS = -Wall `pkg-config --libs --cflags gtk+-3.0`
SRC = Hanoi.c Functions.o Functions.h
OBJ = Hanoi.o Functions.o


#Reglas explicitas

all: $(OBJ)
	$(CC) $(CFLAGS) -o Hanoi $(OBJ)
clean:
	$(RM) $(OBJ) main

#Reglas implicitas
Functions.o: Functions.c Functions.h
Hanoi.o: Hanoi.c Functions.h
