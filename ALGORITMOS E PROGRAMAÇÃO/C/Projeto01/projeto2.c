#include<stdio.h> // Esta biblioteca contém várias funções de entrada e saída. 
#include<locale.h> // para implementar a localização de programas.
#include<stdlib.h>
#include<string.h>
#include <ctype.h> // para incluir a biblioteca do tooper
#include"projeto.h"



void dadosautor()
{
	printf("Projeto prático 01:\n"
			"NOME: Antonio João da Silva Pereira\n"
			"MATRÍCULA: \n"
			"CURSO: Ciências da Computação\n\n");
}

void validavalor(int* status, int* valor, int j, int k, int v)
{
	int temp, input;
	while (*status != 1 || *valor < 0)
	{
		while ((temp = getchar()) != EOF && temp != '\n');
		printf("Input inválido....\n");

		switch (j)
		{
		case 0:
			printf("Digite a quantidade de seções que serão realizadas: ");
			break;

		case 1:
			printf("Digite a quantidade de pessoas que assistiram a seção: ");
			break;

		case 2:

			printf("Digite a idade da pessoa %d: ", v + 1);
			break;
		}
		*status = scanf("%d", valor);
	}
}

void validasexo(char* sexo, int j)
{
	int sexovalido = *sexo == 'M' || *sexo == 'F';
	while (!sexovalido)
	{
		printf("Input inválido... \nDigite o sexo da pessoa %d: ", j);
		scanf(" %c", sexo);
		*sexo = toupper(*sexo);
		sexovalido = *sexo == 'M' || *sexo == 'F';
	}
}

void validafilme(char *nome_filme, int *len)
{
	while (*len == TAM_FILME)
	{
		printf("Digite o nome do filme assistido pela pessoa: ");
		fgets(nome_filme, TAM_NOME, stdin);
		fflush(stdin);
		*len = strlen(nome_filme);
		printf("Nome do filme: %s\n", nome_filme);
	}
}

void pegasessoes(int* qtd_secoes)
{
	printf("Digite a quantidade de seções que serão realizadas: ");
	int status = scanf("%d", qtd_secoes);
	fflush(stdin);
	validavalor(&status, qtd_secoes, 0, 0, 0);
	if (*qtd_secoes != 1) // 2
	{
		printf("Somente é aceito 2 seções como input:\n");
		pegasessoes(qtd_secoes);
	}
	
}

void pegapessoas(int* qtd_pessoas)
{
	printf("Digite a quantidade de pessoas que assistiram a seção: ");
	int status = scanf("%d", qtd_pessoas);
	fflush(stdin);
	validavalor(&status, qtd_pessoas, 1, 0, 0);
	if (*qtd_pessoas < 4) // 10
	{
		printf("É aceito no mínimo 10 pessoas como input:\n");
		pegapessoas(qtd_pessoas);
	}
}

void pegaidades(int **idades,char **sexo,  int qtd_sessoes, int qtd_pessoas,int k, int v)
{
	for (int i = k; i < qtd_sessoes; i++)
	{
		for (int j = v; j < qtd_pessoas; j++)
		{
			printf("Digite a idade da pessoa %d: ", j + 1);
			int status = scanf("%d", &idades[i][j]);
			fflush(stdin);
			validavalor(&status, &idades[i][j], 2, i, j);
			if (idades[i][j] < 3 || idades[i][j] > 100)
			{
				printf("É aceito somente idades entre 3 a 100 anos como input:\n");
				status = 0;			
			}
			validavalor(&status, &idades[i][j], 2, i, j);
			printf("idades[%d][%d] = %d\n", i, j, idades[i][j]);

			pegasexo(sexo, i, j); // Pega o sexo das pessoas

		}
	}
}

void pegasexo(char **sexo, int i, int j)
{
	printf("Digite o sexo da pessoa %d: ", j + 1);
	scanf("%c", &sexo[i][j]);
	sexo[i][j] = toupper(sexo[i][j]);
	validasexo(&sexo[i][j], j+1);
	printf("sexo[%d][%d] = %c\n", i, j, sexo[i][j]);

}

void pegafilmes(char *nome_filmes)
{
	printf("Digite o nome do filme assistido pela pessoa: ");
	fgets(nome_filmes, TAM_NOME, stdin);
	fflush(stdin);
	int len = strlen(nome_filmes);
	printf("len = %d\n", len);
	printf("Nome do filme: %s\n", nome_filmes);
	validafilme(nome_filmes, &len);
}

int main()
{
	setlocale(LC_ALL, ""); 
	// Variáveis:
	int qtd_sessoes, qtd_pessoas, qtd_filmes;
	char *nome_filmes = malloc(sizeof(char) * TAM_NOME);
	int** idades;
	char** sexo;

	dadosautor(); // Imprime os dados do autor
	pegafilmes(nome_filmes);
	pegasessoes(&qtd_sessoes); // Pega a quantidade de seções 
	pegapessoas(&qtd_pessoas); // Pega a quantidade de pessoas

	idades = malloc(sizeof(int*) * qtd_sessoes); // Alocando dinamicamente valores para idade 
	sexo = malloc(sizeof(int*) * qtd_sessoes); // Alocando dinamicamente valores para idade 

	for (int i = 0; i < qtd_sessoes; i++) // aloca um vetor com todos os elementos da matriz
	{
		idades[i] = malloc(sizeof(int) * qtd_pessoas);
		sexo[i] = malloc(sizeof(char) * qtd_pessoas);
	}
	
	pegaidades(idades,sexo, qtd_sessoes, qtd_pessoas, 0, 0); // Pega a idade das pessoas




	printf("%d\n", qtd_sessoes);
	printf("%d\n", qtd_pessoas);
	printf("idades[0][2] = %d\n", idades[0][2]);
	printf("sexo[0][2] = %c\n", sexo[0][2]);

	// Liberendo a memória da matriz:
	for (int i; i < qtd_sessoes; i++)
	{
		free(idades[i]);
		free(sexo[i]);
	}
	free(idades);
	free(sexo);
	free(nome_filmes);
}