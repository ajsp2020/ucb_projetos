#include<stdio.h>
#include<stdlib.h>

// Um algoritmo que receba dois números inteiros e calcule o primeiro elevado ao segundo usando só multiplicações ;

int numeroElevado(num1, num2){
    int i, elevado = 1;
    for (i = 0; i < num2; i++){
        elevado = elevado * num1;
    }

    return elevado;
}


int main(){
    int num1, num2, valor;
    printf("Digite o primeiro valor: "); 
    scanf("%d", &num1);
    printf("Digite o segundo valor :"); 
    scanf("%d", &num2);

    valor = numeroElevado(num1, num2);

    printf("Valor = %d\n", valor);
}