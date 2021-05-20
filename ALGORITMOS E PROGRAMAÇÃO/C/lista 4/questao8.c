#include <stdio.h>

int main()
{
	int anos = 0;
	int anacleto = 150;
	int felisberto = 110;

	int mesmaAltura;
	do {
		anos++;
		anacleto += 2 ;
		felisberto += 3;

		mesmaAltura = (anacleto == felisberto);

	} while (!mesmaAltura);

	printf("%d anos", anos);
}