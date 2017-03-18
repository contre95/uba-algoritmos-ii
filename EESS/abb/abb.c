#include "abb.h"
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

struct abb {
    abb_t * hijo_izq;
    abb_t * hijo_der;
    void * dato;
    const char * clave;
    abb_comparar_clave_t cmp;
    abb_destruir_dato_t destruir_dato;
    size_t peso;
};

abb_t* abb_crear(abb_comparar_clave_t cmp, abb_destruir_dato_t destruir_dato){
    abb_t * abb = malloc(sizeof(abb_t));
    if(!abb) return NULL;
    abb->peso = 0;
    abb->hijo_izq = NULL;
    abb->hijo_der = NULL;
    abb->clave = malloc(sizeof(const char)*200);
    abb->cmp = cmp;
    abb->destruir_dato = destruir_dato;
    if(!abb->clave) return NULL;
    return abb;
}

bool abb_guardar(abb_t *arbol, const char *clave, void *dato){
    if(arbol->peso == 0){
        arbol->peso = 1;
        arbol->dato = dato;
        arbol->clave = clave;
        return true;
    }
    abb_t * abb = abb_crear(arbol->cmp,arbol->destruir_dato);
    if(!abb) return false;
    abb->peso = arbol->peso + 1;
    abb->dato = dato;
    abb->clave = clave;

    if(arbol->cmp(clave,arbol->clave) > 0)
        abb_guardar(arbol->hijo_der,clave,dato);

    else if(arbol->cmp(clave,arbol->clave) < 0)
        abb_guardar(arbol->hijo_izq,clave,dato);

    else if(arbol->cmp(clave,arbol->clave) == 0){
        free(arbol);
        arbol = abb;
    }
    return true;
}
