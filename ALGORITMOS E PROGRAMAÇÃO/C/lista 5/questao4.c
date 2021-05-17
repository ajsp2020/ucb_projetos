#include<stdio.h>
#include<locale.h>
int main()
{
	setlocale(LC_ALL, "");
	int moveis;
	printf("Digite o indice do móvel que gostaria: \n");
	printf("1-cadeira \n2-mesa de computador \n3-estante de livros \n4-mesa de impressora \n5-estante de CD\n");
	scanf("%d", &moveis);

	switch (moveis)
	{
	case 1:
		printf("Cadeira");
		break;
	case 2:
		printf("Mesa de computador");
		break;
	case 3:
		printf("Estante de livros");
		break;
	case 4:
		printf("Mesa de impressora");
		break;
	case 5:
		printf("Estante de CD");
		break;

	default:
		printf("Móvel não disponível");
		break;
	}

	return 0;

}