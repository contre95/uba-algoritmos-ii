#include "../tda/pila/pila.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

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
    char palabra_stack[] = "";
        for (size_t i = 0; i < strlen(str); i++) {
            if( str[i]==sep){
                char *palabra = malloc(sizeof(char) * strlen(palabra_stack));
                string_array[num_pal] = palabra;
                palabra_stack[0] = *"";
                num_pal++;
            }else{
                strcat(palabra_stack,str[i]);
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


//    pila_t *pila_polaca = pila_crear();
//    char *cuenta = split(argv[1]," ");

    /*
    for(int entrada = 1 ; entrada < argc ; entrada++){
      printf("%s\n",argv[entrada]);
        for(int i=0; i < strlen(argv[entrada]) ; i++){
            char n = argv[entrada][i];
          //  printf("%c\n",n);
            if(isdigit(n)){
              int  num = atoi(&n);
              //printf("apilo el resultado : %i\n",num);
              pila_apilar(pila_polaca,&num);
              //printf("el tope es: %i\n",*(int*)pila_ver_tope(pila_polaca) );
            }
            if(n=='+'){

                //printf("el tope es: %i\n",*(int*)pila_ver_tope(pila_polaca) );
                int *num1 = pila_desapilar(pila_polaca);
                //printf("%i\n",*num1);
                //printf("el tope es: %i\n",*(int*)pila_ver_tope(pila_polaca) );
                int *num2 = pila_desapilar(pila_polaca);
                //printf("%i\n",*num2);
                int resultado = *num1 + *num2;
                //printf("el resultado es : %i\n",resultado );
                pila_apilar(pila_polaca,&resultado);


          }
            if(n=='-'){
              //printf("el tope es: %i\n",*(int*)pila_ver_tope(pila_polaca) );
              int num1 = *(int*)pila_desapilar(pila_polaca);
              //printf("el tope es: %i\n",*(int*)pila_ver_tope(pila_polaca) );
              int num2 = *(int*)pila_desapilar(pila_polaca);
              int resultado = num1 - num2;
              //printf("el resultado es : %i\n",resultado );
              pila_apilar(pila_polaca,&resultado);

          }
            if(n=='*'){
              //printf("el tope es: %i\n",*(int*)pila_ver_tope(pila_polaca) );
              int num1 = *(int*)pila_desapilar(pila_polaca);
              //printf("el tope es: %i\n",*(int*)pila_ver_tope(pila_polaca) );
              int num2 = *(int*)pila_desapilar(pila_polaca);
              int resultado = num1 * num2;
              //printf("el resultado es : %i\n",resultado );
              pila_apilar(pila_polaca,&resultado);

          }
            if(n=='/'){
              printf("el tope es: %i\n",*(int*)pila_ver_tope(pila_polaca) );
              int num1 = *(int*)pila_desapilar(pila_polaca);
              printf("el tope es: %i\n",*(int*)pila_ver_tope(pila_polaca) );
              int num2 = *(int*)pila_desapilar(pila_polaca);
              int resultado = num1 / num2;
              printf("el resultado es : %i\n",resultado );
              pila_apilar(pila_polaca,&resultado);

          }
      }

    int resultado_final = *(int*)pila_desapilar(pila_polaca);
    printf("%i\n",resultado_final);
    }
    pila_destruir(pila_polaca);*/
    return 0;
}
