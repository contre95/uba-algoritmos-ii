#include "lista.h"
#include "testing.h"
#include <stddef.h>
#include <stdio.h>


/* ******************************************************************
 *                   PRUEBAS UNITARIAS ALUMNO
 * *****************************************************************/

void pruebas_lista_alumno(void){
    lista_t *lista_prueba  = lista_crear();
    print_test("Lista vacia es NULL", lista_esta_vacia(lista_prueba) );
    print_test("Lista ver primero de lista vacia es NULL", lista_ver_primero(lista_prueba)==NULL);
    print_test("El largo es == 0 ?",lista_largo(lista_prueba)==0);
    int a = 4;
    print_test("Inserto al principio un 4 ",lista_insertar_primero(lista_prueba,&a));
    print_test("Ver primero es un 4 ?", *(int*)lista_ver_primero(lista_prueba)==a);
    print_test("Ver ultimo es un 4 ?", *(int*)lista_ver_ultimo(lista_prueba)==a);
    print_test("Ver que largo el largo es 1",lista_largo(lista_prueba)==1);
    print_test("Lista no esta vacia", !lista_esta_vacia(lista_prueba));
    int b = 7;
    print_test("Inserto al principio un 7 ",lista_insertar_primero(lista_prueba,&b));
    print_test("Ver primero es un 7 ?", *(int*)lista_ver_primero(lista_prueba)==b);
    print_test("Ver que largo el largo es 2",lista_largo(lista_prueba)==2);
    print_test("Ver ultimo es un 4 ?", *(int*)lista_ver_ultimo(lista_prueba)==a);
    char c = 'a';
    print_test("Inserto a lo ultimo una a ",lista_insertar_ultimo(lista_prueba,&c));
    print_test("Ver que largo el largo es 3",lista_largo(lista_prueba)==3);
    print_test("Ver ultimo es una a", *(char*)lista_ver_ultimo(lista_prueba)==c);
    print_test("Borrar el primero devuelve 7", *(int*)lista_borrar_primero(lista_prueba)==b);
    print_test("Ver primero es un 4 ?", *(int*)lista_ver_primero(lista_prueba)==a);
    lista_destruir(lista_prueba,NULL);

    /* PROBAMOS LOS ITERDORES */

    printf("%s\n\n","PRUEBA DE ITERADORES" );
    lista_t* lista_prueba2 = lista_crear();
    char t = 'a';
    char q = 'b';
    char r = 'c';
    //char d = 'd';

    print_test("inserto el valor  -> a",lista_insertar_ultimo(lista_prueba2,&t));
    print_test("inserto el valor  -> b",lista_insertar_ultimo(lista_prueba2,&q));
    print_test("inserto el valor  -> c",lista_insertar_ultimo(lista_prueba2,&r));
    printf("Cant elementos : %i\n",(int)lista_largo(lista_prueba2));
    lista_iter_t* iterador = lista_iter_crear(lista_prueba2);
    char asd = 'r';
    print_test("inserto un valor al principio - > r",lista_iter_insertar(iterador,&asd));
    printf("Cant elementos : %i\n",(int)lista_largo(lista_prueba2));
    print_test("lista iter avanzar", lista_iter_avanzar(iterador));
    print_test("Borror el elemento a :",*(char*)lista_iter_borrar(iterador)=='a');
    printf("Cant elementos : %i\n",(int)lista_largo(lista_prueba2));
    printf("El elemento es  : %c\n", *(char*)lista_iter_ver_actual(iterador));
    print_test("Borror el elemento actual b  : ",*(char*)lista_iter_borrar(iterador)=='b');
        printf("Cant elementos : %i\n",(int)lista_largo(lista_prueba2));
    print_test("Ultimo elemento es igual a c ", *(char*)lista_iter_ver_actual(iterador) == 'c');
    print_test("lista iter avanzar", lista_iter_avanzar(iterador));
    print_test("iterador esta al final ",lista_iter_al_final(iterador));
    lista_insertar_ultimo(lista_prueba2,&asd);
    print_test("inserto un valor al - > r",lista_iter_insertar(iterador,&asd));
    print_test("iterador no esta mas al final ",!lista_iter_al_final(iterador));
        printf("Cant elementos : %i\n",(int)lista_largo(lista_prueba2));
    print_test("inserto un valor al - > r",lista_iter_insertar(iterador,&asd));
        printf("Cant elementos : %i\n",(int)lista_largo(lista_prueba2));
    print_test("lista iter avanzar1", lista_iter_avanzar(iterador));
    print_test("lista iter avanzar2", lista_iter_avanzar(iterador));
    print_test("lista iter avanzar3", !lista_iter_avanzar(iterador));
    print_test("lista iter avanzar4", !lista_iter_avanzar(iterador));
    printf("Cant elementos : %i\n",(int)lista_largo(lista_prueba2));
    print_test("iterador no esta mas al finalASDASD ",lista_iter_al_final(iterador));
    print_test("iterador esta al final ",lista_iter_al_final(iterador));



    lista_iter_avanzar(iterador);
    print_test("iterador esta al final ",lista_iter_al_final(iterador));


    print_test("lista iter no puede avanzar", !lista_iter_avanzar(iterador));
    char re = 's';
    print_test("Inserto un elemento con el iter al final",lista_iter_insertar(iterador,&re));
    print_test("lista iter avanzar", lista_iter_avanzar(iterador));
    printf("Cant elementos : %i\n",(int)lista_largo(lista_prueba2));
    lista_iter_destruir(iterador);
    lista_destruir(lista_prueba2,NULL);
}
