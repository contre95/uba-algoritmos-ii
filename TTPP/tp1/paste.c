#define _POSIX_C_SOURCE 200809L
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void error(char *message){
    fprintf(stderr, "%s\n", message);
}
int cant_lineas(FILE * file){
    int lines;
    int ch;
    while((ch = fgetc(file)) != EOF){
        if (ch == '\n')
            lines++;
    }
    return lines;
}

int main(int argc, char const *argv[]) {

    if(argc != 3){
        error("CANTIDAD DE ARCHIVOS NO ES LA CORRECTA !");
        return 1;
    }

    FILE * file_1 = fopen(argv[1],"r");
    if(!file_1) return 1;
    int b = cant_lineas(file_1);
    FILE * file_2 = fopen(argv[2],"r");
    if(!file_2) return 1;
    int a = cant_lineas(file_2);

    if(a != b ) return -1;
    rewind(file_1);
    rewind(file_2);
    char * linea_1 = NULL;
    char * linea_2 = NULL;
    size_t capacidad_2 = 0;
    size_t capacidad_1 = 0;
    ssize_t longitud_1;
    ssize_t longitud_2;
    while((longitud_1 = getline(&linea_1,&capacidad_1,file_1) != -1) && (longitud_2 = getline(&linea_2,&capacidad_2,file_2) != -1)){
        fprintf(stdout,"%s\t%s\n",strtok(linea_1,"\n"),strtok(linea_2,"\n"));
        free(linea_1);
        free(linea_2);
    }
    fclose(file_1);
    fclose(file_2);

    return 0;
}
