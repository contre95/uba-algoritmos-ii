EXEC = pruebas
CC = gcc
CFLAGS = -Werror -pedantic -std=c99 -g

all: srtutil.o

srtutil.o: srtutil.c strutil.h
	$(CC) $(CFLAGS) srtutil.c -c
