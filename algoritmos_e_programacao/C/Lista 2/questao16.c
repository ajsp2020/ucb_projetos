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

PESSOA p;


void apresentacao()
{
	printf("Questão 16:\nFazer um algoritmo que leia o nome e a altura de três pessoas, determine e apresente o nome\n"
		"e a altura da menor delas.\n\n");
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

void crialistaposicao(int posicao[TAM_LISTA])
{
	for (int i = 0; i < TAM_LISTA; i++)
	{
		posicao[i] = i;
	}
}


void selecionaaltura(PESSOA* p, int posicao[TAM_LISTA], int tam_lista) 
{
	if (tam_lista < 1)
	{
		return;
	}

	for (int i = 0; i < tam_lista - 1 ; i++)
	{
		if (p->altura[i] > p->altura[i + 1])
		{
			float a = p->altura[i];
			int pos = posicao[i];
			p->altura[i] = p->altura[i + 1];
			posicao[i] = posicao[i + 1];
			p->altura[i + 1] = a;
			posicao[i + 1] = pos;
		}
	}

	selecionaaltura(p, posicao, tam_lista - 1);
}

void imprimeresultado(PESSOA* p, int posicao[TAM_LISTA])
{
	printf("Nome: %s", p->nome[posicao[0]]);
	printf("Altura %.2f", p->altura[0]);
}

int main()
{
	setlocale(LC_ALL, "");

	int tam_lista = TAM_LISTA;
	int posicao[TAM_LISTA];
	char n[TAM_NOME];

	apresentacao();
	pegadados(&p);
	crialistaposicao(posicao);
	selecionaaltura(&p, posicao, tam_lista);
	imprimeresultado(&p, posicao);
}