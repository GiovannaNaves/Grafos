#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main() {
    string filename;
    int numVertices, numPairs;

    cin >> filename;

    ifstream file(filename);

    if (!file.is_open()) {
        cerr << "Erro ao abrir o arquivo: " << filename << std::endl;
        return 1;
    }

    file >> numVertices >> numPairs;

    vector<int> firstNumbers(numPairs);
    vector<int> secondNumbers(numPairs);

    for (int i = 0; i < numPairs; ++i) {
        file >> firstNumbers[i] >> secondNumbers[i];
    }

    file.close();

    return 0;
}
