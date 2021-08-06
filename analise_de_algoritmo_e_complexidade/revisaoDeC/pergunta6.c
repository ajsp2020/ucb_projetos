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
        printf("Fila Cheia\n");
    }else{
        *tras = *tras + 1;
        fila[*tras] = valor;
    }
}

void fila_desenfileirar(int fila[TAM], int *frente, int tras){

    if(fila_vazia(*frente, tras)){
        printf("A  fila está vazia!\n");
    }else{
        printf("O valor %d foi retirado\n", fila[*frente]);
        fila[*frente] = 0;
        *frente = *frente + 1;
    }


}

void imprime_vetor(int vetor[TAM], int tamanho){
    int cont;

    printf("\n");

    if(tamanho <= 0){
        printf("A fila esta vazia\n");
    }
    else
    {
        for(cont = 0; cont <tamanho; cont++)
        {
            printf("%d ", vetor[cont]);
        }

        printf("\n");
    }

  

}

int fila_tamanho(int tras, int frente){
    return (tras - frente) + 1;
}

int valores_unicos(int vetor[TAM], int unicos[TAM], int *unico, int tamanho){
    *unico = 0;
    int n = 0;
    int i, j;
    for (i = 0; i < tamanho; i++){
        for (j = 0; j < *unico; j++){
            if(vetor[i] == unicos[j]) break;
        }
        
        if (j == *unico)
        {
            unicos[n] = vetor[i];
            printf("unicos[%d] = %d\n", n,  unicos[n]);
            *unico += *unico + 1;
            n++;
        }
    }

    return n;
}

int conta_iguais(int vetor1[TAM], int vetor2[TAM], int tamanho1, int tamanho2)
{
    int i, j, soma = 0;
    for(i = 0; i < tamanho1; i++){
        for(j = 0; j < tamanho2; j++){
            if(vetor1[i] == vetor2[j]) soma++;
        }
    }

    return soma;
}

int menu()
{
    int opt;

    printf("O que deseja fazer?\n");
    printf("0 - Sair\n");
    printf("1 - Exibir as FILAS\n");
    printf("2 - Adicionar um valor a FILA 1\n");
    printf("3 - Adicionar um valor a FILA 2\n");
    printf("4 - Tirar um valor da FILA 1\n");
    printf("5 - Tirar um valor da FILA 2\n");
    printf("6 - Retorna a quantidade de elementos que aparecem simultaneamente nas duas FILAS\n");
    
    printf("Opção: "); scanf("%d", &opt);

    return opt;
}


int main()
{
    int fila1[TAM];
    int fila2[TAM];
    int unicos1[TAM];
    int unicos2[TAM];

    int u[TAM];
    int frente1, frente2, tras1, tras2;
    int valor1, valor2, unico;

    fila_construtor(&frente1, &tras1);
    fila_construtor(&frente2, &tras2);

    int opt, n1, n2, soma;

    do{
        opt = menu();

        switch (opt)
        {
        case 0: break;

        case 1:
            printf("Fila 1:");
            imprime_vetor(fila1, fila_tamanho(tras1, frente1));
            printf("Fila 2:");
            imprime_vetor(fila2, fila_tamanho(tras2, frente2));

            break;

        case 2:

            printf("Digite um valor que queira adcionar na FILA 1: "); scanf("%d", &valor1); printf("\n");
            fila_enfileirar(fila1, valor1, &tras1);

            break;

        case 3:            
        
            printf("Digite um valor que queira adcionar na FILA 2: "); scanf("%d", &valor2);
            fila_enfileirar(fila2, valor2, &tras2);

            break;

        case 4:

            fila_desenfileirar(fila1, &frente1, tras1);
            break;

        case 5:

            fila_desenfileirar(fila2, &frente2, tras2);
            break;

        case 6:
        
            n2 = valores_unicos(fila2, unicos2, &unico ,fila_tamanho(tras2, frente2));
            soma = conta_iguais(unicos1, unicos2, n1, n2);
            printf("Valores que aparecem simultameamente = %d\n", soma);

            break;

            default:

            break;
        }


    }while(opt);

    return 0;
}