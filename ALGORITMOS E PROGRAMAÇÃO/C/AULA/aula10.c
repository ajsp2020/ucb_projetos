#include <stdio.h>

int main()
{
	char opcao;
	//printf("Deseja entrar no laco?? ");
	//scanf("%c", &opcao);

	//while (opcao == 'S' || opcao == 's')
	//{
	//	printf("Sim, eu quero repetir!");
	//	printf("Deseja entrar no laco novamente?? ");
	//	scanf("%c", &opcao);
	//}

	do
	{
		printf("Entrei no loop\n");
		printf("Deseja entrar no loop novamente?");
		scanf("%c", &opcao);
		fflush(stdin);


	} while (opcao == 'S');
}