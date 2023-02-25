/*Algoritmo de ordenamiento por método de selección
Fecha Lunes 29 de marzo de 2021
Autor: María Guadalupe Bastida González 
Versión: 1.0*/

#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#define tam 600000 /*Servirá para determinar el tamaño del arreglo */

int vector[tam]; /* Se declara el arreglo de numeros enteros en donde serán almacenados los datos a ordenar  */
int i, j, k, aux,u;	/* Se declaran las variables que servirán para la manipulación del arreglo */

int main() {
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
	for (k = 0; k <= tam-1; k++) {   	/* Se ordena el arreglo de enteros por selección */
		i = k;
		aux = vector[k];
		for (j = k + 1; j <= tam; j++) {
			if (vector[j] < aux) {
				i = j;
				aux = vector[i];
			}
		}
		vector[i] = vector[k];
		vector[k] = aux;
	}
	
		fclose(datos); /* Se cierra el archivo */
}
