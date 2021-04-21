
#define TAM_NOME 40
#define TAM_LISTA 2
#define TAM_FILME 1


struct pessoas
{
	int** idades;
	char** sexo;
};
typedef struct pessoas PESSOAS;


void dadosautor();
void validavalor(int* status, int* valor, int j, int k, int v);
void pegasessoes(int* qtd_secoes);
void pegapessoas(int* qtd_pessoas);

void pegaidades(PESSOAS* p, int qtd_sessoes, int qtd_pessoas, int k, int v);
//void pegaidades(int** idades, char** sexo, int qtd_sessoes, int qtd_pessoas, int k, int v);

void pegasexo(PESSOAS* p, int i, int j);
//void pegasexo(char** sexo, int i, int j);

//void validasexo(PESSOAS* p, int i, int j);
void validasexo(char* sexo, int j);

void pegafilmes(char* nome_filmes);
void validafilme(char* nome_filme, int* len);

void alocamemoria(PESSOAS* p, int qtd_sessoes, int qtd_pessoas);
void liberamemoria(PESSOAS* p, int qtd_sessoes);
