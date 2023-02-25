/*
    Implementacion del algoritmo de la mochila completa(0,1) pidiendo valores al usuario
    Fecha: 23 de mayo de 2021
    Autor: Pablo Emanuel Mejia Romo
    Version: 1.2
*/

#include <stdio.h>
#include <stdlib.h>

void valores(int [], int, int [], int); //Se declara la funcion que llenará la mochila

int max(int, int);

int main(){
    int p, n;
    //Se pide el numero de piezas que se pretende ingresar a la mochila
    printf("Cuantas piezas va a ingresar: ");
    scanf("%d", &n);
    //Se pide el peso maximo que soporta la mochila
    printf("Cual es el peso maximo que soporta la mochila: ");
    scanf("%d", &p);

    int peso[n+1];
    int vals[n+1];
    //Para esta implementacion es necesario agregar al principio de la lista de pesos y valores un 0
    peso[0]=vals[0]=0;

    //Se piden los pesos de las piezas y el valor
    for(int i = 1; i<=n; i++){
        printf("\nIngresa el peso de la pieza %d: ", i);
        scanf("%d", &peso[i]);
        printf("Ingresa el valor de la pieza %d: ", i);
        scanf("%d", &vals[i]);
    }
    //Se invoca el llenador de mochila
    valores(peso, p, vals, n+1);
}
//Se declara una funcion que servirá para retornar el valor más grande entre 2 numeros
int max(int a, int b){
    if(a>b)
        return a;
    else
        return b;
}

void valores(int pesos[], int pesoM, int vals[], int N){
    //Se declara una matriz auxiliar
    int aux_v[N+1][pesoM+1];
    //Se inicializa  la matriz auxiliar a 0
    for(int i = 0; i<N; i++)
        for(int j = 0; j<=pesoM; j++)
            aux_v[i][j] = 0;

    //se ejecuta el ciclo for que llenará la matriz con valores que servirán para determinar el llenado de la mochila
    for(int i = 1; i<N; i++){
        for(int j = 1; j<=pesoM; j++){
            if(i==1 && j>=pesos[i]){
                aux_v[i][j] = vals[i];
            }else if(j<pesos[i]){
                aux_v[i][j] = aux_v[i-1][j];
            }else{
                aux_v[i][j] = max(aux_v[i-1][j],vals[i] + aux_v[i-1][j-pesos[i]]);
            }
        }
    }
    //se imprimen los valores de la matriz
    for(int i = 0; i<N; i++){
        for(int j = 0; j<=pesoM; j++)
            printf("%d\t", aux_v[i][j]);
        printf("\n");
    }
    int j = pesoM;

    //Se imprimen las piezas que se ingresarán a la mochila
    printf("\nSolo toma las pezas: ");
    for(int i = N-1; i>0; i--){
        if((aux_v[i][j] != aux_v[i-1][j]) && (aux_v[i][j] == (aux_v[i-1][j-pesos[i]] + vals[i]))){
            printf("%d, ", i);
            j-=pesos[i];
        }
    }
}