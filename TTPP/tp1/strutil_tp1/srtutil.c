#include "../tda/pila/pila.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
extern char *strdup(const char* s);

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
    size_t carga = 0;
    size_t total = 1000;
    char *palabra = malloc(total); // {}
    int largo = 0;

    for (size_t i = 0; i < strlen(str); i++) {

        if( str[i]==sep || i==strlen(str)-1){

            if(i==strlen(str)-1){
                palabra[largo] = str[i];
                palabra[largo+1] = '\0';
                largo += 1;
            }
            string_array[num_pal] = strdup(palabra);
            largo = 0;
            num_pal++;
        }else{
            palabra[largo] = str[i];
            palabra[largo+1] = '\0';
            largo ++;
            carga++;
            if(carga > total*0.8){
                realloc(palabra,total*2);
            }
        }
    }


    free(palabra);
    string_array[cant_pal] = NULL;
    return string_array;
}

void join(char** strv, char sep){
        char string[1000];
        int p = 0;
        int largo = 0;
        while (strv[p]) {
            for (size_t i = largo; i < strlen(strv[p]) ; i++) {
                    string[i] = strv[p][i];
            }
        printf("%i\n",largo );
        largo+=strlen(strv[p]);
        p++;
        }
        printf("\n%s\n",string );
    //    return &string;
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
        printf("%s : %i\n",array[i],strlen(array[i]));
    }
    join(array,' ');

free_strv(array);
    return 0;
}
