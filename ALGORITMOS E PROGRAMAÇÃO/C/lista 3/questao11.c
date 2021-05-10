#include <stdio.h>
#include <locale.h>
#include <stdlib.h>


int main()
{
	setlocale(LC_ALL, "");

	int qtd_juizes, status;
	do {
		fflush(stdin);
		printf("Digite a quantidade de juizes das prova: ");
		status = scanf("%d", &qtd_juizes);
		
	} while (status != 1);

	int* juizes = malloc(sizeof(int) * qtd_juizes);
	int** notas = malloc(sizeof(float*) * 3);

	for (int i = 0; i < 3; i++) notas[i] = malloc(sizeof(float) * qtd_juizes);

	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < qtd_juizes; j++)
		{
			printf("Digite a nota %d do candidado %d: ", j+1, i+1);
			scanf("%d", &notas[i][j]);
		}
	}
	

	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < qtd_juizes; j++)
		{
			printf("Nota %d do candidado %d. \n", notas[i][j], i);
		}
	}

	free(juizes);
	free(notas);

	for (int i = 0; i < 3; i++) free(notas[i]);
}