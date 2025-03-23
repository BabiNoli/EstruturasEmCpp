//
// Created by barba on 23.03.2025.
//

#ifndef MEUVECTOR_H
#define MEUVECTOR_H



class MeuVector {
    private:
        int* dados;       // ponteiro para armazenar elementos
        int capacidade;   // tamanho fixo para este vetor

    public:
        // Construtor que recebe o tamanho desejado
        MeuVector(int tamanho);

        // Destrutor
        ~MeuVector();

        // Métodos básicos
        int get(int indice) const;        // obtém valor
        void set(int indice, int valor);  // define valor

        int size() const;                 // retorna capacidade

        // (Opcional) imprime todos os valores
        void print() const;

};



#endif //MEUVECTOR_H
