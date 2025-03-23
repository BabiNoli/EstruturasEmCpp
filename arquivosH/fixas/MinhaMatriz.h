//
// Created by barba on 23.03.2025.
//

#ifndef MINHAMATRIZ_H
#define MINHAMATRIZ_H

class MinhaMatriz {
private:
    int** dados;     // ponteiro de ponteiro (para 2D)
    int linhas;
    int colunas;

public:
    // Construtor
    MinhaMatriz(int lin, int col);

    // Destrutor
    ~MinhaMatriz();

    // Métodos
    int get(int i, int j) const;
    void set(int i, int j, int valor);
    void print() const;

    int getLinhas() const;
    int getColunas() const;

};

#endif //MINHAMATRIZ_H
