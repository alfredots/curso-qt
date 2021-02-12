cmake_minimum_required(VERSION 3.5)

project(lab3 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(lab3
    main.cpp
    iproduto.cpp
    produtoalimenticio.cpp
    produtoeletronico.cpp
    iimposto.cpp
    impostoicms.cpp
    impostoipi.cpp
)
