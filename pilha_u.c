#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>

#define TAM 10

bool pilha_vazia(int topo){
    if(topo < 0){
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
int pilha_get(int pilha[TAM], int *topo){
    if(pilha_vazia(*topo)){
        printf("A pilha está vazia\n");
        return 0;
    }else{
        return pilha[*topo];
    }
}

void imprime_vetor(int vetor[TAM], int topo){
    int cont;

    printf("\n");

    for(cont = 0; cont <=topo; cont++){
        printf("%d ", vetor[cont]);
    }
    printf("\n");
    for(cont = 0; cont <=topo; cont++){
        printf("^ ");
    }
    if (topo < 0) printf("A PILHA está vazia");

    printf("\nTopo: %d\n", topo);

}

void pilha_push(int pilha[TAM], int valor, int* topo){
        if(pilha_cheia(*topo)){
        printf("Pilha cheia\n");
    }else{
        *topo = *topo + 1;
        pilha[*topo] = valor; 
    }
}

void pilha_pop(int pilha[TAM], int* topo){
    
    printf("\n");

    if(pilha_vazia(*topo)) {
        printf("A Pilha está vazia\n");
    }else{
        printf("Valor Removido: %d\n",pilha[*topo]);
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

int menu()
{
    int opt;

    printf("O que deseja fazer?\n");
    printf("0 - Sair\n");
    printf("1 - Zerar a PILHA\n");
    printf("2 - Exibir a PILHA\n");
    printf("3 - Adicionar um valor a PILHA\n");
    printf("4 - Tirar um valor da PILHA\n");
    printf("Opcão: "); scanf("%d", &opt);

    return opt;
}

void opcao(int pilha[TAM], int valor, int* topo, int opt){
    switch (opt)
    {
    case 0:
        
        break;
    case 1:
        pilha_construtor(pilha, topo);
        break;

    case 2:
        imprime_vetor(pilha, *topo);
        break;

    case 3:
        printf("Digite um valor que queira adicionar: "); scanf("%d", &valor);
        pilha_push(pilha, valor, topo); 
        break;

    case 4:
        pilha_pop(pilha, topo);
        break;

    default:
        break;
    }
}

int main()
{
    int pilha[TAM];
    int topo = -1, valortRetirado; // topo da pilha

    pilha_construtor(pilha, &topo);

    // Caso não possa colocar mais valores

    int opt, valor;

    do{
        opt= menu();
        opcao(pilha, valor, &topo, opt);
    }while(opt);
    


}
