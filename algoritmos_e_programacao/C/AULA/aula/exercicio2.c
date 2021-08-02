#include<stdio.h>
#include<locale.h>
#include<stdlib.h>


int main()
{
	setlocale(LC_ALL, "");
	int n;
	printf("Digite a quantidade de notas que deseja incluir: ");
	scanf("%d", &n);

	float *notas;
	notas = malloc(sizeof(float) * n);

	for (int i = 0; i < n; i++)
	{
		printf("Digite a nota %d ", i + 1);
		scanf("%f", &notas[i]);
	}
	for (int i = 0; i < n; i++)
	{
		printf("nota %d = %.2f\n", i + 1, notas[i]);
	}

	free(notas);
}