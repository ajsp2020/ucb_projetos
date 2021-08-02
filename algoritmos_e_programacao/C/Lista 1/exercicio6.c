#include <stdio.h>
#include <locale.h>

float notas[2];

void imprimeresultado(float media);

void apresentacao(){

	setlocale(LC_ALL, "");

	printf("Questão Seis\n");
	printf("  Leia 2 valores A e B, que correspondem a 2 notas de um aluno. A seguir, calcule a"
		"média do aluno,\n sabendo que a nota A tem peso 3.5 e a nota B tem peso 7.5 (A soma "
		"dos pesos portanto é 11).\n Assuma que cada nota pode ir de 0 até 10.0.\n");
}
void calculamedia() {
	float media = (notas[0] * 3.5 + notas[1] * 7.5) / 11;
	imprimeresultado(media);
}


void peganotas() {
	float nota;
	for (int i = 0; i < 2; i++) {
		printf("Digite a nota%d: ", i+1);
		scanf("%f", &nota);
		if (nota > 10 || nota < 0) {
			printf("Não é possível acrescentar nota maior que 10 ou negativa.\n");
			peganotas();
			break;
		}
		else {
			notas[i] = nota;
		}
		
	}
	
}
void imprimeresultado(float media) {
	printf("A média do aluno é: %.2f", media);
}


int main() {

	apresentacao();
	
	peganotas();

	calculamedia();
}