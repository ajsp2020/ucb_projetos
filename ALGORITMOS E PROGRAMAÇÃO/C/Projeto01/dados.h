#ifndef _VALIDACAO_H_ // Checa se o valor é único e se não estiver definido o define e continua o resto da página
#define _VALIDACAO_H_

// VALORES CONSTANTES PARA O PROCESSO DE VALIDAÇÃO:
#define NUM_SESSOES 2 // quantidade de sessões permitidas
#define NUM_PESSOAS 2 // quantidade mínima de pessoas permitida
#define TAM_FILME 1 // tamanho mínimo que é aceito como input para o nome do filme
#define TAM_NOME 40 // tamanho máximo que é aceito como input para o tamanho do filme 

//STRUCTS
struct sexo
{
	char** sexo; // Define um array com {{valores_sessao1}, {valores_sessao2}}  (neste caso um ponteiro de ponteiro) para o sexo
	int* masculino; // Um array com tamanho de (int * sessoes) para salvar a quantidade de pessoas do sexo masculinho por sessao
	int* feminino; // Um array com tamanho de (int * sessoes) para salvar a quantidade de pessoas do sexo feninino por sessao
};
typedef struct sexo SEXO;

struct pessoas
{
	int* pessoas; // Um array com tamanho de (int * sessoes) para salvar a quantidade de pessoas por sessao
	int** idades; // Define um array com {{valores_sessao1}, {valores_sessao2}}  (neste caso um ponteiro de ponteiro) para a idade
	SEXO s;
};
typedef struct pessoas PESSOAS;

struct filme
{
	char* nome; // Define um array que vai guardar o nome do filme (um ponteiro)
	int sessoes; // Um array  para salvar a quantidade de sessoes 
	PESSOAS p;
};

struct classificacao // Salva a quantidade de pessoas por classificação
{
	int criancas;
	int adolecentes;
	int adultos;
	int idosos;
}; // Define as variáveis criadas com o valor zero 
typedef struct classificacao CLASSIFICACAO;


typedef struct filme FILME;

void validavalor(int* status, int* valor, int j, int k, int v);
void validasexo(char* sexo, int j);
void validafilme(char* nome_filme, int* len, int tam_fime, int tam_nome);

void pegapessoas(FILME* f);
void pegasessoes(FILME* f);
void pegaidades(FILME* f, int k, int v);
void pegasexo(FILME* f, int i, int j);
void pegafilmes(FILME* f);

void alocamemoria(FILME* f);
void alocamemoria_(FILME* f);
void liberamemoria(FILME* f);

void contaidades(FILME* f, CLASSIFICACAO* c, int sessoes);
int contasexo(FILME* f, int valor, int questao, int sexo);

void menu();
void limpatela();
#endif