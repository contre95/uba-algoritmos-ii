#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "hash.h"

#define LARGO 50

enum nodo_estado {OCUPADO,VACIO,BORRADO};

struct hash_node {
    char * clave;
    void * valor;
    enum nodo_estado estado;
} typedef hash_node_t;

struct hash {
    hash_node_t * hash_array;
    size_t largo; // Representa el largo total del Array (del Hash)
    size_t nodos_ocupados; // Representa la cantidad de Nodos Ocupados.
    size_t espacio_ocupado; // Representa la cantidad de Nodos Ocupados y Borrados.
    hash_destruir_dato_t funcion_destruir; // Almacena la función Destruir.
};

struct hash_iter {
    const hash_t *hash;
    size_t pos;
};

// La función de Hash recibe por parametro una cadena y un rango, y devuelve
// un entero dentro de ese rango correspondiente al valor de Hash de esa cadena.
size_t hash_function(const char *word, size_t hashTableSize){
  unsigned int counter, hashAddress =0;
  for (counter =0; word[counter]!='\0'; counter++){
    hashAddress = hashAddress*word[counter] + word[counter] + counter;
  }
  return (hashAddress%hashTableSize);
}


// Esta función comienza a buscar dentro de un Array de nodos, el primer nodo vacío comenzando desde el índice.
size_t buscar_lugar_vacio(hash_node_t* array, size_t tam, size_t index) {
    for(size_t i = index ; i < tam; i++) { // RECORRO DE INDEX HASTA EL FINAL BUSCANDO UNO VACIO
        if(array[i].estado == VACIO) {
            return i;
        }
    }
    for(size_t i = 0; i < index; i++) { // RECORRO DE 0 HASTA INDEX BUSCANDO UNO VACIO
        if(array[i].estado == VACIO) {
            return i;
        }
    }
    return -1;
}

// Copia el contenido de un Array de Nodos en otro.
// TODOO: Contemplar cuando esto puede dar NULL;
bool copy_arrays(hash_node_t *array1, size_t tam1, hash_node_t *array2, size_t tam2) {
    for(int x = 0; x < tam1; x++) { // RECORRO EL ARREGLO 1
        if(array1[x].estado == OCUPADO) { // SI EL ELEMENTO DEL ARREGLO 1 ESTA OCUPADO
            size_t new_clave = hash_function(array1[x].clave, tam2);
            size_t index = buscar_lugar_vacio(array2, tam2, new_clave);
            strcpy(array2[index].clave,array1[x].clave);
            array2[index].valor = array1[x].valor;
            array2[index].estado = OCUPADO;
        }
    }
    return true;
}

// Devuelvo un array de 'tam' cantidad de nodos, todos seteados en Null.
hash_node_t *new_array(size_t tam) {
    hash_node_t *array = malloc(sizeof(hash_node_t) * tam);
    if(!array)
        return NULL;

    // Inicializo todos los nodos en VACIO.
    for(int i = 0; i < tam; i++){
        array[i].estado = VACIO;
        array[i].clave = malloc(sizeof(char[200]));
        array[i].valor = NULL;
    }

    return array;
}


hash_node_t* obtener_nodo(const hash_t* hash,const char * clave){
    size_t hashed_clave = hash_function(clave, hash->largo);
    //printf("NO ROMPI BUSCANDO %s - %i - %i\n", clave, hashed_clave, (int)hash->largo);

    for(size_t i = hashed_clave ; i < hash->largo; i++) {
        if(hash->hash_array[i].estado == VACIO) {
            return NULL;
        }
        if(hash->hash_array[i].estado == OCUPADO && strcmp(clave,hash->hash_array[i].clave) == 0 ) {
            return hash->hash_array + i;
        }
    }
    for(int i = 0; i < hashed_clave; i++) {
        if(hash->hash_array[i].estado == VACIO) {
            return NULL;
        }
        if(hash->hash_array[i].estado == OCUPADO && strcmp(clave,hash->hash_array[i].clave) == 0 ) {
            return hash->hash_array + i;
        }
    }
    return NULL;
}

hash_t *hash_crear(hash_destruir_dato_t destruir_dato){
    hash_t * hash = malloc(sizeof(hash_t));
    if(!hash) return NULL;
    hash->largo = LARGO;
    hash->nodos_ocupados = 0;
    hash->espacio_ocupado = 0;
    hash->funcion_destruir = destruir_dato;
    hash->hash_array = new_array(hash->largo);

    return hash;
}

