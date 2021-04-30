#include<stdio.h> // Esta biblioteca contém várias funções de entrada e saída. 
#include <ctype.h> // para incluir a biblioteca do tooper
#include<string.h> // Bibiloteca de string
#include<stdlib.h> // nescessário para usar as funções malloc e free
#include"dados.h" // header file

// VALIDANDO OS DADOS:
// VALIDA DADOS DE ENTRADA PARA VALORES INTEIRO
//void validavalor(int* status, int* valor, valor no switch, valor de entrada, contador)
void validaValor(int* status, int* valor, int contador) // continar arrumando
{
	int temp, input;

	if (*valor < 3 || *valor > 100) *status = 0;

	while (*status != 1 || *valor < 0)
	{
		while ((temp = getchar()) != EOF && temp != '\n');
			printf("Input inválido....\n");
			printf("Digite a idade da pessoa %d: ", contador + 1);
		
		*status = scanf("%d", valor);
		if (*valor < 3 || *valor > 100) *status = 0;
	}
}

// PEGANDO OS DADOS: 
// VALIDA OS DADOS PARA O SEXO
void validaSexo(char* sexo, int j)
{
	int sexovalido = *sexo == 'M' || *sexo == 'F';

	while (!sexovalido)
	{
		printf("Input inválido... \nDigite o sexo da pessoa (M - Masculino | F - Feminino) %d: ", j + 1);
		scanf(" %c", sexo);
		*sexo = toupper(*sexo);
		sexovalido = *sexo == 'M' || *sexo == 'F';
	}
}


// PEGANDO A QUANTIDADE DE SESSOES:
int pegaSessoes(FILME* f)                                                                   // recebe como parametro a struct filme
{
		printf("Digite a quantidade de seções que serão realizadas: ");                     // Pergunta o nome das pessoas 
		int status = scanf("%d", &f->sessoes);                                              // Pega o nome: se status for 1 o valor do input é válido
		fflush(stdin);
	
		if (f->sessoes != NUM_SESSOES || status == 0)                                       // se o valor não for válido
		{
			pegaSessoes(f);                                                                 // Volta a função
			return 0;                                                                       // Termina evitando que repita diversar vezes 
		}

	alocaMemoria(f); // aloca a memoria
}

int retornaSessoes(FILME f) // Função de retorno para a quantidade de sessoes
{
	return f.sessoes;
}
// PEGA A QUANTIDADE DE PESSOAS EM CADA SESSAO 
int pegaPessoas(FILME* f, int sessao)
{
	for (int i = sessao; i < f->sessoes; i++) // Adicionando a quantidade de pessoas por sessao e colocando no array.
	{
		printf("Digite a quantidade de pessoas que assistiram a seção %d: ", i + 1);
		int status = scanf("%d", &f->p.pessoas[i]);
		fflush(stdin);

		if (f->p.pessoas[i] < NUM_PESSOAS || status == 0) // 10
		{
			pegaPessoas(f, i); // Se for menor que o numero mínimo volta a função
			return 0;
		}
	}
	alocaMemoria_(f); // Alocando memoria de acordo com a quantidade pessoas por sessao
}

// PEGA O VALOR DA IDADE DE TODOS POR SESSAO
void pegaIdades(FILME* f, int sessao, int pessoa)
{
	for (int i = sessao; i < f->sessoes; i++) // Para cada sessao se adiciona as idades no array
	{
		printf("SESSÃO %d:\n", i + 1);
		for (int j = pessoa; j < f->p.pessoas[i]; j++) 
		{
			printf("Digite a idade da pessoa %d: ", j + 1); // Pede a idade das pessoas

			int status = scanf("%d", &f->p.idades[i][j]); // Pegando os valores de idade 
			validaValor(&status, &f->p.idades[i][j], j); // Validado os valores da idade 
			fflush(stdin);

			pegaSexo(f, i, j); // Pega o sexo das pessoas
		}
	}
}

// PEGA O VALOR DO SEXO DE TODOS POR SESSAO
void pegaSexo(FILME* f, int i, int j)
{
	printf("Digite o sexo da pessoa (M - Masculino | F - Feminino)  %d: ", j + 1); 
	scanf("%c", &f->p.s.sexo[i][j]);

	f->p.s.sexo[i][j] = toupper(f->p.s.sexo[i][j]);

	validaSexo(&f->p.s.sexo[i][j], j);
}

// PEGA O NOME DO FILME
void pegaFilmes(FILME* f) 
{
	int len;   

	fflush(stdin);
	f->nome = malloc(sizeof(char) * TAM_NOME); // aloca a memória 
	do {
		printf("Digite o nome do filme: "); // Pede o nome do filme 
		fgets(f->nome, sizeof(f->nome), stdin); //Pega o nome do filme com a função fgets
		fflush(stdin); 

		len = strlen(f->nome); // conta o tamanho
		
	} while (len == 1); // enquanto o tamanho for igual a 1 volta para o do 

	pegaSessoes(f); // Pega as sessoes
}

