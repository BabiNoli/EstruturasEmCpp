#include <iostream>

// Inclua os headers de cada estrutura
#include "arquivosH/fixas/MeuVector.h"
#include "arquivosH/fixas/MinhaMatriz.h"
#include "arquivosH/dinamicas/ListaSimples.h"
#include "arquivosH/dinamicas/ListaDupla.h"
#include "arquivosH/dinamicas/ListaCircularSimples.h"
#include "arquivosH/dinamicas/ListaCircularDupla.h"
#include "arquivosH/dinamicas/Pilha.h"
#include "arquivosH/dinamicas/Fila.h"
#include "arquivosH/dinamicas/ArvoreBinaria.h"
#include "arquivosH/dinamicas/ArvoreMultipla.h"


int main2() {
    std::cout << "===== TESTES DAS ESTRUTURAS EM C++ =====\n\n";

    {
        std::cout << "[VECTOR]\n";
        MeuVector vector2(6);
        vector2.get(2);
        vector2.set(3, 45);
        std::cout << "Vector completo:\n";
        vector2.imprimir();
        std::cout << "Depois de remover 20:\n";
        vector2.imprimir(); // 10 -> 30 -> NULL
        std::cout << "\n";
    }

    {
        std::cout << "[MATRIZ]\n";
        MinhaMatriz MinhaMatriz2(6,6);
        int elemento = MinhaMatriz2.get(2, 2);
        std::cout << elemento << std::endl;
        MinhaMatriz2.set(3, 2, 45);
        std::cout << "Matriz completo:\n";
        MinhaMatriz2.imprimir();

        std::cout << "\n";
    }


    /*// 1) Vetor (MeuVetor2)
    {
        std::cout << "[VETOR]\n";
        MeuVector v(5);
        v.set(0, 10);
        v.set(1, 20);
        v.set(2, 30);
        std::cout << "Conteudo do vetor: ";
        v.print(); // deve mostrar "10 20 30 0 0"
        std::cout << "v.size() = " << v.size() << "\n\n";
    }

    // 2) Matriz (MinhaMatriz)
    {
        std::cout << "[MATRIZ]\n";
        MinhaMatriz m(2, 3);
        m.set(0, 0, 1);
        m.set(0, 1, 2);
        m.set(0, 2, 3);
        m.set(1, 0, 4);
        m.set(1, 1, 5);
        m.set(1, 2, 6);
        std::cout << "Conteudo da matriz 2x3:\n";
        m.print(); // deve mostrar duas linhas: "1 2 3" e "4 5 6"
        std::cout << "Linhas: " << m.getLinhas()
                  << ", Colunas: " << m.getColunas() << "\n\n";
    }*/


    // 3) Lista Simples (ListaSimples)
    {
        std::cout << "[LISTA SIMPLES]\n";
        ListaSimples lista;
        lista.inserirInicio(10);
        lista.inserirFim(20);
        lista.inserirFim(30);
        std::cout << "Lista apos inserir 10,20,30:\n";
        lista.imprimir(); // 10 -> 20 -> 30 -> NULL
        std::cout << "Buscar 20: " << (lista.buscar(20) ? "achou" : "nao achou") << "\n";
        lista.remover(20);
        std::cout << "Depois de remover 20:\n";
        lista.imprimir(); // 10 -> 30 -> NULL
        std::cout << "\n";
    }

    // 4) Lista Dupla (ListaDupla)
    {
        std::cout << "[LISTA DUPLA]\n";
        ListaDupla ld;
        ld.inserirInicio(100);
        ld.inserirFim(200);
        ld.inserirFim(300);
        std::cout << "ListaDupla para frente:\n";
        ld.imprimirParaFrente();  // 100 <-> 200 <-> 300 <-> NULL
        std::cout << "ListaDupla para tras:\n";
        ld.imprimirParaTras();    // 300 <-> 200 <-> 100 <-> NULL
        ld.remover(200);
        std::cout << "Apos remover 200:\n";
        ld.imprimirParaFrente(); // 100 <-> 300 <-> NULL
        std::cout << "\n";
    }

    // 5) Lista Circular Simples (ListaCircularSimples)
    {
        std::cout << "[LISTA CIRCULAR SIMPLES]\n";
        ListaCircularSimples lcs;
        lcs.inserirFim(1);
        lcs.inserirFim(2);
        lcs.inserirFim(3);
        lcs.imprimir(); // 1 -> 2 -> 3 -> (volta para o início)
        lcs.inserirInicio(0);
        lcs.imprimir(); // 0 -> 1 -> 2 -> 3 -> ...
        lcs.remover(2);
        lcs.imprimir(); // removeu o 2
        std::cout << (lcs.buscar(3) ? "3 esta na lista\n" : "3 nao esta na lista\n");
        std::cout << "\n";
    }

    // 6) Lista Circular Dupla (ListaCircularDupla)
    {
        std::cout << "[LISTA CIRCULAR DUPLA]\n";
        ListaCircularDupla lcd;
        lcd.inserirInicio(10);
        lcd.inserirFim(20);
        lcd.inserirFim(30);
        lcd.inserirFim(40);
        std::cout << "Para frente:\n";
        lcd.imprimirParaFrente(); // 10 <-> 20 <-> 30 <-> 40 <-> (volta ao inicio)
        std::cout << "Para tras:\n";
        lcd.imprimirParaTras();   // 40 <-> 30 <-> 20 <-> 10 <-> (volta ao fim)
        lcd.remover(20);
        lcd.imprimirParaFrente(); // 10 <-> 30 <-> 40 <-> ...
        std::cout << "\n";
    }

    // 7) Pilha (Pilha)
    {
        std::cout << "[PILHA]\n";
        Pilha pilha;
        pilha.push(7);
        pilha.push(14);
        pilha.push(21);
        std::cout << "Topo da pilha: " << pilha.peek() << "\n"; // deve ser 21
        std::cout << "Pop: " << pilha.pop() << "\n";            // remove 21
        std::cout << "Pop: " << pilha.pop() << "\n";            // remove 14
        std::cout << (pilha.vazia() ? "Pilha vazia\n" : "Pilha nao vazia\n");
        std::cout << "\n";
    }

    // 8) Fila (Fila)
    {
        std::cout << "[FILA]\n";
        Fila fila;
        fila.enqueue(1000);
        fila.enqueue(2000);
        fila.enqueue(3000);
        std::cout << "Frente: " << fila.frenteValor() << "\n";  // 1000
        std::cout << "Dequeue: " << fila.dequeue() << "\n";     // remove 1000
        std::cout << "Dequeue: " << fila.dequeue() << "\n";     // remove 2000
        std::cout << (fila.vazia() ? "Fila vazia\n" : "Fila nao vazia\n");
    }

    // 9) Arvore Binaria (ArvoreBinaria)
    {
        std::cout << "\n[ARVORE BINARIA]\n";
        ArvoreBinaria ab;
        ab.inserir(15);
        ab.inserir(10);
        ab.inserir(20);
        ab.inserir(8);
        std::cout << "Pre-ordem: ";
        ab.imprimirPreOrdem();           // 15 10 8 20
        std::cout << (ab.buscar(10) ? "Achou 10\n" : "Nao achou 10\n");
    }

    // 10) Arvore Multipla (ArvoreMultipla)
    {
        std::cout << "\n[ARVORE MULTIPLA]\n";
        ArvoreMultipla am;
        am.inserirRaiz(1);
        NodeArvoreMultipla* r = am.buscar(1);
        am.inserirFilho(r, 2);
        am.inserirFilho(r, 3);
        NodeArvoreMultipla* f2 = am.buscar(2);
        am.inserirFilho(f2, 4);
        std::cout << "Pre-ordem: ";
        am.imprimirPreOrdem();           // 1 2 4 3
    }

    std::cout << "\n===== FIM DOS TESTES =====" << std::endl;
    return 0;
}
