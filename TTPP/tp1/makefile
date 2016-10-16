EXEC = pruebas
CC = gcc
CFLAGS = -Werror -pedantic -std=c99 -g

all: paste more dc strutil

paste: paste_tp1/paste.c
	$(CC) $(CFLAGS) -o paste paste_tp1/paste.c

paste_run: paste
	./paste paste_tp1/fechas.txt paste_tp1/ciudades.txt

paste_valgrind: paste
	valgrind --leak-check=full --track-origins=yes --show-reachable=yes ./paste paste_tp1/fechas.txt paste_tp1/ciudades.txt

more: more_tp1/more.c
	$(CC) $(CFLAGS) -o more more_tp1/more.c

more_run: more
	./more more_tp1/prueba_more.txt 7

more_valgrind: more
	valgrind --leak-check=full --track-origins=yes --show-reachable=yes ./more more_tp1/prueba_more.txt 7

dc: dc_tp1/dc.c tda/pila/pila.o
	$(CC) $(CFLAGS) -o dc tda/pila/pila.o dc_tp1/dc.c

dc_run: dc
	./dc "2 9 4 + *" "2 3 + 3 *"

dc_valgrind: dc
	valgrind --leak-check=full --track-origins=yes --show-reachable=yes ./dc "2 9 4 + *" "2 3 + 3 *"

strutil: strutil_tp1/srtutil.c
	$(CC) $(CFLAGS) -o strutil strutil_tp1/srtutil.c

strutil_run: strutil
	./strutil "hola como estas" 5

strtil_valgrind: strutil
	valgrind --leak-check=full --track-origins=yes --show-reachable=yes ./dc "hola como estas" 5

reset:
	rm paste more dc strutil

remove_crap:
	rm vgcore.* .*.swp .*.swo
