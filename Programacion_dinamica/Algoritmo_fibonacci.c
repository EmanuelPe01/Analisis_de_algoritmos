/*
    Implementacion del algoritmo Fibonacci
    Fecha: 23 de mayo de 2021
    Autor: Pablo Emanuel Mejia Romo
    Version: 1.2
*/
#include <stdio.h>
#include <stdlib.h>
#define Max 100

long long bottom(long long);
long long top(long long);
long long memo_f[Max];
void llenar(){                      //
    for(int i = 0; i<Max; i++)      // -1 denota que no fue calculado
        memo_f[i] = -1;             //
}


int main(){
    int n;
    printf("Escriba el n-esimo que quiere calcular: ");
    scanf("%d", &n);
    llenar();
    printf("N-esimo elemento por Bottom-up: %d", bottom(n));
    printf("\nN-esimo elemento por Top-down: %d", top(n));
}

long long bottom(long long n){
    long long fib[n+1];
    fib[0] = 0;
    fib[1] = 1;
    for(int i = 2; i<=n; i++)
        fib[i] = fib[i-1] + fib[i-2];
    
    return fib[n];
}

long long top (long long n){
    if(n==0 || n==1)
    //fibo[0] = 0, fibo[1] = 1
        return n;
    else if(memo_f[n] == -1){
        //Este fibonacci nunca se calcula
        //Me guarda el resultado
        memo_f[n] = top(n-1) + top(n-2);
        return memo_f[n];
    }else
        return memo_f[n];
    
        
}
