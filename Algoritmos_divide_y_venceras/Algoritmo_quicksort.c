/*
    Implementación del algoritmo de ordenamiento por Quicksort 
    Fecha: 28 de abril de 2021
    Autor: María Guadalupe Bastida Gonzáñez
    Versión: 1.0
*/
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define N 40
void Quick_sort(int *, int , int ); //Se define la función en donde se implementar el ordenamiento por quiksort
int main( int argc, char *argv[]){
	int L[N],i; //Definimos un arreglo de N numeros 
	srand(time(NULL));  
	for(i=0; i<N; i++){
		L[i]=rand()%N+1; //Llenamos el arreglo con numeros aleatarios  
	}
	Quick_sort(L,0,N-1);
	for(i=0; i<N; i++){
		printf("%d\t",L[i]); // se imprime el arreglo ya ordenado por Quicksort
	}
	return 0;
}
	void Quick_sort(int L[], int ini, int fin){
		int piv, izq, der, med; // el medio es la división media del arreglo
		//caso base
		if(ini<fin){
			piv=L[ini]; // inicializamos el pivote con el primer elemento 
			izq=ini;
			// se ubican los elementos a la izquierda y derecha del pivote
			der=fin;
			while(izq<der){
				while(der>izq && L[der]>piv) //ubica a los valores menores a la izquierda
				der--;
				if(der>izq){
					L[izq]=L[der];
					izq++;
				}
				while(izq<der && L[izq]<piv) //ubica a los valores mayores a la derecha
				izq++;
				if(izq<der){
					L[der]=L[izq];
					der--;
				}
			}
			L[der]=piv; // ubica el pivote en su posicion
			med=der;
			// llamadas recursivas de la función 
			Quick_sort(L,ini,med-1);
			Quick_sort(L,med+1,fin);
		}
	}