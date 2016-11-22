#define _POSIX_C_SOURCE 200809L
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "pila.h"

void error(char *message){
    fprintf(stderr, "%s\n", message);
}
int main(int argc, char const *argv[]) {
    if(argc != 3){
        error("CANTIDAD DE ARCHIVOS NO ES LA CORR=CTA !");
        return 1;
    }
    FILE * file_1 = fopen(argv[1],"r");
    char * line_1 = NULL;
    char * line_2 = NULL;
    size_t capacidad_2 = 0;
    size_t capacidad_1 = 0;
    ssize_t longitud_1;
    ssize_t longitud_2;
    for(int i=0; i < atoi(argv[2]) ; i++){
        longitud_1 = getline(&line_1,&capacidad_1,file_1);
        fprintf(stdout,"%s",line_1);
    }
    while(getchar() == '\n' && !feof(file_1)){
        longitud_2 = getline(&line_2,&capacidad_2,file_1);
        fprintf(stdout,"%s",strtok(line_2,"\n"));
    }
    fclose(file_1);
    return 0;
}
