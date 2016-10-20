#include "pila.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include "strutil.h"
extern int *strdup(const char* s);




int main(int argc, char const *argv[]){
    if(argc <= 1){
        fprintf(stderr, "%s\n", "CANTIDAD DE ARCHIVOS NO ES LA CORRECTA !");
        return 1;
    }
    char **array = split(argv[1],' ');
    pila_t * pila_polaca = pila_crear();

    for(int i = 0; i < cant_palabras(argv[1],' ')  ; i++){
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
    printf("\n%i\n",*(int*)resultado_final);
    free(resultado_final);
    pila_destruir(pila_polaca);
    free_strv(array);
    return 0;
}
