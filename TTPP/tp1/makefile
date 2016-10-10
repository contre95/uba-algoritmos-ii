EXEC = pruebas
CC = gcc
CFLAGS = -Werror -pedantic -std=c99 -g

all: paste more

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

dc: dc_tp1/dc.c ../tda/pila/pila.o
	$(CC) $(CFLAGS) -o dc ../tda/pila/pila.o dc_tp1/dc.c

dc_run: dc
	echo "2 9 4 + *" | ./dc

dc_valgrind: dc
	valgrind --leak-check=full --track-origins=yes --show-reachable=yes ./more dc_tp1/prueba_more.txt 7

reset:
	rm paste more

remove_crap:
	rm vgcore.* .*.swp .*.swo
