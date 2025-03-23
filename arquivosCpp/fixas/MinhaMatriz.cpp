//
// Created by barba on 23.03.2025.
//

#include "../../arquivosH/fixas/MinhaMatriz.h"
#include <iostream>
using namespace std;

int main() {
    int n, m, i, j;
    cout << "Digite o tamanho da matriz[][]: ";
    cin >> n >> m;
    int matriz[n][m];
    cout << "Digite os elementos: ";
    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            cin >> matriz[i][j];
        }
    }

    cout << endl;
    for (i= 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            cout << matriz[i][j] << " ";
        }
        cout << endl;
    }

    cout << endl;
    cout << "Pares: ";
    for (i= 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            if (matriz[i][j] % 2 == 0) {
                cout << matriz[i][j] << " ";
            }
        }
    }
    return 0;
}
