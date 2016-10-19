#include "pila.h"
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
    int total = 100;
    char *palabra = malloc(total);
    if(!palabra) return NULL;
    int largo = 0;

    for (size_t i = 0; i < strlen(str); i++) {

        if( str[i]==sep || i==strlen(str)-1){

            if(i==strlen(str)-1){
                palabra[largo] = str[i];
                palabra[largo+1] = '\0';
                largo += 1;
            }
            string_array[num_pal] = strdup(palabra);
            if(!string_array[num_pal]) return NULL;
            largo = 0;
            num_pal++;
        }else{
            palabra[largo] = str[i];
            palabra[largo+1] = '\0';
            largo ++;
            carga++;
            if(carga > total-total/5){
                //printf("%s : %i : %i : %i\n","Aca realloque !",total-total/5,total,total*2);
                char * aux = realloc(palabra,total*2);
                if (aux) palabra = aux;
                else return NULL;
                total*=2;
            }
        }
    }


    free(palabra);
    string_array[cant_pal] = NULL;
    return string_array;
}

char* join(char** strv, char sep){
        int i = 0;
        size_t tam = 0;
        while(strv[i]){
            tam+=strlen(strv[i])+1;
            i++;
        }
        char *string = malloc(sizeof(char)*tam);
        if(!string) return NULL;
        int p = 0;
        int largo = 0;
        while (strv[p]) {
            //printf("%s\n",strv[p]);
            for (size_t x =0; x < (strlen(strv[p])) ; x++) {
                    string[largo + x] = strv[p][x];
            }
        largo+=( strlen(strv[p]));
        p++;
        if(p!=i) string[largo] = sep;
        largo++;
        }
    return string;
}

void free_strv(char* strv[]){
    int i = 0;
    while (strv[i]) {
        free(strv[i]);
        i++;
    }
    free(strv);
}
/*
int main(int argc, char const *argv[]){
    if(argc <= 1){
        error("CANTIDAD DE PARAMETROS INVALIDOS !");
        return 1;
    }

    char **array = split(argv[1],' ');
    for(int i = 0; i < cant_palabras(argv[1],' ')  ; i++){
        printf("%s : %i\n",array[i],strlen(array[i]));
    }
    char * stringg = join(array,'');
    printf("%s\n",stringg);
    free(stringg);
    free_strv(array);

    return 0;
}*/
