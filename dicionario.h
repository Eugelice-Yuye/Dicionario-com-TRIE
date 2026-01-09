typedef struct tst TST; //estrutura para a �rvore

typedef struct entradaArquivo EntradaArquivo; //estrutura para o ficheiro

TST *inicializar(); //inicializa��o da �rvroe

int consultar(TST *raiz, char *palavrinha); //buscar ou consultar uma palavra

void carregar_palavra_ficheriro(TST **trie); //Fun��o para carregar o ficheiro das palavras

void inserir(TST **raiz, char *palavrinha); //inser��o de uma palavra na �rvore

TST * novo_no(char palavra); //inser��o de um novo n�

char *prefixo_mais_longo(TST *raiz,char* letra, char* palavra,char* palavra_dois,char *palavra_tres,int cont); //fun��o para verificar o prefixo mais
// longo entre as palavras

void palavras_mesmo_prefixo(TST* raiz, char* auxiliar, int profundidade, char* prefixo); //fun��o para imprimir palavras com o mesmo prefixo

void verificador_ortografico(TST** raiz, char* palavra); // fun��o verificador ortogr�fico

int remover(TST *raiz, char* auxiliar); //fun��o para remover uma palavra

void impressao_em_ordem(TST *raiz, char* palavra, int cont); //impress�o das palavras em ordem

int palavras_similares(TST *raiz,char* palavra1,char *palavra2); //fun��o para achar as palavras similares por ditanciamento m�nimo

unsigned long calcular_hash(const char* nome_arquivo); // função para gerar hash do arquivo

void adicionar_arquivo(EntradaArquivo** dicionario, int* contador); //função para adicionar o hash do arquivo na memória

int verificar_integridade_arquivo(const EntradaArquivo* dicionario, int contador); //função para verificar integridade do arquivo

void atualizarArquivo(char* palavra); //função para actualizar ficheiro
