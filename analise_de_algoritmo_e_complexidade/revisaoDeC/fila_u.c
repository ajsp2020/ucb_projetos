#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>
#define TAM 10

void fila_construtor(int* frente, int* tras){
    *frente = 0;
    *tras = -1;
}

bool fila_vazia(int frente, int tras){
    if(frente > tras){
        return true;
    }else{
        return false;
    }
}

bool fila_cheia(int tras){
    if(tras == TAM - 1){
        return true;
    }else{
        return false;
    }
}

void fila_enfileirar(int fila[TAM], int valor, int* tras){

    if(fila_cheia(*tras)){
        printf("Fila Cheia");
    }else{
        *tras = *tras + 1;
        fila[*tras] = valor;
    }
}

void fila_desenfileirar(int fila[TAM], int *frente, int tras){

    if(fila_vazia(*frente, tras)){
        printf("A  fila está vazia!");
    }else{
        printf("O valor %d foi retirado", fila[*frente]);
        fila[*frente] = 0;
        *frente = *frente + 1;
    }


}

void imprime_vetor(int vetor[TAM], int tamanho){
    int cont;

    printf("\n");

    for(cont = 0; cont <TAM; cont++){
        printf("%d - ", vetor[cont]);
    }

}

int fila_tamanho(int tras, int frente){
    return (tras - frente) + 1;
}

int main()
{
    int fila[TAM];

    int frente, tras;
    int valor, valorRetirado;

    fila_construtor(&frente, &tras);
    fila_enfileirar(fila, 5, &tras);
    fila_enfileirar(fila, 7, &tras);
    fila_desenfileirar(fila, &frente, tras);
    fila_desenfileirar(fila, &frente, tras);


    fila_enfileirar(fila, 8, &tras);

    imprime_vetor(fila, fila_tamanho(tras, frente));

    return 0;
}