// grafo.cpp
#include "grafo.hpp"
#include <fstream>
#include <iostream>

Grafo::Grafo(const std::string& filename, int v) {
    carregarGrafo(filename);
    vertice = v;
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
    sucessores.resize(numArestas);
    antecessores.resize(numArestas);
    pointer.resize(numArestas);

    for (int i = 0; i < numArestas; ++i) {
        file >> origem[i] >> destino[i];
    }

    file.close();
    forwardStar(origem, destino);
    backwardStar(origem, destino);
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
    int indiceSucessores = 0;
    for (indice = 0; indice <= n; indice++){
        if (origem[indice] == vertice){
            sucessores[indiceSucessores] = destino[indice];
            indiceSucessores++;
        }
        if(origem[indice] == origem[indice-1]){
        } else {
        pointer[it] = indice;
        it++;
        }
    };
}

void Grafo:: backwardStar(std::vector<int>& origem, std::vector <int> & destino){
    bubbleSortGrafo(destino);
    int n = origem.size();
    int it = 0;
    int indice = 0;
    int indiceAntecessores = 0;
    for (indice = 0; indice <= n; indice++){
        if (destino[indice] == vertice){
            antecessores[indiceAntecessores] = origem[indice];
            indiceAntecessores++;
        }
        if(destino[indice] == destino[indice-1]){
        } else {
        pointer[it] = indice;
        it++;
        }
    };
}