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

// Varre o array procurando o menor valor
void solucao1(ARRAY* a){

    int menor = 9999999;
    for(int i = 0; i < a->tamanho; i++){
        if(menor > a->vetor[i]){
            menor = a->vetor[i];
        }
    }
    printf("Valor menor solucao 1 = %d\n", menor);
}
// bubbleSort() -> Ordenando e pegando o menor valorr
void solucao2(ARRAY* a){

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
    }


    

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
    // QuickSort -> Ordenando e pegando o menor valor
    void solucao3(ARRAY* a, int p, int r){
        if(p < r){
            int q;
            q = divide(a, p, r);
            solucao3(a, p, q-1);
            solucao3(a, q+1, r);
        }


    }





void criaArray(ARRAY* a){
    int i;
    printf("Digite a quantidade de valores que deseja acrescentar: "); scanf("%d", &a->tamanho);
    a->vetor = malloc(sizeof(int) * a->tamanho);

    int segundos = time(0);
    srand(segundos);
    //printf("Array = { ");
    for (i = 0; i < a->tamanho; i++){
        int numero = rand();
        a->vetor[i] = numero % 1000 ;
        
        //printf("%d ", a->vetor[i]);
        
    }
    //printf("}\n");
}

void liberaArray(ARRAY* a){
    free(a->vetor);
}

int main(){
    clock_t t; 
    ARRAY a;
    ARRAY b;
    ARRAY c;

    criaArray(&a);
    criaArray(&b);
    criaArray(&c);

    // Tempo solucao 1:
    t = clock();
    solucao1(&a);
    printf("Valor menor solucao 3  = %d\n", c.vetor[0]);
    t = clock() - t;  
    printf("Tempo de execução da solução 3: %lf milissegundos\n", ((double)t)/((CLOCKS_PER_SEC/1000)));

    // Tempo solucao 2:
    t = clock();
    solucao2(&b); 
    printf("Valor menor solucao 2  = %d\n", c.vetor[0]);
    t = clock() - t;  
    printf("Tempo de execução da solução 2: %lf milissegundos\n", ((double)t)/((CLOCKS_PER_SEC/1000)));
    
    // Tempo solucao 3:
    t = clock();
    solucao3(&c, 0, a.tamanho -1);
    printf("Valor menor solucao 3  = %d\n", c.vetor[0]);
    t = clock() - t;  
    printf("Tempo de execução da solução 3: %lf milissegundos\n", ((double)t)/((CLOCKS_PER_SEC/1000)));

    // Liberando os Arrays:
    liberaArray(&a);
    liberaArray(&b);
    liberaArray(&c);
}
