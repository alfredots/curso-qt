cmake_minimum_required(VERSION 3.5)

project(lab3 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(lab3
    main.cpp
    iimposto.cpp
    ipi.cpp
    icms.cpp
    iproduto.cpp
    produtoeletronico.cpp
    produtoalimenticio.cpp
)
