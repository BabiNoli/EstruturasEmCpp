//
// Created by barba on 23.03.2025.
//

#ifndef LISTACIRCULARDUPLA_H
#define LISTACIRCULARDUPLA_H
#include "../../arquivosH/nos/noDuplo.h"


class ListaCircularDupla {

    private:
        NodeDuplo* head; // Aponta para o primeiro nó
        NodeDuplo* tail; // Aponta para o último nó

    public:
        ListaCircularDupla();
        ~ListaCircularDupla();

        bool vazia() const;

        void inserirInicio(int valor);
        void inserirFim(int valor);
        bool remover(int valor);
        bool buscar(int valor) const;

        void imprimirParaFrente() const;
        void imprimirParaTras() const;
    };

#endif // LISTACIRCULARDUPLA_H