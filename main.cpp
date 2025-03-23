#include <iostream>
#include "arquivosH/dinamicas/ListaSimples.h"  // ou qualquer arquivo que inclua o Node
#include "arquivosH/dinamicas/ListaDupla.h"
#include "arquivosH/dinamicas/ListaCircularSimples.h"
#include "arquivosH/dinamicas/ListaCircularDupla.h"
#include "arquivosH/dinamicas/Pilha.h"
#include "arquivosH/dinamicas/Fila.h"

#ifdef _WIN32
#include <windows.h>   // só disponível no Windows
#endif

int main() {

    #ifdef _WIN32
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);
    #endif

    //std::cout << "Olá, ç, ã, é!" << std::endl;


    std::cout << "Testando lista simples\n";
    ListaSimples lista;
    lista.inserirInicio(10);
    lista.inserirFim(20);
    lista.inserirFim(30);

    lista.imprimir(); // deve mostrar: 10 -> 20 -> 30 -> NULL


    std::cout << "Testando lista dupla\n";

    ListaDupla listaDupla;

    listaDupla.inserirInicio(10);
    listaDupla.inserirFim(20);
    listaDupla.inserirFim(30);
    listaDupla.inserirFim(40);

    std::cout << "Impressão para frente: ";
    listaDupla.imprimirParaFrente();   // 10 <-> 20 <-> 30 <-> 40 <-> NULL

    std::cout << "Impressão para trás: ";
    listaDupla.imprimirParaTras();     // 40 <-> 30 <-> 20 <-> 10 <-> NULL

    std::cout << "Remover 20\n";
    listaDupla.remover(20);

    listaDupla.imprimirParaFrente();   // 10 <-> 30 <-> 40 <-> NULL
    listaDupla.imprimirParaTras();     // 40 <-> 30 <-> 10 <-> NULL

    std::cout << "Buscar 30: " << (listaDupla.buscar(30) ? "achou" : "não achou") << std::endl;
    std::cout << "Buscar 50: " << (listaDupla.buscar(50) ? "achou" : "não achou") << std::endl;

    std::cout << "Testando lista circular simples\n";

    ListaCircularSimples lista_circular_simples;
    lista_circular_simples.inserirFim(10);
    lista_circular_simples.inserirFim(20);
    lista_circular_simples.inserirFim(30);
    lista_circular_simples.imprimir(); // 10 -> 20 -> 30 -> (volta para o início)

    lista_circular_simples.inserirInicio(5);
    lista_circular_simples.imprimir(); // 5 -> 10 -> 20 -> 30 -> (volta para o início)

    lista_circular_simples.remover(20);
    lista_circular_simples.imprimir(); // 5 -> 10 -> 30 -> (volta para o início)

    std::cout << "Buscar 30: " << (lista_circular_simples.buscar(30) ? "achou" : "não achou") << std::endl;
    std::cout << "Buscar 50: " << (lista_circular_simples.buscar(50) ? "achou" : "não achou") << std::endl;

    std::cout << "Testando lista circular dupla\n";
    ListaCircularDupla lista_circular_dupla;

    lista_circular_dupla.inserirInicio(10);
    lista_circular_dupla.inserirFim(20);
    lista_circular_dupla.inserirFim(30);
    lista_circular_dupla.inserirFim(40);

    lista_circular_dupla.imprimirParaFrente(); // 10 <-> 20 <-> 30 <-> 40 <-> (volta ao inicio)
    lista_circular_dupla.imprimirParaTras();   // 40 <-> 30 <-> 20 <-> 10 <-> (volta ao fim)

    lista_circular_dupla.remover(20);
    lista_circular_dupla.imprimirParaFrente(); // 10 <-> 30 <-> 40 <-> (volta ao inicio)

    std::cout << "Buscar 30: " << (lista_circular_dupla.buscar(30) ? "achou" : "não achou") << std::endl;
    std::cout << "Buscar 100: " << (lista_circular_dupla.buscar(100) ? "achou" : "não achou") << std::endl;

    std::cout << "Testando Pilha\n";
    Pilha p;
    p.push(10);
    p.push(20);
    p.push(30);

    std::cout << "Topo: " << p.peek() << std::endl; // deve ser 30
    std::cout << "Pop: " << p.pop() << std::endl;   // remove e retorna 30
    std::cout << "Pop: " << p.pop() << std::endl;   // deve ser 20

    std::cout << (p.vazia() ? "Pilha vazia" : "Pilha não vazia") << std::endl;

    std::cout << "Testando Fila\n";
    Fila f;
    f.enqueue(10);
    f.enqueue(20);
    f.enqueue(30);

    std::cout << "Frente: " << f.frenteValor() << std::endl; // 10
    std::cout << "Dequeue: " << f.dequeue() << std::endl;    // remove 10
    std::cout << "Frente: " << f.frenteValor() << std::endl; // 20

    f.dequeue(); // remove 20
    f.dequeue(); // remove 30
    // f.dequeue(); // geraria exceção pois agora está vazia

    std::cout << (f.vazia() ? "Fila vazia" : "Fila não vazia") << std::endl;



    return 0;

}



// TIP See CLion help at <a
// href="https://www.jetbrains.com/help/clion/">jetbrains.com/help/clion/</a>.
//  Also, you can try interactive lessons for CLion by selecting
//  'Help | Learn IDE Features' from the main menu.