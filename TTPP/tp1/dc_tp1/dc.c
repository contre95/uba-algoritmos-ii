#include "../tda/pila/pila.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void error(char *message){
    fprintf(stderr, "%s\n", message);
}

int main(void) {
    pila_t *pila = pila_crear();
    int a = 2;
    pila_apilar(pila,&a);
    printf("%i\n",*(int*)pila_ver_tope(pila));


    
    return 0;
}
