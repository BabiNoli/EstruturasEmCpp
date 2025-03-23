//
// Created by barba on 23.03.2025.
//

#include "../../arquivosH/dinamicas/ListaCircularDupla.h"
#include <iostream>

ListaCircularDupla::ListaCircularDupla() {
    head = nullptr;
    tail = nullptr;
}

ListaCircularDupla::~ListaCircularDupla() {
    if(!head) return; // vazia, nada a liberar

    NodeDuplo* atual = head;
    // Precisamos percorrer toda a lista até voltar ao head.
    do {
        NodeDuplo* temp = atual;
        atual = atual->next;
        delete temp;
    } while(atual != head);

    head = nullptr;
    tail = nullptr;
}

bool ListaCircularDupla::vazia() const {
    return (head == nullptr);
}

void ListaCircularDupla::inserirInicio(int valor) {
    NodeDuplo* novoNo = new NodeDuplo(valor);
    if(vazia()) {
        // Se vazia, head=tail=novoNo, e ambos apontam para si mesmos
        head = novoNo;
        tail = novoNo;
        head->next = head;
        head->prev = head;
    } else {
        // Liga o novo nó antes do head
        novoNo->next = head;
        novoNo->prev = tail;
        head->prev = novoNo;
        tail->next = novoNo; // tail->next = novoNo para circularidade

        head = novoNo; // agora novoNo passa a ser o primeiro
    }
}

void ListaCircularDupla::inserirFim(int valor) {
    NodeDuplo* novoNo = new NodeDuplo(valor);
    if(vazia()) {
        // se vazia, é igual a inserirInicio no caso
        head = novoNo;
        tail = novoNo;
        head->next = head;
        head->prev = head;
    } else {
        // insere após tail
        novoNo->prev = tail;
        novoNo->next = head; // pois tail->next = head numa lista circular
        tail->next = novoNo;
        head->prev = novoNo;
        tail = novoNo; // agora novoNo é o último
    }
}

bool ListaCircularDupla::remover(int valor) {
    if(vazia()) return false;

    NodeDuplo* atual = head;
    // Vamos percorrer até voltar no head
    do {
        if(atual->data == valor) {
            // Se há só 1 nó (head=tail e next=prev=head)
            if(atual == head && atual == tail) {
                delete atual;
                head = nullptr;
                tail = nullptr;
            }
            // se for o head mas há vários nós
            else if(atual == head) {
                head = head->next;
                head->prev = tail;
                tail->next = head;
                delete atual;
            }
            // se for o tail
            else if(atual == tail) {
                tail = tail->prev;
                tail->next = head;
                head->prev = tail;
                delete atual;
            }
            // nó do meio
            else {
                atual->prev->next = atual->next;
                atual->next->prev = atual->prev;
                delete atual;
            }
            return true;
        }
        atual = atual->next;
    } while(atual != head);

    return false; // não encontrou
}

bool ListaCircularDupla::buscar(int valor) const {
    if(vazia()) return false;
    NodeDuplo* atual = head;
    do {
        if(atual->data == valor) return true;
        atual = atual->next;
    } while(atual != head);
    return false;
}

// IMPRIMIR PARA FRENTE
void ListaCircularDupla::imprimirParaFrente() const {
    if(vazia()) {
        std::cout << "Lista vazia\n";
        return;
    }
    NodeDuplo* atual = head;
    do {
        std::cout << atual->data << " <-> ";
        atual = atual->next;
    } while(atual != head);
    std::cout << "(volta ao inicio)\n";
}

// IMPRIMIR PARA TRÁS
void ListaCircularDupla::imprimirParaTras() const {
    if(vazia()) {
        std::cout << "Lista vazia\n";
        return;
    }
    NodeDuplo* atual = tail;
    do {
        std::cout << atual->data << " <-> ";
        atual = atual->prev;
    } while(atual != tail);
    std::cout << "(volta ao fim)\n";
}
