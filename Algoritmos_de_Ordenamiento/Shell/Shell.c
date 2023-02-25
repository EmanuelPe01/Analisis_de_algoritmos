/*Algoritmo de ordenamiento por método de Shell
Fecha Lunes 29 de marzo de 2021
Autor: Pablo Emanuel Mejía Romo
Versión: 1.1*/

#include <stdio.h>
#include<time.h>
#include<stdlib.h>
#define tam 5000 /*Servirá para determinar el tamaño del arreglo */


void shell(int [], int , int); /* Se declara el prototipo de la función que ordenará el arreglo*/
int vector[tam]; /* Se declara un arreglo de numeros enteros en donde serán almacenados los datos a ordenar  */
int n = tam, i, j, u; /* Se declaran las variables que servirán para la manipulación del arreglo */

int main(){
    FILE *datos = fopen("numeros.txt", "r"); /* Se declara un apuntador a archivo el cual contiene los datos que se almacenarán en el arreglo */

    /* Se verifica que se haya leído el archivo */
    if(datos == NULL){
        printf("Error al leer archiivo");
        return 1;
    }
    /* Se almacenan los datos del archivo en el arreglo */
    for (i = 0; i<tam; i++){
        fscanf(datos, "%d", &u);
        vector[i] = u;
    }
     
    /* Comienza método de ordenamiento */
    while (n>1)
    {
        n/=2; 
        /* Se llama a la suncion shell */
        shell(vector, tam, n);
    }
    /* Finaliza método de ordenamiento */

    return 0;
}

void shell(int a[], int n, int inter){
    int j, aux, i;
    /* Comienza ordenamiento por shell */
    for(i = inter; i<n; i+=inter){
        aux = a[i];
        for (j = i; j>=inter && a[j-inter]>aux; j-=inter)
        {
            a[j] = a[j-inter];
        }
        a[j] = aux;
    }
    /* Finaliza rodenamiento por shell */
}
