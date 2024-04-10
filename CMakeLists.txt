cmake_minimum_required(VERSION 3.27)
project(ProjetCDataFrame C)

set(CMAKE_C_STANDARD 11)

# Ajoutez ici les dossiers où se trouvent vos fichiers sources
include_directories(PARTIE1SIMPLE)
include_directories(PARTIE2)

# Ajoutez tous vos fichiers sources ici
add_executable(PARTIE1SIMPLE
        PARTIE1SIMPLE/Colonnes.c
        PARTIE1SIMPLE/Colonnes.h
        PARTIE1SIMPLE/main.c)
add_executable(PARTIE2
        PARTIE2/fonctions.c
        PARTIE2/fonctions.h
        PARTIE2/main2.c)