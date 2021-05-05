#include<stdio.h>
#include<locale.h>

// Escrever um programa que declare um vetor de reais e leia as notas de 30 alunos.

int main()
{
	setlocale(LC_ALL, "");
	float notas[30];
	for (int i = 0; i < 30; i++)
	{
		printf("Digite a nota %d: ", i+1);
		scanf("%f", &notas[i]);
	}
	for (int i = 0; i < 30; i++)
	{
		printf("%.2f\n", notas[i]);
	}
}