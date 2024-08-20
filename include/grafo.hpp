// grafo.hpp
#ifndef GRAFO_H
#define GRAFO_H

#include <vector>
#include <string>

class Grafo {
private:
    int vertice;
    int numVertices;
    int numArestas;
    int numSucessores;
    int numAntecessores;
    std::vector<int> origem;
    std::vector<int> destino;
    std::vector<int> pointerFS;
    std::vector<int> pointerBS;
    std::vector<int> sucessores;
    std::vector<int> antecessores;

public:
    Grafo(const std::string& filename, int vertice);
    void carregarGrafo(const std::string& filename);
    int particionar(std::vector<int>& vetor, int baixo, int alto);
    void quickSortGrafo(std::vector<int>& vetor, int baixo, int alto);
    void forwardStar (std::vector<int>& origem, std::vector <int> & destino);
    void backwardStar (std::vector<int>& origem, std::vector <int> & destino);
};

#endif
