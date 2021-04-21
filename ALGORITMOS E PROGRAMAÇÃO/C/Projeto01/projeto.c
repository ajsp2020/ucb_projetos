#include<stdio.h> // Esta biblioteca contém várias funções de entrada e saída. 
#include<locale.h> // para implementar a localização de programas.
#include<stdlib.h>
#include<string.h>

#define TAM_NOME 20
#define TAM_LISTA 2

void dadosautor()
{
	printf("Projeto prático 01:\n"
			"NOME: Antonio João da Silva Pereira\n"
			"MATRÍCULA: \n"
			"CURSO: Ciências da Computação\n\n");
}

void validavalor(int status, int* valor, int j, int i)
{
	int temp, input;
	while (status != 1 || *valor < 0)
	{
		while ((temp = getchar()) != EOF && temp != '\n');
		printf("Input inválido....\n");

		if (j == 0)
		{
			printf("Digite a quantidade de seções que serão realizadas: ");
		}
		if (j == 1)
		{
			printf("Digite a quantidade de pessoas que assistiram a seção: ");
		}
		if (j == 2)
		{
			printf("Digite a idade da pessoa %d: ", i + 1);
		}

		status = scanf("%d", valor);
		fflush(stdin);
	}
}

void pegasessoes(int* qtd_secoes)
{
	printf("Digite a quantidade de seções que serão realizadas: ");
	int status = scanf("%d", qtd_secoes);
	fflush(stdin);
	validavalor(status, qtd_secoes, 0, 0);
	if (*qtd_secoes != 2)
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
	validavalor(status, qtd_pessoas, 1, 0);
	if (*qtd_pessoas < 10)
	{
		printf("É aceito no mínimo 10 pessoas como input:\n");
		pegapessoas(qtd_pessoas);
	}
}

void pegaidades(int* idades, int qtd_pessoas, int v)
{
	int idade;
	for (int i = v; i < qtd_pessoas; i++)
	{
		printf("Digite a idade da pessoa %d: ", i + 1);
		int status = scanf("%d", &idades[i]);
		fflush(stdin);
		validavalor(status, &idades[i], 2, i);
		if (idades[i] < 3 || idades[i] > 100)
		{
			printf("É aceito somente idades entre 3 a 100 anos como input:\n");
			pegaidades(idades, qtd_pessoas, i);
			break;
		}
	}
}

int main()
{
	setlocale(LC_ALL, ""); 
	// Variáveis:
	int qtd_sessoes, qtd_pessoas;
	int *idades = malloc(sizeof(int*) * qtd_pessoas);
	char nome_filmes[TAM_LISTA][TAM_NOME];
	char *sexo = malloc(sizeof(char*) * qtd_pessoas);

	// funções
	dadosautor(); // Imprime os dados do autor
	pegasessoes(&qtd_sessoes); // Pega a quantidade de seções 
	//pegafilmes(); // Pega o nome do filme
	pegapessoas(&qtd_pessoas); // Pega a quantidade de pessoas
	//pegasexo(); // Pega o sexo das pessoas
	pegaidades(idades, qtd_pessoas, 0); // Pega a idade das pessoas
	printf("%d\n", qtd_sessoes);
	printf("%d\n", qtd_pessoas);
	printf("idades[6] = %d\n", idades[6]);
	free(idades);
	free(sexo);
}