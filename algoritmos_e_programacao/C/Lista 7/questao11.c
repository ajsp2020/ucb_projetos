#include<stdio.h>
#define QTD_FUNCIONARIOS 5

int main()
{
	float salario[QTD_FUNCIONARIOS], soma = 0, media;
	
	for (int i = 0; i < QTD_FUNCIONARIOS; i++)
	{
		printf("Digite o Salario: ");
		scanf("%f", &salario[i]);
		soma += salario[i];
	}
	for (int i = 0; i < QTD_FUNCIONARIOS; i++)
	{
		for (int j = 0; j < QTD_FUNCIONARIOS - i - 1; j++)
		{
			if (salario[j] > salario[j + 1])
			{
				float temp = salario[j + 1];
				salario[j + 1] = salario[j];
				salario[j] = temp;
			}
		}
	}

	media = soma / QTD_FUNCIONARIOS;

	printf("Maior salario: %.2f\n", salario[QTD_FUNCIONARIOS - 1]);
	printf("Menor salario: %.2f\n", salario[0]);
	printf("Media salario: %.2f\n", media);

}