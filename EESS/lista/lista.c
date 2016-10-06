#include "lista.h"
#include <stdlib.h>
/* Defino la estructura */




typedef struct node node_t;
struct node{
    void *data;
    node_t *next_node;
};
struct lista{
    node_t *first_node;
    node_t *last_node;
    size_t len;
};

node_t* nodo_crear(void){
  node_t *node = malloc(sizeof(node_t));
  if (node==NULL){
    return NULL;
  }
  return node;
  //llenar los nodos con NULL y ETC
}

lista_t* lista_crear(void){
    lista_t *lista = malloc(sizeof(lista_t));
     if (lista == NULL){
         return NULL;
     }
     lista->len = 0;
     lista->first_node = NULL;
     lista->last_node = NULL;
     return lista;
}

bool lista_esta_vacia(const lista_t *lista){
     return lista->first_node==NULL && lista->last_node==NULL;
}

bool lista_insertar_ultimo(lista_t *lista, void* valor){

    node_t *node = nodo_crear();
    node->data = valor;
    node->next_node = NULL;

    if(lista_esta_vacia(lista)){
        lista->first_node = node;
    }else{
        lista->last_node->next_node = node;

    }
  lista->last_node = node;
    lista->len++;
    return true;
}
bool lista_insertar_primero(lista_t *lista, void* valor){
    node_t *node = nodo_crear();
    node->data = valor;

    if(lista_esta_vacia(lista)){
        lista->last_node = node;
        node->next_node = NULL;
      }
    node->next_node = lista->first_node;
    lista->first_node = node;
    lista->len++;
    return true;

}

size_t lista_largo(const lista_t *lista){
    return lista->len;
}

void* lista_borrar_primero(lista_t *lista){

    if(lista_esta_vacia(lista)){
        return NULL;
    }
    if(lista_largo(lista)==1){
        lista->last_node = NULL;
    }
    void* dato_a_devolver = lista->first_node->data;
    node_t *second_node = lista->first_node->next_node;
    free(lista->first_node);
    lista->first_node = second_node;
    lista->len--;
    return dato_a_devolver;

}

void* lista_ver_primero(const lista_t *lista){
    if(lista_esta_vacia(lista)){
        return NULL;
    }
    return lista->first_node->data;
}

void* lista_ver_ultimo(const lista_t *lista){
    if(lista_esta_vacia(lista)){
        return NULL;
    }
    return lista->last_node->data;
}

void lista_destruir(lista_t *lista, void destruir_dato(void*)){
    node_t *act_node = lista->first_node;
    while(act_node){
        node_t * next_node = act_node->next_node;
        if (destruir_dato){
            destruir_dato(act_node->data);
        }
        free(act_node);
        act_node = next_node;
    }
    free(lista);
}


/* ITERATOR MY FRIEND */



struct lista_iter{
    node_t *prev_node;
    node_t *act_node;
    lista_t *lista;
};

lista_iter_t* lista_iter_crear(lista_t *lista){
    lista_iter_t *lista_iter = malloc(sizeof(lista_iter_t));
    if(lista_iter == NULL){
        return NULL;
    }
    lista_iter->lista = lista;
    lista_iter->prev_node = NULL;
    lista_iter->act_node = lista->first_node;
    return lista_iter;
}

bool lista_iter_avanzar(lista_iter_t *iter){
    if(lista_iter_al_final(iter)){
        return false;
    }
    iter->prev_node = iter->act_node;
    iter->act_node =  iter->act_node->next_node;
    return true;
}

void *lista_iter_ver_actual(const lista_iter_t *iter){
    if(lista_esta_vacia(iter->lista) || lista_iter_al_final(iter)){
        return NULL;
    }
    return iter->act_node->data;
}

bool lista_iter_al_final(const lista_iter_t *iter){
    return iter->act_node == NULL;
}

void lista_iter_destruir(lista_iter_t *iter){
    free(iter);
}

bool lista_iter_insertar(lista_iter_t *iter, void *dato){
    if(lista_iter_al_final(iter)){
        iter->prev_node = iter->lista->last_node;
        if(!lista_insertar_ultimo(iter->lista, dato)) return false;
        iter->act_node = iter->lista->last_node;
        return true;
    }
    if(iter->prev_node == NULL){
        if(!lista_insertar_primero(iter->lista, dato)) return false;
        iter->act_node = iter->lista->first_node;
        return true;
    }
    else{
        node_t * new_node = nodo_crear();
        new_node->data = dato;
        new_node->next_node = iter->act_node;
        iter->prev_node->next_node =  new_node;
        iter->act_node = new_node;
        iter->lista->len++;
        return true;
    }
}

void *lista_iter_borrar(lista_iter_t *iter){
    if(lista_esta_vacia(iter->lista)){
        return NULL;
    }
    if(lista_iter_al_final(iter)){
        return NULL;
    }
    if(iter->act_node == iter->lista->first_node){
        iter->act_node = iter->lista->first_node->next_node;
        return lista_borrar_primero(iter->lista);
    }
    if(iter->act_node == iter->lista->last_node) {
        iter->lista->last_node = iter->prev_node;
    }
    iter->prev_node->next_node = iter->act_node->next_node;
    void * data_to_delete = iter->act_node->data;
    free(iter->act_node);
    iter->act_node = iter->prev_node->next_node;
    iter->lista->len--;
    return data_to_delete;

}

void lista_iterar(lista_t *lista, bool(*visitar)(void *dato, void *extra), void *extra){

    node_t * node_act = lista->first_node;
    while( node_act != NULL ){
      if(!visitar(node_act->data, extra)) break;
      node_act = node_act->next_node;
    }
  }
