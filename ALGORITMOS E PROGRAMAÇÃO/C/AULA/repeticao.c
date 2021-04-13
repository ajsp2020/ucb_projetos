#include<stdio.h>

int main()
{
	int numero;
	printf("Digite o numero: ");
	scanf("%d", &numero);

	for (int contador = 1; contador <= 5000; contador++)
	{
		printf("%d x %d = %d\n", numero, contador, numero * contador);

	}
	//printf("%d x 1 = %d\n", numero, numero * 1);
	//printf("%d x 2 = %d\n", numero, numero * 2);
	//printf("%d x 3 = %d\n", numero, numero * 3);
	//printf("%d x 4 = %d\n", numero, numero * 4);
}