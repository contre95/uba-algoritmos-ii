
strutil.o: pila.o
heap.o: heap.c heap.h
abb.o: pila.o
uniq-count: uniq-count.o strutil.o hash.o cola.o
comm: comm.o hash.o strutil.o
heap-utils: heap-utils.o heap.o
