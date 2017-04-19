EXEC = pruebas
CC = gcc
CFLAGS = -Wall -Wconversion -Wno-sign-conversion -Wbad-function-cast -Wshadow -Wpointer-arith -Wunreachable-code -Wformat=2 -Werror -std=c99 -g

all: pruebas

pruebas: genera_cola.o
	$(CC) $(CFLAGS) pruebas_alumno.c main.c testing.c cola.o -o $(EXEC)

genera_cola.o: cola.c cola.h
	$(CC) $(CFLAGS) cola.c -c

run: pruebas
	./pruebas

remove:
		rm cola.o pruebas vgcore.*

valgrind: pruebas
	valgrind --leak-check=full --track-origins=yes --show-reachable=yes ./pruebas
