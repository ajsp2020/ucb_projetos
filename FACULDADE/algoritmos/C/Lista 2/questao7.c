#include <stdio.h>
#include <locale.h>

void apresentacao()
{
	printf("Questão 7:\n");
	printf("Ler dois valores numéricos e apresentar a diferença do maior valor pelo menor.\n\n");
}

void validavalor(int status, float* numero, int i)
{
	int temp, input;
	while (status != 1)
	{
		while ((temp = getchar()) != EOF && temp != '\n');
		printf("Input inválido... Digite o valor%d", i);
		status = scanf("%f", numero);
	}
}

void pegavalores(float valor[2])
{
	for (int i = 0; i < 2; i++)
	{
		float numero;
		printf("Digite o valor%d: ", i);
		int status = scanf("%f", &numero);
		validavalor(status, &numero, i);
		valor[i] = numero;
	}
}

void sortedlista(float valor[2])
{
	for (int i = 0; i < 2; i++)
	{
		if (valor[i] < valor[i + 1])
		{
			float n = valor[i];
			valor[i] = valor[i + 1];
			valor[i + 1] = n;
		}
	}
}

void calculadiferenca(float valor[2], float* diferenca)
{
	*diferenca = valor[0] - valor[1];
}

void imprimeresultado(float valor[2], float diferenca)
{
	printf("%f\t %f\n", valor[0], valor[1]);
	printf("%f\n", diferenca);
}

int main()
{
	float valor[2] , diferenca;
	setlocale(LC_ALL, "");
	apresentacao();
	pegavalores(valor);
	sortedlista(valor);
	calculadiferenca(valor, &diferenca);
	imprimeresultado(valor, diferenca);
}