#include<stdio.h>
#include<stdio.h>
#include<string.h>
#include<locale.h>
#include<ctype.h>
#include<stdlib.h>

int main()
{

	char fileira;
	int letraFileira, numeroFileira, posicao, idade;
	int letraEhValida = 0;
	int letraValida;
	int numeroValido = 0;
	int valoresValidos;
	// Pegando o assento e a idade
	fflush(stdin);
	do { // Arrumar <========================

		fflush(stdin);
		printf("\n\nQUAL ASSENTO DESEJA RESERVAR? ");
		scanf("%d %c", &numeroFileira, &fileira);

		if (isalpha(fileira) != 0 && isdigit(numeroFileira) == 0) numeroValido = 1;
		
	} while (!numeroValido);

	printf("TUDO OK");
}