#include<stdio.h>
#include<string.h>
#include<locale.h>
#include<ctype.h>
#include<stdlib.h>
#include<time.h>

#define TAM_RESERVA 200

int main()
{
	setlocale(LC_ALL, "Portuguese");
	char destinosNacionais[27][40] = { "Rio Branco", "Maceio", "Macapa", "Manaus", "Salvador", "Fortaleza", "Brasilia", "Vitoria", "Goiania", "Sao Luis",
									"Cuiaba", "Campo Grande", "Belo Horizonte", "Belem", "Joao Pessoa", "Curitiba", "Recife", "Teresina", "Rio de Janeiro",
									"Natal", "Porto Alegre", "Porto Velho", "Boa Vista", "Florianopolis", "Sao Paulo", "Aracaju", "Palmas" };
	char destino[40], resposta;

	float precoReal = 599.49;
	int preco;

	int assentosDestinosNacionais[27][202];
	for (int i = 0; i < 27; i++)
	{
		for (int j = 0; j < 203; j++)assentosDestinosNacionais[i][j] = 0;
	}
	for (int i = 0; i < 27; i++) assentosDestinosNacionais[i][0] = i;
	

	//int assentosExistentes[27];
	//for (int i = 0; i < 27; i++) assentosExistentes[i] = 0; // Assentos existentes por voo.

	int lista = 0; // Variavel que controla o ponteiro da lista de reservas
	/* INICIO: CRIANDO UM ARRAY COM TODAS AS RESERVAS POSSÍVEIS */

	// reserva = {numero da reserva/ voo/ poltronas}
	int reservas[200];
	for (int i = 0; i < 100; i++) reservas[i] = 0;

	/* FIM: CRIANDO UM ARRAY COM TODAS AS RESERVAS POSSÍVEIS */

	/* INICIO: CRIANDO UM ARRAY COM TODOS OS VOOS E VAGANDO TODOS OS LUGARES */

	// 0 -> Lugares disponíveis;
	// 1 -> Lugares com reserva;
	// 2 -> Lugares Comfirmados;

	char rioBranco[200], maceio[200], macapa[200], manaus[200], salvador[200], fortaleza[200], brasilia[200];
	for (int i = 0; i < 200; i++)
	{
		rioBranco[i] = 0;
		maceio[i] = 0;
		macapa[i] = 0;
		manaus[i] = 0;
		salvador[i] = 0;
		fortaleza[i] = 0;
		brasilia[i] = 0;
	}
	/* FIM: CRIANDO UM ARRAY COM TODOS OS VOOS E VAGANDO TODOS OS LUGARES */

	/* INICIO: CRIA A QUANTIDADE DE ASSENTOS CADA VOO VAI TER: */

	char respostaSaida1;

	do {// INCIO DO WHILE MENU:

		/* INICIO: CRIANDO UM MENU: */
		int respostaMenu;
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
		printf("*     1 - ADICIONAR UM DESTINO:                                                                                             *\n");
		printf("*     2 - ADICIONAR QUANTIDADE DE ASSENTOS PARA O DESTINO:                                                                  *\n");
		printf("*     3 - FAZER UMA RESERVA:                                                                                                *\n");
		printf("*     4 - CONFIRMAR UMA RESERVA:                                                                                            *\n");
		printf("*     5 - CANCELAR UMA RESERVA:                                                                                             *\n");
		printf("*     6 - DADOS DO VOO:                                                                                                     *\n");
		printf("*     7 - SAIR:                                                                                                             *\n");
		printf("*                                                                                                                           *\n");
		printf("*****************************************************************************************************************************\n");
		scanf(" %d", &respostaMenu);
		/* FIM: CRIANDO UM MENU. */

		switch (respostaMenu)
		{
		case 1:

			break;

		case 2: // ADICIONAR QUANTIDADE DE ASSENTOS PARA O DESTINO:
			do {
				fflush(stdin);
				printf("DESTINO: ");
				fgets(destino, 40, stdin);

				for (int i = 0; i < 27; i++)
				{
					int status = 0;
					int respostaValida;

					if (strncmp(destinosNacionais[i], destino, 5) == 0)
					{
						printf("Destino encontrado\n");
						do {
							fflush(stdin);

							printf("QUANTIDADE DE ASSENTOS EXISTENTES PARA: %s ", destinosNacionais[i]);
							status = scanf("%d", &assentosDestinosNacionais[i][1]);

							respostaValida = assentosDestinosNacionais[i][1] >= 90 && assentosDestinosNacionais[i][1] <= 200 && status == 1;

						} while (!respostaValida);
					}
				}

				printf("DESEJA ADICIONAR MAIS VOOS? (S/N): ");
				scanf(" %c", &respostaSaida1);

			} while (respostaSaida1 == 'S' || respostaSaida1 == 's');

			break;

			/* FIM: CRIA A QUANTIDADE DE ASSENTOS CADA VOO VAI TER. */

		case 3:; // INICIO FAZER UMA RESERVA   
			
				int temDestino = 0, voo, numeroVoo;
				int numeroAssento;
				int numeroIdade;
				

				fflush(stdin);
				printf("DIGITE O DESTINO: ");
				fgets(destino, 40, stdin);

				for (int i = 0; i < 27; i++)
				{

					if (strncmp(destinosNacionais[i], destino, 5) == 0)
					{
						voo = i;
						temDestino = 1;
					}
				}

				if (temDestino == 1)
				{

					system("cls");

					printf("DESTINO: %s\n", destinosNacionais[voo]);

					fflush(stdin);
					char respostaReserva;
					printf("DESEJA FAZER UMA RESERVA? ");
					scanf(" %c", &respostaReserva);



					if (respostaReserva == 'S') // INICIO DA RESERVA
					{
						/* INICIO: GERANDO UM CÓDIGO DE RESERVA UNICO */

						int  temIgual, temNaLista;

						printf("LISTA %d\n", lista);

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


						printf("NUMERO DA RESERVA: %d\n", reserva);

						/* FIM: GERANDO UM CÓDIGO DE RESERVA UNICO */

						printf("DESTINO: %s\n", destinosNacionais[voo]);
						printf("QUANTIDADE DE ASSENTOS DISPONÍVEIS: %d\n", assentosDestinosNacionais[voo][1]); // colocar o assento disponivel menos oq ja foi escolhido
						printf("POLTRONAS DISPONÍVEIS: \n\n");

						/* INICIO: IMPRIMINDO O ESQUEMA DO AVIÃO COM A OCUPAÇÃO DAS POLTRONAS */

						int sairReserva;

						do { // do while do voo 0:

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
								if (assentosDestinosNacionais[voo][i + 3] == 0)
								{
									printf("\033[0;32m");
									printf("D ");
									printf("\033[0;37m");
								}
								else if (assentosDestinosNacionais[voo][i + 3] == 1)
								{
									printf("\033[0;31m");
									printf("R ");
									printf("\033[0;37m");
								}
										
								else if (assentosDestinosNacionais[voo][i + 3] == 2)
								{
									printf("\033[0;34m");
									printf("C ");
									printf("\033[0;37m");
								}
							}
							/* FIM: IMPRIMINDO O ESQUEMA DO AVIÃO COM A OCUPAÇÃO DAS POLTRONAS */

							// -->  Criar uma forma de sair da area de reserva, dar o preço e perguntar de deseja confirmar a passagem

							/*INICIO: PERGUNTANDO E RESERVANDO O LOCAL DE ACORDOR COM A FILEIRA E SEU NÚMERO */

							char fileira;
							int letraFileira;
							int numeroFileira;
							int posicao;
							int idade;
								


							fflush(stdin);
							printf("\n\nQUAL ASSENTO DESEJA RESERVAR? ");
							scanf("%c %d", &fileira, &numeroFileira);
							printf("QUAL A IDADE DO PASSAGEIRO?");
							scanf("%d", &idade);

							if (idade <= 5) preco = precoReal * 0.5 * 100;
							else preco = precoReal * 100;

							printf("%c", fileira);
							printf("%d\n", numeroFileira);

							/* FIM: PERGUNTANDO E RESERVANDO O LOCAL DE ACORDOR COM A FILEIRA E SEU NÚMERO */

							/* INICIO: RESERVAR O LOCAL */

							if (fileira == 'a') letraFileira = 0;
							else if (fileira == 'b') letraFileira = 1;
							else if (fileira == 'c') letraFileira = 2;
							else if (fileira == 'd') letraFileira = 3;
							else if (fileira == 'e') letraFileira = 4;
							else if (fileira == 'f') letraFileira = 5;

							posicao = letraFileira + (numeroFileira - 1) * 6;


							/* INICIO: VERIFICAR SE O ASSENTO FOI OU NÃO JÁ RESERVADO */

							if (assentosDestinosNacionais[voo][posicao + 3] != 0)
							{
								printf("\nO ASSENTO NÃO PODE SER RESERVADO:\n");
								system("pause");
							}
							else
							{
								if (numeroAssento > numeroVoo && numeroAssento < numeroVoo + 7)
								{
									assentosDestinosNacionais[voo][posicao + 3] = 1;
									reservas[numeroAssento] = posicao;
									reservas[numeroIdade] = preco;
									numeroAssento++;
									numeroIdade++;
								}
								else
								{
									printf("NÃO É PERMITIDO RESERVAR MAIS POLTRONAS:\n");
								}

							}
							for (int i = 0; i < 28; i++) // testando
							{
								printf("reservas[%d] = %d\n", i, reservas[i]);
							}

							/* FIM: VERIFICAR SE O ASSENTO FOI OU NÃO JÁ RESERVADO */

							/* FIM: RESERVAR O LOCAL */

							int valoresValidos;
							do { // DO WHILE DA SAIDA DA RESERVA

								printf("DESEJA RESERVAR MAIS UM ASSENTO? \n"); // Arrumar -> dando erro quando coloca valor diferente de 1 e 2******
								printf(" 1 - SIM: \n");
								printf(" 2 - NÃO: \n");
								scanf("%d", &sairReserva);

								valoresValidos = sairReserva == 1 || sairReserva == 2;

							} while (!valoresValidos); // FIM DO DO WHILE DA SAIDA DA RESERVA
				
						} while (sairReserva == 1);


					} // FINAL DA RESERVA
					
				}

			break;

		case 4:; // CONFIRMAR UMA RESERVA: 
			/* 4 -> INICIO: CALCELAMENTO DA RESERVA */

			int codigoReserva;
			printf("DIGITE O CÓDIGO DA RESERVA:");
			scanf("%d", &codigoReserva);

			/* 4.1 -> INICIO: IMPRIMIDO O CÓDIGO DA RESERVA, O DESTINO, O ASSENTO E SEU VALOR */

			float valor;
			float soma = 0;

			for (int i = 0; i < TAM_RESERVA; i += 14)
			{
				//printf("reservas[%d] = %d\n",i, reservas[i]);
				if (reservas[i] == codigoReserva)
				{
					printf("CÓDIGO DE RESERVA: %d\n", reservas[i]);
					printf("DESTINO: %s\n", destinosNacionais[reservas[i + 1]]);

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
											printf("POLTRONA: a %d \n", fileiraNumero + 1);
											printf("PREÇO: R$ %.2f\n", valor);
											break;

										case 1:
											valor = (float)reservas[poltrona + 6] / 100;
											printf("POLTRONA: b %d \n", fileiraNumero + 1);
											printf("PREÇO: R$ %.2f\n", valor);
											break;

										case 2:
											valor = (float)reservas[poltrona + 6] / 100;
											printf("POLTRONA: c %d \n", fileiraNumero + 1);
											printf("PREÇO: R$ %.2f\n", valor);
											break;

										case 3:
											valor = (float)reservas[poltrona + 6] / 100;
											printf("POLTRONA: d %d \n", fileiraNumero + 1);
											printf("PREÇO: R$ %.2f\n", valor);
											break;

										case 4:
											valor = (float)reservas[poltrona + 6] / 100;
											printf("POLTRONA: e %d \n", fileiraNumero + 1);
											printf("PREÇO: R$ %.2f\n", valor);
											break;

										case 5:
											valor = (float)reservas[poltrona + 6] / 100;
											printf("POLTRONA: f %d \n", fileiraNumero + 1);
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

					/* 4.1.2 -> INICIO: IMPRIMINDO O TOTAL DA PASSAGEM E ATUALIZANDO O VOO */

					printf("TAXA DE EMBARQUE: R$ 35,00\n");
					printf("PREÇO TOTAL: R$ %.2f\n\n", soma + 35.00);

					int status;
					do { // Validando a resposta.
						fflush(stdin);
						printf("DESEJA CONFIRMAR A RESERVA?\n");
						printf(" 1 - SIM:\n");
						printf(" 2 - NÃO:\n");
						status = scanf("%d", &resposta);

					} while (status != 1 && (resposta != 1 || resposta != 2));
					
					if (resposta == 1) // Ser quer Confirmar a reserva
					{
						for (int poltrona = i + 2; poltrona < i + 8; poltrona++)
						{
							if (reservas[poltrona] != 0)
							{
								voo = reservas[i + 1];
								assentosDestinosNacionais[voo][reservas[poltrona] + 3] = 2;
							}
						}
					}
					/* 4.1.2 -> FIM: IMPRIMINDO O TOTAL DA PASSAGEM E ATUALIZANDO O VOO */
				}
				/* 4.1 -> FIM: IMPRIMIDO O CÓDIGO DA RESERVA, O DESTINO, O ASSENTO E SEU VALOR */
			}
			
			/* 4 -> FIM: CALCELAMENTO DA RESERVA */
			break;

		case 5: 
			/* 5 -> INICIO: CANCELAMENTO DA RESERVA*/
			
			printf("DIGITE O CÓDIGO DA RESERVA:");
			scanf("%d", &codigoReserva);

			/* 5.1 -> INICIO: IMPRIMIDO O CÓDIGO DA RESERVA, O DESTINO */


			for (int i = 0; i < TAM_RESERVA; i += 14)
			{
				//printf("reservas[%d] = %d\n",i, reservas[i]);
				if (reservas[i] == codigoReserva)
				{
					printf("CÓDIGO DE RESERVA: %d\n", reservas[i]);
					printf("DESTINO: %s\n", destinosNacionais[reservas[i + 1]]);
				}
			}
			/* 5.1 -> FIM: IMPRIMIDO O CÓDIGO DA RESERVA, O DESTINO */

			/* 5.2 -> INÍCIO: CONFIRMAR SE DESEJA CANCELAR A RESERVA */ 

			int status;

			do { // Validando a resposta.
				fflush(stdin);
				printf("DESEJA CANCELAR A RESERVA?\n");
				printf(" 1 - SIM:\n");
				printf(" 2 - NÃO:\n");
				status = scanf("%d", &resposta);

			} while (status != 1 && (resposta != 1 || resposta != 2));


			/* 5.2 -> FIM: CONFIRMAR SE DESEJA CANCELAR A RESERVA */

			/* 5.3 -> INICIO: ATUALIZANDO O SISTEMA DO VOO */
	
			for (int i = 0; i < TAM_RESERVA; i += 14)
			{
				if (reservas[i] == codigoReserva) 
				{		
					if (resposta == 1) // Ser quer Confirmar a reserva
					{
						for (int poltrona = i + 2; poltrona < i + 8; poltrona++)
						{
							if (reservas[poltrona] != 0)
							{
								voo = reservas[i + 1];
								assentosDestinosNacionais[voo][reservas[poltrona] + 3] = 2;
								for (int reserva = i; reserva < i + 14; reserva++) reservas[reserva] = 0; //Zerando a reserva
							}
						}
					}
				}

				/* 5.3 -> FIM: ATUALIZANDO O SISTEMA DO VOO */


			}
				
			/* 5 -> FIM: CANCELAMENTO DA RESERVA*/
			break;

		case 6:
			fflush(stdin);
			printf("DIGITE O VOO: ");
			fgets(destino, 40, stdin);

			for (int i = 0; i < 27; i++)
			{

				if (strncmp(destinosNacionais[i], destino, 5) == 0)
				{
					voo = i;
					temDestino = 1;
				}
			}
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
				if (assentosDestinosNacionais[voo][i + 3] == 0)
				{
					printf("\033[0;32m");
					printf("D ");
					printf("\033[0;37m");
				}
				else if (assentosDestinosNacionais[voo][i + 3] == 1)
				{
					printf("\033[0;31m");
					printf("R ");
					printf("\033[0;37m");
				}

				else if (assentosDestinosNacionais[voo][i + 3] == 2)
				{
					printf("\033[0;34m");
					printf("C ");
					printf("\033[0;37m");
				}
			}
			printf("\n");
			system("pause");
			break;

		default:

			break;

		}  // FIM DO WHILE MENU:


	} while (1);  // FINAL SWITH CASA MENU:
}