char* retornaFilme(FILME f) // Funçao de retorno para o nome
{
	return f.nome;
}
// FIM DE PEGANDO OS DADOS

// ALOCANDO MEMÓRIA:
void alocaMemoria(FILME* f)
{
	f->p.idades = malloc(sizeof(int*) * f->sessoes); // Ponteiro de ponteiro contendo todos os valores da idade por sessao
	f->p.s.sexo = malloc(sizeof(int*) * f->sessoes); // Ponteiro de ponteiro contendo todos os valores do sexo por sessao
	f->p.pessoas = malloc(sizeof(int) * f->sessoes); // Ponteiro contendo o valor todal de pessoas por sessao
	f->p.s.masculino = malloc(sizeof(int) * f->sessoes); // Ponteiro contento o valor das pessoas do sexo masculino por sessao
	f->p.s.feminino = malloc(sizeof(int) * f->sessoes); // Ponteiro contendo o valor das pessoas do sexo feninino por sessao

	pegaPessoas(f, 0); // Pega a quantidade de pessoas
}

void alocaMemoria_(FILME* f) // Criando um array com os dados para cada sessao com a quantidade de pessoas 
{
	for (int i = 0; i < f->sessoes; i++) // aloca um vetor com todos os elementos da matriz
	{
		f->p.idades[i] = malloc(sizeof(int) * f->p.pessoas[i]);
		f->p.s.sexo[i] = malloc(sizeof(int*) * f->p.pessoas[i]);
	}
	pegaIdades(f, 0, 0); // Pegando as idades
}
// FIM ALOCANDO MEMÓRIA

// LIBERANDO MEMÓRIA:
void liberaMemoria(FILME* f)
{
	for (int i; i < f->sessoes; i++)
	{
		free(f->p.idades[i]); // Liberando a memoria para o array de idades
		free(f->p.s.sexo[i]); // Liberanda a memoria para o array de sexo
	}
	free(f->p.idades); // Liberando a mamoria para o array de idades
	free(f->p.s.sexo); // Liberando a memoria para o array de sexo
	free(f->nome); // Liberando a memoria para o array do nome
	free(f->p.pessoas); // Liberando a memoria para o array de pessoas
	free(f->p.s.masculino); // Liberando o array de memória de pessoas do sexo masculino
	free(f->p.s.feminino); // Liberando o array de memória de pessoas do sexo feninino 
}

// CONTA A QUANTIDADE DE PESSOAS DO SEXO MASCULINO E FEMININO PARA O MESMO FILME
int contaSexo(FILME* f,int valor, int questao, int sexo) 
{
	for (int i = valor; i <= valor; i++) // Zerando os valores de acordo com a sessao
	{
		f->p.s.masculino[i] = 0;
		f->p.s.feminino[i] = 0;
	}
	switch (questao) 
	{
	case 1: // Caso seja a resposta da questao 1
		for (int i = valor; i <= valor; i++) // Para cada sessao sera:
		{
			for (int j = 0; j < f->p.pessoas[i]; j++) // Vai passar por cada elemento 
			{
				if (f->p.s.sexo[i][j] == 'M') f->p.s.masculino[i] += 1; // somar 1 se masculino
				else if (f->p.s.sexo[i][j] == 'F') f->p.s.feminino[i] += 1; // somar1 se feminino
			}
			if (sexo == 0) return  f->p.s.masculino[i]; // Se sexo = 0 vai retornar os valores masculinos
			else if (sexo == 1) return f->p.s.feminino[i]; // Se sexo = 1 vai retornar os valores femininos
		}

	case 2: // caso questão 2 : Igual ao anterior mas adicionando o critério de idade
		for (int i = valor; i <= valor; i++)
		{
			for (int j = 0; j < f->p.pessoas[i]; j++)
			{
				if (f->p.idades[i][j] >= 18 && f->p.s.sexo[i][j] == 'M') f->p.s.masculino[i] += 1;
				else if (f->p.idades[i][j] >= 18 && f->p.s.sexo[i][j] == 'F') f->p.s.feminino[i] += 1;
			}
			if (sexo == 0) return  f->p.s.masculino[i];
			else if (sexo == 1) return f->p.s.feminino[i];
		}
		break;
	default:
		break;
	}
}

// CONTA A QUANTIDADE DE PESSOAS DE ACORDO A SUA CLASSIFICACAO: 
void contaIdades(FILME* f, CLASSIFICACAO* c, int sessoes)
{
	for (int i = 0; i < f->sessoes; i++) // Passa por cada sessão e soma a idade de acordo com a classificacao
	{
		for (int j = 0; j < f->p.pessoas[i]; j++)
		{
			if (f->p.idades[i][j] >= 65) c->idosos += 1;
			else if (f->p.idades[i][j] >= 18) c->adultos += 1;
			else if (f->p.idades[i][j] >= 14) c->adolecentes += 1;
			else if (f->p.idades[i][j] >= 3) c->criancas += 1;
			else printf("Erro na contagem!");
		}
	}
}