#define _POSIX_C_SOURCE 200809L
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "hash.h"
#include "strutil.h"

int main(int argc, char *argv[]) {
    if(argc<3) {
        fprintf(stderr, "Error en la cantidad de parametros.\n");
        return -1;
    }
    if(argv[3] && (strcmp(argv[3],"-1") != 0 && strcmp(argv[3],"-2") != 0)) {
        printf("%s\n", argv[3]);
        fprintf(stderr, "El tercer parametro es incorrecto.\n");
        return -1;
    }
    int param;
    param = argv[3] ? atoi(argv[3]) : 0 ;

    FILE * file_1 = fopen(argv[1],"r");
    FILE * file_2 = fopen(argv[2],"r");
    if(!file_1) return 1;
    if(!file_2) return 1;

    char * linea_1 = NULL;
    size_t capacidad_1 = 0;

    char ** vector;
    hash_t * hash = hash_crear(NULL);

    while(getline(&linea_1,&capacidad_1,file_1) != -1){
        if(strcmp(linea_1, "\n") == 0) continue;
        linea_1 = strtok(linea_1, "\n");
        vector  = split(linea_1,' ');
        for(int x = 0 ; vector[x]!= NULL ; x++){
            int* aux = malloc(sizeof(int*));
            *(int*)aux = -1;
            hash_guardar(hash,vector[x], aux);
        }
    }

    while(getline(&linea_1,&capacidad_1,file_2) != -1){
        if(strcmp(linea_1, "\n") == 0) continue;
        linea_1 = strtok(linea_1, "\n");
        vector  = split(linea_1,' ');
        for(int x = 0 ; vector[x]!= NULL ; x++){
            int* aux = malloc(sizeof(int*));
            if(hash_obtener(hash,vector[x]))
                *(int*) aux = 0;
            else
                *(int*) aux = -2;
            hash_guardar(hash,vector[x], aux);
        }
    }

    hash_iter_t * iter_hash = hash_iter_crear(hash);
    while(!hash_iter_al_final(iter_hash)){
        const char * clave = hash_iter_ver_actual(iter_hash);
        if(*(int*)hash_obtener(hash,clave) == param){
            printf("%s\n",clave);
        }


        hash_iter_avanzar(iter_hash);
    }
}
