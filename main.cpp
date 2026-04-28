#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <limits>

using namespace std;

// Estrutura do Nó da Árvore
struct Node {
    int val;
    Node* left;
    Node* right;

    Node(int v) : val(v), left(nullptr), right(nullptr) {}
};

// Array global para guardar as raizes de cada versão (máx 100)
Node* versions[100];
int current_version = 0;

// Função de Inclusão com path-copying
Node* insert(Node* root, int val) {
    if (!root) {
        return new Node(val);
    }
    
    Node* n = new Node(root->val);
    n->left = root->left;
    n->right = root->right;
    
    if (val < n->val) {
        n->left = insert(n->left, val);
    } else {
        // Se for igual, para simplificar vamos tratar como bst normal, 
        // inserindo à direita no caso de duplicatas, 
        // ou ignorar se a regra for conjunto (o pdf fala "apenas um se houver repetição"). 
        // Vou inserir a direita as repetições.
        n->right = insert(n->right, val);
    }
    return n;
}

// Encontra o nó com menor valor
Node* findMin(Node* root) {
    while (root && root->left) {
        root = root->left;
    }
    return root;
}

// Função de Remoção com path-copying
Node* removeNode(Node* root, int val, bool& found) {
    if (!root) return nullptr;

    if (val < root->val) {
        Node* left_child = removeNode(root->left, val, found);
        if (!found) return root; // Não achou, retorna a raiz original sem criar nós

        Node* n = new Node(root->val);
        n->left = left_child;
        n->right = root->right;
        return n;
    } else if (val > root->val) {
        Node* right_child = removeNode(root->right, val, found);
        if (!found) return root;

        Node* n = new Node(root->val);
        n->left = root->left;
        n->right = right_child;
        return n;
    } else { // Achou o nó a ser removido
        found = true;
        
        // Nó com 1 filho ou nenhum
        if (!root->left) return root->right;
        if (!root->right) return root->left;

        // Nó com 2 filhos
        Node* temp = findMin(root->right);
        Node* n = new Node(temp->val);
        n->left = root->left;
        bool dummy = false;
        n->right = removeNode(root->right, temp->val, dummy);
        return n;
    }
}

// Retorna o sucessor estrito de val. Se não houver, retorna um valor sentinela.
const int INFINITO = numeric_limits<int>::max();

int successor(Node* root, int val) {
    int succ = INFINITO;
    Node* curr = root;
    
    while (curr) {
        if (curr->val > val) {
            succ = curr->val;
            curr = curr->left;
        } else {
            curr = curr->right;
        }
    }
    
    return succ;
}

// Função para imprimir a árvore in-order
void printTree(Node* root, int depth, bool& first) {
    if (!root) return;
    printTree(root->left, depth + 1, first);
    
    if (!first) {
        cout << " ";
    }
    cout << root->val << "," << depth;
    first = false;
    
    printTree(root->right, depth + 1, first);
}

int main(int argc, char* argv[]) {
    if (argc < 2) {
        cerr << "Uso: " << argv[0] << " <arquivo_de_entrada.txt>\n";
        return 1;
    }

    ifstream infile(argv[1]);
    if (!infile.is_open()) {
        cerr << "Erro ao abrir o arquivo: " << argv[1] << "\n";
        return 1;
    }

    versions[0] = nullptr; // Versão inicial é vazia

    string line;
    while (getline(infile, line)) {
        if (line.empty()) continue;

        stringstream ss(line);
        string operation;
        ss >> operation;

        if (operation == "INC") {
            int val;
            ss >> val;
            
            Node* nova_raiz = insert(versions[current_version], val);
            current_version++;
            versions[current_version] = nova_raiz;
            
        } else if (operation == "REM") {
            int val;
            ss >> val;
            
            bool found = false;
            Node* nova_raiz = removeNode(versions[current_version], val, found);
            current_version++;
            versions[current_version] = nova_raiz; // Mesmo se não achado, a versão aumenta (baseado na especificação)

        } else if (operation == "SUC") {
            int val, versao;
            ss >> val >> versao;
            
            cout << line << "\n"; // Imprime a operação
            
            if (versao > current_version || versao < 0) {
                versao = current_version;
            }
            
            int suc = successor(versions[versao], val);
            if (suc == INFINITO) {
                cout << "infinito\n";
            } else {
                cout << suc << "\n";
            }
            
        } else if (operation == "IMP") {
            int versao;
            ss >> versao;
            
            cout << line << "\n"; // Imprime a operação
            
            if (versao > current_version || versao < 0) {
                versao = current_version;
            }
            
            bool first = true;
            printTree(versions[versao], 0, first);
            cout << "\n";
        }
    }

    infile.close();
    return 0;
}
