#include <stdio.h>
#include <locale.h>
#include <string.h>
#include <ctype.h>


void apresentacao() 
{
	printf("Questão 4: \n");
	printf("Desenvolver um algoritmo que leia o nome e o sexo de uma pessoa e apresente como saída\n"
		"uma das seguintes mensagens : “Ilmo.Sr.”, para o sexo masculino ou “Ilma.Sra.” para o sexo\n"
		"feminino, acrescentando o nome em seguida. Observe o exemplo de um resultado :\n\n"
		"\t\t\t\tIlma Sra.Ana Rita\n\n");
}

void peganome(char (*nome)) 
{
	printf("Digite um nome: ");
	scanf(" %s", nome);
	*nome = toupper(*nome);
}

void validasexo(char* sexo) 
{
	int sexovalido = *sexo == 'M' || *sexo == 'F';
	while (!sexovalido) 
	{
		printf("Input inválido... \nDigite o sexo: ");
		scanf(" %c", sexo);
		*sexo = toupper(*sexo);
		sexovalido = *sexo == 'M' || *sexo == 'F';
	}
}

void pegasexo(char (*sexo)) 
{
	printf("Digite o sexo: ");
	scanf(" %c", sexo);
	*sexo = toupper(*sexo);
	validasexo(sexo);
}

void imprimeresultado(char(*nome), char(sexo)) 
{
	if (sexo == 'M') printf("Ilmo Sr. %s\n", nome);
	else printf("Ilma Sra. %s\n", nome);
}
int main() 
{
	setlocale(LC_ALL, "");
	char nome[20];
	char sexo;

	apresentacao();
	peganome(nome);
	pegasexo(&sexo);
	imprimeresultado(nome, sexo);
}