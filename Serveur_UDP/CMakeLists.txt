cmake_minimum_required(VERSION 3.27)
project(Serveur_UDP C)

set(CMAKE_C_STANDARD 11)

add_executable(Serveur_UDP main.c
        serveur.c)
