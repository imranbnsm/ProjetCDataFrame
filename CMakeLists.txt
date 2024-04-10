cmake_minimum_required(VERSION 3.27)
project(ProjetCDataFrame C)

set(CMAKE_C_STANDARD 11)

# Ajoutez ici les dossiers où se trouvent vos fichiers sources
include_directories(PARTIE1SIMPLE)

# Ajoutez tous vos fichiers sources ici
add_executable(PARTIE1SIMPLE
        PARTIE1SIMPLE/Colonnes.c
        PARTIE1SIMPLE/Colonnes.h
        PARTIE1SIMPLE/main.c)