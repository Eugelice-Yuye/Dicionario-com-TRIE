#include<stdio.h>
#include<stdlib.h>
#include<locale.h>
#include "dicionario.c"

int main() { 

	setlocale(LC_ALL,"portuguese");

	system("color 5f");

	TST *trie=inicializar();

	char palavra [10000],palavra_um[1000],palavra_dois[1000],palavra_tres[1000],letra[1000],*raiz[100];
	
	int opcao,distancia,numero;

	int contador = 0;

    EntradaArquivo* dicionario = NULL;
	
	carregar_palavra_ficheriro(&trie);

	do
	{ 
		system("cls");
		printf("\tDICIONIONÁRIO\n\n"); 
		printf("[1]-Inserir\n"); 
		printf("[2]-Consultar\n"); 
		printf("[3]-Prefixo mais longo\n"); 
		printf("[4]-Palavras similares por distanciamento mínimo\n"); 
		printf("[5]-Palavras com o mesmo prefixo\n"); 
		printf("[6]-Remover\n");
		printf("[7]-Verificador Ortográfico\n");
		printf("[8]-Índice(Impressão das palavras em Ordem)\n");
		printf("[9]-Verificar integridade\n");
		printf("[0]-Adicionar arquivo\n");
		printf("[11]-sair do programa\n\n"); 
		printf("Selecione a opção: "); 
		fflush(stdin); 
		scanf("%d",&opcao); 
		
		switch(opcao) 
		{
			case 1: 
			
				fflush(stdin);
				printf("Insira a palavra:"); 
				scanf("%s",palavra); 
				fflush(stdin);
				if(!consultar(trie,palavra))
				{
					inserir(&(trie),palavra);
					printf("\n--- Palavra inserida---\n");
				}
				else
				{
					printf("A palavra <%s> já foi inserida!\n",palavra);
				}
					system("pause");
			 	break;
				  
			case 2: 
			 {
				fflush(stdin);
				printf("Insira a palavra:"); 
				scanf("%s",palavra); 
				fflush(stdin);
				if(consultar(trie,palavra)) 
				{ 
					printf("A palavra <%s> encontra-se na arvore!\n",palavra); 
				} 
				else 
				{ 
					printf("A palavra <%s> não foi encontrada!\n",palavra); 
				}
				system("pause");
				break; 
			 
			}
			case 3: 
			{ 
				fflush(stdin);
				printf("Digite a primeira palavra:");
				gets(palavra);
				fflush(stdin);
				
				printf("Digite a segunda palavra:");
				gets(palavra_dois);
				fflush(stdin);
			
				printf("Digite a terceira palavra:");
				gets(palavra_tres);
				fflush(stdin);
				
				//Condição para verificar a existencia das palavras
				if(consultar(trie,palavra)&&consultar(trie,palavra_dois)&&consultar(trie,palavra_tres))
					printf("O prefixo mais longo entre a palavra %s, %s e %s é: %s \n",palavra,palavra_dois,palavra_tres, prefixo_mais_longo(trie,palavra,letra,palavra_dois,palavra_tres,0));
					
				else if (!consultar(trie,palavra))
				
					printf("A palavra <%s> não encontra-se na árvore!\n",palavra);
					
				else if (!consultar(trie,palavra_dois))
				
				printf("A palavra <%s> não encontra-se na árvore!\n",palavra_dois);
					
				else if (!consultar(trie,palavra_tres))
				
				printf("A palavra <%s> não encontra-se na árvore!\n",palavra_tres);
					
				system("pause");
				break;
			} 
		
			case 4: 
			{
				fflush(stdin);
				printf("Digite a primeira palavra:");
				gets(palavra_um);
				fflush(stdin);

				printf("Digite a segunda palavra:");
				gets(palavra_dois);
				fflush(stdin);

				// cálculo da distancia entre as palavras
				distancia=palavras_similares(trie,palavra_um,palavra_dois);
				if(distancia!=-1)
					printf("A distância de edição entre a palavra %s e %s é de : %d ",palavra_um,palavra_dois,distancia);
					
				else if (!consultar(trie,palavra_um))
				
					printf("A palavra <%s> não encontra-se na árvore!\n",palavra_um);
					
				else if (!consultar(trie,palavra_dois))
				
				printf("A palavra <%s> não encontra-se na árvore!\n",palavra_dois);

				system("pause");
				break;
			}
			
			case 5: 
			{ 
				fflush(stdin);
				printf("Digite o prefixo:");
				gets(palavra);
				fflush(stdin);
			
				char auxiliar[100];
   		
    			printf("As palavras que tem <%s> como prefixo são:\n",palavra);
    			palavras_mesmo_prefixo(trie, auxiliar, 0,palavra);
    			system("pause");
				break;
			
			} 
			
			case 6:
			{
				fflush(stdin);
				printf("Digite a palavra a ser removida:\n");
				gets(palavra);
				fflush(stdin);
			
				remover(trie,palavra);
				printf("A palavra <%s> foi removida!",palavra);
				system("pause");
				break;
			}
			
			case 7:
			{
				 
   		 		verificador_ortografico(&(trie), "palavra.txt");
				system("pause");
				break;
				
			}
			
			case 8:
			{
				impressao_em_ordem(trie, palavra, 0);
				system("pause");
			}

			case 9:
			{
   		 		verificar_integridade_arquivo(dicionario, contador);
				system("pause");
				break;
			}

			case 0:
			{
   		 		adicionar_arquivo(&dicionario, &contador);
				system("pause");
				break;
			}
			
			default:
				printf("opcao inválida\n");
				system("pause");
				break;
		
		} 
	} while(opcao!=11);
	 
	return 0;
}

