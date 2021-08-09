//Implemente as três soluções para o problema de determinar o k-ésimo menor 
//número em um grupo de n números. Use o quarto algoritmo para ordenação se 
//necessário. Calcule a complexidade de tempo de cada um considerando o pior 
// caso. Compare as complexidades

#include<stdio.h>
#include<stdlib.h>
#include<time.h> //clock(), CLOCKS_PER_SEC e clock_t

struct array
{
    int tamanho;
    int *vetor;
};
typedef struct array ARRAY;

// Solução para procurar o valor um por um no array
void solucao1(ARRAY* a){
    clock_t t; 
    t = clock();

    int menor = 9999999;
    for(int i = 0; i < a->tamanho; i++){
        if(menor > a->vetor[i]){
            menor = a->vetor[i];
        }
    }
    printf("Valor menor solucao 1 = %d\n", menor);

    t = clock() - t;

    // Imprimindo o tempo
    printf("Tempo de execução da solução 1: %lf milissegundos\n", ((double)t)/((CLOCKS_PER_SEC/1000)));
}
// bubbleSort()
void solucao2(ARRAY* a){

    clock_t t;
    t = clock();

    int i, j, aux;
    for(i = a->tamanho -1; i>= 1; i--){
        for(j = 0; j < i; j++){
            if(a->vetor[j]>a->vetor[j+1]){
                aux = a->vetor[j];
                a->vetor[j] = a->vetor[j + 1];
                a->vetor[j+1] = aux;
            }
        }
    }

    printf("Valor menor solucao 2  = %d\n", a->vetor[0]);

    t = clock() - t;

    // Imprimindo o tempo
    printf("Tempo de execução da solução 2: %lf milissegundos\n", ((double)t)/((CLOCKS_PER_SEC/1000)));
    }


    // QuickSort

    // Trocando os valores
    void troca(int* a, int* b){
        int t = *a;
        *a  = *b;
        *b = t;
    }

    int divide(ARRAY *a, int baixo, int alto){
        int pivo = a->vetor[alto]; // selecionando o ultimo elemento como pivo;
        int i = (baixo - 1); // Index do menor elemento

        for (int j = baixo; j < alto - 1; j++){

            // Se o numero atual for menor ou igual ao pivo
            if (a->vetor[j] <= pivo){
                i++; // incremento o index do menor valor
                troca(&a->vetor[i], &a->vetor[j]);
            }
        }
        troca(&a->vetor[i + 1], &a->vetor[alto]);
        return (i + 1);
    }

    void solucao3(ARRAY* a, int p, int r){
        if(p < r){
            int q;
            q = divide(a, p, r);
            solucao3(a, p, q-1);
            solucao3(a, q+1, r);
        }
        printf("Valor menor solucao 3  = %d\n", a->vetor[0]);
        // Conttinuar .. ver questão da impresssao do menor valor e o calulo do tempop

    }

    void calculaTemmpo(){
        
    }

    void imprimeValor(){
        
    }



void criaArray(ARRAY* a){
    int i;
    printf("Digite a quantidade de valores que deseja acrescentar: "); scanf("%d", &a->tamanho);
    a->vetor = malloc(sizeof(int) * a->tamanho);

    int segundos = time(0);
    srand(segundos);
    printf("Array = { ");
    for (i = 0; i < a->tamanho; i++){
        int numero = rand();
        a->vetor[i] = numero % 1000 ;
        
        printf("%d ", a->vetor[i]);
        
    }
    printf("}\n");
}

void liberaArray(ARRAY* a){
    free(a->vetor);
}

int main(){

    ARRAY a;
    ARRAY b;
    ARRAY c;
s
    criaArray(&b);
    criaArray(&c);

    solucao1(&a);
    solucao2(&b);
    solucao3(&c, 0, a.tamanho -1);

    liberaArray(&a);
    liberaArray(&b);
    liberaArray(&c);
}
