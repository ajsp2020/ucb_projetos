#include <stdio.h>
#include <locale.h>

#define VALOR 2

void apresentacao()
{
	printf("Questão 7:\nLer dois valores numéricos e apresentar a diferença do maior valor pelo menor.\n\n");
}


void validavalor(int status, float* valor, int i)
{
	int temp, input;
	while (status != 1)
	{
		while ((temp = getchar()) != EOF && temp != '\n');
		printf("Input inválido....\n");


		printf("Digite o valor%d: ", i);
		status = scanf("%f", valor);
	}
}

void pegavalores(float valor[VALOR])
{
	for (int i = 0; i < VALOR; i++)
	{
		float numero;
		printf("Digite o valor%d: ", i);
		int status = scanf("%f", &numero);
		validavalor(status, &numero, i);
		valor[i] = numero;
	}
}

void sortedlista(float valor[VALOR])
{
	for (int i = 0; i < VALOR - 1; i++)
	{
		if (valor[i] < valor[i + 1])
		{
			float n = valor[i];
			valor[i] = valor[i + 1];
			valor[i + 1] = n;
		}
	}
}

void calculadiferenca(float valor[VALOR], float* diferenca)
{
	*diferenca = valor[0] - valor[1];
}

void imprimeresultado(float valor[VALOR], float diferenca)
{
	printf("A difrença entre %.2f e %.2f é de: %.2f\n",valor[0], valor[1],  diferenca);
}

int main()
{
	setlocale(LC_ALL, "");

	float valor[VALOR] , diferenca;

	apresentacao();
	pegavalores(valor);
	sortedlista(valor);
	calculadiferenca(valor, &diferenca);
	imprimeresultado(valor, diferenca);
}