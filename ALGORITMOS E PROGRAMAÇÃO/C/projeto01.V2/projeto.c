
/*
NOME: Antonio João da Silva Pereira\n"
MATRÍCULA: UC21106344
CURSO: Ciências da Computação

Para esse projeto, eu tentei utilizar 3 conceitos implementados pelo autor do livro:

1- O uso do código limpo do capítulo 1:

	Segundo Grandy Booch, autor do livro Object Oriented Analysis:

		"Um código limpo é simple e direto. Ele é tão bem legivel
		quanto uma prosa bem escrita. Ele jamais torna confuso o
		objetivo do desenvolvedor, em vez disso, ele está repleto de
		abstrações claras e linhas de controle objetivas.

2- Uso de Nomes Significativos do capítulo 2:

	"O nome de uma variável, função ou classe deve responder a todas as grandes questões.
	Ela deve lhe dizer porque existe, o que faz e como é usado. Se um nome requer um
	comentário, então não revela seu propósito.

3 - capítulo 3:

	Funções pequenas com no máximo 20 linhas, bem endentadas e com um propósito único.
	(A função deve fazer apenas uma coisa).
*/

#include<stdio.h> // Esta biblioteca contém várias funções de entrada e saída. 
#include<locale.h> // para implementar a localização de programas.
#include<stdlib.h> // nescessário para usar as funções malloc e free e system
#include<string.h> //  Manipulação de strings
#include <ctype.h> // para incluir a biblioteca do tooper
#include"projeto.h" // header file
#include "dados.h" // header file

// VALORES CONSTANTES PARA O PROCESSO DE VALIDAÇÃO:

FILME f;

CLASSIFICACAO c;


// IMPRIME OS DADOS DO ALUNO:

void dadosAluno()
{
	printf("NOME: Antonio João da Silva Pereira\n"
			"MATRÍCULA: UC21106344\n"
			"CURSO: Ciências da Computação\n\n");
}

// LIMPA A TELA 
void limpaTela()
{
	system("cls"); // Limpa a tela 
}

// APLICA AS FUNÇÕES DE ACORDO COM OS INPUTS DO IMPRIMEMENU();
void direcionaResposta(int resp1, char* resp2)
{
	if (resp1 < 1 || resp1 > 6) //  Retorna a função imprimeMenu caso os valores de input do menu seja menor que 1 ou maior que 6
	{
		printf("Input inválido!\n");
		imprimeMenu(); // Função de retorno 
	}
	//DIRECIONA AS FUNÇÕES DE ACORDO COM O INPUT:
	else if (resp1 == 1) pegaFilmes(&f); 
	else if (resp1 == 2) imprimeFilme();
	else if (resp1 == 3) imprimeSessoes(c);
	else if (resp1 == 4) imprimeDados();
	else if (resp1 == 5) dadosAluno(); 
	else if (resp1 == 6)
	{
		int inputValido; // Validado o input
		do { 
			// PERGUNTA SE DESEJA SAIR OU CONTINUAR NO MENU
			printf("Deseja sair (S/N): "); // Pede confirmação se deseja sair
			scanf(" %c", resp2); // Pega a resposta da confirmação
			*resp2 = toupper(*resp2); // Volta com a resposta 
			inputValido = *resp2 == 'S' || *resp2 == 'N';

		} while (!inputValido);
	}
}


// LÊ O TEXTO COM O ASSUNTO TEÓRICO
void imprimeDados()
{
	FILE* arq; 
	char Linha[150]; // Cria um array do tamanho de 150 char
	char* result; // cria um ponteiro para o resultado 
	int i; 

	// Abre um arquivo TEXTO para LEITURA
	arq = fopen("introducao.txt", "rt");
	if (arq == NULL)  // Se houve erro na abertura
	{
		printf("Problemas na abertura do arquivo\n");
		return;
	}
	i = 1;
	while (!feof(arq))
	{
		// Lê uma linha (inclusive com o '\n')
		result = fgets(Linha, 150, arq);  // o 'fgets' lê até 149 caracteres ou até o '\n'
		if (result)  // Se foi possível ler
			printf("Linha %d : %s", i, Linha);
		i++;
	}
	fclose(arq);
}

