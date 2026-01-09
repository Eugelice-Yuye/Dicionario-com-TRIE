#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"dicionario.h"

#define MAX_FILENAME_SIZE 256


//estrutura para a árvore
struct tst{
	char palavra; 
    struct tst *esquer, *meio, *dir; 
    int chave;
};

//estrutura para o ficheiro
typedef struct entradaArquivo{
    char nome_arquivo[MAX_FILENAME_SIZE];
    unsigned long hash;
};

//inicialização da árvroe
TST *inicializar()
{
	
	return NULL;
}

//Função para carregar o ficheiro das palavras
void carregar_palavra_ficheriro(TST **trie)
{
	
	FILE *arquivo;
	char palavra[10000];
	arquivo = fopen("palavra.txt","r");
	
	while(!feof(arquivo)){
		fscanf(arquivo,"%s\n",palavra);
		inserir(trie, palavra);
	}
	fclose(arquivo);
}

//inserção de um novo nó
TST * novo_no(char palavra)
{
	
    TST *novo = (TST*)malloc(sizeof(TST));
    if (novo){
    	
    	novo->palavra = palavra;
    	novo->esquer = NULL;
		novo->meio = NULL;
		novo->dir = NULL;
    	novo->chave= 0;
    	
	}
	else
	{
        printf("Erro de memoria\n");
    }
    
    return novo;
}

//inserção de uma palavra na árvore

void inserir(TST **raiz, char *palavra)
{
	
   if(!(*raiz))
		*raiz=novo_no(*palavra);
	if((*raiz)->palavra<(*palavra))
		inserir(&((*raiz)->dir),palavra);
	else if((*raiz)->palavra>(*palavra))
		inserir(&((*raiz)->esquer),palavra);
	else{
		if(*(palavra+1))
			inserir(&((*raiz)->meio),(palavra+1));
		else
			(*raiz)->chave = 1;
	}
}

//buscar ou consultar uma palavra

int consultar(TST *raiz, char *palavra)
{
	
	if(raiz==NULL)
		 return 0;
	if(raiz->palavra<*palavra)
		consultar(raiz->dir,palavra);
	else if(raiz->palavra>*palavra)
		consultar(raiz->esquer,palavra);
	else{
		if(*(palavra+1)){
			consultar(raiz->meio,(palavra+1));
		}
		else
			return raiz->chave;
	}
}

//função para verificar o prefixo mais longo entre as palavras
char *prefixo_mais_longo(TST *raiz,char* letra, char* palavra,char* palavra_dois,char *palavra_tres,int cont)
{

if (raiz!=NULL&&(*letra)==(*palavra_dois)&&(*palavra_dois)==(*palavra_tres))
    {

    	if(raiz->esquer!=NULL)
        	prefixo_mais_longo(raiz->esquer,letra,palavra,palavra_dois,palavra_tres,cont);
        	if(raiz->palavra==*letra&&(*letra)==(*palavra_dois)&&(*palavra_dois)==(*palavra_tres))
        		palavra[cont] = raiz->palavra;
        if (raiz->chave||(*letra)!=(*palavra_dois)||(*palavra_dois)!=(*palavra_tres))
        {
            palavra[cont+1] = '\0';
        } 
        if(raiz->meio!=NULL)
        	prefixo_mais_longo(raiz->meio,letra+1,palavra,palavra_dois+1,palavra_tres+1,cont+1);
        if(raiz->dir!=NULL)
        	prefixo_mais_longo(raiz->dir,letra,palavra,palavra_dois,palavra_tres,cont);
    }
 
    return palavra;
}

//função para imprimir palavras com o mesmo prefixo

void palavras_mesmo_prefixo(TST* raiz, char* auxiliar, int profundidade, char* prefixo) 
{
    if (!raiz) {
        return;
    }
    palavras_mesmo_prefixo(raiz->esquer, auxiliar, profundidade, prefixo);
    auxiliar[profundidade] = raiz->palavra;
    if (raiz->chave)
	{
        if (strncmp(auxiliar, prefixo, strlen(prefixo)) == 0) 
		{
            printf("%s\n", auxiliar);  
        }
    }
    palavras_mesmo_prefixo(raiz->meio, auxiliar, profundidade+1, prefixo);
    palavras_mesmo_prefixo(raiz->dir, auxiliar, profundidade, prefixo);
}

//função para achar as palavras similares por ditanciamento mï¿½nimo

int palavras_similares(TST *raiz,char* palavra1,char *palavra2)
{

	int cont=-1,i;
	if(consultar(raiz,palavra1)&&consultar(raiz,palavra2)){
		cont++;
		if(strlen(palavra1)>strlen(palavra2)){
			for(i=0;palavra1[i]!='\0';i++)
				if(palavra1[i]!=palavra2[i])
					cont++;
		}
			else{
					for(i=0;palavra2[i]!='\0';i++)
						if(palavra1[i]!=palavra2[i])
							cont++;
			}
		return cont;
	}
	else
		return cont;

}

