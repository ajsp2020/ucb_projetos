#include<stdio.h>

int main()
{
	float valor= 555;
	float percentagem;

	printf("Digite o percentual a ser calculado: ");
	scanf("%f", &percentagem);

	float resutado = valor * percentagem / 100;

	printf("%.2f ", resutado);
}