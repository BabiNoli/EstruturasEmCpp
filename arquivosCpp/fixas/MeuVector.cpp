//
// Created by barba on 23.03.2025.
//

#include "../../arquivosH/fixas/MeuVector.h"
#include <iostream>

using namespace std;

int main() {
    int n, i, j;
    cout << "Digite o tamanho do vetor: ";
    cin >> n;
    int vetor[n];
    cout << "Digite os elementos: ";
    for (i = 0; i < n; i++) {
        cin >> vetor[i];
    }

    cout << endl;
    for (j = 0; j < n; j++) {
        cout << vetor[j] << " ";
    }
    cout << endl;
    cout << "Pares: ";
    for (j = 0; j < n; j++) {
        if (vetor[j] % 2 == 0) {
            cout << vetor[j] << " ";
        }
    }

    return 0;
}

