#include <stdio.h>

int main() {

	float notaA, notaB, notaC, media;

	printf("Digite a nota A: ");
	scanf("%f", &notaA);

	printf("Digite a nota B: ");
	scanf("%f", &notaB);

	printf("Digite a nota C: ");
	scanf("%f", &notaC);

	media = (notaA * 2 + notaB * 3 + notaC * 5) / 10;
	printf("A media eh: %.2f", media);

}