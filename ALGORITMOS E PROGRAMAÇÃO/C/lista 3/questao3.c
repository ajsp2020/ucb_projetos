#include <stdio.h>
#include<locale.h>


int main()
{
	float alturas[10];

	for (int i = 0; i < 10; i++)
	{
		printf("Digite a altura %d ", i);
		scanf("%d", &alturas[i]);
		fflush(stdin);
	}
	int j = 1;
	float altura;
	while (j < 10)
	{
		
		if (alturas[0] > alturas[j])
		{
			altura = alturas[j];
			alturas[j] = alturas[0];
			alturas[0] = altura;
		}
		j++;
	}

	printf("%d", alturas[0]);
}