#include<stdio.h>

void exercicio() 
{
	printf("Exercicio numero 2\n");
	printf("Construa um algoritmo que calcule a area de um circulo cujo raio eh fornecido pelo usuario(use area = 3.14 x raio2)\n");
}

float calculaArea(float raio)
{
	return 3.14 * raio * raio;
}

int main()
{
	float raio;
	exercicio();
	printf("Digite o valor do raio: ");
	scanf("%f", &raio);

	float area = calculaArea(raio);

	printf("A area do raio eh: %.2f", area);
}