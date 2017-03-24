#include "pila.h"
#include <stdlib.h>
#define TAM0 100
/* Definición del struct pila proporcionado por la cátedra.
 */
struct pila {
    void **datos;
    size_t tam;
    size_t largo;
};

/* *****************************************************************
 *                    PRIMITIVAS DE LA PILA
 * *****************************************************************/

bool pila_redimensionar(pila_t *pila,size_t tam);

void pila_destruir(pila_t *pila){
         free(pila->datos);
         free(pila);
 }

bool pila_esta_vacia(const pila_t *pila){
    if(pila->largo == 0){
        return true;
    }
    return false;
}

void* pila_ver_tope(const pila_t *pila){
        if(pila_esta_vacia(pila)){
            return NULL;
        }
        return pila->datos[pila->largo-1];
}

void* pila_desapilar(pila_t *pila){
    if(pila_esta_vacia(pila)){
        return NULL;
    }
    if(pila->largo <= pila->tam/4){
        if(!pila_redimensionar(pila,pila->tam/2)) return false;
    }
    pila->largo -= 1;
    return pila->datos[pila->largo];
}

bool pila_apilar(pila_t *pila, void* valor){
    if(pila->largo >= pila->tam){
        if(!pila_redimensionar(pila,pila->tam*2)) return false;
    }
    pila->datos[pila->largo] = valor;
    pila->largo += 1;
    return true;
}


pila_t* pila_crear(void) {
     pila_t *pila = malloc(sizeof(pila_t));

     if (pila == NULL) return NULL;

     pila->largo = 0;
     pila->tam = TAM0;
     pila->datos = malloc(pila->tam * sizeof(void*));

     if (pila->datos == NULL) {
         free(pila);
         return NULL;
     }
     return pila;
 }

 bool pila_redimensionar(pila_t* pila, size_t tam_nuevo) {
     void* datos_nuevo = realloc(pila->datos, tam_nuevo * sizeof(void*));

     // Cuando tam_nuevo es 0, es correcto si se devuelve NULL.
     // En toda otra situación significa que falló el realloc.
     if (tam_nuevo > 0 && datos_nuevo == NULL) return false;

     pila->datos = datos_nuevo;
     pila->tam = tam_nuevo;
     return true;
 }

// ... lista para entregar ... //
