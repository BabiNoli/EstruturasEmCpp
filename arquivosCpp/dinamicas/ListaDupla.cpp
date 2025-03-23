//
// Created by barba on 23.03.2025.
//

#include "../../arquivosH/dinamicas/ListaDupla.h"
#include <iostream>

ListaDupla::ListaDupla() {
    head = nullptr;
    tail = nullptr;
}

ListaDupla::~ListaDupla() {
    // Percorre de head até o fim, liberando nós
    NodeDuplo* atual = head;
    while(atual) {
        NodeDuplo* temp = atual;
        atual = atual->next;
        delete temp;
    }
}

// Inserir no INÍCIO
void ListaDupla::inserirInicio(int valor) {
    NodeDuplo* novoNo = new NodeDuplo(valor);

    // Se a lista estiver vazia
    if(!head) {
        head = novoNo;
        tail = novoNo;
    } else {
        // Liga o antigo head ao novoNo
        novoNo->next = head;
        head->prev = novoNo;
        // Atualiza o head
        head = novoNo;
    }
}

// Inserir no FIM
void ListaDupla::inserirFim(int valor) {
    NodeDuplo* novoNo = new NodeDuplo(valor);

    // Se lista estiver vazia
    if(!tail) {
        head = novoNo;
        tail = novoNo;
    } else {
        // Conecta
        tail->next = novoNo;
        novoNo->prev = tail;
        // Atualiza tail
        tail = novoNo;
    }
}

// REMOVER
bool ListaDupla::remover(int valor) {
    // Se vazia:
    if(!head) return false;

    NodeDuplo* atual = head;

    while(atual) {
        if(atual->data == valor) {
            // Se é o primeiro nó
            if(atual == head) {
                head = head->next;
                if(head) {
                    head->prev = nullptr;
                } else {
                    // Se head virou nulo, tail também deve
                    tail = nullptr;
                }
            }
            // Se é o último nó
            else if(atual == tail) {
                tail = tail->prev;
                tail->next = nullptr;
            }
            // Nó do meio
            else {
                atual->prev->next = atual->next;
                atual->next->prev = atual->prev;
            }
            delete atual;
            return true;
        }
        atual = atual->next;
    }
    return false; // não encontrou
}

// BUSCAR
bool ListaDupla::buscar(int valor) const {
    NodeDuplo* atual = head;
    while(atual) {
        if(atual->data == valor) return true;
        atual = atual->next;
    }
    return false;
}

// IMPRIMIR para frente
void ListaDupla::imprimirParaFrente() const {
    NodeDuplo* atual = head;
    while(atual) {
        std::cout << atual->data << " <-> ";
        atual = atual->next;
    }
    std::cout << "NULL\n";
}

// IMPRIMIR para trás
void ListaDupla::imprimirParaTras() const {
    NodeDuplo* atual = tail;
    while(atual) {
        std::cout << atual->data << " <-> ";
        atual = atual->prev;
    }
    std::cout << "NULL\n";
}
