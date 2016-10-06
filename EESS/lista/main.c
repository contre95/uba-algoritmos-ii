#include "testing.h"
#include <stdio.h>

void ejemplo_iteradores(void);
void pruebas_lista_alumno(void);

/* ******************************************************************
 *                        PROGRAMA PRINCIPAL
 * *****************************************************************/

int main(void) {
    /* Ejecuta todas las pruebas unitarias. */
    printf("~~~ PRUEBAS DEL ALUMNO ~~~\n");
    pruebas_lista_alumno();
    //ejemplo_iteradores();
    return failure_count() > 0;
}
