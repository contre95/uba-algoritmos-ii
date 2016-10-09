EXEC = pruebas
CC = gcc
CFLAGS = -Werror -pedantic -std=c99 -g

all: pruebas

pruebas: ejemplo_iteradores.c pruebas_alumno.c main.c testing.c lista.o
	$(CC) $(CFLAGS) pruebas_alumno.c main.c testing.c lista.o -o $(EXEC)

lista.o: lista.c lista.h
	$(CC) $(CFLAGS) lista.c -c

run: pruebas
	./pruebas

reset: lista.o pruebas
	rm lista.o pruebas .lista.c.swp vgcore.*

remove_vgcore:
	rm vgcore.*

valgrind: pruebas
	valgrind --leak-check=full --track-origins=yes --show-reachable=yes ./pruebas
