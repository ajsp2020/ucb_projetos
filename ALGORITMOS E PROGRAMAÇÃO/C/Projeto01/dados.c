#include<stdio.h> // Esta biblioteca contém várias funções de entrada e saída. 
#include <ctype.h> // para incluir a biblioteca do tooper
#include<string.h> // Bibiloteca de string
#include<stdlib.h> // nescessário para usar as funções malloc e free
#include"dados.h" // header file

// VALIDANDO OS DADOS:
// VALIDA DADOS DE ENTRADA PARA VALORES INTEIRO
//void validavalor(int* status, int* valor, valor no switch, int k, int v)
void validavalor(int* status, int* valor, int j, int k, int v)
{
	int temp, input;

	if (j == 2 && (*valor < 3 || *valor > 100)) *status = 0;

	while (*status != 1 || *valor < 0)
	{
		while ((temp = getchar()) != EOF && temp != '\n');
		printf("Input inválido....\n");

		switch (j)
		{
		case 0:
			printf("Digite a quantidade de seções que serão realizadas: ");
			break;

		case 1:
			printf("Digite a quantidade de pessoas que assistiram a seção: ");
			break;

		case 2:

			printf("Digite a idade da pessoa %d: ", v + 1);
			break;

		case 3:
			limpatela();
			menu();
			break;
		}
		*status = scanf("%d", valor);
		if (j == 2 && (*valor < 3 || *valor > 100)) *status = 0;
	}
}

// PEGANDO OS DADOS: 
// VALIDA OS DADOS PARA O SEXO
void validasexo(char* sexo, int j)
{
	int sexovalido = *sexo == 'M' || *sexo == 'F';
	while (!sexovalido)
	{
		printf("Input inválido... \nDigite o sexo da pessoa %d: ", j + 1);
		scanf(" %c", sexo);
		*sexo = toupper(*sexo);
		sexovalido = *sexo == 'M' || *sexo == 'F';
	}
}

// VALIDA OS DADOS PARA O NOME DO FILME
void validafilme(char* nome_filme, int* len, int tam_fime, int tam_nome)
{
	while (*len == tam_fime) //	analiza de o tamanho do array é igual a 1
	{
		printf("Digite o nome do filme: ");
		fgets(nome_filme, tam_nome, stdin);
		fflush(stdin);
		*len = strlen(nome_filme);
		printf("Nome do filme: %s\n", nome_filme);
	}
}

// PEGANDO A QUANTIDADE DE SESSOES:
void pegasessoes(FILME* f)
{
	printf("Digite a quantidade de seções que serão realizadas: ");
	int status = scanf("%d", &f->sessoes);
	fflush(stdin);
	validavalor(&status, &f->sessoes, 0, 0, 0);
	if (f->sessoes != NUM_SESSOES) // 2
	{
		printf("Somente é aceito 2 seções como input:\n");
		pegasessoes(f);
	}
	alocamemoria(f);
}
// PEGA A QUANTIDADE DE PESSOAS EM CADA SESSAO 
void pegapessoas(FILME* f)
{
	for (int i = 0; i < f->sessoes; i++)
	{
		printf("Digite a quantidade de pessoas que assistiram a seção %d: ", i + 1);
		int status = scanf("%d", &f->p.pessoas[i]);
		fflush(stdin);
		validavalor(&status, &f->p.pessoas[i], 1, 0, 0);

		if (f->p.pessoas[i] < NUM_PESSOAS) // 10
		{
			printf("É aceito no mínimo 10 por sessão:\n");
			pegapessoas(f);
		}
	}
	alocamemoria_(f);
}

// PEGA O VALOR DA IDADE DE TODOS POR SESSAO
void pegaidades(FILME* f, int k, int v)
{
	for (int i = k; i < f->sessoes; i++)
	{
		printf("SESSÃO %d:\n", i + 1);
		for (int j = v; j < f->p.pessoas[i]; j++)
		{
			printf("Digite a idade da pessoa %d: ", j + 1);
			int status = scanf("%d", &f->p.idades[i][j]);
			validavalor(&status, &f->p.idades[i][j], 2, i, j);
			fflush(stdin);
			pegasexo(f, i, j); // Pega o sexo das pessoas
		}
	}
}

// PEGA O VALOR DO SEXO DE TODOS POR SESSAO
void pegasexo(FILME* f, int i, int j)
{
	printf("Digite o sexo da pessoa %d: ", j + 1);
	scanf("%c", &f->p.s.sexo[i][j]);
	f->p.s.sexo[i][j] = toupper(f->p.s.sexo[i][j]);
	validasexo(&f->p.s.sexo[i][j], j);
}

// PEGA O NOME DO FILME
void pegafilmes(FILME* f)
{
	f->nome = malloc(sizeof(char) * TAM_NOME);
	printf("Digite o nome do filme: ");
	fgets(f->nome, TAM_NOME, stdin);
	fflush(stdin);
	int len = strlen(f->nome);
	printf("Nome do filme: %s\n", f->nome);
	validafilme(f->nome, &len, TAM_FILME, TAM_NOME);
	pegasessoes(f);
}
// FIM DE PEGANDO OS DADOS

// ALOCANDO MEMÓRIA:
void alocamemoria(FILME* f)
{
	f->p.idades = malloc(sizeof(int*) * f->sessoes);
	f->p.s.sexo = malloc(sizeof(int*) * f->sessoes);
	f->p.pessoas = malloc(sizeof(int) * f->sessoes);
	f->p.s.masculino = malloc(sizeof(int) * f->sessoes);
	f->p.s.feminino = malloc(sizeof(int) * f->sessoes);

	pegapessoas(f);
}

void alocamemoria_(FILME* f)
{
	for (int i = 0; i < f->sessoes; i++) // aloca um vetor com todos os elementos da matriz
	{
		f->p.idades[i] = malloc(sizeof(int) * f->p.pessoas[i]);
		f->p.s.sexo[i] = malloc(sizeof(int*) * f->p.pessoas[i]);
	}
	pegaidades(f, 0, 0);
}
// FIM ALOCANDO MEMÓRIA

// LIBERANDO MEMÓRIA:
void liberamemoria(FILME* f)
{
	for (int i; i < f->sessoes; i++)
	{
		free(f->p.idades[i]);
		free(f->p.s.sexo[i]);
	}
	free(f->p.idades);
	free(f->p.s.sexo);
	free(f->nome);
	free(f->p.pessoas);
	free(f->p.s.masculino);
	free(f->p.s.feminino);
}

// CONTA A QUANTIDADE DE PESSOAS DO SEXO MASCULINO E FEMININO PARA O MESMO FILME
int contasexo(FILME* f,int valor, int questao, int sexo)
{
	for (int i = valor; i <= valor; i++)
	{
		f->p.s.masculino[i] = 0;
		f->p.s.feminino[i] = 0;
	}
	switch (questao)
	{
	case 1:
		for (int i = valor; i <= valor; i++)
		{
			for (int j = 0; j < f->p.pessoas[i]; j++)
			{
				if (f->p.s.sexo[i][j] == 'M') f->p.s.masculino[i] += 1;
				else if (f->p.s.sexo[i][j] == 'F') f->p.s.feminino[i] += 1;
			}
			if (sexo == 0) return  f->p.s.masculino[i];
			else if (sexo == 1) return f->p.s.feminino[i];
		}

	case 2:
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
void contaidades(FILME* f, CLASSIFICACAO* c, int sessoes)
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