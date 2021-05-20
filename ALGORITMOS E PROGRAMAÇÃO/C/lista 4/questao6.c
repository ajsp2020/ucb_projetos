#include <stdio.h>

int main()
{
	int numero;
	printf("Digite o valor de n: ");
	scanf("%d", &numero);

    for (int i = 2; i < numero; i++)
    {
        if ((i % 2 == 0) && (i != 2) ||
            (i % 3 == 0) && (i != 3) ||
            (i % 5 == 0) && (i != 5) ||
            (i % 7 == 0) && (i != 7));

        else
        {
            printf("%d ", i);
        }
    }
  

}