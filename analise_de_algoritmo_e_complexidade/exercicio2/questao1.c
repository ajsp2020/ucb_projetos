#include<stdio.h>
#include<stdlib.h>
#include<locale.h>

// Um algoritmo que receba um número e imprima os n primeiros termos da série de Fibonacci;

int fibonacci(int n){
    if (n <= 1){  
        printf("%d = ", n);  
        return 1; 
    } 
    else{
        printf("%d * ", n); 
        return n * fibonacci(n - 1); 
    }
}


int main(){
    int n;
    printf("Digite o valor de n: "); scanf("%d", &n);
    int valor = fibonacci(n);

    printf("%d\n", valor);

}
