#include <stdio.h>
#include <stdlib.h>

int main()
{
	int valores[3];

	for (int i = 0; i < 3; i++)
	{
		printf("Digite um valor inteiro: ");
		scanf("%d", &valores[i]);
		if (i > 0 && valores[i] > valores[0])
		{
			int valor = valores[i];
			valores[i] = valores[0];
			valores[0] = valor;
		}
	}

	system("cls");

	printf("O maior valor informado eh: %d", valores[0]);
}