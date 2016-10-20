#include "pila.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include "strutil.h"
extern int *strdup(const char* s);

int polish(char const *operation){

    char **array = split(operation,' ');
    pila_t * pila_polaca = pila_crear();

    int cant_pal = 1;
    for (size_t i = 0; i < strlen(operation) ; i++) {
        if( operation[i]==' ') cant_pal++;
    }

    for(int i = 0; i < cant_pal ; i++){
        char *elemento = array[i];
        int *valor_1 = pila_desapilar(pila_polaca);
        int *valor_2 = pila_desapilar(pila_polaca);
        int *result= malloc(sizeof(int));
        if(*elemento == '-') *result = *valor_2 - *valor_1;
        else if(*elemento == '+') *result = *valor_2 + *valor_1;
        else if(*elemento == '/') *result = *valor_2 / *valor_1;
        else if(*elemento == '*') *result = *valor_2 * *valor_1;
        else{
            int* number= malloc(sizeof(int));
            *number =  atoi(elemento);
            pila_apilar(pila_polaca,number);
            continue;
        }
        pila_apilar(pila_polaca,result);
        free(valor_1);
        free(valor_2);
    }

    int *resultado_final = pila_desapilar(pila_polaca);
    pila_destruir(pila_polaca);
    free_strv(array);
    return *resultado_final;
}

int main(){
    printf("\n%i\n",polish("123 123 +"));
    return 0;
}
