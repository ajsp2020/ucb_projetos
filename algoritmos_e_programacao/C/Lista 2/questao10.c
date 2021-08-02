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

	default:
		printf("Input inválido...\n");
		pegacomponentes(num_componentes);
	}
	
}

void pegavalores(float* valores, int num_componentes) // Pega os valores e salva num array 
{
	for (int i = 0; i < num_componentes; i++) 
	{
		printf("Digite o valor %d ", i);
		scanf("%f", &valores[i]); // valores[0] = 5 ; valores[1] = 4 ; valores[2] = 3
	}
}

void selecionamenor(float * valores, int num_componentes) // Vou usar da bubblesort para colocar os valores em ordem crescente ({5, 4, 3}, 3)
{
	// valores[3] = {5, 4, 3} -> valores[3]  = {4, 3, 5} -> valores[3]  = {3, 4, 5} -> valores[3]  = {3, 4, 5} 
	if (num_componentes < 1) return; // (3 < 1) F -> (2 < 1) F -> (1 < 1) F -> (0 < 1) T -> sai da função 

	for (int i = 0; i < num_componentes; i++)  // i = 0 -> i = 1 -> i = 2 / i = 0 -> i = 1 / i = 0
	{
		if (valores[i] > valores[i+1]) // (5 > 4) T -> (5 > 3) T -> (5 > 5) F / (4 > 3) T -> (4 > 5) F / (3 < 4) F
		{
			float temp = valores[i]; // temp = 5 -> temp = 5 -> F / temp = 4 -> F / F
			valores[i] = valores[i + 1]; // valores[0] = 4 -> valores[1] = 3 -> F / valores[0] = 3 -> F / F
			valores[i + 1] = temp; // valores[0 + 1] = 5 -> valores[1 + 1] = 5 -F / valores[0 + 1] = 4 -> F / F
		}
	}
	selecionamenor(valores, num_componentes - 1); // ({4, 3, 5}, 2) -> ({3, 4, 5}, 1) -> ({3, 4, 5}, 0) 
}

void imprimeresposta(float* valores)
{
	printf("O menor valor é %.2f", valores[0]); // imprimindo o valores[0] = 3
} 

int main()
{
	setlocale(LC_ALL, "");
	apresentacao();

	float *valores;
	int i, num_componentes = 3;
	pegacomponentes(&num_componentes); // Pergunta quantos valores gostaria de adicionar 
	valores = malloc(sizeof(float) * num_componentes); // Aloca dinamicamente esses valores criando um array com o tamanho informado na funcao anterior 
	pegavalores(valores, num_componentes); // valores[3] = {5, 4, 3}
	selecionamenor(valores, num_componentes); // Colocando os valores em ordem crescente
	imprimeresposta(valores); // Enviando o array em ordem crescente 


	free(valores);
	
}