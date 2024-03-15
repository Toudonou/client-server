cmake_minimum_required(VERSION 3.27)
project(Recepteur_UDP C)

set(CMAKE_C_STANDARD 11)

add_executable(Recepteur_UDP main.c
        client.h
        client.c)
