#include<stdio.h>
#include<stdlib.h>


// Um algoritmo que encontre o maior elemento de uma matriz quadrada cujo tamanho n ( nxn elementos) é passado como parâmetro
int main(){

    int n;

    printf("Digite o tamanho da matriz n x n: ");
    scanf("%d", &n);

    int **matriz;
    matriz = malloc(sizeof(int*) * n);

    for (int i = 0; i < n; i++){
        matriz[i] = malloc(sizeof(int) * n);
    }

    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            printf("Digite o valor da matriz[%d][%d]: ", i + 1, j + 1);
            scanf("%d", &matriz[i][j]);
        }
    }
    int maior = 0;
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            if(maior < matriz[i][j]){
                maior = matriz[i][j];
            }
            
        }
    }

    printf("\n");
    printf("Maior valor da matriz: %d\n",maior);

   for (int i = 0; i < n; i++){
       free(matriz[i]);
   }
    free(matriz);
}
