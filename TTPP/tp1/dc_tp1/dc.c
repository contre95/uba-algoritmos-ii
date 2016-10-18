#include "../tda/pila/pila.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include "../strutil_tp1/strutil.h"

int main(int argc, char const *argv[]){
    if(argc <= 1){
        error("CANTIDAD DE PARAMETROS INVALIDOS !");
        return 1;
    }
    char **array = split(argv[1],' ');
    printf("%s\n","Las operaciones son : " );
    for(int i = 0; i < cant_palabras(argv[1],' ')  ; i++){
        printf("%s : %i",array[i],strlen(array[i]));
    }
    pila_t pila_polaca = pila_crear();

    for(int i = 0; i < cant_palabras(argv[1],' ')  ; i++){
        if(*array[i]=='+'){
            int result = pila_desapilar(pila_polaca) + pila_desapilar(pila_polaca);
            pila_apilar(pila_polaca,(int)result);
        }
        if(*array[i]=='*'){
            int result = pila_desapilar(pila_polaca) * pila_desapilar(pila_polaca);
            pila_apilar(pila_polaca,(int)result);
        }
        if(*array[i]=='-'){
            int result = pila_desapilar(pila_polaca) - pila_desapilar(pila_polaca);
            pila_apilar(pila_polaca,(int)result);
        }
        if(*array[i]=='/'){
            int result = pila_desapilar(pila_polaca) / pila_desapilar(pila_polaca);
            pila_apilar(pila_polaca,(int)result);
        }
        pila_apilar(pila_polaca,(int)atoi(array[i]));
    }
    printf("%i\n",pila_desapilar(pila_polaca));
    free_strv(array);
    return 0;
}
