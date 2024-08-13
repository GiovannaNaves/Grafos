// Grafo.cpp
#include "Grafo.h"
#include <fstream>
#include <iostream>

Grafo::Grafo(const std::string& filename) {
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
}

void Grafo::exibirGrafo() {
    std::cout << "Número de Vértices: " << numVertices << std::endl;
    std::cout << "Arestas: " << std::endl;
    for (int i = 0; i < numArestas; ++i) {
        std::cout << origem[i] << " -> " << destino[i] << std::endl;
    }
}
