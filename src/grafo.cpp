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

int Grafo::particionar(std::vector<int>& vetor, std::vector<int>& vetor2, int baixo, int alto) {
    int pivô = vetor[alto];
    int i = baixo - 1;

    for (int j = baixo; j < alto; ++j) {
        if (vetor[j] <= pivô) {
            ++i;
            std::swap(vetor[i], vetor[j]);
            std::swap(vetor2[i], vetor2[j]);
        }
    }
    std::swap(vetor[i + 1], vetor[alto]);
    std::swap(vetor2[i + 1], vetor2[alto]);
    return i + 1;
}

void Grafo:: quickSortGrafo(std::vector<int>& vetor, std::vector<int>& vetor2, int baixo, int alto) {
    if (baixo < alto) {
        int pivoIndex = particionar(vetor, vetor2, baixo, alto); 
        quickSortGrafo(vetor, vetor2, baixo, pivoIndex - 1);
        quickSortGrafo(vetor, vetor2, pivoIndex + 1, alto); 
    }
}

void Grafo:: forwardStar(std::vector<int>& origem, std::vector <int> & destino){
    quickSortGrafo(origem, destino, 0, origem.size() - 1);

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
    quickSortGrafo(destino, origem, 0, destino.size() -1);
    int n = origem.size();
    numAntecessores = 0;
    for (int indice = 0; indice < n; indice++){
        if (destino[indice] == vertice){
            antecessores.push_back(origem[indice]);
            numAntecessores++;
        }
        if(indice == 0 || destino[indice] != destino[indice - 1]){
            pointerBS.push_back(indice);
        }
    };
}