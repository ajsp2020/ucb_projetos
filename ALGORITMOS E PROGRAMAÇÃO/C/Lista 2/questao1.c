#include <stdio.h>
#include <locale.h>
#include <string.h>

#define TAM_PLACA 8

void abertura() 
{
	printf("Questão 1:\nConstrua um algoritmo que a partir da leitura da velocidade e placa do carro, avise ao\n"
		"motorista somente se ele será multado, quando estiver trafegando no Eixo Rodoviário \n(limite"
		"de 80 km / h)\n\n");
}

void validavalor(int status, int* valor)
{
	int temp, input;
	while (status != 1 || *valor < 0)
	{
		while ((temp = getchar()) != EOF && temp != '\n');
		printf("Input inválido....\n");
		if (*valor < 0) printf("Não é aceito valores negativos!\n");

		printf("Digite a velocidade do veículo: ");
		status = scanf("%d", valor);
	}
}

void levelocidade(int* velocidade) 
{
	printf("Digite a velocidade do veículo: ");
	int status = scanf("%d", velocidade);
	validavalor(status, velocidade);
}

void leplaca(char placa[TAM_PLACA]) 
{
	printf("Digite a placa do carro: ");
	scanf("%s", placa);
}

int seramutado(int velocidade) 
{
	if (velocidade > 80) return 1;
	return 0;
}

void imprimedados(int vel, char placa[TAM_PLACA], int velocidade) 
{
	if (seramutado(velocidade)) printf("Veículo placa %s esta trafegando com velocidade de %d km/h: Será multado", placa, vel);
	else  printf("Veículo placa %s esta trafegando com velocidade de %d km/h: Não será multado", placa, vel); //Resposta: Questão 5
}

int main() 
{
	setlocale(LC_ALL, "");

	int velocidade;
	char placa[TAM_PLACA];

	abertura();
	levelocidade(&velocidade);
	leplaca(placa);
	imprimedados(velocidade, placa, velocidade);
}