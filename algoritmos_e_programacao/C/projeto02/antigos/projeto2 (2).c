#include<stdio.h>
#include<string.h>
#include<locale.h>
#include<ctype.h>
#include<stdlib.h>


int main()
{
	setlocale(LC_ALL, "Portuguese");
	char destinosNacionais[27][40] = { "Rio Branco", "Maceio", "Macapa", "Manaus", "Salvador", "Fortaleza", "Brasilia", "Vitoria", "Goiania", "Sao Luis",
									"Cuiaba", "Campo Grande", "Belo Horizonte", "Belem", "Joao Pessoa", "Curitiba", "Recife", "Teresina", "Rio de Janeiro",
									"Natal", "Porto Alegre", "Porto Velho", "Boa Vista", "Florianopolis", "Sao Paulo", "Aracaju", "Palmas" };
	char destino[40], resposta;
	int destinosNacionaisPosicao[27], assentosExistentes[27];

	for (int i = 0; i < 27; i++) destinosNacionaisPosicao[i] = i;
	for (int i = 0; i < 27; i++) assentosExistentes[i] = 0; // Assentos existentes por voo.

	do {

		int temDestino = 0, posicao, quatidadeAssentos;
		fflush(stdin);
		printf("DESTINO: ");
		fgets(destino, 40, stdin);


		for (int i = 0; i < 27; i++)
		{
			int status = 0;
			int respostaValida;

			if (strncmp(destinosNacionais[i], destino, 5) == 0)
			{
				printf("Destino encontrado\n");
				do {
					fflush(stdin);

					printf("QUANTIDADE DE ASSENTOS EXISTENTES: ");
					status = scanf("%d", &assentosExistentes[i]);

					respostaValida = assentosExistentes[i] >= 90 && assentosExistentes[i] <= 200 && status == 1;

				} while (!respostaValida);
				posicao = i;
				temDestino = 1;
				break;
			}
		}

		if (temDestino == 1)
		{
			system("cls");

			printf("DESTINO: %s\n", destinosNacionais[posicao]);

			switch (posicao)
			{
			case 0:
				quatidadeAssentos = assentosExistentes[posicao]; // Quantidade de assentos disponíveis

				printf("QUANTIDADE DE ASSENTOS DISPONÍVEIS: %d", quatidadeAssentos);

				int rioBranco[200];

				for (int i = 0; i < quatidadeAssentos; i++) rioBranco[i] = 0; // Zero para o assento vazio

				printf("PREÇO ");
				break;

			default:
				break;
			}
		}
		else
		{
			fflush(stdin);
			printf("Destino não encontrado! \n");
		}

		int respostaValida;

		do {
			fflush(stdin);
			printf("Deseja Procurar outro destino? (S/N): \n");
			scanf(" %c", &resposta);

			resposta = toupper(resposta);

			if (resposta == 'S')
			{
				main();
				break;
			}
			else if (resposta == 'N') 
			{
				exit(0);
			}

			respostaValida = resposta == 'S' || resposta == 'N';

		} while (!respostaValida);
	
	} while (resposta == 'S');
	
}