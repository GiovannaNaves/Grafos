// grafo.cpp
#include "grafo.hpp"
#include <fstream>
#include <iostream>

Grafo::Grafo(const std::string& filename, int v) {
    vertice = v;
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

    backwardStar(origem, destino);

    std::cout << "Sucessores = " << numSucessores << std::endl;
    std::cout << "Antecessores = " <<numAntecessores << std::endl;
    for (int elemento : sucessores) {
        std::cout << elemento << " ";
    }    
    std::cout << std::endl;
    for (int elemento : antecessores) {
        std::cout << elemento << " ";
    }
    std::cout << std::endl;

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
    numSucessores = 0;
    for (int indice = 0; indice < n; indice++){
        if (origem[indice] == vertice){
            sucessores.push_back(destino[indice]);
            numSucessores++;
        }
        if(indice == 0 || origem[indice] != origem[indice-1]){
            pointerFS.push_back(indice);
        }
    };
}

void Grafo:: backwardStar(std::vector<int>& origem, std::vector <int> & destino){
    bubbleSortGrafo(destino);
    int n = origem.size();
    numAntecessores = 0;
    for (int indice = 0; indice < n; indice++){
        if (destino[indice] == vertice){
            antecessores.push_back(origem[indice]);
            numAntecessores++;
        }
        if(destino[indice] != destino[indice-1]){
        pointerBS.push_back(indice);
        }
    };
}