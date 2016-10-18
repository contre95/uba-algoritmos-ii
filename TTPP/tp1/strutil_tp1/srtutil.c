#include "../tda/pila/pila.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
//char strdup(const char string);

void error(char *message){
    fprintf(stderr, "%s\n", message);
}

int cant_palabras(const char* str, char sep){
    int cant_pal = 1;
    for (size_t i = 0; i < strlen(str) ; i++) {
        if( str[i]==sep) cant_pal++;
    }
    return cant_pal;
}
char** split(const char* str, char sep){
    int cant_pal = cant_palabras(str,sep);

    char **string_array = malloc(sizeof(char*) * (cant_pal + 1));

    int num_pal = 0;
    char palabra[1000] = "";
    int largo = 0;
    for (size_t p = 0; p < cant_pal; p++) {
        while(str[p]!=sep){
            palabra[largo] = str[p];
            largo += 1;
        }
        palabra[largo+1] = '\0';
        string_array[num_pal] = malloc(sizeof(char)*(largo+1));
        //fijarse si se hizo el malloc
        strcpy(string_array[num_pal],palabra);
        largo = 0;
        num_pal++;
    }
    /*for (size_t i = 0; i < strlen(str); i++) {
        palabra[largo] = str[i];
        largo += 1;
        if( str[i]==sep || i==strlen(str)-1){
            palabra[largo+1] = '\0';
            string_array[num_pal] = malloc(sizeof(char)*(largo+1));
            //fijarse si se hizo el malloc
            strcpy(string_array[num_pal],palabra);
            largo = 0;
            num_pal++;
        }
    }*/
    string_array[cant_pal] = NULL;
    return string_array;
}

void free_strv(char* strv[]){
    int i = 0;
    while (strv[i]) {
        //printf("no llegue al final\n");
        free(strv[i]);
        i++;
    }
    free(strv);
    //printf("llegue al final\n");
}

int main(int argc, char const *argv[]){

    char **array = split(argv[1],' ');
    for(int i = 0; i < cant_palabras(argv[1],' ')  ; i++){
        printf("\n%s\n",array[i]);
    }
free_strv(array);
    return 0;
}
