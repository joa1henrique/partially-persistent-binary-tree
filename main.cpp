
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include "bst.hpp"

using namespace std;

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

    versions[0] = nullptr; //versão inicial vazia

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
            versions[current_version] = nova_raiz; //mesmo se não achado, a versão aumenta

        } else if (operation == "SUC") {
            int val, versao;
            ss >> val >> versao;
            
            cout << line << "\n"; //imprime a operação
            
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
            
            cout << line << "\n"; //imprime a operação
            
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
            versions[current_version] = nova_raiz; //mesmo se não achado, a versão aumenta

        } else if (operation == "SUC") {
            int val, versao;
            ss >> val >> versao;
            
            cout << line << "\n"; //imprime a operação
            
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
            
            cout << line << "\n"; //imprime a operação
            
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
