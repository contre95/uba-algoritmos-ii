EXEC = pruebas
CC = gcc
CFLAGS = -Wall -Wconversion -Wno-sign-conversion -Wbad-function-cast -Wshadow -Wpointer-arith -Wunreachable-code -Wformat=2 -Werror -std=c99 -g

all: pruebas

pruebas: genera_pila.o
	$(CC) $(CFLAGS) pruebas_alumno.c main.c testing.c pila.o -o $(EXEC)

genera_pila.o: pila.c pila.h
	$(CC) $(CFLAGS) pila.c -c

run: pruebas
	./pruebas

remove_vgcore:
	rm vgcore.*

valgrind: pruebas
	valgrind --leak-check=full --track-origins=yes --show-reachable=yes ./pruebas
