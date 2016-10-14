#include "strutil.h"
#include <string.h>


char** split(const char* str, char sep){
    cant_pal = 1;
    for (size_t i = 0; i < strlen(str) ; i++) {
        if( str[i]==sep) cant_pal++;
    }

    char *string_array = malloc(size_of(char*) * cant_pal + 1);

    int num_pal = 0
    char palabra_stack[] = ""
        for (size_t i = 0; i < strlen(str); i++) {
            if( str[i]==sep){
                char *palabra = malloc(size_of(char) * strlen(palabra_stack));
                string_array[num_pal] = palabra;
                palabra_stack = "";
                num_pal++;
            }else{
                strcat(palabra,str[i]);
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
