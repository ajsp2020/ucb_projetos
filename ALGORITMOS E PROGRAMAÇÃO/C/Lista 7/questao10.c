#include<stdio.h>

int main()
{
	char nome[40];
	int i = 0, letraValida = 0;
	do {

		printf("Digite o nome um caractere por vez: \n");
		scanf(" %c", &nome[i]);
		letraValida = nome[i] != '#';
		i++;

	} while (letraValida);

	for (int j = 0; j < i - 1; j++) printf("%c", nome[j]);
}