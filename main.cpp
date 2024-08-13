// main.cpp
#include <iostream>
#include "Grafo.h"

using namespace std;

int main() {
    string filename;
    int vertice;

    cout << "Digite o nome do arquivo: ";
    cin >> filename;

    Grafo grafo(filename);

    grafo.exibirGrafo();

    return 0;
}
