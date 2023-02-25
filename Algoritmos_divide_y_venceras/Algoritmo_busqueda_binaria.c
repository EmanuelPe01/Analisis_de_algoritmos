/*
    Implementación del algoritmo de búsqueda binaria recursiva con previo ordenamiento de un arreglo 
    Fecha: 28 de abril de 2021
    Autores: María Guadalupe Bastida Gonzáñez y Pablo Emanuel Mejía Romo
    Versión: 1.0
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#define N 40

void Quick_sort(int *, int , int ); //Se define la función en donde se implementar el ordenamiento por quiksort
int busqueda_binaria(int *, int, int, int); //Se define la funcón en donde se implementa el algoritmo de búsqueda binaria

int main(){
    int numeros[N];
    srand(time(NULL));

    for(int i=0; i<N; i++)
        numeros[i]=rand()%N+1;       
		
    int busqueda = rand()%N+1; //Definimos una variable que almacenará el dato buscado dentro del arreglo
    Quick_sort(numeros, 0, N-1); // Se ordena el arreglo 
    int resultado = busqueda_binaria(numeros, busqueda, 0, N-1); //Se realiza la busqueda binaria

    for(int i = 0; i<N; i++)
        printf("%d\t", numeros[i]);

    if(resultado>=0) //Verifica que el resultado de la función sea un numero positivo
        printf("\nEl numero %d se encuentra en la posicion %d del arreglo\n", busqueda, resultado);//Se imprime el resultado, es decir, la posición en donde se encuentra el numero que se buscó
    else 
        printf("\nEl numero %d no se encuentra en el arreglo", busqueda);
    return 0;
}

int busqueda_binaria(int *array, int busqueda, int izquierda, int derecha){

    if(izquierda > derecha) //Si esta condición se cumple, el numero buscado no está en el arreglo y devuelve un numero negativo
        return -1;
    int indice = floor((izquierda + derecha) /2); //Se redondea el resultado de la división, ya que si no se hace, este tipo de dato solo toma la parte entera
    int medio = array[indice];

    if(busqueda == medio)//Si se cumple, termina la recursión y devuelve la posición
        return indice;

    if(busqueda < medio)//Si se cumple, el numero esta en la derecha 
        derecha = indice-1;
    else  //Sino el numero se encuetra a la izquierda
        izquierda = indice+1;
    
    return busqueda_binaria (array, busqueda, izquierda, derecha);
}

void Quick_sort(int *array, int ini, int fin){
    int piv, izq, der, med;
	if(ini<fin){
        piv=array[ini]; // inicializamos el pivote con el primer elemento 
		izq=ini;
		// se ubican los elementos a la izquierda y derecha del pivote
        der=fin;
		while(izq<der){
			while(der>izq && array[der]>piv)
	    		der--;
			if(der>izq){
				array[izq]=array[der];
				izq++;
			}
			while(izq<der && array[izq]<piv)
		    	izq++;
			if(izq<der){
				array[der]=array[izq];
				der--;
			}
		}
		array[der]=piv;// ubica el pivote en su posición
		med=der;
		// llamadas recursivas
		Quick_sort(array,ini,med-1);
	    Quick_sort(array,med+1,fin);
	}
}
