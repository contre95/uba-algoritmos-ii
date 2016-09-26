#include "cola.h"
#include "testing.h"
#include <stddef.h>
#include <stdio.h>


/* ******************************************************************
 *                   PRUEBAS UNITARIAS ALUMNO
 * *****************************************************************/

void pruebas_cola_alumno() {
    cola_t* cola_prueba = cola_crear();
    print_test("Creo la cola ", cola_prueba);
    print_test("Cola creda vacia ", cola_esta_vacia(cola_prueba));
    print_test("Cola ver primero", !cola_ver_primero(cola_prueba));
    print_test("Cola desencola null pq esta vacia", cola_desencolar(cola_prueba)==NULL);

    int numero = 100;
    print_test("Encolo el entero 100 ", cola_encolar(cola_prueba,&numero));
    int* cien  = cola_ver_primero(cola_prueba);
    print_test("Veo que el primero sea 100", *cien==100);
    print_test("Me fijo si la cola esta vacia", !cola_esta_vacia(cola_prueba));
    print_test("Desencolo el 100", cola_desencolar(cola_prueba));

    int a=2;
    int b =3;
    int c=2;
    printf("%s\n","Encolo 2, 3 y 2 en ese orden:" );
    cola_encolar(cola_prueba,&a);
    cola_encolar(cola_prueba,&b);
    cola_encolar(cola_prueba,&c);
    int *aa = cola_ver_primero(cola_prueba);
    int *aaa = cola_desencolar(cola_prueba);
    int *bb = cola_desencolar(cola_prueba);
    print_test("Veo que el primero sea 2",*aa==2);
    print_test("Veo que al desencolar desencola el 2",*aaa==2);
    print_test("Veo que al desencolar desencola el 2",*bb==3);

    cola_destruir(cola_prueba,NULL);
}
