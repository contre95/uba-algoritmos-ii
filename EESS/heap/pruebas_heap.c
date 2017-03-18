#include "testing.h"
#include <stdbool.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "heap.h"

int comparation(const void *a, const void *b){
    int res = strcmp((char*) a, (char*) b);
    return res;
}

void pruebas_heap_alumno() {
    heap_t * heap1 = heap_crear(comparation);
    char* cad1 = "Argentina";
    char* cad2 = "Brasil";
    char* cad3 = "Chile";
    char* cad4 = "Japon";
    char* cad5 = "Dinamarca";
    char* cad6 = "Korea";
    char* cad7 = "Suiza";
    char* cad8 = "Mexico";
    print_test("Desencolar no devuelve nada", !heap_desencolar(heap1));
    print_test("Ver máximo tampoco", !heap_ver_max(heap1));
    print_test("Quiero encolar en el Heap a Argentina", heap_encolar(heap1, cad1));
    print_test("Quiero encolar en el Heap a Brasil", heap_encolar(heap1, cad2));
    print_test("Quiero encolar en el Heap a Chile", heap_encolar(heap1, cad3));
    print_test("Quiero encolar en el Heap a Japon", heap_encolar(heap1, cad4));
    print_test("Quiero encolar en el Heap a Dinamarca", heap_encolar(heap1, cad5));
    print_test("Quiero encolar en el Heap a Korea", heap_encolar(heap1, cad6));
    print_test("Quiero encolar en el Heap a Suiza", heap_encolar(heap1, cad7));
    print_test("Quiero encolar en el Heap a Mexico", heap_encolar(heap1, cad8));

    //show_heap(heap1);


    printf("Desencolo el mayor: %s\n", (char*)heap_desencolar(heap1));
    printf("Desencolo el mayor: %s\n", (char*)heap_desencolar(heap1));
    print_test("Desencolar es una operacion valida", heap_desencolar(heap1));

    heap_destruir(heap1, NULL);
    printf("\nDESTRUIMOS EL HEAP Y PROBAMOS HEAPIFY\n\n");

    void* arreglo[] = {cad6, cad5, cad7, cad8, cad1, cad4, cad3,cad2};
    void* arreglo2[] = {cad6, cad6, cad5, cad7, cad8, cad1, cad4, cad3,cad2};

    heap_t *heap2 = heap_crear_arr(arreglo, 8, comparation);

    //show_heap(heap2);
    free(heap2);

    printf("PROBAMOS HEAPSORT\n");
    heap_sort(arreglo2, 8, comparation);
    printf("HEAPSORT: ");
    for(int x = 0; x < 8; x++) {
        printf("%s - ", (char*) arreglo2[x]);
    }
    printf("\n");


}
