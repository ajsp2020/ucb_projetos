#include<stdio.h>

int main()
{
	char maisVoto;
	int candidato, pele = 0, maradona = 0, brancos = 0, nulos = 0;
	do {
		fflush(stdin);
		printf("Digite o seu voto: \n");
		printf("25 - Pele:\n33 -Maradona:\n ");
		scanf("%d", &candidato);

		switch (candidato)
		{
		case 25:
			pele++;
			break;
		case 33:
			maradona++;
			break;
		case 0:
			brancos++;
			break;
		default:
			nulos++;
			break;
		}

		printf("Deseja adicionar mais algum voto? (S/N) ");
		scanf(" %c", &maisVoto);

	} while (maisVoto == 'S'|| maisVoto == 's');


	printf("Quantidade de votos Pele: %d\n", pele);
	printf("Quantidade de votos Maradona: %d\n", maradona);
	printf("Quantidade de votos Brancos: %d\n", brancos);
	printf("Quantidade de votos Nulos: %d\n", nulos);

	if (pele > maradona) printf("O vencedor foi o Pele\n");
	else if (pele < maradona) printf("O vencedor foi o Maradona\n");
	else  printf("Foi empate\n");
}