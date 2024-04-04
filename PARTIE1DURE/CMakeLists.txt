cmake_minimum_required(VERSION 3.27)
project(Projet_C C)

set(CMAKE_C_STANDARD 11)

include_directories(..)

add_executable( PARTIE1DURE
        Colonnes.c
        Colonnes.h
        main.c)
