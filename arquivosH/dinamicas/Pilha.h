//
// Created by barba on 23.03.2025.
//

#ifndef PILHA_H
#define PILHA_H
#include "../../arquivosH/nos/noSimples.h"


class Pilha {

    private:
        NodeSimples* topo; // ponteiro para o "topo" (último inserido)

    public:
        Pilha();
        ~Pilha();

        void push(int valor);  // empilha
        int pop();             // desempilha e retorna valor
        int peek() const;      // retorna valor do topo sem remover
        bool vazia() const;
    };

#endif // PILHA_H
