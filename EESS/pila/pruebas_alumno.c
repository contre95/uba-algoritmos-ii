#include "pila.h"
#include "testing.h"
#include <stddef.h>


/* ******************************************************************
 *                   PRUEBAS UNITARIAS ALUMNO
 * *****************************************************************/

void pruebas_pila_alumno() {
    pila_t* ejemplo = NULL;
    pila_t* pila_prueba = pila_crear();
    print_test("Puntero inicializado a NULL", ejemplo == NULL);
    print_test("Pila iniciada vacia         ",pila_esta_vacia(pila_prueba));
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
        print_test("Pila ver tope               ",pila_ver_tope(pila_prueba)==&y);
    }
    char asd[] = "holaocmoestas";
    pila_apilar(pila_prueba,asd);
    print_test("Desapilo el vector que apile", pila_desapilar(pila_prueba)==&asd );
    pila_t *pila_nueva = pila_crear();
    pila_apilar(pila_prueba,pila_nueva);
    print_test("Desapilo el vector que apile", pila_ver_tope(pila_prueba)==pila_nueva );
    pila_destruir(pila_desapilar(pila_prueba));
    pila_destruir(pila_prueba);
}
