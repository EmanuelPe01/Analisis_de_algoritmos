/*Algoritmo de ordenamiento por método de Burbuja 
Fecha Lunes 29 de marzo de 2021
Autor: Pablo Emanuel Mejía Romo
Versión: 1.0*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define tam 200000 /*Servirá para determinar el tamaño del arreglo */

int vector[tam]; /* Se declara un arreglo de numeros enteros en donde serán almacenados los datos a ordenar  */
int aux, i, j; /* Se declaran las variables que servirán para la manipulación del arreglo */

int main(){
    FILE *datos = fopen("numeros.txt", "r"); /* Se declara un apuntador a archivo el cual cotiene los datos que se almacenarán en el arreglo */

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

    /* Comienza ordenamiento por burbuja */
    for(i= 0; i<tam; i++){
        for (j = 0; j < tam-1; j++){
            if(vector[j] > vector [j+1]){
                aux = vector[j];
                vector[j] = vector[j+1];
                vector[j+1] = aux; 
            }
        }
    }
    /* Finaliza ordenamiento por burbuja */
    return 0;
}
