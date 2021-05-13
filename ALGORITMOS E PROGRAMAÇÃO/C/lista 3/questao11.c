#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#include<string.h>


int main()
{
	setlocale(LC_ALL, "");

	int qtd_juizes, status;
	do {
		fflush(stdin);
		printf("Digite a quantidade de juizes da prova: ");
		status = scanf("%d", &qtd_juizes);
		
	} while (status != 1); // Validação 

	int* juizes = malloc(sizeof(int) * qtd_juizes);
	int** notas = malloc(sizeof(float*) * 3);
	int** nome = malloc(sizeof(char) * 3);

	for (int i = 0; i < 3; i++) notas[i] = malloc(sizeof(float) * qtd_juizes);
	for (int i = 0; i < 3; i++) nome[i] = malloc(sizeof(float) * 40);

	for (int i = 0; i < 3; i++) 
	{ 
		printf("Digite o nome do candidado %d: ", i + 1); // Pede a nota de cada juiz para o candidado
		scanf("%s", &nome[i]); // pega a nota
	}

	for (int i = 0; i < 3; i++) { // Para cada candidato
		for (int j = 0; j < qtd_juizes; j++) // Cada juiz dá uma nota
		{
			printf("Digite a nota do juiz %d do %s ", j+1, nome[i]); // Pede a nota de cada juiz para o candidado
			scanf("%d", &notas[i][j]); // pega a nota
		}
	}
	

	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < qtd_juizes; j++)
		{
			printf("Nota %d do candidado %d. \n", notas[i][j], i + 1);
		}
	}



	free(juizes);
	free(notas);
	free(nome);

	for (int i = 0; i < 3; i++) free(notas[i]);
	for (int i = 0; i < 3; i++) free(nome[i]);
}