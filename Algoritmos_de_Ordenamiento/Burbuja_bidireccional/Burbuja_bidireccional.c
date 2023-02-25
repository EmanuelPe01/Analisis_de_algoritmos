/*Algoritmo de ordenamiento por método de Burbuja bidireccional
Fecha Lunes 29 de marzo de 2021
Autor: Pablo Emanuel Mejía Romo
Versión: 1.0*/

#include <stdio.h>
#include <stdlib.h>
#define tam 400000 /*Servirá para determinar el tamaño del arreglo */


int vector[tam]; /* Se declara un arreglo de numeros enteros en donde serán almacenados los datos a ordenar  */
int i, bandera, comienzo=0, fin=tam, actual=0, direccion=1, aux; /* Se declaran las variables que servirán para la manipulación del arreglo */

int main(){
    FILE *datos = fopen("numeros.txt", "r"); /* Se declara un apuntador a archivo el cual contiene los datos que se almacenarán en el arreglo */

	/* Se verifica que se haya leído el archivo */
    if(datos == NULL){
        printf("Error al leer archiivo");
        return 1;
    }
    /* Se almacenan los datos del archivo en el arreglo */
     for (i = 0; i<tam; i++){
        fscanf(datos, "%d", &aux);
        vector[i] = aux;
    }
	
	/* Comienza ordenamiento por burbuja bidereccional */
    do{
        bandera = 0;
        while (((direccion == 1)&&(actual<fin)) || ((direccion == -1)&&(actual>comienzo))) /* Se hacen dos condiciones para optimizar el codigo, es decir, tambien se puede hacer con 2 ciclos for */
        {
            if(vector[actual] < vector [actual-1]){ 
                aux = vector[actual];					
                vector[actual] = vector[actual-1];
                vector[actual-1] = aux; 			
                bandera = 1;
            }
            actual += direccion; 
    	}
            
        if(direccion == 1) fin--; else comienzo++;
		direccion = -direccion; 
            
    }while(bandera == 1);
    /* Finaliza ordenamiento por burbuja bidireccional */ 
    return 0;
}

