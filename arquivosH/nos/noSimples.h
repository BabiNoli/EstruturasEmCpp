//
// Created by barba on 23.03.2025.


#ifndef NOSIMPLES_H
#define NOSIMPLES_H

// "NodeSimples" como struct "top-level"
struct NodeSimples {
    int data;
    NodeSimples* next;

    // construtor básico
    NodeSimples(int val) {
        data = val;
        next = nullptr;
    }
};

#endif // NOSIMPLES_H
