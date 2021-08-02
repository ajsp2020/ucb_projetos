#include<stdio.h>
#include <conio.h>
#include<stdlib.h>

int main()
{
	// Criando um vetor com 80 elementos:
	int i;
	int valores_ini[100];
	int valores_fin[100];
	int soma = 0;

	for (i = 0; i < 100; i++)
	{
		int valor = ("%d", rand() % 100);
		valores_ini[i] = valor;
		printf("%d\t", valores_ini[i]);
		
	}
	printf("\n");

	
	for (i = 0; i < 100; i++)
	{
		int valor = ("%d", rand() % 100);
		valores_fin[i] = valor;
		printf("%d\t", valores_fin[i]);
		
	}
	printf("\n");



	for (i = 0; i < 100; i++)
	{
		if (valores_ini[i] == valores_fin[i])
		{
			soma++;
			printf("SOMA: %d\n", soma);
			printf("POSICAO: %d\n", i);
		}
	}
	printf("\n");

}