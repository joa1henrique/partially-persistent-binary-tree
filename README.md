# Trabalho de Estruturas de Dados Avançadas
## Árvore Binária de Busca com Persistência Parcial

Este projeto implementa uma Árvore Binária de Busca (BST) parcialmente persistente usando a técnica de Cópia de Caminho (Path Copying).

## Linguagem
- **C++**, padrão C++11 ou superior.

## Como rodar o programa
O projeto contém um `Makefile` configurado para facilitar a compilação e execução.

1. **Compilar:**
   No terminal, digite:
   ```bash
   make build
   ```
   Isso irá gerar um executável chamado `bst_persistente`.

2. **Executar:**
   Para rodar o programa passando um arquivo de texto como entrada, use:
   ```bash
   make run ARGS="caminho_para_arquivo.txt"
   ```
   Ou chame o executável diretamente:
   ```bash
   ./bst_persistente caminho_para_arquivo.txt
   ```

## Estruturas e Funções

**Arquivo `main.cpp`:**
Neste arquivo está todo o código fonte da estrutura e sua interação com o arquivo de entrada.

### Estruturas
- `struct Node`: Representa um nó da árvore.
  - `int val`: O valor armazenado no nó.
  - `Node* left`: Ponteiro para o filho à esquerda.
  - `Node* right`: Ponteiro para o filho à direita.

### Principais Funções
- `Node* insert(Node* root, int val)`: Retorna uma nova versão da árvore (nova raiz) com o valor inserido, copiando apenas os nós do caminho percorrido (Path Copying).
- `Node* findMin(Node* root)`: Encontra o nó com o menor valor em uma subárvore.
- `Node* remove(Node* root, int val, bool& found)`: Remove o nó com o valor especificado, criando e retornando uma nova versão da árvore se o valor for encontrado.
- `int sucessor(Node* root, int val)`: Retorna o sucessor de um valor `val` em uma dada versão da árvore (o menor valor que é estritamente maior que `val`). Retorna `-1` (ou outro indicador) quando não há sucessor.
- `void printTree(Node* root, int depth, bool& first)`: Percorre a árvore em ordem (in-order) imprimindo os valores e suas respectivas profundidades no formato `valor,profundidade`.
