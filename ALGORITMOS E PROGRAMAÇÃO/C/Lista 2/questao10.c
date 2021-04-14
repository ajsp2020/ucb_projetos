#include<stdio.h>
#include<locale.h>
#include <stdlib.h> 

void apresentacao()
{
	printf("Questão 10:\nFaça um algoritmo em português estruturado que leia três valores numéricos e encontre qual\n"
		"o menor deles, mostrando - o no final.Faça o chinesinho ao lado do seu algoritmo. \n\n");
}

void pegacomponentes(int *num_componentes)
{
	int v;
	printf("Se deseja o valor padrão (3) digite 1 ou 2 para adicionar outro valor: ");
	scanf("%d", &v);

	switch (v)
	{
	case 1:

		break;

	case 2:
		printf("Digite a quantidade de numeros que deseja descobrir o menor valor: ");
		scanf("%d", num_componentes);

		break;
	}
}

int main()
{
	setlocale(LC_ALL, "");
	apresentacao();

	float *valores;
	int i, num_componentes = 3;
	pegacomponentes(&num_componentes);
	valores = malloc(sizeof(float) * num_componentes);

	
	for (int i = 0; i < num_componentes; i++)
	{
		printf("Digite o valor %d ", i);
		scanf("%f", &valores[i]);
	}
	for (int i = 0; i < num_componentes; i++)
	{
		printf("%f\n", valores[i]);
	}

	free(valores);
	
}