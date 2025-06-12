#ifndef NOARVOREBINARIA_H
#define NOARVOREBINARIA_H

// Estrutura de nó para uma árvore binária
struct NodeArvoreBinaria {
    int data;                       // valor armazenado no nó
    NodeArvoreBinaria* esquerda;    // ponteiro para filho à esquerda
    NodeArvoreBinaria* direita;     // ponteiro para filho à direita

    // construtor básico
    NodeArvoreBinaria(int val) {
        data = val;
        esquerda = nullptr;
        direita = nullptr;
    }
};

#endif // NOARVOREBINARIA_H
