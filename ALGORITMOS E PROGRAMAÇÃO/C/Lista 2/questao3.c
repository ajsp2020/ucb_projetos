#include <stdio.h>
#include <locale.h>

#define LADOS 3

void apresentacao() 
{
	printf("Questão 3:\nDado três valores, verificar se eles podem constituir os lados de um triângulo \n(triângulo é uma"
		"figura geométrica onde cada lado é menor do que a soma dos outros dois lados).\n\n");
}

void validavalor(int status, float* valor, int i)
{
	int temp, input;
	while (status != 1 || *valor < 0)
	{
		while ((temp = getchar()) != EOF && temp != '\n');
		printf("Input inválido....\n");
		if (*valor < 0) printf("Não é aceito valores negativos!\n");

		printf("Digite o valor do lado %d: ", i + 1);
		status = scanf("%d", valor);
	}
}

void pegalados(float lados[LADOS]) 
{
	float lado;
	int status;
		for (int i = 0; i < LADOS; i++) 
		{
			printf("Digite o valor do lado %d: ", i + 1);
			status = scanf("%f", &lado);
			validavalor(status, &lado, i);
			lados[i] = lado;
		}	
}

int ehtriangulo(float lados[LADOS]) 
{
	float soma = 0;
	for (int i = 0; i < LADOS; i++) 
	{
		for (int j = 0; j < LADOS; j++) 
		{
			if (i != j) 
			{
				soma += lados[j];
			}
		}
		if (lados[i] > soma) return 0;

		soma = 0;
	}
	return 1;	
}

void imprimevalor(float lados[LADOS]) 
{
	if (ehtriangulo(lados)) printf("Pode constituir os lados de um triângulo.\n");
	else printf("Não pode constituir os lados de um trângulo.\n"); //Resposta: Questão 5
}

int main() 
{
	setlocale(LC_ALL, "");
	float lados[LADOS];

	apresentacao();
	pegalados(lados);
	imprimevalor(lados);

	return 0;
}