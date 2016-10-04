#include "cola.h"
#include <stdlib.h>
typedef struct node node_t;
struct node{
    void *data;
    node_t *next_node;
};
struct cola{
    node_t *first_node;
    node_t *last_node;
};
cola_t* cola_crear(void){
    cola_t *cola = malloc(sizeof(cola_t));
     if (cola == NULL){
         return NULL;
     }
     cola->first_node = NULL;
     cola->last_node = NULL;
     return cola;
}
bool cola_esta_vacia(const cola_t *cola){
     return cola->first_node==NULL &&  cola->last_node == NULL;
}
bool cola_encolar(cola_t *cola, void* valor){
    node_t *node = malloc(sizeof(node_t));
    if (node==NULL){
        return false;
    }
    node->data = valor;
    node->next_node = NULL;
    if(cola_esta_vacia(cola)){
        cola->first_node = node;
        cola->last_node = node;
    }else{
        cola->last_node->next_node = node;
        cola->last_node = node;
    }
    return true;
}
void* cola_desencolar(cola_t *cola){
    if(cola_esta_vacia(cola)){
        return NULL;
    }
    void* dato_a_devolver = cola->first_node->data;
    node_t *second_node = cola->first_node->next_node;
    if(cola->first_node == cola->last_node){
        cola->last_node = NULL;
    }
    free(cola->first_node);
    cola->first_node = second_node;
    return dato_a_devolver;
}
void* cola_ver_primero(const cola_t *cola){
    if(cola_esta_vacia(cola)){
        return NULL;
    }
    return cola->first_node->data;
}
void cola_destruir(cola_t *cola, void destruir_dato(void*)){
    node_t *act_node = cola->first_node;
    while(act_node){
        node_t * node_next = act_node->next_node;
        if (destruir_dato){
        destruir_dato(act_node->data);
        }
        free(act_node);
        act_node = node_next;
    }
    free(cola);
}
