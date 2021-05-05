#include <stdio.h>
#include <locale.h>

//int calculaFactorial(int n)
//{
//	if (n == 0) return 1;
//	else return (n * calculaFactorial(n - 1));
//}


int main()
{
	int n, valor = 1;
	setlocale(LC_ALL, "");
	printf("Digite o valor de n: ");
	scanf("%d", &n);
	//valor = calculaFactorial(n);

	while (n >= 1)
	{
		valor *= n;
		n--;
	}
	printf("O factorial de %d é: %d", n, valor);
}