#include "tda/pila.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void error(char *message){
    fprintf(stderr, "%s\n", message);
}

int int main(int argc, char const *argv[]) {

    if(argc != 3){
        error("CANTIDAD DE ARCHIVOS NO ES LA CORRECTA !");
        return 1;
    }

    /*code*/
}
