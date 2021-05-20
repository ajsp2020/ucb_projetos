#include <stdio.h>
#include <locale.h>
#include <string.h>

int main()
{
	setlocale(LC_ALL, "");
	char paises[3][40];
	int medalhas[3];
	int posicao[3] = { 0 , 1, 2 };

	for (int i = 0; i < 3; i++)
	{
		fflush(stdin);
		printf("Digite o nome do país: ");
		fgets(paises[i], 40, stdin);

		int ouro;
		printf("Digite a quantidade de medalhas de ouro: ");
		scanf("%d", &ouro);

		int prata;
		printf("Digite a quantidade de medalhas de prata: ");
		scanf("%d", &prata);

		int bronze;
		printf("Digite a quantidade de medalhas de bronze: ");
		scanf("%d", &bronze);

		medalhas[i] = ouro * 3 + prata * 2 + bronze * 1;

	}
	do {
		for (int i = 0; i < 2; i++)
		{
			if (medalhas[i] < medalhas[i + 1])
			{
				int medalha = medalhas[i];
				int temp = posicao[i];

				medalhas[i] = medalhas[i + 1];
				posicao[i] = posicao[i + 1];

				medalhas[i + 1] = medalha;
				posicao[i + 1] = temp;
			}
		}
	} while (medalhas[0] < medalhas[1] || medalhas[1] < medalhas[2]);




	for (int i = 0; i < 3; i++)
	{
		printf("PAIS: %s", paises[posicao[i]]);
		printf("PONTOS: %d\n", medalhas[i]);
		printf("CLASSIFICAÇÃO: %d Lugar\n", i + 1);
	}

}