//
// Created by barba on 23.03.2025.
//

#ifndef LISTASIMPLES_H
#define LISTASIMPLES_H
#include "../../arquivosH/nos/noSimples.h"  // para usar NodeSimples


class ListaSimples {

    private:
        NodeSimples* head; // ponteiro para o primeiro nó

    public:
        ListaSimples();
        ~ListaSimples();

        void inserirInicio(int val);
        void inserirFim(int val);


        void imprimir() const;
        bool buscar(int valor) const;
        void inserirNoMeio(int pos, int valor); // Ex: inserir após 'pos' passos, ou "posição"

    };

#endif //LISTASIMPLES_H
