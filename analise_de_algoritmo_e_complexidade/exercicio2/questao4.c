//Implemente as três soluções para o problema de determinar o k-ésimo menor 
//número em um grupo de n números. Use o quarto algoritmo para ordenação se 
//necessário. Calcule a complexidade de tempo de cada um considerando o pior 
// caso. Compare as complexidades

#include<stdio.h>
#include<stdlib.h>
#include<time.h>

struct array
{
    int *vetor;
};
typedef struct array ARRAY;



void criaArray(ARRAY* a){
    int n, i;
    printf("Digite a quantidade de valores que deseja acrescentar: "); scanf("%d", &n);
    a->vetor = malloc(sizeof(int) * n);

    int segundos = time(0);
    srand(segundos);

    for (i = 0; i < n; i++){
        int numero = rand();
        a->vetor[i] = numero % 1000;
        printf("%d\n", a->vetor[i]);
    }
}

void liberaArray(ARRAY* a){
    free(a->vetor);
}

int main(){

    ARRAY a;

    criaArray(&a);
    liberaArray(&a);


}
