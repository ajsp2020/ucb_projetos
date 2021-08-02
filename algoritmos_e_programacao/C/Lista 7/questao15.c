#include <stdio.h>


int main()
{
	int caracteres[30];
	int sair = 0, i = 0;
	do {
		fflush(stdin);
		printf("Digite o caractere: ");
		caracteres[i] = getchar();
		sair = caracteres[i] >= 123 || caracteres[i] < 97;
		i++;

	} while (!sair);

	i--;

	int caractere, encontrou = 0;
	fflush(stdin);
	printf("Digite o caractere que deseja encontrar: ");
	caractere = getchar();


	for (int k = 0; k < i; k++)
	{
		if (caracteres[k] == caractere)
		{
			printf("Caractere encontrado!");
			encontrou = 1;
		}
	}

	if (encontrou == 0) printf("Caractere nao encontrado!");
	
}