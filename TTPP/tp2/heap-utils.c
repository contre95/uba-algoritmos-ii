#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "heap.h"

int main(void) {
    return 0;
}

void** top_k(size_t k, void** datos, size_t tam_datos, cmp_func_t cmp) {
    void** arreglo = malloc(sizeof(void*) * k);
    heap_t* heap = heap_crear_arr(datos, tam_datos,cmp);

    for(size_t x = 0; x < k; x++) {
        arreglo[x] = heap_esta_vacio(heap) ? NULL : heap_desencolar(heap);
    }
    return arreglo;
}
