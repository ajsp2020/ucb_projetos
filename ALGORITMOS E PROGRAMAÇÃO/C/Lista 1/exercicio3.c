#include <stdio.h>

void abertura() {
	printf("Terceira questao:\n");
	printf("Construa um algoritmo que calcule a media aritmetica de 3 numeros quaisquer fornecidos pelo usuario.\n\n");
}

float calculamedia(float valores[3], float* media) {
	int soma = 0;
	for (int i=0; i < 3; i++) {
		soma += valores[i];
	}
	(*media) = soma / 3;
}
void pegavalor(float valores[3], int* quantidade) {
	float valor;
	printf("Digite o valor %d: ", *quantidade + 1);
	scanf("%f", &valor);
	valores[(*quantidade)] = valor;
	(*quantidade)++;
}

int main() 
{
	int quantidade = 0;
	float valores[3];
	float media;
	abertura();
	do 
	{
	pegavalor(valores, &quantidade);

	} while (quantidade < 3);

	calculamedia(valores, &media);
	printf("A media eh: %.2f", media);
}