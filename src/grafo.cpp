// grafo.cpp
#include "grafo.hpp"
#include <fstream>
#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>

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

void Grafo::sortGrafo(std::vector<int>& origem, std::vector<int>& destino) {
    // Combinar origem e destino em um vetor de pares
    std::vector<std::pair<int, int>> combinados;
    for (size_t i = 0; i < origem.size(); ++i) {
        combinados.push_back({origem[i], destino[i]});
    }

    // Ordenar o vetor de pares baseado no primeiro valor (origem)
    std::sort(combinados.begin(), combinados.end(), [](const std::pair<int, int>& a, const std::pair<int, int>& b) {
        return a.first < b.first;
    });

    // Separar os pares de volta nos vetores origem e destino
    for (size_t i = 0; i < combinados.size(); ++i) {
        origem[i] = combinados[i].first;
        destino[i] = combinados[i].second;
    }
}

void Grafo:: forwardStar(std::vector<int>& origem, std::vector <int> & destino){
    sortGrafo(origem, destino);

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
    sortGrafo(destino, origem);
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