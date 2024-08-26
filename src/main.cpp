#include <iostream>
#include "grafo.hpp"

using namespace std;

int main() {
    string filename;
    int v;

    cout << "Digite o nome do arquivo e o número do vértice: ";
    cin >> filename >> v;

    Grafo grafo(filename, v);

    return 0;
}
