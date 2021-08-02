#include<stdio.h>
#include<locale.h>
#include<stdlib.h>


int somador = 0;

void pergunta()
{
	printf("\nPergunta 3:\n\nImplemente uma rotina RECURSIVA que some os elementos de um vetor de tamanho n\n");
}

void tamanhoDoVetor(int* numerosDeElementos)
{
	printf("Digite a quantidade de elementos no vetor: ");
	scanf("%d", numerosDeElementos);
}

void alocaMemoria(int** vetor, int numerosDeElementos)
{
	*vetor = malloc(sizeof(int) * numerosDeElementos);
}

void adicionaValores(int *vetor, int numerosDeElementos)
{
	for (int i = 0; i < numerosDeElementos; i++)
	{
		system("clear");
		printf("Digite o valor do elemento %d: ", i + 1);
		scanf("%d", &vetor[i]);	
	}
}

int somaValores(int* vetor, int numerosDeElementos)
{
	
    if (numerosDeElementos == 0) return 0;  

    else
    {
		somador = vetor[0] + somaValores(vetor + 1, numerosDeElementos - 1);
        return  somador;
    }
}

void devolveValores(int soma)
{
	system("clear");
	printf("soma = %d\n", soma);
}

int main()
{
	setlocale(LC_ALL, "");

	pergunta();

	int numerosDeElementos;
	tamanhoDoVetor(&numerosDeElementos);

	int* vetor;
	alocaMemoria(&vetor, numerosDeElementos);

	adicionaValores(vetor, numerosDeElementos);
    
	int soma = somaValores(vetor, numerosDeElementos);

	devolveValores(soma);

	free(vetor);

	return 0;
}