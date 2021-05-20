#include<stdio.h>
#include<locale.h>


void apresentacao()
{
	printf("Questão 15:\n Faça um algoritmo que calcule e escreva o valor a ser pago a sua provedora de acesso à\n"
		"Internet, para isso você deverá ler a quantidade de horas que você utilizou.Sabe - se que você\n"
		"pagará R$ 30, 00 por até 20 horas de uso(va1or básico), caso você tenha usado mais de 20\n"
		"horas, então você deve acrescentar 10 \\% do valor básico para cada hora extra utilizada.\n");
}

void validavalor(int status, float* valor)
{
	int temp, input;
	while (status != 1 || *valor < 0)
	{
		while ((temp = getchar()) != EOF && temp != '\n');
		printf("Input inválido....\n");
		printf("Digite a quantidade de horas de internet utilizada: ");

		status = scanf("%f", valor);
	}
}

void pegahoras(float* horas)
{
	printf("Digite a quantidade de horas de internet utilizada: ");
	int status = scanf("%f", horas);
	validavalor(status, horas);
}

void calculavalor(float* valor, float horas)
{
	if (horas <= 20) *valor = 30;
	else *valor = 30 + (horas - 20) * 30 * 0.1;
}

void imprimevalor(float valor)
{
	printf("Valor a ser pago R$ %.2f", valor);
}

int main()
{
	float horas, valor;
	setlocale(LC_ALL, "");
	apresentacao();
	pegahoras(&horas);
	calculavalor(&valor, horas);
	imprimevalor(valor);
}