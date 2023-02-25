/*Algoritmo de ordenamiento por método de inserción
Fecha Lunes 29 de marzo de 2021
Autor: María Guadalupe Bastida González 
Versión: 1.0*/

#include <stdio.h>
#include <stdlib.h>
#define tam 600000 /*Servirá para determinar el tamaño del arreglo */

int vector[tam]; /* Se declara un arreglo de numeros enteros en donde serán almacenados los datos a ordenar  */
int i, j, aux; /* Se declaran las variables que servirán para la manipulación del arreglo */

int main(){ /* Se declara un apuntador a archivo el cual contiene los datos que se almacenarán en el arreglo */
    FILE *datos = fopen("numeros.txt", "r");

    /* Se verifica que se haya leído el archivo */
    if(datos == NULL){
        printf("Error al abrir archivo");
        return 1;
    }
    /* Se almacenan los datos del archivo en el arreglo */
    for(i = 0; i<tam; i++){
        fscanf(datos, "%d", &aux);
        vector[i] = aux;
    }

    /* Comienza ordenamiento por inserción */
    for(i = 0; i<tam; i++){
        aux = vector[i];
        for(j = i; j>0 && vector[j-1]>aux; j--)
            vector[j]=vector[j-1];

        vector[j] = aux;
    }
    /* Finaliza ordenamiento por inserción*/

    return 0;
}
