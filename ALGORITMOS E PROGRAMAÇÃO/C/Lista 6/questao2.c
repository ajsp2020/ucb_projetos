#include<stdio.h>

int main()
{
	int factorial = 1,  n;
	int contagem = 1;

	printf("Digite o valor do factorial: ");
	scanf("%d", &n);

	while (contagem <= n)
	{
		factorial *= contagem;
		contagem++;
	}
	printf("O Factorial eh: %d\n", factorial);
}