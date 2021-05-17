#include <stdio.h>

int main() // FALTA TERMINAR
{
	char sexo;
	float alturas[50];
	float altura_mulheres[50];
	int i = 0;
	int mulheres = 0;
	do {
		fflush(stdin);
		printf("Digite o sexo (M - Masculino | F - Feminino): \n");
		scanf("%c", &sexo);
		printf("Digite a altura: \n");
		scanf("%f", &alturas[i]);

		if (sexo == 'F')
		{
			altura_mulheres[mulheres] = alturas[i];
			mulheres++;
		}
		i++;
	} while (i < 5);

	int podeSair;
	do {
		for (int j = 0; j < sizeof(alturas); i++)
		{
			if (alturas[i] > alturas[i + 1])
			{
				int altura = alturas[i + 1];
				alturas[i] = alturas[i + 1];
				alturas[i + 1] = altura;
			}			
		}
		for (int j = 0; j < sizeof(alturas); i++) 
		{
			int podeSair = alturas[0] < alturas[j];
		}
		
	} while (!podeSair);

	printf("A menor altura é: %d", alturas[0]);
}