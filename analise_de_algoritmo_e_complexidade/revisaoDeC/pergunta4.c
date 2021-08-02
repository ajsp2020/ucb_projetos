#include<stdio.h>
#include<locale.h>
#include<stdlib.h>


void pergunta()
{
    printf("Pergunta 4:\n\nUsando uma estrutura de dados com três campos (x, y, z), escreva uma rotina que receba"
"um array deesse tipo estruturado e um inteiro n retorne uuma matriz nXn preenchida com os dados passados no array");
}

int main()
{
    int *array, n;

    printf("Digite o tamanho da matriz");
    scanf("%d", n);

    array = malloc(sizeof(int) * n);


    // Continuar...

    free(array);
}

