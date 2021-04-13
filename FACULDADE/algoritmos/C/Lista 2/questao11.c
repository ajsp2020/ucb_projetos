#include<stdio.h>
#include<locale.h>

void apresentacao()
{
	printf("Questão 11:\n");
	printf(" Alterar o exercício do triângulo (exercício 9), de forma que o algoritmo apresente no caso de\n"
		 "triângulo o seu tipo : equilátero(todos os lados são iguais), isósceles(dois lados iguais) ou um\n"
		 "outro triângulo qualquer(escaleno).Apresente o algoritmo, fazendo o teste do algoritmo\n"
		 "(chinesinho) ao lado\n");
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

void quetriangulo(float lado[3], char *triangulo, int* ladosiguais) // preciso mudar 
{	
	for (int i = 0; i < 2; i++)
	{
		for (int j = 1; j < 3; j++)
		{
			if (i != j) {
				if(lado[i] == lado [j]) (*ladosiguais)++;
			}
		}
	}
}

void imprimevalor(float lados[3], int ladosiguais)
{
	if (ehtriangulo(lados))
	{
		printf("Pode constituir os lados de um triângulo.\n");

		if (ladosiguais == 1) printf("Triângulo Isóceles");
		else if (ladosiguais == 0) printf("Triângulo Escaleno");
		else printf("Triângulo Equilátero");
	}
	else printf("Não pode constituir os lados de um trângulo.\n");
}

int main()
{
	setlocale(LC_ALL, "");
	float lados[3];
	char triangulo[20];
	int ladosiguais = 0;

	apresentacao();
	pegalados(lados);
	quetriangulo(lados, triangulo, &ladosiguais);
	imprimevalor(lados, ladosiguais);
}