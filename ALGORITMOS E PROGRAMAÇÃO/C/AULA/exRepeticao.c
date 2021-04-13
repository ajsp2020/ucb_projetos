#include<stdio.h>
#include<locale.h>
#include<string.h>
//#include<conio.h>

int main()
{
	char nome[20];
	char sobrenome[20];
	setlocale(LC_ALL, "");
	printf("Digite o seu nome: ");
	scanf("%s", nome);
	scanf("%s", sobrenome);

	for (int i = 0; i < 5; i++)
	{
		printf("Eu, %s %s vou passar em algoritmo com média 10: \n", nome, sobrenome);
		//getch();
	}

	return 0;
}