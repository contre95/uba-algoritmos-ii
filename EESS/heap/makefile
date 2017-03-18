EXEC = pruebas
CC = gcc
CFLAGS = -Wall -Wconversion -Wno-sign-conversion -Wbad-function-cast -Wshadow -Wpointer-arith -Wunreachable-code -Wformat=2 -Werror -std=c99 -g

all: pruebas

pruebas: pruebas_heap.c main.c testing.c heap.o
	$(CC) $(CFLAGS) pruebas_heap.c main.c testing.c heap.o -o $(EXEC)

heap.o: heap.c heap.h
	$(CC) $(CFLAGS) heap.c -c

run: pruebas
	./pruebas

reset:
	rm heap.o pruebas .heap.c.swp vgcore.*

remove_vgcore:
	rm vgcore.*

valgrind: pruebas
	valgrind --leak-check=full --track-origins=yes --show-reachable=yes ./pruebas
