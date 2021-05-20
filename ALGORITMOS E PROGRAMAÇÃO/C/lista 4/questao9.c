#include <stdio.h>

int main()
{
    int numerosecreto = 42;

    int chute;
    int tentativas = 1;


    while (1) {

        printf("Tentativa %d \n", tentativas);
        printf("Qual eh o seu chute? ");

        scanf("%d", &chute);
        printf("Seu chute foi %d \n", chute);

        if (chute < 0) {
            printf("Voce não pode chutar numeros negativos!\n");

            continue; // Impedi que continue de executar o código e ao mesmo tempo permite que o programa continue a rodar 
        }

        int acertou = chute == numerosecreto;
        int maior = chute > numerosecreto;

        if (acertou) {
            printf("Parabens voce acertou em %d tentativas\n", tentativas);
            printf("Jogue novamente! voce eh um bom jogador\n");
            break;
        }
        else if (maior) {
            printf("Seu chute foi maior que o numero secreto\n");
        }
        else {
            printf("Seu chute foi menor que o numero secreto\n");
        }

        tentativas++;
    }
    printf("Fim de jogo! \n");
}