/*
    Implementación del algoritmo de ordenamiento por Merge Sort
    Fecha: 28 de abril de 2021
    Autor: María Guadalupe Bastida Gonzáñez
    Versión: 1.0
*/
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define N 40
void Merge_sort(int *, int , int ); //Se define la función en donde se implementar el ordenamiento por Merge Sort
void Mezcla(int *, int, int, int ); //Se define la función en donde se realiza el ordenamiento por mezcla
int main( int argc, char *argv[]){
	srand(time(NULL));
	int L[N],i; //Definimos un arreglo de N numeros 
	srand(time(NULL));  
	for(i=0; i<N; i++){
		L[i]=rand()%N+1; //Llenamos el arreglo con numeros aleatarios  
	}
	Merge_sort(L,0,N-1);
	for(i=0; i<N; i++){
		printf("%d\t",L[i]); // se imprime el arreglo ya ordenado por Merge Sort
	}
	return 0;
}
void Merge_sort(int L[], int ini, int fin){
	int m;
	m=(ini+fin)/2; // divide el vector o lista en dos 
	if(ini<fin){
		Merge_sort(L, ini, m); //llamadas recursivas
		Merge_sort(L, m+1, fin);
		Mezcla(L, ini, m, fin);	// proceso de mezcla para ir ordenando y juntando la lista
	}
}
void Mezcla( int L[], int ini, int m, int fin){
	int aux[N],i,j,k,t; //vector aux sonde se copiara la lista, los subindices i y j recorren las sublistas respectivamente
	k=0;
	i=ini;
	j=m+1;
	//ciclo que se encarga de la mezcla 
	while(i<=m && j<=fin){
		k++;
		if(L[i]<L[j]){
			aux[k]=L[i];
			i++;
		}
		else{
			aux[k]=L[j];
			j++;
		}
	}
	// si quedaron elementos en la primera sublista se los pasa al vector aux
	for (t=i;t<=m;t++){
		k++;
		aux[k]=L[t];
	}
		// si quedaron elementos en la segunda sublista se los pasa al vector aux 
	for (t=j;t<=fin;t++){
		k++;
		aux[k]=L[t];
	}
		// se copia el aux a la lista original 
	for (t=1;t<=k;t++){
		L[ini+t-1]=aux[t];
	}
}