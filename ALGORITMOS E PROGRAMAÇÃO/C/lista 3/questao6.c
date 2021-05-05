#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#include <string.h>

int main()
{
	setlocale(LC_ALL, "");
	int *resposta;
	resposta = malloc(sizeof(int) * (10));
	int i = 0;
	char sair;
	int ehValido;
	do {
	
		printf("Qual fruta deseja comprar?\n"
			"1 => ABACAXI\n"
			"2 = > MAÇA\n"
			"3 = > PERA'\n");
		scanf("%d", &resposta[i]);
		fflush(stdin);

		ehValido = resposta[i] > 0 && resposta[i] < 4;
		if (!ehValido)
		{
			printf("A fruta não está disponível!\n");
			continue;
		}
		else
		{
			printf("Deseja acrecentat mais fruta? (S/N) ");
			scanf(" %c", &sair);
			fflush(stdin);

			if (sair == 'N') continue;
			else if (sair == 'S') i++;
		}
		system("pause");
		system("cls");
	} while (!ehValido || sair == 'S');

	printf("i = %d\n", i);

	for (int j = 0; j <= i; j++)
	{
		printf("%d\n", resposta[j]);
	}

	free(resposta);
}
