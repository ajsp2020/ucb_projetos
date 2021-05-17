#include<stdio.h>

int main()
{
	char sexo;
	float alturas[4];
	float altura_mulheres[50];
	float altura_homens[50];
	int i = 0;
	int mulheres = 0;
	int homens = 0;
	while (i < 4)
	{
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
		else if (sexo == 'M' || sexo == 'm') 
		{
			altura_homens[homens] = alturas[i];
			homens++;
		}
		
		i++;
	} 

	for (int j = 0; j < i - 1; j++)
	{
		for (int k = j + 1; k < i; k++)
		{
			if (alturas[i] > alturas[j])
			{
				float altura = alturas[i];
				alturas[i] = alturas[j];
				alturas[j] = altura;

				printf("Altura:  %d\n", alturas[i]);
			}
		}
	}



	printf("A menor altura eh: %d", alturas[1]);
}