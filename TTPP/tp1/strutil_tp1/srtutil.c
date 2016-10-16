#include "../tda/pila/pila.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
char strdup(const char string);

void error(char *message){
    fprintf(stderr, "%s\n", message);
}



char** split(const char* str, char sep){
    int cant_pal = 1;
    for (size_t i = 0; i < strlen(str) ; i++) {
        if( str[i]==sep) cant_pal++;
    }

    char **string_array = malloc(sizeof(char*) * cant_pal + 1);

    int num_pal = 0;
    char *palabra_stack = malloc(sizeof(char));
        for (size_t i = 0; i < strlen(str); i++) {
            if( str[i]==sep){
                string_array[num_pal] = palabra_stack;
            //    char *palabra_stack = malloc(sizeof(char));
                num_pal++;

            }else{
                char * palabra_stack2 = malloc(sizeof(char) * (strlen(palabra_stack) + 2));
                palabra_stack2[strlen(palabra_stack2)] = str[i];
                palabra_stack2[strlen(palabra_stack2)+1] = '\0';
                free(palabra_stack);
                *palabra_stack = *palabra_stack2;
            }
        }
        string_array[cant_pal+1] = NULL;
        return string_array;
}

void free_strv(char* strv[]){
    int i = 0;
    while (!strv[i]) {
        free(strv[i]);
        i++;
    }
    free(strv);
}


int main(int argc, char const *argv[]) {

    for(int i = 0; i < atoi(argv[2]) ; i++){
    char **array = split(argv[1],' ');
    printf("%s\n",*array[i]);
}
//free_strv(argv[1]);
//    pila_t *pila_polaca = pila_crear();
//    char *cuenta = split(argv[1]," ");
    return 0;
}
