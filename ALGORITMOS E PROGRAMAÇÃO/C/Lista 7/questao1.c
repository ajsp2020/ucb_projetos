#include<stdio.h>

int main()
{
	float notas[30] = {9, 10, 8};

	for (int i = 0; i < 30; i++) printf("%.2f\t", notas[i]);
}