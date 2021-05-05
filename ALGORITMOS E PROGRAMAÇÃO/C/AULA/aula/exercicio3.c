#include<stdio.h>
#include<locale.h>
#include<stdlib.h>



int main()
{
	setlocale(LC_ALL, "");
	int n;
	float soma = 0;
	do {
		fflush(stdin);
		printf("Digite a quantidade de valores que deseja incluir: ");
		scanf("%d", &n);
	} while (n <= 0 || n >= 100);


	float* valores;
	valores = malloc(sizeof(float) * n);

	for (int i = 0; i < n; i++)
	{
		printf("Digite a nota %d ", i + 1);
		scanf("%f", &valores[i]);
	}

	for (int i = 0; i < n; i++)
	{
		soma += valores[i];
	}
	printf("%.2f", soma);
	free(valores);
}