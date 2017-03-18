EXEC = pruebas
CC = gcc
CFLAGS = -Werror -Wconversion -Wno-sign-conversion -Wbad-function-cast -Wshadow -Wpointer-arith -Wunreachable-code -Wformat=2 -pedantic -std=c99 -g

all: pruebas

pruebas: pruebas_catedra.c main.c testing.c hash.o
	$(CC) $(CFLAGS) pruebas_catedra.c main.c testing.c hash.o -o $(EXEC)

hash.o: hash.c hash.h
	$(CC) $(CFLAGS) hash.c -c

run: pruebas
	./pruebas

reset: hash.o pruebas
	rm hash.o pruebas .hash.c.swp vgcore.*

remove_vgcore:
	rm vgcore.*

valgrind: pruebas
	valgrind --leak-check=full --track-origins=yes --show-reachable=yes ./pruebas
