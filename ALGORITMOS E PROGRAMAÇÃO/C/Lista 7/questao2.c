#include<stdio.h>

int main()
{

	float notas[50] = { 9, 10, 8 };

	printf("Digite a quantidade de alunos: ");
	int alunos;
	scanf("%d", &alunos);

	for (int i = 0; i < alunos; i++) printf("%.2f\t", notas[i]);
}