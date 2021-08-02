#include<stdio.h>
#include<locale.h>
#include <stdlib.h> 


void pergunta()
{
	printf("\nPergunta 1:\n\nImplemente uma rotina que retorne todos os valores acima da média de um vetor de inteiro passado como parâmetro.\n");
	// system("pause");
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

void encontraMedia(int* vetor, float* media,int numerosDeElementos)
{
	int soma = 0;
	for (int i = 0; i < numerosDeElementos; i++)
	{
		soma += vetor[i];
	}

	*media = (float)soma /  (float)numerosDeElementos;
}

void devolveValores(int* vetor, float media, int numerosDeElementos)
{
	system("clear");

	printf("Os valores acima da média do vetor são:\n");

	for (int i = 0; i < numerosDeElementos; i++)
	{
		if (vetor[i] > media)
		{
			printf("Valor %d\n", vetor[i]);
		}
	}
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

	float media;
	encontraMedia(vetor, &media, numerosDeElementos);

	devolveValores(vetor, media, numerosDeElementos);

	free(vetor);

	return 0;
}