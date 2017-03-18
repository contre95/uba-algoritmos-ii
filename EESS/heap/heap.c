#include <stdbool.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "heap.h"

struct heap {
    void ** array;
    size_t largo;
    cmp_func_t comparador;
};

void swap(heap_t * heap,size_t i1, size_t i2){
    if(i1 == i2) return;
    void *aux = heap->array[i1];
    heap->array[i1] = heap->array[i2];
    heap->array[i2] = aux;
}

void up_heap(heap_t * heap, size_t index){
    if(index == 0) return;
    size_t pos_padre = (index-1)/2;
    //printf("Mi hijo es %d (%s) y mi padre %d (%s)\n", (int) index, (char*) heap->array[index], (int) pos_padre, (char*) heap->array[pos_padre]);
    if(heap->comparador(heap->array[index], heap->array[pos_padre]) > 0) {
        swap(heap,index,pos_padre);
        up_heap(heap, pos_padre);
    }
}

void down_heap(heap_t * heap, size_t index){
    if(index >= heap->largo) return;
    size_t pos_hijo_izq = index * 2 + 1;
    size_t pos_hijo_der = index * 2 + 2;
    size_t pos_mayor = index;

    if(pos_hijo_izq < heap->largo && heap->comparador(heap->array[index], heap->array[pos_hijo_izq]) < 0)
        pos_mayor = pos_hijo_izq;
    if(pos_hijo_der < heap->largo && heap->comparador(heap->array[pos_mayor], heap->array[pos_hijo_der])  < 0)
        pos_mayor = pos_hijo_der;
    if(pos_mayor != index) {
        swap(heap, index, pos_mayor);
        down_heap(heap, pos_mayor);
    }
    //printf("Mi hijo es %d (%s) y mi padre %d (%s)\n", (int) index, (char*) heap->array[index], (int) pos_padre, (char*) heap->array[pos_padre]);
}


/* PRIMITIVAS */

void show_heap(heap_t *heap) {
    printf("DEBUG DE HEAP: ");
    for(size_t x = 0; x < heap->largo; x++) {
        printf("%s - ", (char*)heap->array[x]);
    }
    printf("\n");
}

heap_t * heap_crear(cmp_func_t cmp){
    heap_t * heap = malloc(sizeof(heap_t));
    if(!heap) return NULL;
    heap->largo = 0;
    void ** heap_array = malloc(sizeof(void*)*heap->largo);
    if(!heap_array) return NULL;
    heap->array = heap_array;
    heap->comparador = cmp;
    return heap;
}

heap_t * heap_crear_arr(void *arreglo[], size_t n,cmp_func_t cmp) {
    heap_t * heap = malloc(sizeof(heap_t));
    if(!heap) return NULL;
    heap->largo = n;
    heap->array = arreglo;
    heap->comparador = cmp;
    for(int x = (int) n / 2 - 1; x >=  0; x--)
        down_heap(heap, x);

    return heap;
}

size_t heap_cantidad(const heap_t *heap){
    return heap->largo;
}

void heap_destruir(heap_t *heap, void destruir_elemento(void *e)){
    for (int i=0; i<heap->largo ; i++){
        if(destruir_elemento){
            destruir_elemento(heap->array[i]);
        }
    }
    free(heap->array);
    free(heap);
}

bool heap_esta_vacio(const heap_t *heap){
    return heap->largo == 0;
}

bool heap_encolar(heap_t *heap, void *elem){
    if(!heap || !elem) return false;
    void **array_aux = realloc(heap->array, sizeof(void*) * (heap->largo + 1));
    if (!array_aux) return false;
    heap->array = array_aux;
    heap->array[heap->largo] = elem;
    heap->largo++;
    up_heap(heap, heap->largo - 1);
    return true;
}

void *heap_desencolar(heap_t *heap) {
    if(!heap || heap->largo == 0) return NULL;
    void* aux = heap->array[0];
    swap(heap, 0, heap->largo - 1);
    if(heap->largo != 1) {
        void **array_aux = realloc(heap->array, sizeof(void*) * (heap->largo - 1));
        if(!array_aux) return NULL;
        heap->array = array_aux;
    }
    else {
        free(heap->array);
        heap->array = malloc(sizeof(void*) * 0);
    }
    heap->largo--;
    down_heap(heap, 0);
    return aux;
}

void *heap_ver_max(const heap_t *heap){
    if(heap->largo == 0) return NULL;
    return heap->array[0];
}


void heap_sort(void *elementos[], size_t cant, cmp_func_t cmp) {
    if(cant == 0) return;
    heap_t *heap = heap_crear(cmp);
    for(int x = 0; x < cant; x++) {
        heap_encolar(heap, elementos[x]);
    }
    for(int x = (int) cant - 1; x >= 0; x--) {
        elementos[x] = heap_desencolar(heap);
    }
    heap_destruir(heap, NULL);
}
