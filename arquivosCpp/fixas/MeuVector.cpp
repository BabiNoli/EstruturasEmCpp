#include "../../arquivosH/fixas/MeuVector.h"
#include <iostream>

using namespace std;


MeuVector::MeuVector(int tamanho) {
    capacidade = tamanho;
    // aloca array de int
    dados = new int[capacidade];
    // inicializa com zero
    for (int i = 0; i < capacidade; i++) {
        dados[i] = 0;
    }
}

MeuVector::~MeuVector() {
    // libera a memória alocada dinamicamente
    delete[] dados;
}

int MeuVector::get(int indice) const {
    // em código real, pode ser útil validar indice
    return dados[indice];
}

void MeuVector::set(int indice, int valor) {
    dados[indice] = valor;
}

int MeuVector::tamanho() const {
    return capacidade;
}

void MeuVector::imprimir() const {
    for (int i = 0; i < capacidade; i++) {
        std::cout << dados[i] << " ";
    }
    std::cout << std::endl;
}