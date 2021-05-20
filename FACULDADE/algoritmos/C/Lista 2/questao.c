
#include <stdio.h>
#include <string.h>
#include <ctype.h>


void peganome(char(*nome))
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

void pegasexo(char(*sexo))
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