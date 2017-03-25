#include "pila.h"
#include "testing.h"
#include <stddef.h>
#include <stdio.h>


/* ******************************************************************
 *                   PRUEBAS UNITARIAS ALUMNO
 * *****************************************************************/

void pruebas_pila_alumno() {
    pila_t* ejemplo = NULL;

    print_test("Puntero inicializado a NULL", ejemplo == NULL);

    pila_t* pila = pila_crear();
    print_test("Crear pila", pila != NULL);

    int valor=20;

    print_test("apilar 20 en pila es true", pila_apilar(pila,&valor));
    print_test("tope debe ser = 20",pila_ver_tope(pila)==&valor);

    valor=2000;

    print_test("apilar 2000 en pila es true", pila_apilar(pila,&valor));
    print_test("tope debe ser = 2000",pila_ver_tope(pila)==&valor);
    print_test("reapilar 2000 en pila es true debe redimensionarse",pila_apilar(pila,&valor));

    pila_destruir(pila);
    print_test("La pila fue destruida",true);

    pila= pila_crear();
    print_test("Crear pila ",pila !=NULL);
    print_test("Verificar que ver tope en una pila recien creada sea nulo",pila_ver_tope(pila)==NULL);
    print_test("Verificar que desapilar una pila recien creada sea nulo",pila_desapilar(pila)==NULL);
    print_test("Verificar que la pila recien creada este vacia",pila_esta_vacia(pila)==true);

    valor=4;
    print_test("apilar 4 en pila es true",pila_apilar(pila,&valor));
    print_test("Verificar que la pila no este vacia",pila_esta_vacia(pila)==false);

    printf("\n\n");

    printf("\nPRUEBAS CONRTE !\n");

    printf("\n\n");
    pila_t* pila_prueba = pila_crear();
    print_test("Puntero inicializado a NULL", ejemplo == NULL);
    print_test("Pila iniciada vacia         ",pila_esta_vacia(pila_prueba));
    print_test("Pila ver tope               ",pila_ver_tope(pila_prueba)==NULL);
    char a = 'a';
    pila_apilar(pila_prueba, &a);
    print_test("Pila apilar              ",!pila_esta_vacia(pila_prueba));
    int o = 8;
    pila_apilar(pila_prueba, &o);
    print_test("Pila ver tope               ",pila_ver_tope(pila_prueba)==&o);
    pila_desapilar(pila_prueba);
    print_test("Pila desapilar           ",pila_ver_tope(pila_prueba)==&a);
    double y = 12.4;
    for (int e = 0 ; e<=1000 ; e++){
        pila_apilar(pila_prueba, &y);
        print_test("Pila ver tope (for)     ",pila_ver_tope(pila_prueba)==&y);
    }
    char asd[] = "holaocmoestas";
    pila_apilar(pila_prueba,asd);
    print_test("Desapilo el vector que apile", pila_desapilar(pila_prueba)==&asd );
    pila_t *pila_nueva = pila_crear();
    pila_apilar(pila_prueba,pila_nueva);
    print_test("Desapilo el vector que apile", pila_ver_tope(pila_prueba)==pila_nueva );
    pila_destruir(pila_desapilar(pila_prueba));
    pila_destruir(pila_prueba);

    printf("\n\n");
    printf("\n\n");
}
