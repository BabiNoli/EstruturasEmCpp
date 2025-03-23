//
// Created by barba on 23.03.2025.
//

#ifndef LISTADUPLA_H
#define LISTADUPLA_H

#include "../../arquivosH/nos/noDuplo.h"

    class ListaDupla {
    private:
        NodeDuplo* head;  // ponteiro para o primeiro nó
        NodeDuplo* tail;  // ponteiro para o último nó

    public:
        ListaDupla();
        ~ListaDupla();

        void inserirInicio(int valor);
        void inserirFim(int valor);
        bool remover(int valor);
        bool buscar(int valor) const;

        void imprimirParaFrente() const;
        void imprimirParaTras() const;
    };

#endif // LISTADUPLA_H