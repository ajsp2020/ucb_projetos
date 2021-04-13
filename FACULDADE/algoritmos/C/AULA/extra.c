status = scanf("")

void validavelocidade(int status, int temp, int imput, int* velocidade) {
	while (status != 1)
	{
		while ((temp = getchar()) != EOF && temp != '\n');
		printf("Input invalido.... por favor digite a velocidade: ");
		status = scanf("%d", velocidade);
	}
}
validavelocidade(status, temp, input, velocidade);