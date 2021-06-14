#include<stdio.h>
#include<string.h>
#include<locale.h>
#include<ctype.h>
#include<stdlib.h>
#include<time.h>

#define TAM_RESERVA 200
#define QTD_ASSENTOS 204
#define QTD_VOOS 27

int main()
{
	setlocale(LC_ALL, "Portuguese");
	char destinosNacionais[QTD_VOOS][40] = { "Rio Branco", "Maceio", "Macapa", "Manaus", "Salvador", "Fortaleza", "Brasilia", "Vitoria", "Goiania", "Sao Luis",
											"Cuiaba", "Campo Grande", "Belo Horizonte", "Belem", "Joao Pessoa", "Curitiba", "Recife", "Teresina", "Rio de Janeiro",
											"Natal", "Porto Alegre", "Porto Velho", "Boa Vista", "Florianopolis", "Sao Paulo", "Aracaju", "Palmas" };
	char destino[40], resposta;
	float precoReal;
	int preco, sairDoPrograma = 2;

	int assentosDestinosNacionais[QTD_VOOS][QTD_ASSENTOS];
	for (int i = 0; i < QTD_VOOS; i++)
	{
		for (int j = 0; j < QTD_ASSENTOS; j++)assentosDestinosNacionais[i][j] = 0;
	}
	for (int i = 0; i < QTD_VOOS; i++) assentosDestinosNacionais[i][0] = i;
	
	int lista = 0; // Variavel que controla o ponteiro da lista de reservas
	/* INICIO: CRIANDO UM ARRAY COM TODAS AS RESERVAS POSSÍVEIS */

	// reserva = {numero da reserva/ voo/ poltronas/ preço }
	int reservas[TAM_RESERVA];
	for (int i = 0; i < TAM_RESERVA; i++) reservas[i] = 0;

	/* FIM: CRIANDO UM ARRAY COM TODAS AS RESERVAS POSSÍVEIS */

	// 0 -> Lugares disponíveis;
	// 1 -> Lugares com reserva;
	// 2 -> Lugares Comfirmados;

	char respostaSaida1;

	do {// INCIO DO WHILE MENU:

		/* INICIO: CRIANDO UM MENU: */
		int respostaMenu, valoresValidos;
		do {
			system("cls");
			printf("*****************************************************************************************************************************\n");
			printf("*                                                                                                                           *\n");
			printf("*                                                 SALUMAR LINHAS AEREAS                                                     *\n");
			printf("*                                                                                                                           *\n");
			printf("*****************************************************************************************************************************\n");
			printf("*                                                          MENU                                                             *\n");
			printf("*                                                                                                                           *\n");
			printf("*****************************************************************************************************************************\n");
			printf("*                                                                                                                           *\n");
			printf("*     - DIGITE:                                                                                                             *\n");
			printf("*                                                                                                                           *\n");
			printf("*     1 - SAIR:                                                                                                             *\n");
			printf("*     2 - CADASTRAR VOO:                                                                                                    *\n");
			printf("*     3 - FAZER UMA RESERVA:                                                                                                *\n");
			printf("*     4 - CONFIRMAR UMA RESERVA:                                                                                            *\n");
			printf("*     5 - CANCELAR UMA RESERVA:                                                                                             *\n");
			printf("*     6 - DADOS DO VOO:                                                                                                     *\n");
			printf("*     7 - DADOS DA RESERVA:                                                                                                 *\n");
			printf("*                                                                                                                           *\n");
			printf("*****************************************************************************************************************************\n");
			fflush(stdin);
			printf("          ==> ");
			int status = scanf(" %d", &respostaMenu);

			valoresValidos = (respostaMenu >= 1 || respostaMenu <= 7) && status == 1;
			system("cls");

		} while (!valoresValidos);
		/* FIM: CRIANDO UM MENU. */

		switch (respostaMenu)
		{
		case 1:;

			int status;
			do {
				fflush(stdin);
				printf(" - DESEJA SAIR DO PROGRAMA?\n");
				printf(" 1 - SIM:\n");
				printf(" 2 - NÃO:\n");
				printf("     ==> ");
				status = scanf("%d", &sairDoPrograma);

			} while (status != 1 && (sairDoPrograma != 1 || sairDoPrograma != 2));
			break;

		case 2:;

			/* 2 -> INICIO: ADICIONAR QUANTIDADE DE ASSENTOS E O PREÇO PARA O DESTINO: */
			int adicionarVoos, naoEncontrou = 0;
			do {
				fflush(stdin);
				printf(" - DESTINO: \n");
				printf("   ==> ");
				fgets(destino, 40, stdin);
				system("cls");
				for (int voo = 0; voo < QTD_VOOS; voo++)
				{
					int status = 0;
					int respostaValida;

					if (strncmp(destinosNacionais[voo], destino, 5) == 0)
					{
						/* 2.1 -> inicio: pega a quantidade de assento: */
						if (assentosDestinosNacionais[voo][1] != 0)
						{
							printf(" - VOO JÁ CADASTRADO! - \n");
							system("pause");
							break;
						}
						do {
							fflush(stdin);

							printf(" - QUANTIDADE DE ASSENTOS EXISTENTES PARA: %s \n", destinosNacionais[voo]);
							printf("   ==> ");
							status = scanf("%d", &assentosDestinosNacionais[voo][1]);

							respostaValida = assentosDestinosNacionais[voo][1] >= 90 && assentosDestinosNacionais[voo][1] <= 200 && status == 1;

						} while (!respostaValida);
						/* 2.1 -> fim: pega a quantidade de assento: */

						/* 2.2 -> inicio: pega o preço do assento: */
						do {
							fflush(stdin);

							printf(" - PREÇO DA PASSAGEM PARA: %s \n", destinosNacionais[voo]);
							printf("   ==> ");
							status = scanf("%f", &precoReal);
							assentosDestinosNacionais[voo][2] = precoReal * 100;

							respostaValida = status == 1;

						} while (!respostaValida);

						/* 2.2 -> fim: pega o preço do assento: */
					}
					else naoEncontrou++;

					if (naoEncontrou == QTD_VOOS)
					{
						printf(" - DESTINO NÃO ENCONTRADO\n");
						system("pause");
					}
				}
			
				int valoresValidos;
				do {
					system("cls");
					fflush(stdin);
					printf(" - DESEJA ADICIONAR OUTRO VOO?  \n");
					printf(" 1 - SIM: \n");
					printf(" 2 - NÃO: \n");
					printf("     ==> ");
					int status = scanf(" %d", &adicionarVoos);

					valoresValidos = (adicionarVoos == 1 || adicionarVoos == 2) && status == 1;
					system("cls");
				} while (!valoresValidos);

			} while (adicionarVoos == 1);

			break;

			/* 2 -> INICIO: ADICIONAR QUANTIDADE DE ASSENTOS E O PREÇO PARA O DESTINO: */

		case 3:; 

			/* 3 -> INICIO: FAZER UMA RESERVA */
			
			int temDestino = 0, voo, numeroVoo, numeroAssento, numeroIdade;
				
			fflush(stdin);
			printf(" - DIGITE O DESTINO: \n");
			printf("   ==> ");
			fgets(destino, 40, stdin);

			/* 3.1 -> Inicio: pega o número do voo */
			for (int i = 0; i < QTD_VOOS; i++)
			{

				if (strncmp(destinosNacionais[i], destino, 5) == 0)
				{
					voo = i;
					temDestino = 1;
				}
			}
			/* 3.1 -> Fim: pega o número do voo */

			/* 3.2 -> Início: Gera um código de reserva, cria um mapa, pega a poltrona */
			if (temDestino == 1 && assentosDestinosNacionais[voo][1] != 0)
			{
				system("cls");
				printf(" - DESTINO: %s\n", destinosNacionais[voo]);

				/* 3.2.1 -> Início: confirma se quer fazer uma reserva */
				int fazerReserva;
				int valoresValidos;
				do { 

					fflush(stdin);
					printf(" - DESEJA FAZER UMA RESERVA?  \n"); 
					printf(" 1 - SIM: \n");
					printf(" 2 - NÃO: \n");
					printf(" ==> ");
					int status = scanf(" %d", &fazerReserva);

					valoresValidos = (fazerReserva == 1 || fazerReserva == 2) && status ==1;
					system("cls");
				} while (!valoresValidos); 
				/* 3.2.1 -> Fim: confirma se quer fazer uma reserva */

				/* 3.2.2 -> Inicio: Cria um código de reserva único e adiciona na lista de reservas seu numero e voo correspondente */
				if (fazerReserva == 1)
				{
					int  temIgual, temNaLista;

					srand((unsigned)time(NULL));
					int reserva = 1 + (rand() % 1000);
					do {

						for (temNaLista = 0; temNaLista < TAM_RESERVA; temNaLista += 14) temIgual = reservas[temNaLista] == reserva;
						if (temIgual) reserva = 1 + (rand() % 1000);
						else
						{
							reservas[lista] = reserva; // O primeiro vai receber a reserva
							numeroVoo = lista + 1;
							reservas[numeroVoo] = voo; // O segundo recebe o voo					
							numeroAssento = numeroVoo + 1;
							numeroIdade = numeroAssento + 6;								
						}

					} while (temIgual == reserva);

					lista += 14;
				/* 3.2.2 -> Fim: Cria um código de reserva único e adiciona na lista de reservas seu numero e voo correspondente */

					/* 3.2.4 -> Inicio: Pega o assento e a idade do passageiro, calcula o preco e atualiza os dados da reserva */

					printf("\n\n");
					char fileira;
					int letraFileira, numeroFileira, posicao, idade, numeroValido = 0;
					int sairReserva;
					// Pegando o assento e a idade
					fflush(stdin);
					do { 
						/* 3.2.3 -> Inicio: Cria um mapa do avião com a ocupação das pontronas */

						do {

							printf(" - NUMERO DA RESERVA: %d\n", reserva);
							printf(" - DESTINO: %s\n", destinosNacionais[voo]);
							printf(" - TOTAL DE ASSENTOS: %d\n", assentosDestinosNacionais[voo][1]); // colocar o assento disponivel menos oq ja foi escolhido
							printf(" - MAPA DAS POLTRONAS: \n\n");


							int corredor = 1;
							printf("D - DISPONÍVEL\n"
								"R - RESERVADO\n"
								"C - CONFIRMADO\n");

							printf("\n\t\t\t\t\t\t   a b c        d e f\n");
							for (int i = 0; i < assentosDestinosNacionais[voo][1]; i++)
							{

								if (i % 3 == 0) printf("\t");
								if (i % 6 == 0) printf("\n");
								if (i % 6 == 0 || i == 0)
								{
									if (corredor < 10) printf("\t\t\t\t\t\t %d ", corredor);
									else printf("\t\t\t\t\t\t%d ", corredor);

									corredor++;
								}
								if (assentosDestinosNacionais[voo][i + 4] == 0)
								{
									printf("\033[0;32m");
									printf("D ");
									printf("\033[0;37m");
								}
								else if (assentosDestinosNacionais[voo][i + 4] == 1)
								{
									printf("\033[0;31m");
									printf("R ");
									printf("\033[0;37m");
								}

								else if (assentosDestinosNacionais[voo][i + 4] == 2)
								{
									printf("\033[0;34m");
									printf("C ");
									printf("\033[0;37m");
								}
							}
							/* 3.2.3 -> Fim: Cria um mapa do avião com a ocupação das pontronas */

							printf("\n");
							fflush(stdin);
							printf(" - QUAL ASSENTO DESEJA RESERVAR? \n");
							printf("   ==> ");
							scanf("%d %c", &numeroFileira, &fileira);

							char letrasValidas[6][1] = { 'a', 'b', 'c', 'd', 'e', 'f' };
							
							if (isalpha(fileira) != 0 && isdigit(numeroFileira) == 0 && numeroFileira < corredor && numeroFileira > 0) numeroValido = 1;
							else
							{
								printf(" - INPUT INVÁLIDO - \n");
								system("pause");
							}

							system("cls");

						} while (!numeroValido);

					int idadeValida;
					do {
							
						printf(" - QUAL A IDADE DO PASSAGEIRO? \n");
						printf("   ==> ");
						scanf("%d", &idade);

						idadeValida = idade >= 0 && idade <= 120;
						if (!idadeValida)
						{
							printf(" - INPUT INVÁLIDO - \n");
							system("pause");
							system("cls");
						}

					} while (!idadeValida);
					

					// Calculando o preço por passagem
					if (idade <= 5) preco = assentosDestinosNacionais[voo][2] * 0.5;
					else preco = assentosDestinosNacionais[voo][2];

					// Encontrando a posição da poltrona
					if (fileira == 'a') letraFileira = 0;
					else if (fileira == 'b') letraFileira = 1;
					else if (fileira == 'c') letraFileira = 2;
					else if (fileira == 'd') letraFileira = 3;
					else if (fileira == 'e') letraFileira = 4;
					else if (fileira == 'f') letraFileira = 5;

					posicao = letraFileira + (numeroFileira - 1) * 6;

					// atualizando os dados da reserva
					if (assentosDestinosNacionais[voo][posicao + 4] != 0)
					{
						printf("\n - O ASSENTO NÃO PODE SER RESERVADO - \n");
						system("pause");
					}
					else
					{
						if (numeroAssento > numeroVoo && numeroAssento < numeroVoo + 7)
						{
							assentosDestinosNacionais[voo][posicao + 4] = 1;
							reservas[numeroAssento] = posicao;
							reservas[numeroIdade] = preco;
							numeroAssento++;
							numeroIdade++;
						}
						else
						{
							printf(" - NÃO É PERMITIDO RESERVAR MAIS POLTRONAS - \n");
						}

					}
					/* 3.2.4 -> Fim: Pega o assento e a idade do passageiro e atualiza os dados da reserva */

					do { 
						fflush(stdin);
						printf("cls");
						printf(" - DESEJA RESERVAR MAIS UM ASSENTO? \n"); 
						printf(" 1 - SIM: \n");
						printf(" 2 - NÃO: \n");
						printf("     ==> ");
						int status = scanf(" %d", &sairReserva);

						valoresValidos = (sairReserva == 1 || sairReserva == 2) && status == 1;

					} while (!valoresValidos); 

					system("cls");
				
					} while (sairReserva == 1);
				} 
			/* 3.2 -> Início: Gera um código de reserva, cria um mapa, pega a poltrona */
			}
			else
			{
				if (temDestino != 1) printf(" - DESTINO NÃO ENCONTRADO! - \n");
				else if (assentosDestinosNacionais[voo][1] == 0) printf(" - VOO NÃO CADASTRADO! - \n");
				system("pause");
			}

			/* 3 -> FIM: FAZER UMA RESERVA */
			break;

		case 4:; // CONFIRMAR UMA RESERVA: 
			/* 4 -> INICIO:  CONFIRMAR UMA RESERVA */

			int codigoReserva;
			printf(" - DIGITE O CÓDIGO DA RESERVA:\n");
			printf("   ==> ");
			scanf("%d", &codigoReserva);

			/* 4.1 -> Inicio: Imprimindo o código da reserva, o destino, o assento e seu valor */

			float valor, soma = 0;

			for (int i = 0; i < TAM_RESERVA; i += 14)
			{
				if (reservas[i] == codigoReserva)
				{
					printf(" - CÓDIGO DE RESERVA: %d\n", reservas[i]);
					printf(" - DESTINO: %s\n", destinosNacionais[reservas[i + 1]]);

					// Imprimindo a poltrona e seu valor
					for (int poltrona = i + 2; poltrona < i + 8; poltrona++)
					{
						if (reservas[poltrona] != 0) 
						{
							for (int fileiraNumero = 0; fileiraNumero < 33; fileiraNumero++)
							{
								for (int fileiraLetra = 0; fileiraLetra < 6; fileiraLetra++)
								{
									if (reservas[poltrona] == fileiraLetra + fileiraNumero * 6)
									{
										switch (fileiraLetra)
										{
										case 0:;
											valor = (float)reservas[poltrona + 6] / 100;
											printf("POLTRONA: %dA \n", fileiraNumero + 1);
											printf("PREÇO: R$ %.2f\n", valor);
											break;

										case 1:
											valor = (float)reservas[poltrona + 6] / 100;
											printf("POLTRONA: %dB \n", fileiraNumero + 1);
											printf("PREÇO: R$ %.2f\n", valor);
											break;

										case 2:
											valor = (float)reservas[poltrona + 6] / 100;
											printf("POLTRONA: %dC \n", fileiraNumero + 1);
											printf("PREÇO: R$ %.2f\n", valor);
											break;

										case 3:
											valor = (float)reservas[poltrona + 6] / 100;
											printf("POLTRONA: %dD \n", fileiraNumero + 1);
											printf("PREÇO: R$ %.2f\n", valor);
											break;

										case 4:
											valor = (float)reservas[poltrona + 6] / 100;
											printf("POLTRONA: %dE \n", fileiraNumero + 1);
											printf("PREÇO: R$ %.2f\n", valor);
											break;

										case 5:
											valor = (float)reservas[poltrona + 6] / 100;
											printf("POLTRONA: %dF \n", fileiraNumero + 1);
											printf("PREÇO: R$ %.2f\n", valor);
											break;

										default:
											break;
										}										
									}
								}
							}
						}	

						soma += (float)reservas[poltrona + 6] / 100;
						
					}

					// Imprindo o valor total
					printf(" - TAXA DE EMBARQUE: R$ 35,00\n");
					printf(" - PREÇO TOTAL: R$ %.2f\n\n", soma + 35.00);

					// Confirmando a reserva
					int status;
					do {
						fflush(stdin);
						printf(" - DESEJA CONFIRMAR A RESERVA?\n");
						printf(" 1 - SIM:\n");
						printf(" 2 - NÃO:\n");
						printf("     ==> ");
						status = scanf("%d", &resposta);

					} while (status != 1 && (resposta != 1 || resposta != 2));
					
					// Atualizando o voo
					if (resposta == 1) 
					{
						for (int poltrona = i + 2; poltrona < i + 8; poltrona++)
						{
							if (reservas[poltrona] != 0)
							{
								int somaInteira = soma * 100;
								voo = reservas[i + 1];
								assentosDestinosNacionais[voo][3] += somaInteira; // <<< Arrumar a sona que está imprimindo em dados do voo com o valor errado e arrumar melhor o código
								assentosDestinosNacionais[voo][reservas[poltrona] + 4] = 2;
							}
						}
					}
				}
				/* 4.1 -> Fim: Imprimindo o código da reserva, o destino, o assento e seu valor */
			}		
			/* 4 -> FIM:  CONFIRMAR UMA RESERVA */

			break;
			
		case 5: 
			/* 5 -> INICIO: CANCELAMENTO DA RESERVA*/
			
			printf(" - DIGITE O CÓDIGO DA RESERVA:\n");
			printf("   ==> ");
			scanf("%d", &codigoReserva);

			/* 5.1 -> INICIO: IMPRIMIDO O CÓDIGO DA RESERVA, O DESTINO */


			for (int i = 0; i < TAM_RESERVA; i += 14)
			{
				if (reservas[i] == codigoReserva)
				{
					printf(" - CÓDIGO DE RESERVA: %d\n", reservas[i]);
					printf(" - DESTINO: %s\n", destinosNacionais[reservas[i + 1]]);

					/* 5.1 -> FIM: IMPRIMIDO O CÓDIGO DA RESERVA, O DESTINO */

					/* 5.2 -> INÍCIO: CONFIRMAR SE DESEJA CANCELAR A RESERVA */

					//int status;

					do { // Validando a resposta.
						fflush(stdin);
						printf(" - DESEJA CANCELAR A RESERVA?\n");
						printf(" 1 - SIM:\n");
						printf(" 2 - NÃO:\n");
						printf("     ==> ");
						status = scanf("%d", &resposta);

					} while (status != 1 && (resposta != 1 || resposta != 2));

					/* 5.2 -> FIM: CONFIRMAR SE DESEJA CANCELAR A RESERVA */

					/* 5.3 -> INICIO: ATUALIZANDO O SISTEMA DO VOO */

					for (int i = 0; i < TAM_RESERVA; i += 14)
					{
						if (reservas[i] == codigoReserva)
						{
							if (resposta == 1)
							{
								for (int poltrona = i + 2; poltrona < i + 8; poltrona++)
								{
									if (reservas[poltrona] != 0)
									{
										voo = reservas[i + 1];
										assentosDestinosNacionais[voo][reservas[poltrona] + 4] = 0;
									}
								}
							}
						}
						/* 5.3 -> FIM: ATUALIZANDO O SISTEMA DO VOO */
				}
			}
			
			}
				
			/* 5 -> FIM: CANCELAMENTO DA RESERVA*/
			break;

		case 6:
			/* 6 -> INICIO: DADOS DO VOO */
			fflush(stdin);
			printf(" - DIGITE O DESTINO: \n");
			printf("   ==> ");
			fgets(destino, 40, stdin);

			for (int i = 0; i < QTD_VOOS; i++)
			{

				if (strncmp(destinosNacionais[i], destino, 5) == 0)
				{
					voo = i;
					temDestino = 1;
				}
			}
			int corredor = 1;
			int assentosDisponiveis = 0, assentosReservados = 0, assentosConfirmados = 0;

			for (int poltrona = 0; poltrona < assentosDestinosNacionais[voo][1]; poltrona++)
			{
				if (assentosDestinosNacionais[voo][poltrona + 4] == 0) assentosDisponiveis++;
				else if (assentosDestinosNacionais[voo][poltrona + 4] == 1) assentosReservados++;
				else if (assentosDestinosNacionais[voo][poltrona + 4] == 2) assentosConfirmados++;
			}
			printf("- TOTAL DE ASSENTOS DISPONÍVEIS: %d\n", assentosDisponiveis);
			printf("- TOTAL DE ASSENTOS RESERVADOS: %d\n", assentosReservados);
			printf("- TOTAL DE ASSENTOS CONFIRMADOS: %d\n", assentosConfirmados);
			printf("\n- VALOR TOTAL VENDIDO: R$ %.2f", (float)assentosDestinosNacionais[voo][3] / 100);

			printf("\n\t\t\t\t\t\t   a b c        d e f\n");
			for (int i = 0; i < assentosDestinosNacionais[voo][1]; i++)
			{

				if (i % 3 == 0) printf("\t");
				if (i % 6 == 0) printf("\n");
				if (i % 6 == 0 || i == 0)
				{
					if (corredor < 10) printf("\t\t\t\t\t\t %d ", corredor);
					else printf("\t\t\t\t\t\t%d ", corredor);

					corredor++;
				}
				if (assentosDestinosNacionais[voo][i + 4] == 0)
				{
					printf("\033[0;32m");
					printf("D ");
					printf("\033[0;37m");
				}
				else if (assentosDestinosNacionais[voo][i + 4] == 1)
				{
					printf("\033[0;31m");
					printf("R ");
					printf("\033[0;37m");
				}

				else if (assentosDestinosNacionais[voo][i + 4] == 2)
				{
					printf("\033[0;34m");
					printf("C ");
					printf("\033[0;37m");
				}
			}
			printf("\n");
			system("pause");

			/* 6 -> FIM: DADOS DO VOO */
			break;

		case 7:;

			//int codigoReserva;
			fflush(stdin);
			printf(" - DIGITE O CÓDIGO DA RESERVA:\n");
			printf("   ==> ");
			scanf(" %d", &codigoReserva);

			/* 4.1 -> Inicio: Imprimindo o código da reserva, o destino, o assento e seu valor */

			soma = 0;

			for (int i = 0; i < TAM_RESERVA; i += 14)
			{
				if (reservas[i] == codigoReserva)
				{
					printf(" - CÓDIGO DE RESERVA: %d\n", reservas[i]);
					printf(" - DESTINO: %s\n", destinosNacionais[reservas[i + 1]]);

					// Imprimindo a poltrona e seu valor
					for (int poltrona = i + 2; poltrona < i + 8; poltrona++)
					{
						if (reservas[poltrona] != 0)
						{
							for (int fileiraNumero = 0; fileiraNumero < 33; fileiraNumero++)
							{
								for (int fileiraLetra = 0; fileiraLetra < 6; fileiraLetra++)
								{
									if (reservas[poltrona] == fileiraLetra + fileiraNumero * 6)
									{
										switch (fileiraLetra)
										{
										case 0:;
											valor = (float)reservas[poltrona + 6] / 100;
											printf("POLTRONA: %dA \n", fileiraNumero + 1);
											printf("PREÇO: R$ %.2f\n", valor);
											break;

										case 1:
											valor = (float)reservas[poltrona + 6] / 100;
											printf("POLTRONA: %dB \n", fileiraNumero + 1);
											printf("PREÇO: R$ %.2f\n", valor);
											break;

										case 2:
											valor = (float)reservas[poltrona + 6] / 100;
											printf("POLTRONA: %dC \n", fileiraNumero + 1);
											printf("PREÇO: R$ %.2f\n", valor);
											break;

										case 3:
											valor = (float)reservas[poltrona + 6] / 100;
											printf("POLTRONA: %dD \n", fileiraNumero + 1);
											printf("PREÇO: R$ %.2f\n", valor);
											break;

										case 4:
											valor = (float)reservas[poltrona + 6] / 100;
											printf("POLTRONA: %dE \n", fileiraNumero + 1);
											printf("PREÇO: R$ %.2f\n", valor);
											break;

										case 5:
											valor = (float)reservas[poltrona + 6] / 100;
											printf("POLTRONA: %dF \n", fileiraNumero + 1);
											printf("PREÇO: R$ %.2f\n", valor);
											break;

										default:
											break;
										}
									}
								}
							}
						}

						soma += (float)reservas[poltrona + 6] / 100;

					}

					// Imprindo o valor total
					printf(" - TAXA DE EMBARQUE: R$ 35,00\n");
					printf(" - PREÇO TOTAL: R$ %.2f\n\n", soma + 35.00);
					if (assentosDestinosNacionais[reservas[i + 1]][reservas[i + 2] + 4] == 1) printf(" - RESERVA NÃO CONFIRMADA - \n");
					else if (assentosDestinosNacionais[reservas[i + 1]][reservas[i + 2] + 4] == 2) printf(" - RESERVA CONFIRMADA -\n");
					system("pause");
					break;
				}
			}
		default:

			break;

		}  // FIM DO WHILE MENU:
		system("cls");
	} while (sairDoPrograma != 1);  // FINAL SWITH CASA MENU:
}