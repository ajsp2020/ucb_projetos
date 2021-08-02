#include <stdio.h>
#include<locale.h>

int main() // FALTA TERMINAR
{
	setlocale(LC_ALL, "");
	char sexo;
	float alturas[50];
	float altura_mulheres[50];
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
	} while (i < 5);
	 
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

	for (int j = 0; j < mulheres; j++) media_mulheres += altura_mulheres[j];

	media_mulheres = media_mulheres /(float)mulheres;

	printf("A menor altura é: %.2f\n", alturas[0]);
	printf("A maior altura é: %.2f\n", alturas[i - 1]);
	printf("A media da altura das mulheres é: %.2f\n", media_mulheres);
}