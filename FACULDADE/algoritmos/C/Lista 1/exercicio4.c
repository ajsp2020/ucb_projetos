#include<stdio.h>

void abertura() {
	printf("Quarta questao:\n");
	printf("Construa um algoritmo que a partir da leitura de dois numeros forneca o resto e o quociente da divisao do primeiro pelo segundo numero. \n\n");
}
int calcularesto(int valor1,int valor2) {
	return valor1 % valor2;
}
int calculaquociente(int valor1,int valor2) {
	return valor1 / valor2;
}
void imprimeresultado(int resto,int quociente){
	printf("O resto eh %d\n", resto);
	printf("O quociente eh %d\n", quociente);
}

void pegavalores(int* valor1, int* valor2) {
	
	printf("Digite o primeiro valor: ");
	scanf("%d", valor1);

	printf("Digite o segundo valor: ");
	scanf("%d", valor2);
}

int main()
{
	int valor1, valor2, resto, quociente;
	abertura();
	pegavalores(&valor1, &valor2);
	resto = calcularesto(valor1, valor2);
	quociente = calculaquociente(valor1, valor2);
	imprimeresultado(resto, quociente);
}