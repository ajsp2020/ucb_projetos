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

    for(cont = 0; cont <=topo; cont++){
        printf("%d - ", vetor[cont]);
    }

    printf("Topo: %d", topo);

}

void pilha_push(int pilha[TAM], int valor, int* topo){
        if(*topo == TAM - 1){
        printf("Pilha cheia");
    }else{
        *topo = *topo + 1;
        pilha[*topo] = valor; 
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

int retorna_maior_valor(int pilha[TAM], int topo)
{
    int maior = 0;
    for(int i = 0; i < topo; i++){
        for(int j = 0; j < topo -1; j++){
            if(pilha[i] > pilha[j]) {
                maior = i;
            }else{
                maior = j;
            }
        } 
    }
}


int menu()
{
    int opt;

    printf("O que deseja fazer?\n");
    printf("0 - Sair\n");
    printf("1 - Zerar a PILHA\n");
    printf("2 - Exibir a PILH\nA");
    printf("3 - Adicionar um valor a PILHA\n");
    printf("4 - Tirar um valor da PILHA\n");
    printf("5 - Tirar o maior valor da PILHA\n");

    printf("Opcão: "); scanf("%d", &opt);

    return opt;
}

void opcao(int pilha[TAM], int valor, int* topo, int opt){
    switch (opt)
    {
    case 0:
        
        break;
    case 1:

        break;

    case 2:
        imprime_vetor(pilha, topo);
        break;

    case 3:
        printf("Digite um valor que queira adicionar: "); scanf("%d", &valor);
        pilha_push(pilha, valor, &topo); 
        break;

    case 4:
        pilha_pop(pilha, &topo);
        break;

    case 5:

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
