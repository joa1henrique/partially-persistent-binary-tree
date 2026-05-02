# Trabalho de Estruturas de Dados Avançadas
## Árvore Binária de Busca com Persistência Parcial

Este projeto implementa uma Árvore Binária de Busca parcialmente persistente usando a técnica de Cópia de Caminho (Path Copying).

## Linguagem
- C++, padrão C++11 ou superior.

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


## Organização dos Arquivos

- **main.cpp**: Contém a lógica principal do programa, leitura do arquivo de entrada, controle das versões e chamadas das funções da árvore.
- **bst.hpp**: Declaração da estrutura `Node` e das funções auxiliares da árvore binária de busca persistente.
- **bst.cpp**: Implementação das funções auxiliares e da estrutura `Node`.

### Estruturas
- `struct Node` (declarada em `bst.hpp`, implementada em `bst.cpp`):
   - `int val`: O valor armazenado no nó.
   - `Node* left`: Ponteiro para o filho à esquerda.
   - `Node* right`: Ponteiro para o filho à direita.

### Principais Funções
- `Node* insert(Node* root, int val)` (`bst.hpp`/`bst.cpp`): Retorna uma nova versão da árvore (nova raiz) com o valor inserido, copiando apenas os nós do caminho percorrido (Path Copying).
- `Node* findMin(Node* root)` (`bst.hpp`/`bst.cpp`): Encontra o nó com o menor valor em uma subárvore.
- `Node* removeNode(Node* root, int val, bool& found)` (`bst.hpp`/`bst.cpp`): Remove o nó com o valor especificado, criando e retornando uma nova versão da árvore se o valor for encontrado.
- `int successor(Node* root, int val)` (`bst.hpp`/`bst.cpp`): Retorna o sucessor de um valor `val` em uma dada versão da árvore (o menor valor que é estritamente maior que `val`). Retorna `infinito` quando não há sucessor.
- `void printTree(Node* root, int depth, bool& first)` (`bst.hpp`/`bst.cpp`): Percorre a árvore em ordem (in-order) imprimindo os valores e suas respectivas profundidades no formato `valor,profundidade`.
