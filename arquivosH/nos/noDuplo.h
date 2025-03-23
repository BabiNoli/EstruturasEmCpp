//
// Created by barba on 23.03.2025.
//

#ifndef NODUPLO_H
#define NODUPLO_H

// "NodeSimples" como struct "top-level"
struct NodeDuplo {
    int data;
    NodeDuplo* prev;
    NodeDuplo* next;


    // construtor básico
    NodeDuplo(int val) {
        data = val;
        next = nullptr;
        prev = nullptr;
    }
};

#endif // NOSDUPLO_H