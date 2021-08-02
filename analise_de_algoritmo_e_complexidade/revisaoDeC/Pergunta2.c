#include<stdio.h>
#include<locale.h>
#include<stdlib.h>


void pergunta()
{
	printf("\nPergunta 2:\n\nImplemente uma rotina que faça a multiplicação de duas matrizes nxn\n");
	// system("pause");
}

void defineTamanhoMatrix(int* tamanhoDaMatrix)
{
	printf("Digite o tamanho das matrizes nxn: ");
	scanf("%d", tamanhoDaMatrix);
}


void adicionaValorMatrix(float** matrix, int tamanhoDaMatrix, char nome)
{
	
	for (int i = 0; i < tamanhoDaMatrix; i++)
	{
		for (int j = 0; j < tamanhoDaMatrix; j++)
		{
			system("clear");

			printf("Digite o valor da matrix%c[%d][%d]: ",nome, i+1, j+1);
			scanf("%f", &matrix[i][j]);
		}

	}

	fflush(stdin);
}

void calculaValor(float** matrixA, float** matrixB, float** matrixC, int tamanhoDaMatrix)
{	

	system("clear");

	for (int l = 0; l < tamanhoDaMatrix; l++)
	{
		for (int c = 0; c < tamanhoDaMatrix; c++)
		{
			for (int i = 0; i < tamanhoDaMatrix; i++)
			{
				matrixC[l][c] += matrixA[l][c] * matrixB[i][c];
			}

			printf("Valor o valor da matrixC[%d][%d]: %.2f \n", l+1, c+1, matrixC[l][c]); 

		}
	}
}


int main()
{
	setlocale(LC_ALL, "pt_br");
	int tamanhoDaMatrix;
	defineTamanhoMatrix(&tamanhoDaMatrix);
	printf("%d\n", tamanhoDaMatrix);

	float** matrixA, ** matrixB, ** matrixC;

	//alocaMemoria;

	matrixA = malloc(sizeof(float*) * tamanhoDaMatrix);
	matrixB = malloc(sizeof(float*) * tamanhoDaMatrix);
	matrixC = malloc(sizeof(float*) * tamanhoDaMatrix);

	for (int i = 0; i < tamanhoDaMatrix; i++)
	{
		matrixA[i] = malloc(sizeof(float) * tamanhoDaMatrix);
		matrixB[i] = malloc(sizeof(float) * tamanhoDaMatrix);
		matrixC[i] = malloc(sizeof(float) * tamanhoDaMatrix);

	}

	printf("Memoria alocada!!\n");

	adicionaValorMatrix(matrixA, tamanhoDaMatrix, 'A');
	adicionaValorMatrix(matrixB, tamanhoDaMatrix, 'B');


	// fim alocaMemoria

	calculaValor(matrixA, matrixB, matrixC, tamanhoDaMatrix);

	//liberaMemoria;

	for (int i = 0; i < tamanhoDaMatrix; i++)
	{
		free(matrixA[i]);
		free(matrixB[i]);
		free(matrixC[i]);
	}

	free(matrixA);
	free(matrixB);
	free(matrixC);


	//fim liberaMemoria

	return 0;
}