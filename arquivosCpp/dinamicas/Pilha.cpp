//
// Created by barba on 23.03.2025.
//

#include "../../arquivosH/dinamicas/Pilha.h"
#include <iostream>
#include <stdexcept> // para std::runtime_error, se quiser

Pilha::Pilha() {
    topo = nullptr;
}

Pilha::~Pilha() {
    // liberar todos os nós
    NodeSimples* atual = topo;
    while(atual != nullptr) {
        NodeSimples* temp = atual;
        atual = atual->next;
        delete temp;
    }
}

void Pilha::push(int valor) {
    NodeSimples* novoNo = new NodeSimples(valor);
    novoNo->next = topo; // aponta para antigo topo
    topo = novoNo;       // agora topo é o novo nó
}

int Pilha::pop() {
    if(vazia()) {
        // você pode tratar de várias formas, ex:
        // retornar um valor especial ou lançar exceção
        throw std::runtime_error("Pilha vazia! Não é possível fazer pop.");
    }
    NodeSimples* temp = topo;
    int valorRemovido = temp->data;
    topo = topo->next;
    delete temp;
    return valorRemovido;
}

int Pilha::peek() const {
    if(vazia()) {
        throw std::runtime_error("Pilha vazia! Não há elemento no topo.");
    }
    return topo->data;
}

bool Pilha::vazia() const {
    return (topo == nullptr);
}

