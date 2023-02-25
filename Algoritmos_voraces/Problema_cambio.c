/*
    Implementacion del problema del cambio pidiendo valores al usuario
    Fecha: 16 de mayo de 2021
    Autor: Pablo Emanuel Mejia Romo
    Version: 1.2
*/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void devolverCambio(float, float*, int); //Se declara el prototipo de la función que devolverá el cambio

int main(){
    float valor = 0;
    int n = 0;
    float *monedas;
    printf("Escriba el valor de su cambio: "); // Se pide al usuario el valor del cambio que obtendrá 
    scanf("%f", &valor);
    printf("Cuantas monedas de valores diferentes tiene: ");// Se pide al usuario el numero de monedas diferentes que tiene
    scanf("%d", &n);
    monedas = (float*) malloc(n*sizeof(float));
    printf("Escriba los diferentes valores de las %d monedas: (presione ENTER cuando termine de escribir su valor)\n", n);// Se pide al usuario los valores de las monedas
    for(int i = 0; i<n; i++)
        scanf("%f", &monedas[i]);
    printf("Valor: %.2f\n", valor);
    devolverCambio(valor, monedas, n);// Se llama a la función que devuelve el cambio
    
}

void devolverCambio(float valor, float* monedas, int n){
    int cambio[n];
    for(int i = 0; i<n; i++) //Se inicializa el arreglo con 0 para no tener datos basura
        cambio[i] = 0;
    for(int i = 0; i<n; i++){
        cambio[i] = floor(valor/monedas[i]); //Divide el valor del cambio con las monedas que el usuario ingresó en el mismo orden
        valor -= (cambio[i]*monedas[i]); // Al valor del cambio se le resta la multiplicacion del resultado anterior por el valor de la moneda
        if(valor == 0)// Si el valor es igual a cero se termina el ciclo 
            break;
    }
    for(int i = 0; i<n ; i++) //Se imprime un arreglo que contiene el numero de las monedas que se van a usar; los resultados se muestran en el orden en el que el usuario ingreso el valor de las monedas
        printf("%d ", cambio[i]);
}
