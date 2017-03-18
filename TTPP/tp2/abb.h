#ifndef ABB_H
#define ABB_H

#include <stdbool.h>

typedef struct abb abb_t;

typedef int (*abb_comparar_clave_t) (const char *, const char *);
typedef void (*abb_destruir_dato_t) (void *);

abb_t* abb_crear(abb_comparar_clave_t cmp, abb_destruir_dato_t destruir_dato);

bool abb_guardar(abb_t *arbol, const char *clave, void *dato);
void *abb_borrar(abb_t *arbol, const char *clave);

void *abb_obtener(const abb_t *arbol, const char *clave);
bool abb_pertenece(const abb_t *arbol, const char *clave);

size_t abb_cantidad(abb_t *arbol);

void abb_destruir(abb_t *arbol);



/* ITERADOR INTERNO IN-ORDER */
void abb_in_order(abb_t *arbol, bool visitar(const char *, void *, void *), void *extra);

/* ITERADOR EXTERNO IN-ORDER */
typedef struct abb_iter abb_iter_t;
typedef struct abb_iter_post abb_iter_post_t;
typedef struct abb_item abb_item_t;

abb_iter_t *abb_iter_in_crear(const abb_t *arbol);
bool abb_iter_in_avanzar(abb_iter_t *iter);
const char *abb_iter_in_ver_actual(const abb_iter_t *iter);
bool abb_iter_in_al_final(const abb_iter_t *iter);
void abb_iter_in_destruir(abb_iter_t* iter);

/* ITERADOR INTERNO POST-ORDER */
void abb_post_order(abb_t* arbol, bool (*visitar)(const char*, void*, void*), void* extra);

/* ITERADOR EXTERNO POST-ORDER */
abb_iter_post_t*  abb_iter_post_crear(const abb_t* arbol);
bool  abb_iter_post_avanzar(abb_iter_post_t* iter);
const char*  abb_iter_post_ver_actual(const abb_iter_post_t* iter);
bool  abb_iter_post_al_final(const abb_iter_post_t* iter);
void  abb_iter_post_destruir(abb_iter_post_t* iter);

// PRIMITIVA ABB OBTENER ITEMS
abb_item_t* abb_obtener_items(const abb_t*);

#endif
