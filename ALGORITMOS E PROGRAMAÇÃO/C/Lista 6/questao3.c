#include <stdio.h>
#include<locale.h>

int main() 
{
	setlocale(LC_ALL, "");
	char sexo;
	float alturas[10];
	float altura_mulheres[10];
	float media_mulheres;
	int i = 0;
	int mulheres = 0;
	do {
		fflush(stdin);
		printf("Digite o sexo (M - Masculino | F - Feminino): \n");
		scanf("%c", &sexo);
		printf("Digite a altura: \n");
		scanf("%f", &alturas[i]);

		if (sexo == 'F' || sexo == 'f')
		{
			altura_mulheres[mulheres] = alturas[i];
			mulheres++;
		}
		i++;
	} while (i < 10);

	for (int j = 0; j < i; j++)
	{
		for (int k = 0; k < i - 1 - j; k++)
		{
			if (alturas[k] > alturas[k + 1])
			{
				float temp = alturas[k];
				alturas[k] = alturas[k + 1];
				alturas[k + 1] = temp;
			}
		}
	}

	int j = 0;
	while (j < mulheres)
	{
		media_mulheres += altura_mulheres[j];
		j++;
	}
	

	media_mulheres = media_mulheres / (float)mulheres;

	printf("A menor altura é: %.2f\n", alturas[0]);
	printf("A maior altura é: %.2f\n", alturas[i - 1]);
	printf("A media da altura das mulheres é: %.2f\n", media_mulheres);
	printf("O numero de homens é: %d\n", i - mulheres);
}