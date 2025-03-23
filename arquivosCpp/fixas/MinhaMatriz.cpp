#include <iostream>
#include "../../arquivosH/fixas/MinhaMatriz.h"

MinhaMatriz::MinhaMatriz(int lin, int col) {
    linhas = lin;
    colunas = col;
    // Aloca as linhas
    dados = new int*[linhas];
    // Para cada linha, alocar colunas
    for(int i = 0; i < linhas; i++) {
        dados[i] = new int[colunas];
        // inicializa com 0
        for(int j = 0; j < colunas; j++) {
            dados[i][j] = 0;
        }
    }
}

MinhaMatriz::~MinhaMatriz() {
    // liberar cada linha
    for(int i = 0; i < linhas; i++) {
        delete[] dados[i];
    }
    // liberar o ponteiro de ponteiros
    delete[] dados;
}

int MinhaMatriz::get(int i, int j) const {
    return dados[i][j];
}

void MinhaMatriz::set(int i, int j, int valor) {
    dados[i][j] = valor;
}

void MinhaMatriz::imprimir() const {
    for(int i = 0; i < linhas; i++) {
        for(int j = 0; j < colunas; j++) {
            std::cout << dados[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

int MinhaMatriz::getLinhas() const {
    return linhas;
}

int MinhaMatriz::getColunas() const {
    return colunas;
}
