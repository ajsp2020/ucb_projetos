#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>

#define TAM 10

bool pilha_vazia(int topo){
    if(pilha_vazia(topo)){
        return true;
    }else{
        return false;
    }
}

bool pilha_cheia(int topo){
        if(topo == TAM - 1){
        return true;
    }else{
        return false;
    }
}

int pilha_tamanho(topo){
    return topo + 1;
}

// Retorna o ultimo valor na pilha
int pilha_get(int vetor[TAM], int *topo){
    if(pilha_vazia(*topo)){
        printf("A pilha está vazia");
        return 0;
    }else{
        return pilha[*topo];
    }
}

void imprime_vetor(int vetor[TAM], int topo){
    int cont;

    printf("\n");

    for(cont = 0; cont <TAM; cont++){
        printf("%d - ", vetor[cont]);
    }

    printf("Topo: %d", topo);

}

void pilha_push(int pilha[TAM], int valor, int* topo){
        if(*topo == TAM - 1){
        printf("Pilha cheia");
    }else{
        *topo = *topo + 1;
        pilha[*topo] = 5; 
    }
}

void pilha_pop(int pilha[TAM], int* topo){
    
    printf("\n");

    if(pilha_cheia(*topo)) {
        printf("A Pilha está vazia");
    }else{
        printf("Valor Removido: %d",pilha[*topo]);
        pilha[*topo] = 0;
        *topo = *topo - 1; 
    }
}

void pilha_construtor(int pilha[TAM], int* topo){

    //Coloca o topo negativo para indicar uma pilhav azia
    *topo = -1;

    int cont;

    for(cont = 0; cont < TAM; cont++)
    {
        pilha[cont] = 0;
    }
}

int main()
{
    int pilha[TAM];
    int topo = -1, valortRetirado; // topo da pilha

    pilha_construtor(pilha, &topo);

    imprime_vetor(pilha, topo);

    // Caso não possa colocar mais valores

    pilha_push(pilha, 5, &topo); 
    imprime_vetor(pilha, topo);

    pilha_push(pilha, 7, &topo);
    imprime_vetor(pilha, topo);

    pilha_pop(pilha, &topo);
    imprime_vetor(pilha, topo);

    imprime_vetor(pilha);



}
