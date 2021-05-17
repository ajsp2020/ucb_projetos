#include<stdio.h>

int main()
{
	int valores[3] = { 0, 0, 0 };

	for (int i = 0; i < 3; i++)
	{
		printf("Digite o valor %d: ", i + 1);
		scanf("%d", &valores[i]);
		fflush(stdin);
		
		for (int j = 0; j < 3; j++)
		{
			if (i > 0 && valores[i] < valores[j] && i != j)
			{
				int valor = valores[i];
				valores[i] = valores[j];
				valores[j] = valor;
				

			}
		}
	}
	for (int i = 0; i < 3; i++) printf("Valor %d\n", valores[i]);
}