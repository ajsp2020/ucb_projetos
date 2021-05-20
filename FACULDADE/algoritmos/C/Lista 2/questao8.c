
#include <stdio.h>
#include <locale.h>
#include <string.h>
#include <ctype.h>

void apresentacao()
{
	printf("Questão 8:\n");
	printf("Modifique o algoritmo 4 (Sr. ou Sra.), feito anteriormente, para ler a altura e apresentar o"
		"peso ideal da pessoa, utilizando as seguintes fórmulas:\n"
		"\t\tpara homem : peso = (72.5 * altura) - 58\n"
		"\t\tpara mulher : peso = (62.1 * altura) - 44.7\n\n");
}

void peganome(char(*nome))
{
	printf("Digite um nome: ");
	fgets(nome, 20, stdin);
	*nome = toupper(*nome);
	fflush(stdin);
}


void validavalor(int status, float* numero)
{
	int temp, input;
	while (status != 1)
	{
		while ((temp = getchar()) != EOF && temp != '\n');
		printf("Input inválido... Digite o valor");
		status = scanf("%f", numero);
	}
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

void pegaaltura(float* altura)
{
	int status;
	printf("Qual a altura: ");
	status = scanf("%f", altura);
	validavalor(status, altura);
}

void calculapeso(float altura, float *peso,char sexo)
{
	if (sexo == 'M') *peso = (72.5 * altura) - 58;
	else *peso = (62.1 * altura) - 44.7;
}

void imprimeresultado(char(*nome), char(sexo), float peso)
{
	if (sexo == 'M') printf("Ilmo Sr. %sSeu peso ideal é de: %.2f", nome, peso);
	else printf("Ilma Sra. %sSeu peso ideal é de: %.2f", nome, peso);
}

int main()
{
	setlocale(LC_ALL, "");
	char nome[20];
	char sexo;
	float altura, peso;

	apresentacao();
	peganome(nome);
	pegasexo(&sexo);
	pegaaltura(&altura);
	calculapeso(altura, &peso, sexo);
	imprimeresultado(nome, sexo, peso);
}