#include<stdio.h>
#include<locale.h>

int main()
{
	setlocale(LC_ALL, "");
	int mes;
	int dia;

	printf("Digite o dia: ");
	scanf("%d", &dia);

	printf("Digite o mês: ");
	scanf("%d", &mes);

	switch (mes)
	{
	case 1:
		if (dia <= 20 && dia > 0) printf("Capricórnio");
		else if (dia > 20 && dia <= 31) printf("Aquário");
		break;

	case 2:
		if (dia <= 20 && dia > 0) printf("Aquário");
		else if (dia > 20 && dia <= 28) printf("Peixes");
		break;

	case 3:
		if (dia <= 20 && dia > 0) printf("Peixes");
		else if (dia > 20 && dia <= 31) printf("Áries");
		break;

	case 4:
		if (dia <= 20 && dia > 0) printf("Áries");
		else if (dia > 20 && dia <= 30) printf("Touro");
		break;

	case 5:
		if (dia <= 20 && dia > 0) printf("Touro");
		else if (dia > 20 && dia <= 31) printf("Gêmeos");
		break;

	case 6:
		if (dia <= 20 && dia > 0) printf("Gêmeos");
		else if (dia > 20 && dia <= 30) printf("Câncer");
		break;

	case 7:
		if (dia <= 20 && dia > 0) printf("Câncer");
		else if (dia > 20 && dia <= 31) printf("Leão");
		break;

	case 8:
		if (dia <= 20 && dia > 0) printf("Leão");
		else if (dia > 20 && dia <= 31) printf("Virgem");
		break;

	case 9:
		if (dia <= 20 && dia > 0) printf("Virgem");
		else if (dia > 20 && dia <= 30) printf("Libra");
		break;

	case 10:
		if (dia <= 20 && dia > 0) printf("Libra");
		else if (dia > 20 && dia <= 31) printf("Escorpião");
		break;

	case 11:
		if (dia <= 20 && dia > 0) printf("Escorpião");
		else if (dia > 20 && dia <= 30) printf("Sargitário");
		break;

	case 12:
		if (dia <= 20 && dia > 0) printf("Sargitário");
		else if (dia > 20 && dia <= 31) printf("Capricórnio");
		break;

	default:
		break;
	}


}