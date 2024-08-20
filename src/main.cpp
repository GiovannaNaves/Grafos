// main.cpp
#include <iostream>
#include "grafo.hpp"

using namespace std;

int main() {
    string filename;
    int v;

    cout << "Digite o nome do arquivo: ";
    cin >> filename >> v;

    Grafo grafo(filename, v);

    return 0;
}
