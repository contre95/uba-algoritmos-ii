#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>

#include "abb.h"
#include "pila.h"

extern char *strdup(const char* s);
typedef struct abb_nodo abb_nodo_t;

struct abb_nodo {
    abb_nodo_t * hijo_izq;
    abb_nodo_t * hijo_der;
    void * dato;
    char * clave;
};

struct abb {
    abb_nodo_t * raiz;
    size_t cantidad;
    abb_comparar_clave_t comparar;
    abb_destruir_dato_t destruir_dato;
};

struct abb_iter {
    const abb_t *arbol;
    abb_nodo_t* nodoactual;
    pila_t* pila;
};

struct abb_iter_post {
    const abb_t *arbol;
    abb_nodo_t* nodoactual;
    pila_t* pila;
};
struct abb_item {
    const char* clave;
    void* valor;
};

abb_nodo_t * abb_nodo_crear(const char *clave, void *dato){
    abb_nodo_t * abb_nodo = malloc(sizeof(abb_nodo_t));
    if(!abb_nodo) return NULL;
    abb_nodo->hijo_izq = NULL;
    abb_nodo->hijo_der = NULL;
    abb_nodo->dato = dato;
    abb_nodo->clave = strdup(clave);
    return abb_nodo;
}

void abb_nodo_destruir(abb_nodo_t* nodo, abb_destruir_dato_t destruir) {
    free(nodo->clave);
    if(destruir)
        destruir(nodo->dato);
    free(nodo);
}

void abb_nodo_destruir_todo(abb_nodo_t* nodo, abb_destruir_dato_t destruir) {
    if(nodo->hijo_izq) {
        abb_nodo_destruir_todo(nodo->hijo_izq, destruir);
    }
    if(nodo->hijo_der) {
        abb_nodo_destruir_todo(nodo->hijo_der, destruir);
    }
    abb_nodo_destruir(nodo, destruir);
}

abb_nodo_t * abb_nodo_buscar_maximo(abb_nodo_t* nodo) {
    abb_nodo_t* aux = nodo;
    if(aux->hijo_der) {
        return abb_nodo_buscar_maximo(aux->hijo_der);
    }
    return aux;
}

abb_nodo_t * buscar_nodo(const abb_t* arbol, abb_nodo_t* nodo, const char* clave) {
    if(arbol->comparar(clave, nodo->clave) < 0 && nodo->hijo_izq) {
        return buscar_nodo(arbol,nodo->hijo_izq, clave);
    }
    else if(arbol->comparar(clave, nodo->clave) > 0 && nodo->hijo_der) {
        return buscar_nodo(arbol,nodo->hijo_der, clave);
    }
    return nodo;
}
// PRIMITIVAS
abb_t* abb_crear(abb_comparar_clave_t cmp, abb_destruir_dato_t destruir_dato){
    abb_t *abb = malloc(sizeof(abb_t));
    if(!abb) return NULL;
    abb->raiz = NULL;
    abb->cantidad = 0;
    abb->comparar = cmp;
    abb->destruir_dato = destruir_dato;
    return abb;
}

bool abb_guardar(abb_t *arbol, const char *clave, void *dato){
    abb_nodo_t *nodo = abb_nodo_crear(clave, dato);
    if(arbol->cantidad == 0) {
        arbol->raiz = nodo;
        arbol->cantidad++;
        return true;
    }
    abb_nodo_t* aux = buscar_nodo(arbol, arbol->raiz, clave);
    if(arbol->comparar(clave, aux->clave) == 0) {
        abb_nodo_destruir(nodo, NULL);
        if(arbol->destruir_dato) arbol->destruir_dato(aux->dato);
        aux->dato = dato;
        return true;
    }
    else if(arbol->comparar(clave, aux->clave) < 0) {
        aux->hijo_izq = nodo;
    }
    else if(arbol->comparar(clave, aux->clave) > 0) {
        aux->hijo_der = nodo;
    }
    arbol->cantidad++;
    return true;
}

size_t abb_cantidad(abb_t *arbol){
    if(!arbol) return 0;
    return arbol->cantidad;
}

bool abb_pertenece(const abb_t *arbol, const char *clave){
    if(arbol->cantidad == 0) return false;
    abb_nodo_t *nodo = buscar_nodo(arbol,arbol->raiz,clave);
    return arbol->comparar(nodo->clave, clave) == 0;
}

void * abb_obtener(const abb_t* arbol, const char* clave) {
    if(arbol->cantidad == 0) return NULL;
    if(!abb_pertenece(arbol, clave)) return NULL;
    abb_nodo_t *nodo = buscar_nodo(arbol,arbol->raiz,clave);
    return nodo->dato;
}

