#include <stdio.h>
#include <locale.h>

void apresentacao() 
{
	printf("Questõa 6:\nEscrever um algoritmo que determine se um número inteiro qualquer é PAR ou IMPAR.\n\n");
}

void validavalor(int status, int* valor)
{
	int temp, input;
	while (status != 1)
	{
		while ((temp = getchar()) != EOF && temp != '\n');
		printf("Input inválido....\n");

		printf("Digite um número inteiro: ");
		status = scanf("%d", valor);
	}
}
int ehpar(int numero)
{
	if (numero % 2 == 0) return 1;
	return 0;
}

void peganumero(int* numero)
{
	printf("Digite um número inteiro: ");
	int status = scanf("%d", numero);
	validavalor(status, numero);
}

void imprimeresultado(int numero)
{
	if (ehpar(numero)) printf("O valor é par.");
	else printf("O valor é impar.");
}

int main()
{
	setlocale(LC_ALL, "");

	int numero;
	
	apresentacao();
	peganumero(&numero);
	imprimeresultado(numero);
}