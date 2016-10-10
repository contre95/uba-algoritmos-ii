#include "../tda/pila/pila.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

enum operat = {"+","-","/","*"};

void error(char *message){
    fprintf(stderr, "%s\n", message);
}

int main(int argc, char const *argv[]) {

    if(argc < 4) return 1;

    pila_t *pila_polaca = pila_crear();
    for(int entrada = 1 ; entrada < argc - 2 ; entrada++){
        for(int i=0; i < strlen(argv[entrada]) ; i++){

            if(isdigit(argv[entrada][i]){
                pila_apilar(pila_polaca,&argv[entrada][i]);
                break;
            }

            switch (operat) {
                case "*":
                    int producto = pila_desapilar(pila_polaca) * pila_desapilar(pila_polaca);
                    pila_apilar(pila_polaca,&producto);
                    break;

                case "/":
                    int producto = pila_desapilar(pila_polaca) / pila_desapilar(pila_polaca);
                    pila_apilar(pila_polaca,&producto);
                    break;

                case "-":
                    int producto = pila_desapilar(pila_polaca) - pila_desapilar(pila_polaca);
                    pila_apilar(pila_polaca,&producto);
                    break;

                case "+":
                    int producto = pila_desapilar(pila_polaca) + pila_desapilar(pila_polaca);
                    pila_apilar(pila_polaca,&producto);
                    break;
            }
        }
        printf("%i\n",pila_desapilar(pila_polaca) );
    }

    return 0;
}
