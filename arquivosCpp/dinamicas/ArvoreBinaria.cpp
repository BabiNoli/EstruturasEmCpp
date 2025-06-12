#include "../../arquivosH/dinamicas/ArvoreBinaria.h"
#include <iostream>

ArvoreBinaria::ArvoreBinaria() {
    raiz = nullptr;
}

ArvoreBinaria::~ArvoreBinaria() {
    liberarRec(raiz);
}

// percorre liberando nós em pós-ordem
void ArvoreBinaria::liberarRec(NodeArvoreBinaria* no) {
    if(no) {
        liberarRec(no->esquerda);
        liberarRec(no->direita);
        delete no;
    }
}

void ArvoreBinaria::inserir(int valor) {
    inserirRec(raiz, valor);
}

// inserção recursiva seguindo a regra da árvore de busca binária
void ArvoreBinaria::inserirRec(NodeArvoreBinaria*& atual, int valor) {
    if(atual == nullptr) {
        atual = new NodeArvoreBinaria(valor);
    } else if(valor < atual->data) {
        inserirRec(atual->esquerda, valor);
    } else {
        inserirRec(atual->direita, valor);
    }
}

bool ArvoreBinaria::buscar(int valor) const {
    return buscarRec(raiz, valor);
}

// busca recursiva
bool ArvoreBinaria::buscarRec(NodeArvoreBinaria* atual, int valor) const {
    if(atual == nullptr) return false;
    if(valor == atual->data) return true;
    if(valor < atual->data) return buscarRec(atual->esquerda, valor);
    return buscarRec(atual->direita, valor);
}

void ArvoreBinaria::imprimirPreOrdem() const {
    preOrdemRec(raiz);
    std::cout << std::endl;
}

// visita o nó, depois esquerda e direita
void ArvoreBinaria::preOrdemRec(NodeArvoreBinaria* no) const {
    if(no == nullptr) return;
    std::cout << no->data << " ";
    preOrdemRec(no->esquerda);
    preOrdemRec(no->direita);
}