// DA UMA PAUSE NO PROGRAMA E ESPERA "ENTER" COMO INPUT:
void Espera()  // Definição da função "Espera"
{
	system("pause"); // Da pause no sistema e sai quando aperta qualquer tecla
}

// MENU
int menu(int* resp1) 
{
	printf("Digite 1 para inserir os dados:\n"
		   "Digite 2 para imprimir o nome do filme, a quantidade de pessoas do sexo feminino e a quantidade de pessoas do sexo\n"
		   "         masculino que assistiram ao filme:\n"
		   "Digite 3 para imprimir quantidade de pessoas maiores de idade(idade maior ou igual a 18 anos) do sexo masculino e a\n"
		   "         quantidade de pessoas maiores de idade do sexo feminino que estiveram presentes em cada sessão:\n"
		   "Digite 4 para ler o texo com a base teórica:\n"
		   "Digite 5 para imprimir os dados do aluno:\n"
		   "Digite 6 para sair:\n");

	int status = scanf("%d", resp1); // Pega a resposta do usuário
	fflush(stdin);

	if (status == 0) // se status == 0:
	{
		menu(resp1); // Volta o menu
		return 0;
	}
}

// 
void imprimeMenu()
{
	int resp1;
	char resp2 = 'N';

	do 
	{   
		menu(&resp1); // Imprime o menu e pega o input
		limpaTela();  // Limpa a tela		                                                   
		direcionaResposta(resp1, &resp2); // Direciona de acordo com input 
		Espera(); // Função de espera 
		limpaTela(); // Funçaõ que limpa a tela

	} while (resp2 == 'N'); 
}

// IMPRIME DADOS DE ACORDO COM A QUESTÃO 1 DO PROJETO
void imprimeFilme()
{
	int soma_f = 0; // Variável para a soma das pessoas do sexo masculino 
	int soma_m = 0; // Variável para a soma das pessoas do sexo feminino
	for (int i = 0; i < retornaSessoes(f); i++)
	{
		soma_f += contaSexo(&f, i, 1, 1); // Soma o retorno da função para o sexo feminino
		soma_m += contaSexo(&f, i, 1, 0); // Soma a retorno da função para o sexo masculino
	}

	printf("NOME DO FILME: %s\n", retornaFilme(f)); // Imprime o retorno da função para o nome
	printf("PESSOAS DO SEXO FEMININO: %d\n", soma_f); // Imprime a soma das pessoas do sexo feminino
	printf("PESSOAS DO SEXO MASCULINO: %d\n", soma_m); // Imprime a soma das pessoas do sexo masculino
}

// IMPRIME DADOS DE ACORDO COM A QUESTÃO 2 DO PROJETO
void imprimeSessoes()
{
	contaIdades(&f,&c,retornaSessoes(f));
	printf("QUANTIDADE DE PESSOAS POR CLASSIFICAÇÃO DE IDADE:\n\n");
	printf("CRIANÇAS (3 ATÉ 13 ANOS): %d\n", c.criancas);
	printf("ADOLESCENTES (14 ATÉ 17 ANOS): %d\n", c.adolecentes);
	printf("ADULTOS (18 ATÉ 64 ANOS): %d\n", c.adultos);
	printf("IDOSOS (65 ATÉ 100 ANOS): %d\n", c.idosos);
	
	int maiores;
	int masculino = 0;
	int feminino = 0;
	printf("\nPESSOAS MAIORES QUE 18: \n\n");
	for (int i = 0; i < retornaSessoes(f); i++)
	{
		printf("SESSÃO %d:\n", i + 1);
		masculino = contaSexo(&f,i, 2, 0);
		feminino = contaSexo(&f,i, 2, 1);
		printf("PESSOAS MAIORES DE 18 DO SEXO MASCULINO: %d \n", masculino);
		printf("PESSOAS MAIORES DE 18 DO SEXO FEMININO: %d \n", feminino);
	}
}

int main()
{
	setlocale(LC_ALL, "");
	printf("ANÁLISE	DO PÚBLICO QUE FREQUÊNTA CINENA: CINE BRASÍLIA\n");

	imprimeMenu();
	liberaMemoria(&f);

	return 0;
}
