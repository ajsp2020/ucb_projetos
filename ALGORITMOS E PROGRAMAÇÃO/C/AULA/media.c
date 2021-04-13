#include<stdio.h>
#include<locale.h>
#include<string.h>
#include <ctype.h>

void apresentacao() {
	printf("Leia quatro números (N1, N2, N3, N4) e o nome do aluno, correspondente às quatro letras de um aluno\n"
		"Calcule a média simples. Para cada uma destas notas, mostre esta média acompanhada pela messagem 'Media: '.\n"
		"Se esta média for maior ou igual a 7.0 \n");
}

void peganome(char (*nome))
{
	printf("Digite o nome do aluno: ");
	fgets(nome, 20, stdin);	// pegar strings com espaço
	fflush(stdin);
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


void validavalor(int status, float* numero)
{
	int temp, input;
	while (status != 1)
	{
		while ((temp = getchar()) != EOF && temp != '\n');
		printf("Input inválido... Digite novamente: ");
		status = scanf("%f", numero);
	}
}
void validanota(float* numero)
{
	int valoraceito = *numero <= 10 && *numero >= 0;
	while (!valoraceito)
	{
		printf("Input inválido... Digite uma nota entre (0 - 10): ");
		scanf("%f", numero);
		valoraceito = *numero < 10 && *numero > 0;
	}
}

void pegavalores(float notas[4], int* n)
{
	float numero;
	printf("Digite o valor da nota %d ", *n + 1);
	int status = scanf("%f", &numero);
	validavalor(status, &numero);
	validanota(&numero);
	notas[(*n)] = numero;
	(*n)++;
}

void pegafrequencia(float* freq)
{
	printf("Digite o valor da frequencia: ");
	int status = scanf("%f", freq);
	validavalor(status, freq);
}

int aprovadopornota(float notas[4], float* media)
{
	float soma = 0;
	for (int i = 0; i < 4; i++) soma += notas[i];
	*media = soma / 4;
	if (*media > 7.0) return 1;
	return 0;

	printf("%f", soma);
}

int aprovadoporfrequencia(float freq)
{
	if (freq >= 75) return 1;
	return 0;
}

void imprimeresutado(float notas[4], float* media, char *nome, float freq)
{
	int aprovado = aprovadopornota(notas, media) && aprovadoporfrequencia(freq);
	int reprovadoporfrequencia = aprovadopornota(notas, media) && !aprovadoporfrequencia(freq);
	int reprovadopornota = !aprovadopornota(notas, media) && aprovadoporfrequencia(freq);

	if (aprovado) printf("O aluno %s está aprovado com média: %.2f: ", nome, *media);
	else if (reprovadoporfrequencia) printf("O aluno %s está reprovado por frequência: ", nome);
	else if (reprovadopornota) printf("O aluno %s está reprovado por nota: ", nome);
	else printf("O aluno %s está reprovado: ", nome);
}

int main()
{
	setlocale(LC_ALL, "");
	float notas[4];
	float media;
	char nome[20];
	char sexo;
	int n = 0;
	float freq;
	apresentacao();

	peganome(nome);
	pegasexo(&sexo);
	pegafrequencia(&freq);

	do
	{
		pegavalores(notas, &n);

	} while (n < 4);
	
	imprimeresutado(notas, &media, nome, freq);
}