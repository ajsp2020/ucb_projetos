#include<stdio.h>

int main()
{
	int preco;
	int ingresso = 120;
	float despesas = 600;
	float lucroMaximo = 0;
	float lucro;
	int valorIngresso;
	float valorPreco;
	int j = 0;

	for (preco = 15; preco >= 3; preco -= 3)
	{
		lucro = preco * ingresso - despesas;
		printf("Lucro maximo para quantidade de ingressos de %d vendidos ao preco de  %d reais: %.2f reais\n", ingresso, preco, lucro);
		

		if (lucro > lucroMaximo)
		{
			lucroMaximo = lucro;
			valorIngresso = ingresso;
			valorPreco = preco;
		}

		ingresso += 26;
	}

	printf("Lucro maximo: %.2f\n", lucroMaximo);
	printf("Preco: %.2f\n", valorPreco);
	printf("Numero de ingressos: %d\n", valorIngresso);
}