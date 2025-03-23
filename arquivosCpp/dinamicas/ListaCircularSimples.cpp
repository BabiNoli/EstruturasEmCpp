//
// Created by barba on 23.03.2025.
//

#include "../../arquivosH/dinamicas/ListaCircularSimples.h"
#include <iostream>

ListaCircularSimples::ListaCircularSimples() {
    tail = nullptr;
}

ListaCircularSimples::~ListaCircularSimples() {
    if(!tail) return; // lista vazia, nada a deletar

    // Se não estiver vazia, precisamos percorrer todos nós e deletá-los
    NodeSimples* atual = tail->next; // primeiro nó
    NodeSimples* fim = tail;         // último nó

    // Percorremos até voltar ao tail
    while(true) {
        NodeSimples* temp = atual;
        if (atual == fim) {
            // é o último nó
            delete temp;
            break;
        }
        atual = atual->next;
        delete temp;
    }
    tail = nullptr;
}

bool ListaCircularSimples::vazia() const {
    return (tail == nullptr);
}

void ListaCircularSimples::inserirInicio(int valor) {
    NodeSimples* novoNo = new NodeSimples(valor);

    if(vazia()) {
        tail = novoNo;
        // Aponta para si mesmo, formando o círculo
        tail->next = tail;
    } else {
        // "head" é tail->next
        NodeSimples* head = tail->next;
        novoNo->next = head;
        tail->next = novoNo;
        // Agora, novoNo é o primeiro
    }
}

void ListaCircularSimples::inserirFim(int valor) {
    NodeSimples* novoNo = new NodeSimples(valor);

    if(vazia()) {
        // se vazia, é igual a inserirInicio
        tail = novoNo;
        tail->next = tail;
    } else {
        // se não vazia, insere após tail
        novoNo->next = tail->next; // tail->next é o "head"
        tail->next = novoNo;
        tail = novoNo; // agora 'novoNo' passa a ser o último
    }
}

bool ListaCircularSimples::remover(int valor) {
    if(vazia()) return false;

    NodeSimples* atual = tail->next; // "head"
    NodeSimples* anterior = tail;    // pois tail->next = head, e "antes do head" seria tail
    NodeSimples* fim = tail;

    do {
        if(atual->data == valor) {
            // se for o único nó (tail->next == tail)
            if(atual == tail && atual->next == tail) {
                delete atual;
                tail = nullptr;
            }
            // se for o tail, mas a lista tem vários
            else if(atual == tail) {
                anterior->next = atual->next;
                tail = anterior;
                delete atual;
            }
            // se for o head (atual = tail->next) mas não único
            else if(atual == tail->next) {
                anterior->next = atual->next;
                delete atual;
            }
            // se for nó do meio
            else {
                anterior->next = atual->next;
                delete atual;
            }
            return true;
        }
        anterior = atual;
        atual = atual->next;
    } while (anterior != fim);
    // Vamos parar quando 'anterior' chegar de novo no fim (tail),
    // ou seja, deu a volta e não encontrou.

    return false; // não achou
}

bool ListaCircularSimples::buscar(int valor) const {
    if(vazia()) return false;

    NodeSimples* atual = tail->next; // head
    NodeSimples* fim = tail;

    // faz do-while para percorrer do head até voltar
    do {
        if(atual->data == valor) return true;
        atual = atual->next;
    } while(atual != fim->next); // fim->next é o head de novo

    return false;
}

void ListaCircularSimples::imprimir() const {
    if(vazia()) {
        std::cout << "Lista vazia\n";
        return;
    }
    NodeSimples* head = tail->next;
    NodeSimples* atual = head;
    do {
        std::cout << atual->data << " -> ";
        atual = atual->next;
    } while (atual != head); // quando voltar ao head, paramos
    std::cout << "(volta para o início)\n";
}
