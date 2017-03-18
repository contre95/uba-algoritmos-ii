#include "tp0.h"

void swap (int *x, int *y) {
	int n = *x;
	*x = *y;
	*y =  n;
}

int maximo(int vector[], int n) {
	if (n==0){
		return -1;
	}
	int max_parcial = vector[0];
	int posicion = 0;
	for (int i = 0 ; i<n ; i++){
		if (vector[i] > max_parcial){
			max_parcial = vector[i];
			posicion = i;
		}
	}
	return posicion;
}

int comparar(int vector1[], int n1, int vector2[], int n2) {
	if (n1==0 && n2>n1) { return -1; }
	if (n2==0 && n1>n2) { return 1; }
		for(int i=0 ;  i<n1 && i<n2  ; i++){
			if (vector1[i]!=vector2[i]){
				if (vector1[i]<vector2[i]){
					return -1;
				}else{
					return 1;
				}
			}
		}
	if (n1<n2){ return -1;  }
	if (n2<n1){ return 1;  }
	return 0;
}

void seleccion(int vector[], int n) {
	int cont = n;
	for (int a=0;a<n;a++){
		int max = maximo(vector,cont);
		swap( &vector[max], &vector[cont-1]);
		cont --;
	}
}
