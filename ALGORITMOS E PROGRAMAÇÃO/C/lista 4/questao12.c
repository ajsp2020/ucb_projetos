#include <stdio.h>

int main()
{
	int resposta, candidato1 = 0, candidato2 = 0, candidato3 = 0, candidato4 = 0, nulo = 0, branco = 0;
	do {

		printf("Digite: \n");
		printf("1 - Candidato 1:\n");
		printf("2 - Candidato 2:\n");
		printf("3 - Candidato 3:\n");
		printf("4 - Candidato 5:\n");
		printf("5 - Voto nulo:\n");
		printf("6 - Voto em branco:\n");
		printf("0 - finalizador:\n");
		scanf("%d", &resposta);

		switch (resposta)
		{
		case 1:
			candidato1++;
			break;
		case 2:
			candidato2++;
			break;
		case 3:
			candidato3++;
			break;
		case 4:
			candidato4++;
			break;
		case 5:
			nulo++;
			break;
		case 6:
			branco++;
			break;
		default:
			break;
		}

	} while (resposta != 0);

	int total = candidato1 + candidato2 + candidato3 + candidato4 + branco + nulo;

	printf("O total de votos para cada candidato e sem percentual sobre o total:\n");
	printf("Candidado 1: %d\t%.2f\n", candidato1, (float)candidato1 / (float)total * 100);
	printf("Candidado 2: %d\t%.2f\n", candidato2, (float)candidato2 / (float)total * 100);
	printf("Candidado 3: %d\t%.2f\n", candidato3, (float)candidato3 / (float)total * 100);
	printf("Candidado 4: %d\t%.2f\n", candidato4, (float)candidato4 / (float)total * 100);
	printf("Nulo: %d\t%.2f\n", nulo, (float)nulo / (float)total * 100);
	printf("Branco: %d\t%.2f\n", branco, (float)branco / (float)total * 100);

	return 0;

}