void *abb_borrar(abb_t *arbol, const char *clave){
    if(arbol->cantidad == 0) return NULL;
    if(!abb_pertenece(arbol, clave)) return NULL;

    void * retorno;
    abb_nodo_t * nodo = arbol->raiz;
    abb_nodo_t * nodo_a_borrar;
    bool es_raiz = false;

    /*HAY QUE CONTEMPLAR EL CASO EN EL QUE SEA LA RAIZ LA QUE SE QUIERE BORRAR.*/
    if(arbol->comparar(clave, arbol->raiz->clave) != 0) {
            while((nodo->hijo_izq && arbol->comparar(nodo->hijo_izq->clave,clave) != 0 ) || (nodo->hijo_der && arbol->comparar(nodo->hijo_der->clave,clave) != 0 )){
                    if(nodo->hijo_izq && arbol->comparar(clave, nodo->hijo_izq->clave) == 0) break;
                    else if(nodo->hijo_der && arbol->comparar(clave, nodo->hijo_der->clave) == 0) break;
                    else if(nodo->hijo_izq && arbol->comparar(clave, nodo->clave) < 0)  nodo = nodo->hijo_izq;
                    else if(nodo->hijo_der && arbol->comparar(clave, nodo->clave) > 0)  nodo = nodo->hijo_der;
            }
            nodo_a_borrar = (nodo->hijo_der && arbol->comparar(clave, nodo->hijo_der->clave) == 0) ? nodo->hijo_der : nodo->hijo_izq;
    }else{
            nodo_a_borrar = nodo;
            es_raiz = true;
    }

    retorno = nodo_a_borrar->dato;

    /*CASO EN EL QUE NO TENGO HIJOS */
    if(!nodo_a_borrar->hijo_izq && !nodo_a_borrar->hijo_der) {
        if(es_raiz)
                arbol->raiz = NULL;
        else
            (nodo->hijo_der && arbol->comparar(clave, nodo->hijo_der->clave) == 0) ? (nodo->hijo_der = NULL) : (nodo->hijo_izq = NULL);
        abb_nodo_destruir(nodo_a_borrar,NULL);
        arbol->cantidad--;
    }

    /*CASO EN EL QUE TENGO UN SOLO HIJO */
    else if(!nodo_a_borrar->hijo_izq || !nodo_a_borrar->hijo_der) {
        abb_nodo_t * aux = nodo_a_borrar->hijo_izq ? nodo_a_borrar->hijo_izq : nodo_a_borrar->hijo_der;
        if(es_raiz)
            arbol->raiz = aux;
        else
            (nodo->hijo_der && arbol->comparar(clave, nodo->hijo_der->clave) == 0) ? (nodo->hijo_der = aux) : (nodo->hijo_izq = aux) ;
        abb_nodo_destruir(nodo_a_borrar,NULL);
        arbol->cantidad--;
    }

    /*CASO EN EL QUE TENGO DOS HIJOS */
    else{
        abb_nodo_t * max = abb_nodo_buscar_maximo(nodo_a_borrar->hijo_izq);
        char * clave_aux = strdup(max->clave);
        void * dato_aux = abb_borrar(arbol,max->clave);

        free(nodo_a_borrar->clave);
        nodo_a_borrar->clave = clave_aux;
        nodo_a_borrar->dato = dato_aux;
    }

    return retorno;
}

void abb_destruir(abb_t *arbol){
    if(arbol->cantidad > 0)
        abb_nodo_destruir_todo(arbol->raiz, arbol->destruir_dato);
    free(arbol);
}

// PRIMITIVAS DE ITERADOR
abb_iter_t *abb_iter_in_crear(const abb_t *arbol) {
    abb_iter_t* iter = malloc(sizeof(abb_iter_t));
    abb_nodo_t* aux;
    if(!iter)
        return NULL;

    iter->arbol = arbol;
    iter->pila = pila_crear();
    iter->nodoactual = arbol->raiz;
    aux = arbol->raiz;
    while(aux) {
        //printf("ESTOY APILANDO: %s\n", aux->clave);
        pila_apilar(iter->pila, aux);
        aux = aux->hijo_izq;
    }

    return iter;
}

bool abb_iter_in_avanzar(abb_iter_t *iter) {
    if(pila_esta_vacia(iter->pila)) return false;
    abb_nodo_t* actual = pila_desapilar(iter->pila);
    abb_nodo_t* aux;
    if(actual->hijo_der) {
        aux = actual->hijo_der;
        pila_apilar(iter->pila, aux);
        while(aux->hijo_izq) {
            aux = aux->hijo_izq;
            pila_apilar(iter->pila, aux);
        }
    }
    return true;
}

