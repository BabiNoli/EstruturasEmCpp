#include "../../arquivosH/dinamicas/ArvoreMultipla.h"
#include <iostream>

ArvoreMultipla::ArvoreMultipla() {
    raiz = nullptr;
}

ArvoreMultipla::~ArvoreMultipla() {
    liberarRec(raiz);
}

// libera todos os nós de forma recursiva
void ArvoreMultipla::liberarRec(NodeArvoreMultipla* no) {
    if(no) {
        for(auto filho : no->filhos) {
            liberarRec(filho);
        }
        delete no;
    }
}

void ArvoreMultipla::inserirRaiz(int valor) {
    if(raiz == nullptr) {
        raiz = new NodeArvoreMultipla(valor);
    } else {
        raiz->data = valor;
    }
}

void ArvoreMultipla::inserirFilho(NodeArvoreMultipla* pai, int valor) {
    if(pai) {
        NodeArvoreMultipla* novo = new NodeArvoreMultipla(valor);
        pai->filhos.push_back(novo);
    }
}

NodeArvoreMultipla* ArvoreMultipla::buscar(int valor) const {
    return buscarRec(raiz, valor);
}

// busca recursiva em profundidade
NodeArvoreMultipla* ArvoreMultipla::buscarRec(NodeArvoreMultipla* no, int valor) const {
    if(no == nullptr) return nullptr;
    if(no->data == valor) return no;
    for(auto filho : no->filhos) {
        NodeArvoreMultipla* achado = buscarRec(filho, valor);
        if(achado) return achado;
    }
    return nullptr;
}

void ArvoreMultipla::imprimirPreOrdem() const {
    preOrdemRec(raiz);
    std::cout << std::endl;
}

// percorre o nó e depois seus filhos
void ArvoreMultipla::preOrdemRec(NodeArvoreMultipla* no) const {
    if(no == nullptr) return;
    std::cout << no->data << " ";
    for(auto filho : no->filhos) {
        preOrdemRec(filho);
    }
}
