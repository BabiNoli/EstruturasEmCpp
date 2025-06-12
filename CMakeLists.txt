cmake_minimum_required(VERSION 3.16)
project(EstruturasEmCpp)

set(CMAKE_CXX_STANDARD 20)

add_executable(EstruturasEmCpp
        main.cpp
        main2.cpp

        # Fixas (se existirem):
        arquivosCpp/fixas/MeuVector.cpp
        arquivosCpp/fixas/MinhaMatriz.cpp

        # Dinamicas:
        arquivosCpp/dinamicas/ListaSimples.cpp
        arquivosCpp/dinamicas/ListaDupla.cpp
        arquivosCpp/dinamicas/ListaCircularSimples.cpp
        arquivosCpp/dinamicas/ListaCircularDupla.cpp
        arquivosCpp/dinamicas/Pilha.cpp
        arquivosCpp/dinamicas/Fila.cpp
)
