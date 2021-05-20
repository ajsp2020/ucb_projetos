#include <stdio.h>
#include <locale.h>

void apresentacao()
{
	printf("Qustão 2:\nFaça um algoritmo que leia dois números calcule o resultado da multiplicação de um pelo\n"
		"outro sem utilizar a operação de multiplicação(ou seja, utilizando apenas soma)\n");
}

int multiplicacao(int valor1, int valor2)
{
	if (valor2 == 0) return 0;
	else if (valor2 == 1) return valor1;
	else return valor1 + multiplicacao(valor1, valor2 - 1);
}


void pegaValor(int* valor1, int* valor2)
{
	int status;

		fflush(stdin);
		printf("Digite o primeiro valor: ");
		scanf("%d", valor1);
		printf("Digite o segundo valor: ");
		scanf("%d", valor2);
}

int main()
{
	int valor1, valor2;
	setlocale(LC_ALL, "");
	apresentacao();
	pegaValor(&valor1, &valor2);
	int resultado = multiplicacao(valor1, valor2);
	printf("%d X %d = %d",valor1, valor2, resultado);
}