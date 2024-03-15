cmake_minimum_required(VERSION 3.27)
project(Serveur C)

set(CMAKE_C_STANDARD 11)

add_executable(Serveur main.c
        serveur.c
        serveur.h
)
