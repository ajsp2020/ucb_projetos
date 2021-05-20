#include<stdio.h>


int main()
{
	int numero;
	printf("Digite um caractere: ");
	numero = getchar();


	printf("Valor em hexadecimal: ");
	unsigned i;
	for (i = 1 << 31; i > 0; i = i / 2) (numero & i) ? printf("1") : printf("0");
		
	printf("\n");
	printf("valor em decimal: %d\n", numero);
	printf("valor em Hexadecimal: %X\n", numero);
}