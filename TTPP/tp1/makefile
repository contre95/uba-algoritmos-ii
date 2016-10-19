EXEC = pruebas
CC = gcc
CFLAGS = -Werror -pedantic -std=c99 -g

all: paste more dc

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

dc: dc_tp1/dc.c tda/pila/pila.o strutil_tp1/strutil.o
	$(CC) $(CFLAGS) -o dc tda/pila/pila.o strutil_tp1/strutil.o dc_tp1/dc.c

dc_run: dc
	./dc "2 9 4 + *" "2 3 + 3 *"

dc_valgrind: dc
	valgrind --leak-check=full --track-origins=yes --show-reachable=yes ./dc "2 9 4 + *" "2 3 + 3 *"

strutil: strutil_tp1/strutil.c
	$(CC) $(CFLAGS) -o strutil strutil_tp1/strutil.c

strutil_run: strutil
	./strutil "hola como estas"

strutil_valgrind: strutil
	valgrind --leak-check=full --track-origins=yes --show-reachable=yes ./strutil "hola asdsadasd como estas"

reset:
	rm paste more dc

remove_crap:
	rm vgcore.* .*.swp .*.swo
