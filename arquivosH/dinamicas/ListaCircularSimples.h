//
// Created by barba on 23.03.2025.
//

#ifndef LISTACIRCULARSIMPLES_H
#define LISTACIRCULARSIMPLES_H
#include "../../arquivosH/nos/noSimples.h"


class ListaCircularSimples {

    private:
        NodeSimples* tail; // Aponta para o último nó

    public:
        ListaCircularSimples();
        ~ListaCircularSimples();

        bool vazia() const; // verifica se está vazia
        void inserirInicio(int valor);
        void inserirFim(int valor);
        bool remover(int valor);
        bool buscar(int valor) const;

        void imprimir() const;
};

#endif // LISTACIRCULARSIMPLES_H
