//
// Created by barba on 23.03.2025.
//

#include "../../arquivosH/dinamicas/Fila.h"
#include <iostream>
#include <stdexcept>

Fila::Fila() {
    frente = nullptr;
    fundo = nullptr;
}

Fila::~Fila() {
    // liberar nós
    NodeSimples* atual = frente;
    while(atual != nullptr) {
        NodeSimples* temp = atual;
        atual = atual->next;
        delete temp;
    }
}

void Fila::enqueue(int valor) {
    NodeSimples* novoNo = new NodeSimples(valor);
    if(vazia()) {
        frente = novoNo;
        fundo = novoNo;
    } else {
        fundo->next = novoNo;
        fundo = novoNo;
    }
}

int Fila::dequeue() {
    if(vazia()) {
        throw std::runtime_error("Fila vazia! Não é possível fazer dequeue.");
    }
    NodeSimples* temp = frente;
    int valorRemovido = temp->data;
    frente = frente->next;
    // se a fila ficar vazia, fundo deve virar nullptr
    if(frente == nullptr) {
        fundo = nullptr;
    }
    delete temp;
    return valorRemovido;
}

int Fila::frenteValor() const {
    if(vazia()) {
        throw std::runtime_error("Fila vazia! Não há elemento na frente.");
    }
    return frente->data;
}

bool Fila::vazia() const {
    return (frente == nullptr);
}
