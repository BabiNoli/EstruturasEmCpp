#ifndef ARVOREMULTIPLA_H
#define ARVOREMULTIPLA_H

#include "../../arquivosH/nos/noArvoreMultipla.h"

// Classe de árvore n-ária (cada nó pode ter vários filhos)
class ArvoreMultipla {
private:
    NodeArvoreMultipla* raiz;                         // nó raiz

    void liberarRec(NodeArvoreMultipla* no);          // libera memória
    NodeArvoreMultipla* buscarRec(NodeArvoreMultipla* no, int valor) const;
    void preOrdemRec(NodeArvoreMultipla* no) const;

public:
    ArvoreMultipla();
    ~ArvoreMultipla();

    void inserirRaiz(int valor);                      // define a raiz
    void inserirFilho(NodeArvoreMultipla* pai, int valor); // adiciona filho a um nó
    NodeArvoreMultipla* buscar(int valor) const;      // retorna ponteiro para o valor
    void imprimirPreOrdem() const;                    // percorre em pré-ordem
};

#endif // ARVOREMULTIPLA_H
