cmake_minimum_required(VERSION 3.30)
project(EstruturasEmCpp)

set(CMAKE_CXX_STANDARD 20)


add_executable(EstruturasEmCpp
        main.cpp
        arquivosCpp/dinamicas/ListaSimples.cpp
        arquivosH/nos/noSimples.h
        arquivosCpp/dinamicas/ListaDupla.cpp
        arquivosH/nos/noDuplo.h
        arquivosCpp/dinamicas/ListaCircularSimples.cpp
        arquivosCpp/dinamicas/ListaCircularDupla.cpp
        arquivosCpp/dinamicas/Pilha.cpp
        arquivosCpp/dinamicas/Fila.cpp

)