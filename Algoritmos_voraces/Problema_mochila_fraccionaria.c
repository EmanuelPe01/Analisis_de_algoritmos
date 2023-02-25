/*
    Implementación del algoritmo para resolver el problema de la mochila fraccionaria
    Fecha: 12 de mayo de 2021
    Autor: María Guadalupe Bastida Gonzáñez
    Versión: 1.0
*/
#include<stdlib.h>
#include<stdio.h>

struct mochila{
	float valor;// valor del objeto
	float peso;//peso del objeto
	float indice;//indice del objeto
};
int main(){
	int i,n,max,j,cont;
	float pmax,vmax=0;
	printf("Ingresa el numero de objetos que tienes; ");
	scanf("%d",&n);
	mochila elemento[n], aux;
	printf("\nIngresa los valores de cada objeto:	\n");//se asignan los valores de los objetos que se quieren introducir a la mochila
	for(i=0;i<n;i++){
	printf("\ningresa el valor %d:  ",i+1);
	scanf("%f",&elemento[i].valor);
	printf("ingresa el peso %d:  ",i+1);
	scanf("%f",&elemento[i].peso);
	elemento[i].indice=elemento[i].valor/elemento[i].peso;// el elemento indice nos proporciona la mejor opcion de entre los objetos
	}
	printf("\n\n");
	//ordenamietnto de los objetos de mayor a menor según los indices
	for(i=0;i<n;i++){//se puede usar cualquier tipo de ordenamiento, aqui se usa el de selección
	max=i;
	for(j=i+1;j<n;j++){
		if(elemento[j].indice>elemento[max].indice){
			max=j;
		}
	}
	aux=elemento[i];
	elemento[i]=elemento[max];
	elemento[max]=aux;	
	}
	for(i=0;i<n;i++){ // se comprueba el ordenamiento 
		printf("%d: %f , ",i+1,elemento[i].indice);
		printf("%f , ",elemento[i].peso);
		printf("%f  ", elemento[i].valor);
				printf("\n");
	}
	printf("\n\n");
	printf("Ingresa el peso maximo de la mochila; ");// Se asigna el peso total que puede llevar la mochila
	scanf("%f",&pmax);
	//se ingresan los valores a la mochila
	i=0;
	while(pmax>0){
	if(pmax>elemento[i].peso){// metemos los objetos enteros con el mejor indice
		pmax=pmax-elemento[i].peso;
		vmax=vmax+elemento[i].valor;
	}
	else{
	vmax=vmax+(elemento[i].valor*(pmax/elemento[i].peso));// si aun tiene espacio la mochila, mete fracciones del siguiente mejor indice
	pmax=0;
	}
	i++;
}
		printf("El valor maximo que puede llevar la mochila es: %f",vmax);//imprimimos el mejor valor que podemos llevar dentro de la mochila
}