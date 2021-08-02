#include<stdio.h>

int main()
{
	for (int i = 1; i < 7; i++)
	{
		for (int j = 1; j < 7; j++)
		{
			if (i + j == 7) printf("DADO 1: %d, DADO 2: %d, SOMA: %d\n", i, j, i + j);
		}
	}
}