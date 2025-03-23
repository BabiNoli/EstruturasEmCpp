//
// Created by barba on 23.03.2025.
//

#include "../../arquivosH/dinamicas/ListaSimples.h"
#include <iostream>

ListaSimples::ListaSimples() {
    head = nullptr;
}

ListaSimples::~ListaSimples() {
    // percorrer e deletar nós
    NodeSimples* atual = head;
    while(atual) {
        NodeSimples* temp = atual;
        atual = atual->next;
        delete temp;
    }
}

void ListaSimples::inserirInicio(int val) {
    NodeSimples* novoNo = new NodeSimples(val);
    novoNo->next = head;
    head = novoNo;
}

void ListaSimples::inserirFim(int val) {
    NodeSimples* novoNo = new NodeSimples(val);
    if(!head) {
        head = novoNo;
        return;
    }
    NodeSimples* atual = head;
    while(atual->next) {
        atual = atual->next;
    }
    atual->next = novoNo;
}

// IMPRIMIR
void ListaSimples::imprimir() const {
    NodeSimples* atual = head;
    while (atual != nullptr) {
        std::cout << atual->data << " -> ";
        atual = atual->next;
    }
    std::cout << "NULL\n";
}

//  BUSCAR
bool ListaSimples::buscar(int valor) const {
    NodeSimples* atual = head;
    while (atual != nullptr) {
        if (atual->data == valor) {
            return true;
        }
        atual = atual->next;
    }
    return false;
}

// INSERIR NO "MEIO" (por índice ou posição)
void ListaSimples::inserirNoMeio(int pos, int valor) {
    // Se "pos" for 0 ou negativo, insere no início
    if(pos <= 0 || head == nullptr) {
        inserirInicio(valor);
        return;
    }

    NodeSimples* atual = head;
    // Avança (pos-1) nós, ou até o fim
    for(int i = 0; i < pos - 1 && atual->next != nullptr; i++) {
        atual = atual->next;
    }
    // agora 'atual' é o nó após o qual vamos inserir
    NodeSimples* novoNo = new NodeSimples(valor);
    novoNo->next = atual->next;
    atual->next = novoNo;
}

bool ListaSimples::remover(int valor) {
    // Se a lista estiver vazia, não há nada para remover
    if(head == nullptr) {
        return false;
    }

    // Se o valor está no primeiro nó (head)
    if(head->data == valor) {
        NodeSimples* temp = head;
        head = head->next;
        delete temp;
        return true;
    }

    // Senão, percorremos para achar o nó cujo "próximo" contenha o valor
    NodeSimples* atual = head;
    while(atual->next != nullptr && atual->next->data != valor) {
        atual = atual->next;
    }

    // Se chegamos ao fim (atual->next == nullptr), não achamos o valor
    if(atual->next == nullptr) {
        return false;
    }

    // Caso contrário, atual->next é o nó a remover
    NodeSimples* removido = atual->next;
    atual->next = removido->next;
    delete removido;
    return true;

}





