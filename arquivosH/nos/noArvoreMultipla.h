#ifndef NOARVOREMULTIPLA_H
#define NOARVOREMULTIPLA_H

#include <vector>

// Nó para uma árvore genérica (n-ária)
struct NodeArvoreMultipla {
    int data;                                   // valor do nó
    std::vector<NodeArvoreMultipla*> filhos;    // lista de filhos

    // construtor básico
    NodeArvoreMultipla(int val) {
        data = val;
    }
};

#endif // NOARVOREMULTIPLA_H
