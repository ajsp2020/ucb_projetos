#include <stdio.h>
#include <locale.h>

int main();

void apresentacao()
{
	printf("Questão 17:\nVocê tem um desejo incontrolável de descobrir quantos dias você já viveu em toda a sua vida,\n"
		"então faça um algoritmo que leia o ano de nascimento de uma pessoa e o ano atual, depois\n"
		"calcule e escreva o nome e o número de dias, aproximados, já vividos por essa pessoa\n\n");
}

void validavalor(int status, int* valor, int i)
{
	int temp, input;
	while (status != 1 || *valor < 0)
	{
		while ((temp = getchar()) != EOF && temp != '\n');
		printf("Input inválido....\n");

		if (i == 0)
		{
			printf("Qual o seu ano de nascimento? ");
			status = scanf("%d", valor);
		}
		else if (i == 1)
		{
			printf("Qual o ano atual? ");
			status = scanf("%d", valor);
		}
	}
}

void pegaano(int* ano_nascimento, int* ano_atual)
{
	printf("Qual o seu ano de nascimento? ");
	int status = scanf("%d", ano_nascimento);
	validavalor(status, ano_nascimento, 0);

	printf("Qual o ano atual? ");
	status = scanf("%d", ano_atual);
	validavalor(status, ano_atual, 1);

	if (*ano_atual <= *ano_nascimento)
	{
		printf("Data de nacimento não pode ser maior que o ano atual;\n");
		pegaano(ano_nascimento, ano_atual);
	}
}

int calculadias(int* dias, int* ano_nascimento, int* ano_atual)
{
	*dias = (*ano_atual - *ano_nascimento) * 360;
}

void imprimeresultado(int dias)
{
	printf("Dias vividos: %d\n", dias);
}

int main()
{
	setlocale(LC_ALL, "");

	int ano_nascimento, ano_atual, dias_vividos;

	apresentacao();
	pegaano(&ano_nascimento, &ano_atual);
	calculadias(&dias_vividos, &ano_nascimento, &ano_atual);
	imprimeresultado(dias_vividos);
}