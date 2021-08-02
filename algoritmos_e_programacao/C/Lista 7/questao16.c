#include<stdio.h>

int main()
{
	int vetorA[10] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	int vetorB[10] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	int vetorC[10];
	int valor;

	for (int i = 0; i < 10; i++)
	{
		vetorC[i] = vetorA[i] + vetorB[i];
	}

	printf("Qual vetor deseja procurar? ");
	scanf("%d", &valor);

	if(valor >= 0 && valor < 10) printf("%d + %d = %d",vetorA[valor], vetorB[valor], vetorC[valor]);
	

}