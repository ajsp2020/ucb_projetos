#include <stdio.h>
#include <locale.h>
#include <string.h>

#define TAM_LISTA 3
#define TAM_NOME 40

struct pessoa {

	char nome[TAM_LISTA][TAM_NOME];
	float altura[TAM_LISTA];
};
typedef struct pessoa PESSOA;



void apresentacao()
{
	printf("Questão 16:\nFazer um algoritmo que leia o nome e a altura de três pessoas, determine e apresente o nome\n"
		"e a altura da menor delas.\n");
}

void pegadados(PESSOA *p)
{
	float altura;
	for (int i = 0; i < TAM_LISTA; i++)
	{
		printf("Digite o nome: ");
		fgets(p->nome[i], TAM_NOME, stdin);
		fflush(stdin);

		printf("Digite a altura: ");
		scanf("%f", &altura);
		p->altura[i] = altura;
		fflush(stdin);
	}
}

void crialistaposicao( int posicao[TAM_LISTA])
{
	for (int i = 0; i < TAM_LISTA; i++)
	{
		posicao[i] = i;
	}
}


void selecionaaltura(PESSOA *p, int posicao[TAM_LISTA]) // Pensar numa forma de criar uma lista em paralelo e com os valores prévios acessar o valor para pegar o nome equivalente
{
	float a;
	int pos;

	for (int i= 0; i < TAM_LISTA; i++)
	{
		for (int j = 0; j < TAM_LISTA; j++)
		{
			if (p->altura[i] > p->altura[j])
			{
				
				a = p->altura[i];
				pos = posicao[i];
				p->altura[i] = p->altura[j];
				posicao[i] = posicao[j];
				p->altura[j] = a;
				posicao[j] = pos;
			}
		}
	}
}

void imprimeresultado(PESSOA* p, int posicao[TAM_LISTA])
{
	printf("Nome: %s", p->nome[posicao[0]]);
	printf("Altura %.2f", p->altura[0]);
}

int main()
{
	setlocale(LC_ALL, "");

	PESSOA p;

	int posicao[TAM_LISTA];
	char n[TAM_NOME];

	apresentacao();
	pegadados(&p);
	crialistaposicao(posicao);
	selecionaaltura(&p, posicao);
	imprimeresultado(&p, posicao);
}