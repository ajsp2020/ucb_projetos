#include<stdio.h>


int main()
{
	int numeros[100];
	int n = 0, contagem = 0;
	do {
		printf("Digite um valor: ");
		scanf("%d", &numeros[n]);
		n++;

	} while (n < 100);

	for (int i = 0; i < n; i++)
	{
		if (numeros[i] < 0)
		{
			printf("%d", contagem);
			break;
		}
		else {
			contagem++;
		}
	}

	
}