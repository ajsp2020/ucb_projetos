#include<stdio.h>

int main()
{
	int i = 0, l = 0, notas[80], sair, repetidos[80], frequencia[80];

	do {

		printf("Digite a nota: ");
		scanf("%d", &notas[i]);

		sair = notas[i] < 0 || notas[i] > 80;
		i++;

	} while (!sair);

	i--;

	for (int j = 0; j < i; j++)
	{
		for (int k = 0; k < i; k++)
		{
			if (notas[j] == notas[k] && j < k)
			{
				repetidos[l] = notas[j];
				l++;
				for (int m = 0; m < l; m++)
				{
					if (repetidos[m] == repetidos[m + 1]) l--; 
				}

			}
		}
	}

	for (int j = 0; j < l; j++)
	{
		frequencia[j] = 0;

		for (int k = 0; k < i; k++)
		{
			if (repetidos[j] == notas[k])
			{
				frequencia[j] += 1;
			}
		}
	}

	for (int j = 0; j < l; j++) printf("Numero = %d, Frequencia = %d \n", repetidos[j], frequencia[j]);
}