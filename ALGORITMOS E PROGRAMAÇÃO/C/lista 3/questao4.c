#include <stdio.h>
#include <locale.h>

float calculaValor(float soma, float n)
{
	if (n == 0.0) return soma;
	else
	{
		soma = soma + 1 /(n);
		return calculaValor(soma, n - 1);
	}
}


int main()
{
	float n;
	float valor, soma;
	printf("Digite o valor de n: ");
	scanf("%f", &n);
	valor = calculaValor(0, n);
	printf("%.2f", valor);
}