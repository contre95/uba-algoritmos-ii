#define _POSIX_C_SOURCE 200809L
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "hash.h"
#include "cola.h"
#include "strutil.h"

 int main(int argc, char const *argv[]) {
     FILE * file_1 = fopen(argv[1],"r");
     if(!file_1) return 1;

     char * linea_1 = NULL;
     size_t capacidad_1 = 0;

     char ** vector;
     cola_t * cola = cola_crear();
     hash_t * hash = hash_crear(NULL);

     while(getline(&linea_1,&capacidad_1,file_1) != -1){
         //printf("%s\n",linea_1);
         if(strcmp(linea_1, "\n") == 0) continue;
         linea_1 = strtok(linea_1, "\n");
         vector  = split(linea_1,' ');
         for(int x = 0 ; vector[x]!= NULL ; x++){
            int* aux = malloc(sizeof(int*));
            *(int*)aux = 1;
            if(hash_obtener(hash,vector[x])) {
                aux = (int*)hash_obtener(hash,vector[x]);
                *(int*) aux = *(int*) aux + 1;
            } else
                cola_encolar(cola, vector[x]);
            hash_guardar(hash,vector[x], aux);
         }
    }

    while(!cola_esta_vacia(cola)) {
        char* clave = (char*) cola_desencolar(cola);
        printf("%d %s \n", *(int*) hash_obtener(hash,clave), clave);
    }
    cola_destruir(cola, NULL);

 }