const char *abb_iter_in_ver_actual(const abb_iter_t *iter) {
    if(iter->arbol->cantidad == 0) return NULL;
    if(abb_iter_in_al_final(iter)) return NULL;
    abb_nodo_t* aux = pila_ver_tope(iter->pila);
    return aux->clave;
}
bool abb_iter_in_al_final(const abb_iter_t *iter) {
    return pila_esta_vacia(iter->pila);
}

void abb_iter_in_destruir(abb_iter_t* iter) {
    pila_destruir(iter->pila);
    free(iter);
}

void nodo_in_order(abb_nodo_t* nodo, bool visitar(const char *, void *, void *), void *extra) {
    if(!nodo) return;
    if(nodo->hijo_izq)
        nodo_in_order(nodo->hijo_izq, visitar, extra);
    if(!visitar(nodo->clave, nodo->dato, extra)) return;
    if(nodo->hijo_der)
        nodo_in_order(nodo->hijo_der, visitar, extra);
}

void abb_in_order(abb_t *arbol, bool visitar(const char *, void *, void *), void *extra){
    nodo_in_order(arbol->raiz, visitar, extra);
    return;
}

// ITERADOR INTERNO POST ORDER //
void nodo_post_order(abb_nodo_t* nodo, bool visitar(const char *, void *, void *), void *extra) {
    if(!nodo) return;
    if(nodo->hijo_izq)
        nodo_in_order(nodo->hijo_izq, visitar, extra);
    if(nodo->hijo_der)
        nodo_in_order(nodo->hijo_der, visitar, extra);
    if(!visitar(nodo->clave, nodo->dato, extra)) return;
}

void abb_post_order(abb_t *arbol, bool visitar(const char *, void *, void *), void *extra){
    nodo_post_order(arbol->raiz, visitar, extra);
    return;
}

// ITERADOR EXTERNO POST ORDER //
abb_iter_post_t* abb_iter_post_crear(const abb_t* arbol) {
    abb_iter_post_t* iter = malloc(sizeof(abb_iter_post_t));
    abb_nodo_t* aux;
    if(!iter)
        return NULL;

    iter->arbol = arbol;
    iter->pila = pila_crear();
    iter->nodoactual = arbol->raiz;

    aux = arbol->raiz;
    while(aux) {
        pila_apilar(iter->pila, aux);
        if(aux->hijo_der && !aux->hijo_izq){
            aux = aux->hijo_der;
            continue;
        }
        aux = aux->hijo_izq;
    }
    return iter;
}

bool abb_iter_post_avanzar(abb_iter_post_t *iter) {
    if(pila_esta_vacia(iter->pila)) return false;
    abb_nodo_t* actual = pila_desapilar(iter->pila);
    abb_nodo_t* aux = pila_ver_tope(iter->pila);
    if(aux && actual == aux->hijo_izq) {
        aux = aux->hijo_der;
        while(aux) {
            pila_apilar(iter->pila, aux);
            if(aux->hijo_der && !aux->hijo_izq){
                aux = aux->hijo_der;
                continue;
            }
            aux = aux->hijo_izq;
        }
    }
    return true;
}

bool abb_iter_post_al_final(const abb_iter_post_t *iter) {
    return pila_esta_vacia(iter->pila);
}

const char *abb_iter_post_ver_actual(const abb_iter_post_t *iter) {
    if(iter->arbol->cantidad == 0) return NULL;
    if(abb_iter_post_al_final(iter)) return NULL;
    abb_nodo_t* aux = pila_ver_tope(iter->pila);
    return aux->clave;
}

void abb_iter_post_destruir(abb_iter_post_t* iter) {
    pila_destruir(iter->pila);
    free(iter);
}

// ABB OBTENER ITEMS
abb_item_t* abb_obtener_items(const abb_t* arbol) {
    if(arbol->cantidad == 0) return NULL;
    size_t contador = 0;
    abb_item_t* arreglo = malloc(sizeof(abb_item_t) * arbol->cantidad);
    abb_iter_t* iter = abb_iter_in_crear(arbol);
    while(!abb_iter_in_al_final(iter)) {
        char* clave = (char*)abb_iter_in_ver_actual(iter);
        void* dato = abb_obtener(arbol, clave);
        arreglo[contador].clave = clave;
        arreglo[contador].valor = dato;
        contador++;
        abb_iter_in_avanzar(iter);
    }
    abb_iter_in_destruir(iter);
    return arreglo;
}

void arbol_show(abb_item_t* valores) {
    const char* clave = valores[0].clave;
    printf("primera clave = %s\n", clave);
}
