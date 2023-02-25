/*
    Implementación de busqueda de un numero máximo y mínimo en un arreglo
    Fecha: 28 de abril de 2021
    Autor: Pablo Emanuel Mejía Romo
    Versión: 1.0
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define n 40 //Se define el tamaño del arreglo

int max(int *, int, int);      //Se define la función que dovolverá el numero más grande de un arreglo
int min(int *, int, int);      //Se define la función que devolverá el numero más pequeño de un arreglo 

int main(){
    srand(time(NULL));
    int numeros[n]; //Se define el arreglo de numeros con tamaño n
    for(int i=0; i<n; i++){  //Se llena el arreglo con numeros aleatorios y se imprimen
        numeros[i]=rand()%n+1; 
        printf("%d\t", numeros[i]);
    }

    printf("\nEl maximo del arreglo es: %d", max(numeros, numeros[0], n-1)); //Se imprime el resultado de la función max
    printf("\nEl minimo del arreglo es: %d", min(numeros, numeros[0], n-1));   //Se imprime el resultado de la función min
    return 0;
}

int max(int *ar, int aux_, int l){
    if(l < 0) //Se verifica que l sea menor a 0
        return aux_;//Si se cumple, se retorna a la variable axiliar y terminando así la función
    else if(aux_ < ar[l]) //Sino se verifica que la variable axiliar sea menor a la posición l del arreglo ar
        aux_ = ar[l]; // Si se cumple, la variable auxiliar tendra como valor a la posición l
    return max(ar, aux_, l-1); //Se retorna a la función, con los mismos parámetros, excepto l, ya que se pasará como l-1
}

int min(int *a, int aux, int l){
    if(l < 0) //Se verifica que l sea menor a 0
        return aux;//Si se cumple, se retorna a la variable axiliar y terminando así la función
    else if(aux > a[l])//Sino se verifica que la variable axiliar sea menor a la posición l del arreglo ar
        aux = a[l]; // Si se cumple, la variable auxiliar tendra como valor a la posición l
    return min(a, aux, l-1); //Se retorna a la función, con los mismos parámetros, excepto l, ya que se pasará como l-1
}