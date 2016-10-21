#include "pila.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
extern char *strdup(const char* s);


int cant_palabras(const char* str, char sep){
    int cant_pal = 0;
    for (size_t i = 0; i < strlen(str) ; i++) {
        if( str[i]==sep) cant_pal++;
    }
    return cant_pal+1;
}

char** split(const char* str, char sep){

    if (!str) return NULL;
    int cant_pal = cant_palabras(str,sep);

    char **string_array = malloc(sizeof(char*) * (cant_pal + 1));

    int num_pal = 0;
    size_t carga = 0;
    int total = 100;
    char *palabra = malloc(total);
    if(!palabra) return NULL;
    palabra[0] = '\0';
    int largo = 0;



/*
    for (size_t i = 0; i < strlen(str); i++) {

        //printf("%s\n","no es barra 0" );
        if(str[i]==sep && str[i-1]==sep){
            palabra[0] = '\0';
            string_array[num_pal] = strdup(palabra);
            if(!string_array[num_pal]) return NULL;
            num_pal++;
        }
        if( (str[i]==sep || str[i+1]=='\0') ){
            if(i==0 && str[i]==sep ) continue;
            if(str[i]!=sep){
                palabra[largo] = str[i];
                palabra[largo+1] = '\0';
                largo++;
                carga++;
            }
            if(str[i-1]==sep && str[i]!=str[strlen(str)-1]) continue;
            string_array[num_pal] = strdup(palabra);
            free(palabra);
            palabra = malloc(total);
            if(!string_array[num_pal] || !palabra) return NULL;
            largo = 0;
            num_pal++;
        }else{
            palabra[largo] = str[i];
            palabra[largo+1] = '\0';
            largo ++;
            carga++;
            if(carga > total-total/5){
                char * aux = realloc(palabra,total*2);
                if (aux) palabra = aux;
                else return NULL;
                total*=2;
            }
        }
    }
*/

//de aca
    for (size_t i = 0; i < strlen(str); i++) {

        if(str[i]!=sep){
            palabra[largo] = str[i];
            palabra[largo+1] = '\0';
            largo ++;
            carga++;
            if(carga > total-total/5){
                char * aux = realloc(palabra,total*2);
                if (aux) palabra = aux;
                else return NULL;
                total*=2;
            }
        }
        if (str[i+1]=='\0' || str[i]==sep){
            string_array[num_pal] = strdup(palabra);
            free(palabra);
            palabra = malloc(total);
            if(!string_array[num_pal] || !palabra) return NULL;
            palabra[0] = '\0';
            largo = 0;
            num_pal++;
        }

}
if(str[strlen(str)-1]==sep){
    palabra[0] = '\0';
    string_array[num_pal] = strdup(palabra);
    free(palabra);
    palabra = malloc(total);
    if(!string_array[num_pal] || !palabra) return NULL;
    largo = 0;
    num_pal++;

}
// a aca


    if(str[0]=='\0') {
        //printf("%s\n","es barra 0" );
        palabra[0] = '\0';
        string_array[num_pal] = strdup(palabra);
        if(!string_array[num_pal]) return NULL;
        num_pal++;
    }

    free(palabra);
    string_array[num_pal] = NULL;
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
        largo+=(int)strlen(strv[p]);
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
