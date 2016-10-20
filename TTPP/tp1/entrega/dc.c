#include "pila.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include "strutil.h"
extern int *strdup(const char* s);

int polish(const char * operation){

    char **array = split(operation,' ');
    pila_t * pila_polaca = pila_crear();

    int cant_pal = 1;
    for (size_t i = 0; i < strlen(operation[1]) ; i++) {
        if( operation[1][i]==' ') cant_pal++;
    }

    for(int i = 0; i < cant_pal ; i++){
        char *elemento = array[i];
        if(*elemento == '-'){
            int *valor_1 = pila_desapilar(pila_polaca);
            int *valor_2 = pila_desapilar(pila_polaca);
            int *result= malloc(sizeof(int));
            *result = *valor_2 - *valor_1;
            pila_apilar(pila_polaca,result);
            free(valor_1);
            free(valor_2);
        }
        else if(*elemento == '+'){
            int *valor_1 = pila_desapilar(pila_polaca);
            int *valor_2 = pila_desapilar(pila_polaca);
            int *result= malloc(sizeof(int));
            *result = *valor_2 + *valor_1;
            pila_apilar(pila_polaca,result);
            free(valor_1);
            free(valor_2);
        }
        else if(*elemento == '*'){
            int *valor_1 = pila_desapilar(pila_polaca);
            int *valor_2 = pila_desapilar(pila_polaca);
            int *result= malloc(sizeof(int));
            *result = *valor_2 * *valor_1;
            pila_apilar(pila_polaca,result);
            free(valor_1);
            free(valor_2);
        }
        else if(*elemento == '/'){
            int *valor_1 = pila_desapilar(pila_polaca);
            int *valor_2 = pila_desapilar(pila_polaca);
            int *result= malloc(sizeof(int));
            *result = *valor_2 / *valor_1;
            pila_apilar(pila_polaca,result);
            free(valor_1);
            free(valor_2);
        }
        else{
            int* number= malloc(sizeof(int));
            *number =  atoi(elemento);
            pila_apilar(pila_polaca,number);
        }
    }

    int *resultado_final = pila_desapilar(pila_polaca);
    free(resultado_final);
    pila_destruir(pila_polaca);
    free_strv(array);
    return *resultado_final;
}

int main(int argc, char const *argv[]){
    if(argc <= 1){
        fprintf(stderr, "%s\n", "CANTIDAD DE ARCHIVOS NO ES LA CORRECTA !");
        return 1;
    }
    printf("\n%i\n",polish(argv[1]);
    return 0;
}
