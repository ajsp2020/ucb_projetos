#include<stdio.h>

int main()
{
	int numero , soma = 0,  i = 0;


	do {
	
		fflush(stdin);

		printf("Digite um valor inteiro: ");
		scanf("%d", &numero);

		if (numero % 2 == 0 && numero != 0)
		{
			soma += numero;
			i++;
		}
		
	} while (numero != 0);
	float media = (soma / i);

	printf("A media aritimetica dos numeros pares fornecidos eh: %.2f", media);
}