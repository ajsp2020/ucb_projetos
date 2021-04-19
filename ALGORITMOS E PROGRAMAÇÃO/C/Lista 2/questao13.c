#include<stdio.h>
#include<locale.h>
#include<string.h>

void imprimeresultado();

#define TAM_LISTA 8 // Declarando o tamanho da lista como uma constante de valor 8
#define TAM_PALAVRA 40 // Declarando o tamanho da palavra como uma constante de valor 40

void apresentacao()
{
	printf("Questão 12:\nFaça um algoritmo em português estruturado que leia o número de DDD e informe a qual\n"
		"cidade pertence, considerando só os seguintes valores :\n"
		"61 - Brasília\n"
		"71 - Salvador\n"
		"11 - São Paulo\n"
		"21 - Rio de Janeiro\n"
		"32 - Juiz de Fora\n"
		"19 - Campinas\n"
		"27 - Vitória\n"
		"31 - Belo Horizonte\n"
		"qualquer outro - uma cidade no Brasil sem identificação\n\n");
}

void validavalor(int status, int* valor)
{
	int temp, input;
	while (status != 1)
	{
		while ((temp = getchar()) != EOF && temp != '\n');
		printf("Input inválido....\n");
		printf("Digite o número do ddd que deseja: ");

		status = scanf("%d", valor);
	}
}

void pegavalor(int* ddd) // Pega o valor do ddd que desejo encontrar a cidade 
{
	printf("Digite o número do ddd que deseja: "); // ddd = 61
	int status = scanf("%d", ddd);
	validavalor(status, ddd);
}

void descobrecidade(int ddds[TAM_LISTA], char cidades[TAM_LISTA][TAM_PALAVRA], int ddd, char cidade[TAM_PALAVRA]) // Recebendo como parametro a lista com os ddds, a lista com as cidades, o ddd que estou procurando e uma string inicialmente vazia 
{
	for (int i = 0; i < TAM_LISTA; i++) // iterando sobre os ddds
	{
		if (ddd == ddds[i]) // (61 == 61) V
		{
			cidade = cidades[i]; // cidade = Brasília 
			break;
		}
		else
		{
			cidade = "Sem identificação"; 
		}
	}
	imprimeresultado(cidade);
}

void imprimeresultado(char cidade[TAM_PALAVRA]) // Recebendo a cidade encontrada como parametro
{
	printf("Cidade: "); 
	printf("%s", cidade); // cidade: Brasília
}

int main()
{
	int ddds[TAM_LISTA] = { 61, 71, 11, 21, 32, 19, 27, 31 };
	char cidades[TAM_LISTA][TAM_PALAVRA] = { "Brasília", "Salvador", "São Paulo", "Rio de Janeiro", "Juiz de Fora", "Campinas", "Vitória", "Belo Horizonte" };
	char cidade[TAM_PALAVRA];
	int ddd;
	setlocale(LC_ALL, "");
	apresentacao();
	pegavalor(&ddd);
	descobrecidade(ddds, cidades, ddd, cidade);
}