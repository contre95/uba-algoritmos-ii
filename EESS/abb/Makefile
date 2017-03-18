EXEC = pruebas
CC = gcc
CFLAGS = -Werror -pedantic -std=c99 -g

all: pruebas

pruebas: pruebas_alumno.c main.c testing.c abb.o
	$(CC) $(CFLAGS) pruebas_alumno.c main.c testing.c abb.o -o $(EXEC)

abb.o: abb.c abb.h
	$(CC) $(CFLAGS) abb.c -c

run: pruebas
	./pruebas

reset:
	rm nodo_abb.o abb.o pruebas .abb.c.swp vgcore.*

remove_vgcore:
	rm vgcore.*

valgrind: pruebas
	valgrind --leak-check=full --track-origins=yes --show-reachable=yes ./pruebas
