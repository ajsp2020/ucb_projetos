#include <stdio.h>
#include <locale.h>



void apresentacao() 
{
	printf("Questão 3:\n");
	printf("Dado três valores, verificar se eles podem constituir os lados de um triângulo (triângulo é uma"
		"figura geométrica onde cada lado é menor do que a soma dos outros dois lados).\n");
}

void validalado(int status, float* lado, int i) 
{
	int temp, input;
	while (status != 1) 
	{
		while ((temp = getchar()) != EOF && temp != '\n');
		printf("Input inválido... \nDigite o valor do lado %d: ", i + 1);
		status = scanf("%f", lado);
	}
}

void pegalados(float lados[3]) 
{
	float lado;
	int status;
		for (int i = 0; i < 3; i++) 
		{
			printf("Digite o valor do lado %d: ", i + 1);
			status = scanf("%f", &lado);
			validalado(status, &lado, i);
			lados[i] = lado;
		}	
}
int ehtriangulo(float lados[3]) 
{
	float soma = 0;
	for (int i = 0; i < 3; i++) 
	{
		for (int j = 0; j < 3; j++) 
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

void imprimevalor(float lados[3]) 
{
	if (ehtriangulo(lados)) printf("Pode constituir os lados de um triângulo.\n");
	else printf("Não pode constituir os lados de um trângulo.\n");
}

int main() 
{
	setlocale(LC_ALL, "");
	float lados[3];

	apresentacao();
	pegalados(lados);
	imprimevalor(lados);
}