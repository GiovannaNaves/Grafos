// grafo.hpp
#ifndef GRAFO_H
#define GRAFO_H

#include <vector>
#include <string>

class Grafo {
private:
    int numVertices;
    int numArestas;
    std::vector<int> origem;
    std::vector<int> destino;

public:
    Grafo(const std::string& filename);
    void carregarGrafo(const std::string& filename);
    void bubbleSortGrafo(std::vector<int>& vetor);
};

#endif
