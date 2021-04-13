#include<stdio.h>
#include<locale.h>


void imprimeresultado();

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

void pegavalores(float valores[3])
{
	float valor;
	for (int i = 0; i < 3; i++)
	{
		printf("Digite o valor %d ",i + 1);
		int status = scanf("%f", &valor);
		validavalor(status, &valor, i);
		valores[i] = valor;
	}
}

void pegaomaior(float valores[3], float* maior)
{
	for (int i= 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			if (valores[i] > valores[j])
			{
				float temp = valores[i];
				valores[i] = valores[j];
				valores[j] = temp;
			}
		}
	}
		
	imprimeresultado(valores);
}


void imprimeresultado(float valores[3])
{
	printf("%.2f\n", valores[0]);
}

int main()
{
	float valores[3];
	float maior;
	setlocale(LC_ALL, "");
	apresentacao();
	pegavalores(valores);
	pegaomaior(valores, &maior);
	
}