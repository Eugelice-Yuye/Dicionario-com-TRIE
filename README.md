# Dicionário usando TRIE

Este projeto consiste na implementação do **Tipo Abstrato de Dados (TAD) Dicionário** utilizando a estrutura de dados **TRIE (árvore digital)**.  
A aplicação foi desenvolvida no âmbito académico na cadeira de Estrutura de Dados II com o objetivo de aplicar conceitos de **estruturas de dados**, **manipulação de strings** e **verificação de integridade de ficheiros**.

Feito por:
Eugelice Yuye
Manuela António
Siomara dos Santos

## Objetivo do Projeto

- Implementar um dicionário digital baseado em **TRIE**
- Manipular palavras da língua portuguesa (sem acentuação)
- Oferecer funcionalidades avançadas como:
  - Pesquisa por prefixo
  - Correção ortográfica
  - Verificação de integridade de ficheiros
  - Similaridade por distância de edição
    
## Entrada de Dados

- O programa lê um **ficheiro de palavras da língua portuguesa**
- O ficheiro deve conter **no mínimo 50 palavras**
- Palavras acentuadas são desconsideradas por simplicidade

Após a leitura:
- As palavras são carregadas numa **TRIE**
- É gerado um **identificador hash do ficheiro**
- O hash é guardado em memória para verificar a **integridade do ficheiro**

## Funcionalidades Implementadas

Após a criação da TRIE, o sistema disponibiliza as seguintes operações:

### Operações Básicas
-  **Inserir nova palavra**
-  **Consultar palavra**
-  **Remover palavra**
-  **Actualizar palavra existente**

### Operações Avançadas
- **Palavras com o mesmo prefixo**  
  Imprime todas as palavras que possuem o prefixo fornecido.

- **Prefixo mais longo**  
  Determina o maior prefixo comum entre as palavras armazenadas.

- **Palavras similares por distanciamento mínimo**  
  Imprime palavras com a mesma distância de edição (ex.: distância de Levenshtein).
