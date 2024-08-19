// main.cpp
#include <iostream>
#include "grafo.hpp"

using namespace std;

int main() {
    string filename;
    // int vertice;

    cout << "Digite o nome do arquivo: ";
    cin >> filename;

    Grafo grafo(filename);

    return 0;
}
