#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main()
{

	char resposta;
	printf("Digite o sexo (M/F): ");
	scanf("%c", &resposta);

	int codigo;
	codigo = (resposta == 'M') ? 77 : 70;
	codigo = (resposta == 'm') ? 109 : 102;

	switch (codigo)
	{
	case 77:
		printf("Masculino");
		break;

	case 70:
		printf("Feminino");
		break;

	case 109:
		printf("Masculino");
		break;

	case 102:
		printf("Feminino");
		break;

	default:
		break;
	}
}