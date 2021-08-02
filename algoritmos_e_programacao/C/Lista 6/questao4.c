#include<stdio.h>

int main()
{
	float nascidas;
	printf("Digite o numero de criancas nascidas no periodo: ");
	scanf("%f", &nascidas);

	float morreram;
	printf("Digite a quantidade de criancas que morreram: ");
	scanf("%f", &morreram);

	float porcentagemMortas = (morreram / nascidas) * 100;

	char sexo;
	float masculino = 0;
	float mesesVida;
	float meses = 0;
	int j = 0;
	do
	{
		fflush(stdin);
		printf("Digite o sexo criança (m - masc, f-fem) ou v para sair que morreu: \n");
		scanf("%c", &sexo);

		if (sexo == 'M' || sexo == 'm') masculino++;

		printf("Digite o numero de meses de vida da crianca: \n");
		scanf("%f", &mesesVida);

		if (mesesVida <= 24)  meses++;
		j++;

	} while (j < morreram);

	float porcetagemMasculino = (masculino / morreram) * 100;
	float porcentagemMeses = ((meses) / morreram) * 100;

	printf("porcentagem de criancas mortas no periodo: %.2f %%\n", porcentagemMortas);
	printf("porcentagem de criancas masculinas mortas no periodo: %.2f %%\n", porcetagemMasculino);
	printf("porcentagem de criancas mortas no periodo: %.2f %%\n", porcentagemMeses);
}