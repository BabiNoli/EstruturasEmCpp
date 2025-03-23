//
// Created by barba on 23.03.2025.
//

#ifndef FILA_H
#define FILA_H
#include "../../arquivosH/nos/noSimples.h"

class Fila {

    private:
        NodeSimples* frente; // início da fila
        NodeSimples* fundo;  // fim da fila

    public:
        Fila();
        ~Fila();

        void enqueue(int valor); // insere no final
        int dequeue();           // remove do início
        int frenteValor() const; // retorna o valor da frente sem remover
        bool vazia() const;
    };

#endif // FILA_H
