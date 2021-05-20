#include<stdio.h>

int main()
{
	int valor;
	printf("Digite o valor: ");
	int status = scanf("%d", &valor);
	int contador = 0;
	if (status = 1 && valor > 0)
	{
		do {
			valor = valor / 10;
			contador++;
		} while (valor != 0);

		printf("%d", contador);
	}
}