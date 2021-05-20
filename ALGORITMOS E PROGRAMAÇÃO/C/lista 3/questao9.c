#include <stdio.h>
#include<locale.h>
#include <stdlib.h>

#define TAM 100
int main()
{
	char *sexo = malloc(sizeof(char) * TAM);
	char* olhos = malloc(sizeof(char) * TAM);
	char* cabelos = malloc(sizeof(char) * TAM);
	int* idades = malloc(sizeof(int) * TAM);
	int i = 0;

	int sexoValido, olhosValidos, cabelosValidos, idadeValida;

	setlocale(LC_ALL, "");

	do {
		fflush(stdin);
		do {
			printf("Idade: ");
			scanf("%d", &idades[i]);

			idadeValida = idades[i] >= 0 || idades[i] <= 110;
		}while(!idadeValida);

		if (idades[i] < 0) continue;

		else {
			do {
				printf("Sexo (M - Masculino | F - Feminino): ");
				scanf(" %c", &sexo[i]);

				sexoValido = sexo[i] == 'M' || sexo[i] == 'F';
			} while (!sexoValido);

			do {
				printf("Cor dos olhos (A - azuis | V - verdes | C - castanhos | P - pretos): ");
				scanf(" %c", &olhos[i]);

				olhosValidos = olhos[i] == 'A' || olhos[i] == 'V' || olhos[i] == 'C' || olhos[i] == 'P';
			} while (!olhosValidos);

			do {
				printf("Cor dos cabelos (L - loiros | C - Castanhos | P - pretos): ");
				scanf(" %c", &cabelos[i]);

				cabelosValidos = cabelos[i] == 'L' || cabelos[i] == 'C' || cabelos[i] == 'P';
			} while (!cabelosValidos);

			i++;
		}

	} while (idades[i] > 0);

	int maiorIdade;
	for (int j = 0; j < i; j++)
	{
		if (idades[0] < idades[j])
		{
			int idade = idades[0];
			idades[0] = idades[j];
			idades[j] = idade;
		}
	}
	printf("MAIOR IDADE: %d\n", idades[0]);

	int individuoValido;
	int somaIndividuosValidos = 0;
	for (int j = 0; j < i; j++)
	{
		individuoValido = sexo[j] == 'F' && idades[j] >= 18 && idades[j] <= 35 && olhos[j] == 'V' && cabelos[j] == 'L';
		if (individuoValido)
		{
			somaIndividuosValidos++;
		}
	}

	printf("INDIVÍDUOS VÁLIDOS: %d\n", somaIndividuosValidos);

	free(sexo);
	free(olhos);
	free(cabelos);
	free(idades);
}