// Esta funcion redimensiona un Hash al nuevo tamaño dado.
bool hash_redimensionar(hash_t *hash, size_t nuevo_tam) {
    hash_node_t *array = new_array(nuevo_tam);
    if(!array)
        return false;

    //printf("TENGO QUE REDIMENSIONAR %i de %i --> %i\n", (int)hash->nodos_ocupados, (int)hash->largo, (int)nuevo_tam);
    copy_arrays(hash->hash_array, hash->largo, array, nuevo_tam);

    for(int i = 0; i < hash->largo; i++){
        free(hash->hash_array[i].clave);
    }
    free(hash->hash_array);
    hash->hash_array = array;
    hash->largo = nuevo_tam;
    hash->espacio_ocupado = hash->nodos_ocupados;

    return true;
}

bool hash_guardar(hash_t *hash, const char *clave, void *dato) {
    size_t hashed_clave = hash_function(clave, hash->largo);
    hash_node_t * nodo = obtener_nodo(hash,clave);
    if(nodo){
        if(hash->funcion_destruir)
            hash->funcion_destruir(nodo->valor);
        nodo->valor = dato;
        return true;
    }

    if(hash->espacio_ocupado > (hash->largo - hash->largo / 6)) {
        hash_redimensionar(hash, hash->largo * 2);
        return hash_guardar(hash, clave, dato);
    }

    size_t pos_vacio = buscar_lugar_vacio(hash->hash_array, hash->largo, hashed_clave);
    strcpy(hash->hash_array[pos_vacio].clave ,clave);
    hash->hash_array[pos_vacio].valor = dato;
    hash->hash_array[pos_vacio].estado = OCUPADO;
    hash->nodos_ocupados++;
    hash->espacio_ocupado++;
    return true;
}

void *hash_borrar(hash_t *hash, const char *clave){
    if(hash->nodos_ocupados == 0)
        return NULL;

    if(hash->nodos_ocupados < hash->largo / 5 ) {
        hash_redimensionar(hash, hash->largo / 2);
        return hash_borrar(hash, clave);
    }

    hash_node_t * nodo = obtener_nodo(hash,clave);
    if(nodo){
        void* aux = nodo->valor;
        nodo->estado = BORRADO;
        hash->nodos_ocupados--;
        return aux;
    }
    return NULL;
}

size_t hash_cantidad(const hash_t *hash){
    return hash->nodos_ocupados;
}

void *hash_obtener(const hash_t *hash, const char *clave) {
    if(hash->nodos_ocupados == 0)
        return NULL;

    hash_node_t * nodo = obtener_nodo(hash,clave);
    if(nodo)
        return nodo->valor;
    return NULL;
}

bool hash_pertenece(const hash_t *hash, const char *clave){
    hash_node_t * nodo = obtener_nodo(hash,clave);
    if(nodo)
        return true;
    return false;
}

void hash_destruir(hash_t *hash){
    for(int i = 0; i < hash->largo; i++){
        if(hash->hash_array[i].estado == OCUPADO) {
            if(hash->funcion_destruir)
                hash->funcion_destruir(hash->hash_array[i].valor);
        }
        free(hash->hash_array[i].clave);
    }
    free(hash->hash_array);
    free(hash);
}

// COMIENZO FUNCIONES DE ITERADOR

hash_iter_t *hash_iter_crear(const hash_t *hash) {
    hash_iter_t *iter = malloc(sizeof(hash_iter_t));
    if(!iter)
        return NULL;

    iter->hash = hash;
    iter->pos = 0;

    if(iter->hash->hash_array[iter->pos].estado != OCUPADO)
        hash_iter_avanzar(iter);
    return iter;
}

bool hash_iter_avanzar(hash_iter_t *iter){

    if(!hash_iter_al_final(iter)) {
        iter->pos++;
        if(hash_iter_al_final(iter)) return true;
        if(iter->hash->hash_array[iter->pos].estado != OCUPADO){
            return hash_iter_avanzar(iter);}

        return true;
    }
    return false;
}

const char *hash_iter_ver_actual(const hash_iter_t *iter){
    if(hash_iter_al_final(iter))
        return NULL;

    size_t pos = iter->pos;
    return iter->hash->hash_array[pos].clave;
}

bool hash_iter_al_final(const hash_iter_t *iter){
    return iter->pos == iter->hash->largo;
}

void hash_iter_destruir(hash_iter_t* iter){
    free(iter);
}
