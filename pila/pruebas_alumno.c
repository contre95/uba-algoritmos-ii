#include "pila.h"
#include "testing.h"
#include <stddef.h>


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
    print_test("comprobar que la capcidad de pila sea 4",pila_ver_capacidad(pila)==4);

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

}
