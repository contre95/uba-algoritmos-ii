EXEC = pruebas
CC = gcc
CFLAGS = -Werror -pedantic -std=c99 -g

all: paste

paste: paste_tp1/paste.c
			$(CC) $(CFLAGS) -o paste paste_tp1/paste.c

paste_run: paste
		./paste paste_tp1/fechas.txt paste_tp1/ciudades.txt

paste_valgrind: paste
		valgrind ./paste paste_tp1/fechas.txt paste_tp1/ciudades.txt

reset:
		rm paste
		
remove_vgcore:
		rm vgcore.*
