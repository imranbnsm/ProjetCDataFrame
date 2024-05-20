cmake_minimum_required(VERSION 3.27)
project(ProjetCDataFrame C)

set(CMAKE_C_STANDARD 11)

# Ajoutez ici les dossiers où se trouvent vos fichiers sources
include_directories(PARTIE2)

# Ajoutez tous vos fichiers sources ici
add_executable(PARTIE2
        PARTIE2/fonctions.c
        PARTIE2/fonctions.h
        PARTIE2/main.c
        PARTIE2/CdataFrame.h
        PARTIE2/CdataFrame.c
        PARTIE2/list.h
        PARTIE2/list.c
)