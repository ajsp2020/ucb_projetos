#include <stdio.h>

int main()
{
	int valor;

	printf("Digite um valor: ");
	scanf("%d", &valor);

	if (valor <= 2000 && valor > 0)
	{
		for(int i = 0; i < valor; i++) if (i % 2 == 0) printf("%d\n", i);
	}
	else
	{
		printf("Limite de cálculo excedido: ");
	}

	return 0;

}