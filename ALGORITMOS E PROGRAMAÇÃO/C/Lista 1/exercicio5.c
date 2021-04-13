#include <stdio.h>
#include<locale.h>

void apresentacao() {
	setlocale(LC_ALL, "");

	printf("Questão Cinco: \n");
	printf("Fazer um algoritmo para auxiliar um construtor a descobrir a quantidade de rolos e a \n"
		"quantidade de metros avulsos de fios que ele precisa adquirir.Sabe - se que o \n"
		"construtor tem a quantidade total de fios em metros a serem utilizados na instalação \n"
		"elétrica da obra e que cada rolo de fio tem 50 metros.\n");

}
void calcularolo(float* rolo, float fio) {
	*rolo =  fio / 50;
}
float calculafio(int rolo, float* fio) {
	if (*fio >= 50) {
		 *fio = *fio - 50 * rolo;
	}
	else {
		return 0;
	}
}
void imprimeresultado(int rolo, float fio) {

	if (fio == 0) {
		printf("Será nescessário %d rolo(s)\n", rolo);
	}
	else {
		if (rolo == 0) {
			printf("Será nescessário %.2f metros de fio\n", fio);
		}
		else {
			printf("Será nescessário %d rolo(s) + %.2f metros de fio\n", rolo, fio);
		}
	}
}

int main() {
	
	float rolo;
	float fio;

	apresentacao();

	printf("Quantidade de fios em metros: ");
	scanf("%f", &fio);

	calcularolo(&rolo, fio);
	calculafio(rolo, &fio);
	imprimeresultado(rolo, fio);

}