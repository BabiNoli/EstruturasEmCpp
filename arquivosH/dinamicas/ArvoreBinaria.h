#ifndef ARVOREBINARIA_H
#define ARVOREBINARIA_H

#include "../../arquivosH/nos/noArvoreBinaria.h"

// Classe simples de Árvore Binária de Busca
class ArvoreBinaria {
private:
    NodeArvoreBinaria* raiz;                       // raiz da árvore

    // funções auxiliares recursivas
    void inserirRec(NodeArvoreBinaria*& atual, int valor);
    bool buscarRec(NodeArvoreBinaria* atual, int valor) const;
    void preOrdemRec(NodeArvoreBinaria* no) const;
    void liberarRec(NodeArvoreBinaria* no);

public:
    ArvoreBinaria();
    ~ArvoreBinaria();

    void inserir(int valor);                 // insere valor na árvore
    bool buscar(int valor) const;            // procura valor
    void imprimirPreOrdem() const;           // percorre em pré-ordem
};

#endif // ARVOREBINARIA_H
