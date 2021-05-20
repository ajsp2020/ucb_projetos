#include <stdio.h>
#include <locale.h>
#include <stdlib.h>

float calculaAumento(float valor)
{
	return valor + valor * 0.1;
}
int main()
{
	float valor;
	int *produto, i;
	float *preco;

	int qtd_produtos;
	int metodo;
	setlocale(LC_ALL, "");

	printf("Escolha o método: ");
	scanf("%d", &metodo);
	switch (metodo)
	{
	case 1:

		printf("Digite a quantidade de produtos que deseja adicionar: ");
		scanf("%d", &qtd_produtos);
		preco = malloc(sizeof(float) * qtd_produtos);
		produto = malloc(sizeof(int) * qtd_produtos);

		for (int i = 0; i < qtd_produtos; i++)
		{
			fflush(stdin);
			printf("Digite o valor do produto %d: ", i + 1);
			scanf("%f", &preco[i]);
			preco[i] = calculaAumento(preco[i]);

			printf("Digite a identificação do produto %d: ", i + 1);
			scanf("%d", &produto[i]);
		}

		for (int i = 0; i < qtd_produtos; i++)
		{
			printf("O novo valor do produto %d é:R$ %.2f \n", produto[i], preco[i]);
		}

		free(produto);
		free(preco);
		break;

	case 2:

		preco = malloc(sizeof(float) * 100);
		produto = malloc(sizeof(int) * 100);
		char resposta;
		i = 0;
		do {

			fflush(stdin);
			printf("Digite o valor do produto %d: ", i + 1);
			scanf("%f", &preco[i]);
			preco[i] = calculaAumento(preco[i]);

			printf("Digite a identificação do produto %d: ", i + 1);
			scanf("%d", &produto[i]);

			printf("Deseja continuar (S - SIM | N - NÃO)? ");
			scanf(" %c", &resposta);

			if (resposta == 'S') i++;
			
		} while (resposta != 'N');

		for (int j = 0; j <= i; j++)
		{
			printf("O novo valor do produto %d é:R$ %.2f \n", produto[j], preco[j]);
		}

		free(produto);
		free(preco);
		break;

	case 3:

		preco = malloc(sizeof(float) * 100);
		produto = malloc(sizeof(int) * 100);
		i = 0;
		do {

			fflush(stdin);
			printf("Digite o valor do produto %d: ", i + 1);
			scanf("%f", &preco[i]);
			if (preco[i] < 0) continue;
			else
			{
				preco[i] = calculaAumento(preco[i]);

				printf("Digite a identificação do produto %d: ", i + 1);
				scanf("%d", &produto[i]);
				i++;
			}

		} while (preco[i] >= 0);

		for (int j = 0; j < i; j++)
		{
			printf("O novo valor do produto %d é:R$ %.2f \n", produto[j], preco[j]);
		}

		free(produto);
		free(preco);
		break;

	default:
		break;
	}

}