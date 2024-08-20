// grafo.cpp
#include "grafo.hpp"
#include <fstream>
#include <iostream>

Grafo::Grafo(const std::string& filename, int vertice) {
    carregarGrafo(filename);
}

void Grafo::carregarGrafo(const std::string& filename) {
    std::ifstream file(filename);

    if (!file.is_open()) {
        std::cerr << "Erro ao abrir o arquivo: " << filename << std::endl;
        return;
    }

    file >> numVertices >> numArestas;
    origem.resize(numArestas);
    destino.resize(numArestas);

    for (int i = 0; i < numArestas; ++i) {
        file >> origem[i] >> destino[i];
    }

    file.close();
    forwardStar(origem, destino);
}

void Grafo:: bubbleSortGrafo(std::vector<int>& vetor) {
    int n = vetor.size();
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (vetor[j] > vetor[j + 1]) {
                int temp = vetor[j];
                vetor[j] = vetor[j + 1];
                vetor[j + 1] = temp;
            }
        }
    }

}

void Grafo:: forwardStar(std::vector<int>& origem, std::vector <int> & destino){
    bubbleSortGrafo(origem);
    int n = origem.size();
    int it = 0;
    int indice = 0;
    for (indice = 0; indice <= n; indice++){
        if(origem[indice] == origem[indice-1]){
        } else {
        pointer[it] = indice;
        it++;
        }
    };

}