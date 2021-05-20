#include <stdio.h>

int main()
{
	int vinhos_t = 0, vinhos_b = 0, vinhos_r = 0, vinhos_d = 0;
	char resposta;

	do {
		fflush(stdin);
		printf("Digite o vinho que deseja adcionar ou F para sair: ");
		scanf("%c", &resposta);

		switch (resposta)
		{
		case 'T':
			vinhos_t++;
			break;
		case 'B':
			vinhos_b++;
			break;
		case 'R':
			vinhos_r++;
			break;
		case 'D':
			vinhos_d++;
			break;
		default:
			printf("Input invalido:");
			break;
		}
		
	} while (resposta != 'F');

	float somaVinhos = (vinhos_t + vinhos_b + vinhos_r + vinhos_d);

	printf("A porcentagem de vinhos tinto eh: %.2f\n", vinhos_t/somaVinhos * 100);
	printf("A porcentagem de vinhos branco eh: %.2f\n", vinhos_b/somaVinhos * 100);
	printf("A porcentagem de vinhos rose eh: %.2f\n", vinhos_r/somaVinhos * 100);
	printf("A porcentagem de vinhos desconhecido eh: %.2f\n", vinhos_d/somaVinhos * 100);
	
}