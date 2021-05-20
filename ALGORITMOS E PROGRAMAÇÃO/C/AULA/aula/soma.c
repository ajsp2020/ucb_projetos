#include<stdio.h>

int main()
{
	float numero, soma=0;
	int contador;

	for (contador = 0; contador < 5; contador++)
	{
		printf("Digite o numero: ");
		scanf("%f", &numero);
		soma += numero;
	}
	printf("media: %.2f", soma/(contador));
}