#include "../tda/pila/pila.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

char strdup(const char string);

void error(char *message){
    fprintf(stderr, "%s\n", message);
}



int main(int argc, char const *argv[]) {

    for(int i = 0; i < atoi(argv[2]) ; i++){
    char **array = split(argv[1],' ');
    printf("%s\n",*array[i]);
}

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
    pila_destruir(pila_polaca);
    return 0;
}
