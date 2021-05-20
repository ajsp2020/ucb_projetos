#include<stdio.h>
#include<locale.h>

int main()
{
	int soma[20];
	for (int i = 0; i < 20; i++)
	{	
		if (i == 0) soma[i] = 0;
		if (i == 1) soma[i] = 1;
		if (i == 2) soma[i] = 1;
		if (i > 2) soma[i] = soma[i - 1] + soma[i - 2];

		printf("%d\t", soma[i]);
	}
}