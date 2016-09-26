#include <stdio.h>


int main(void){
	
	int car2 = 1 ;
	int *hola = &car2
    int car[] = {1,2,3,4,5};
    int *puntero = car;
    int *puntero2 = &car;
    printf("%p - %i - %p \n",puntero,*puntero,puntero2);
    return 0;
}
