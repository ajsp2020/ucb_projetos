#include <stdio.h>

int main() {
	int a, b, soma;

	printf("Digite o primeiro valor: ");
	scanf("%d", &a);

	printf("Digite o segundo valor: ");
	scanf("%d", &b);

	soma = a + b;

	printf("%d + %d = %d \n", a, b, soma);

	return 0;
}