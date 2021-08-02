#include<stdio.h>
#include<string.h>

int main()
{
	char letras[30];

	
	for (int i = 0; i < 30; i++) 
	{
		printf("Digite as letras: ");
		scanf(" %c", &letras[i]);
	}
	for (int i = 29; i >= 0; i--) printf("%c\t", letras[i]);

}