//função para remover uma palavra
int remover(TST *raiz, char* auxiliar)
{
 	if (raiz == NULL)
        return 0;
    if (*(auxiliar+1)== '\0')
    {
        if (raiz->chave)
        {
            raiz->chave=0;
            return;
        }
            return 0;
    }
    else
    {
        if (*auxiliar < raiz->palavra)
            remover(raiz->esquer ,auxiliar);
        else if (*auxiliar > raiz->palavra)
            remover(raiz->dir ,auxiliar);
        else if (*auxiliar == raiz->palavra)
        {
            if( remover(raiz->meio ,auxiliar+1 ) )
            {
                free(raiz->meio);
                raiz->meio=NULL;
                return !raiz->chave;
            }
        }
    }
    return 0;
}

// função verificador ortográfico
void verificador_ortografico(TST** raiz, char* palavra)
{
	
    FILE* arquivo = fopen(palavra, "r");
    if (arquivo == NULL)
	{
        printf("Erro ao abrir o ficheiro.\n");
        return;
    }

    char palavras[100];
    
    printf("Insira a palavra: ");
    scanf("%s",palavras);
    while (!feof(arquivo))
	{
    	
        if (!consultar(*raiz, palavras))
		{
            printf("A palavra <%s> não encontra-se na árvore.\n", palavras);

            char escolha;
            printf("Deseja adicionar a palavra? (S/N): ");
            scanf(" %c", &escolha);

            if (escolha == 'S' || escolha == 's')
			{
                inserir(raiz, palavras);
                printf("Palavra inserida.\n");
                break;
            } else {
                // obs:inserir a chamada da função actualizar
                printf("Palavra marcada como errada.\n");
                break;
            }
        }
    }

    fclose(arquivo);
}

//impressãoo das palavras em ordem

void impressao_em_ordem(TST *raiz, char* palavra, int cont)
{
    if (raiz!=NULL)
    {
    	if(raiz->esquer!=NULL)
     		impressao_em_ordem(raiz->esquer, palavra, cont); 
        palavra[cont] = raiz->palavra;
        if (raiz->chave)
        {
            palavra[cont+1] = '\0';
            if(strlen(palavra)>=2)
            	printf( "%s\n", palavra);
        } 
        if(raiz->meio!=NULL)
        	impressao_em_ordem(raiz->meio, palavra, cont+1);
        if(raiz->dir!=NULL)
        	impressao_em_ordem(raiz->dir, palavra, cont);
    }
    else
    	printf("\t\t\t\t\t\t\t\t\tï¿½rvore vazia!!");
}

//funçãoo para criar hash do arquivo
unsigned long calcular_hash(const char* nome_arquivo) {
    FILE* file = fopen(nome_arquivo, "rb");
    if (file == NULL) {
        printf("Não foi possÃ­vel abrir o arquivo '%s'.\n", nome_arquivo);
        return 0;
    }

    unsigned long hash = 0;
    int c;
    while ((c = fgetc(file)) != EOF) {
        hash = (hash << 5) + hash + c; // Função de hash
    }

    fclose(file);
    return hash;
}

//função para adicionar hash do arquivo na memória
void adicionar_arquivo(EntradaArquivo** dicionario, int* contador) {
    unsigned long hash = calcular_hash("palavra.txt");

    *dicionario = realloc(*dicionario, (*contador + 1) * sizeof(EntradaArquivo));

    EntradaArquivo nova_entrada;
    strncpy(nova_entrada.nome_arquivo, "palavra.txt", MAX_FILENAME_SIZE);
    nova_entrada.hash = hash;

    (*dicionario)[*contador] = nova_entrada;
    (*contador)++;

    printf("Arquivo '%s' adicionado ao dicionário.\n", "palavra.txt");
}

int verificar_integridade_arquivo(const EntradaArquivo* dicionario, int contador) {
    unsigned long hash_calculado = calcular_hash("palavra.txt");
	int i;
    for (i = 0; i < contador; i++) {
        if (strcmp(dicionario[i].nome_arquivo, "palavra.txt") == 0) {
            if (hash_calculado == dicionario[i].hash) {
                printf("O arquivo '%s' é integro.\n", "palavra.txt");
                return 1; // VerificaÃ§Ã£o bem-sucedida
            } else {
                printf("O arquivo '%s' foi alterado!\n", "palavra.txt");
                return 0; // VerificaÃ§Ã£o falhou
            }
        }
    }

    printf("O arquivo '%s' não foi encontrado!.\n", "palavra.txt");
    return 0; // Verificação falhou
}

// Função para actualizar o arquivo com a nova palavra inserida
void atualizarArquivo(char* palavra) {
    FILE* file = fopen("palavra.txt", "a");
    if (file == NULL) {
        printf("Não foi possível abrir o arquivo '%s'.\n", "palavra.txt");
        return;
    }

    fprintf(file, "%s\n", palavra);

    fclose(file);
}

