#include<stdio.h>
#include<locale.h>
#include <stdlib.h>

#define VALORES 3


void apresentacao()
{
	printf("Questão 14:\nFazer um algoritmo que leia três valores, determine e imprima o maior deles.\n");
}

void validavalor(int status, float* valor, int i)
{
	int temp, input;
	while (status != 1)
	{
		while ((temp = getchar()) != EOF && temp != '\n');
		printf("Input inválido....\n");
		printf("Digite o valor %d ",i + 1);

		status = scanf("%f", valor);
	}
}

void pegavalores(float *valores, int num_valores)
{
	float valor;
	for (int i = 0; i < num_valores; i++)
	{
		printf("Digite o valor %d ",i + 1);
		int status = scanf("%f", &valor);
		validavalor(status, &valor, i);
		valores[i] = valor;
	}
}

void pegaomaior(float *valores, int num_valores, float* maior)
{
	if (num_valores < 1)
	{
		*maior = valores[0];
		return;
	}
	for (int i = 0; i < num_valores; i++)
	{
		if (valores[i] < valores[i + 1])
		{
			float temp = valores[i];
			valores[i] = valores[i + 1];
			valores[i + 1] = temp;
		}
	}
	pegaomaior(valores, num_valores - 1, maior);
	
}

void imprimeresultado(float maior)
{
	printf("O maior número é: %.2f\n", maior);
}

int main()
{
	int num_valores = VALORES;
	float *valores = malloc(sizeof(float*) * num_valores);
	float maior;
	setlocale(LC_ALL, "");
	apresentacao();
	pegavalores(valores, num_valores);
	pegaomaior(valores, num_valores, &maior);
	imprimeresultado(maior);
	free(valores);
}