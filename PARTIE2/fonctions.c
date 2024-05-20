#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "fonctions.h"
#define REALLOC_SIZE 256

/*
 * Projet : CDataframe
 * Auteurs : Antoine Gosse, Imrân Benessam
 * Rôle : Ce fichier implémente les fonctions définies dans fonctions.h pour manipuler les colonnes d'un CDataframe.
 * Il inclut des fonctions pour créer, insérer, supprimer, afficher et effectuer des opérations sur les colonnes.
 */





/*
 * Fonction : creer_colonne
 * Rôle : Créer une nouvelle colonne avec un type et un titre spécifiés.
 * Paramètres :
 *   - type : Type des données de la colonne (ENUM_TYPE).
 *   - titre : Titre de la colonne (char*).
 * Retour : Pointeur vers la nouvelle colonne (COLUMN*).
 */
COLUMN *creer_colonne(ENUM_TYPE type, char* titre) {
    COLUMN *colonne = (COLUMN *) malloc(sizeof(COLUMN));

    if(colonne == NULL){
        return NULL;
    }

    colonne->titre = strdup(titre);
    colonne->TP = 0;
    colonne->TL = 0;
    colonne->column_type = type;
    colonne->data = NULL;
    colonne->index = NULL;

    return colonne;
}

/*
 * Fonction : insert_value
 * Rôle : Insérer une valeur dans une colonne.
 * Paramètres :
 *   - col : Pointeur vers la colonne (COLUMN*).
 *   - value : Pointeur vers la valeur à insérer (void*).
 * Retour : 1 si l'insertion est réussie, 0 sinon (int).
 */
int insert_value(COLUMN *col, void *value) {

    if (col->TL == col->TP) {
        col->TP += REALLOC_SIZE;
        col->data = realloc(col->data, col->TP * sizeof(void *));
        col->index = realloc(col->index, col->TP * sizeof(unsigned long long int));
    }

    if (col->data == NULL || col->index == NULL) {
        return 0; // Échec de l'allocation de mémoire
    }

    if (value == NULL){
        col->data[col->TL] = NULL;
        col->TL++;
        return 1;
    }

    switch (col->column_type) {
        case INT:
            col->data[col->TL] = malloc(sizeof(int));
            *((int *) col->data[col->TL]) = *((int *) value);
            break;
        case CHAR:
            col->data[col->TL] = malloc(sizeof(char));
            *((char *) col->data[col->TL]) = *((char *) value);
            break;
        case UINT:
            col->data[col->TL] = malloc(sizeof(unsigned int));
            *((unsigned int *) col->data[col->TL]) = *((unsigned int *) value);
            break;
        case FLOAT:
            col->data[col->TL] = malloc(sizeof(float));
            *((float *) col->data[col->TL]) = *((float *) value);
            break;
        case DOUBLE:
            col->data[col->TL] = malloc(sizeof(double));
            *((double *) col->data[col->TL]) = *((double *) value);
            break;
        case STRING:
            col->data[col->TL] = malloc(strlen((char *)value) + 1); // Allouer de la mémoire pour la chaîne de caractères + '\0'
            strcpy((char *)col->data[col->TL], (char *)value);
            break;
        case STRUCTURE:
            // Gestion des structures non implémentée
            break;
    }
    col->TL++;
    return 1; // Succès
}

/*
 * Fonction : delete_column
 * Rôle : Supprimer une colonne et libérer la mémoire associée.
 * Paramètres :
 *   - col : Pointeur vers le pointeur de la colonne à supprimer (COLUMN**).
 * Retour : Aucun.
 */
void delete_column(COLUMN **col){
    if (*col != NULL) {
        free((*col)->data);
        free((*col)->titre);
        free((*col));
        *col = NULL; // Éviter les pointeurs libérés
    }
}

/*
 * Fonction : convert_value
 * Rôle : Convertir la valeur d'une cellule en chaîne de caractères.
 * Paramètres :
 *   - col : Pointeur vers la colonne (COLUMN*).
 *   - i : Index de la valeur à convertir (unsigned long long int).
 *   - str : Pointeur vers la chaîne de caractères de destination (char*).
 *   - size : Taille de la chaîne de caractères de destination (int).
 * Retour : Aucun.
 */
void convert_value(COLUMN *col, unsigned long long int i, char *str, int size) {
    if (i >= col->TL) {
        printf("Index hors limites.\n");
        return;
    }

    if (col->data[i] == NULL){
        printf("NULL");
        return;
    }

    switch(col->column_type) {
        case INT:
            snprintf(str, size, "%d", *((int*)col->data[i]));
            break;
        case CHAR:
            snprintf(str, size, "%c", *((char*)col->data[i]));
            break;
        case UINT:
            snprintf(str, size, "%u", *((unsigned int*)col->data[i]));
            break;
        case FLOAT:
            snprintf(str, size, "%.2f", *((float*)col->data[i]));
            break;
        case DOUBLE:
            snprintf(str, size, "%.2lf", *((double*)col->data[i]));
            break;
        case STRING:
            snprintf(str, size, "%s", (char*)col->data[i]);
            break;
        default:
            printf("Type de colonne non géré.\n");
            break;
    }
}

/*
 * Fonction : afficher_col
 * Rôle : Afficher le contenu d'une colonne.
 * Paramètres :
 *   - col : Pointeur vers la colonne (COLUMN*).
 * Retour : Aucun.
 */
void afficher_col(COLUMN* col){
    char str[10];
    printf("%s\n", col->titre);
    for (int i = 0; i < col->TL; i++){
        if (col->data[i] == NULL){
            printf("[%d] NULL\n", i);
        } else {
            convert_value(col, i, str, 10);
            printf("[%d] %s\n", i, str);
        }
    }
}

/*
 * Fonction : nb_occurences
 * Rôle : Compter le nombre d'occurrences d'une valeur dans une colonne.
 * Paramètres :
 *   - col : Pointeur vers la colonne (COLUMN*).
 *   - value : Pointeur vers la valeur à rechercher (void*).
 * Retour : Nombre d'occurrences de la valeur dans la colonne (int).
 */
int nb_occurences(COLUMN* col, void* value) {
    int occ = 0;

    if (col == NULL || col->data == NULL || value == NULL) {
        printf("La valeur recherchee n'existe pas dans la colonne.");
        return 0;
    }

    for (unsigned long long int i = 0; i < col->TL; i++){
        if (col->data[i] == NULL) {
            continue;
        }

        switch (col->column_type) {
            case UINT:
                if (*(unsigned int*)(col->data[i]) == *(unsigned int*)value) {
                    occ++;
                }
                break;
            case INT:
                if (*(int*)col->data[i] == *(int*)value) {
                    occ++;
                }
                break;
            case CHAR:
                if (*(char*)(col->data[i]) == *(char*)value) {
                    occ++;
                }
                break;
            case FLOAT:
                if (*(float*)(col->data[i]) == *(float*)value) {
                    occ++;
                }
                break;
            case DOUBLE:
                if (*(double*)(col->data[i]) == *(double*)value) {
                    occ++;
                }
                break;
            case STRING:
                if (strcmp((char*)(col->data[i]), (char*)value) == 0) {
                    occ++;
                }
                break;
            default:
                printf("Erreur rencontrée");
                break;
        }
    }
    if (occ == 0) {
        printf("La valeur recherchee n'existe pas dans la colonne.\n");
    } else {
        printf("La valeur recherchee apparait %d fois dans la colonne.\n", occ);
    }
    return occ;
}

/*
 * Fonction : val_position
 * Rôle : Afficher la valeur d'une cellule à une position spécifique.
 * Paramètres :
 *   - col : Pointeur vers la colonne (COLUMN*).
 *   - position : Position de la cellule (int).
 * Retour : Aucun.
 */
void val_position(COLUMN* col, int position) {
    if (col == NULL || col->data == NULL ) {
        printf("La colonne est vide.");
        return;
    }

    if (position > col->TL) {
        printf("Taille de la colonne depassee.");
        return;
    }

    for (unsigned long long int i = 0; i < col->TL; i++){
        char str[10];
        if (i == position){
            printf("La valeur a la position %d est : ", position);
            convert_value(col, position, str, 10);
            printf("%s", str);
            return;
        }
    }
}

/*
 * Fonction : val_sup
 * Rôle : Comparer les valeurs d'une colonne avec une valeur donnée pour trouver les valeurs supérieures.
 * Paramètres :
 *   - col : Pointeur vers la colonne (COLUMN*).
 *   - valeur : Pointeur vers la valeur de comparaison (void*).
 *   - bool : Indicateur pour afficher le résultat (int).
 * Retour : Nombre de valeurs supérieures (int).
 */
int val_sup(COLUMN* col, void* valeur, int bool) {
    if (col == NULL || col->data == NULL ) {
        printf("La colonne ou la valeur est NULL.\n");
        return 0;
    }

    int count = 0;

    for (unsigned long long int i = 0; i < col->TL; i++) {
        if (col->data[i] == NULL) {
            continue;
        }

        switch (col->column_type) {
            case UINT:
                if (*(unsigned int*)(col->data[i]) > *(unsigned int*)valeur) {
                    count++;
                }
                break;
            case INT:
                if (*(int*)(col->data[i]) > *(int*)valeur) {
                    count++;
                }
                break;
            case CHAR:
                if (*(char*)(col->data[i]) > *(char*)valeur) {
                    count++;
                }
                break;
            case FLOAT:
                if (*(float*)(col->data[i]) > *(float*)valeur) {
                    count++;
                }
                break;
            case DOUBLE:
                if (*(double*)(col->data[i]) > *(double*)valeur) {
                    count++;
                }
                break;
            case STRING:
                printf("Impossible de comparer des chaines de caracteres avec cette fonction.\n");
                break;
            default:
                break;
        }
    }
    if (count == 0 && bool == 1) {
        printf("Il n'y a pas de valeurs superieures dans la colonne.\n");
    } else if (bool == 1){
        printf("Il y a %d valeur(s) superieure(s) dans la colonne.\n", count);
    }
    return count;
}

/*
 * Fonction : val_inf
 * Rôle : Comparer les valeurs d'une colonne avec une valeur donnée pour trouver les valeurs inférieures.
 * Paramètres :
 *   - col : Pointeur vers la colonne (COLUMN*).
 *   - valeur : Pointeur vers la valeur de comparaison (void*).
 *   - bool : Indicateur pour afficher le résultat (int).
 * Retour : Nombre de valeurs inférieures (int).
 */
int val_inf(COLUMN* col, void* valeur, int bool) {
    if (col == NULL || col->data == NULL ) {
        printf("La colonne ou la valeur est NULL.\n");
        return 0;
    }

    int count = 0;

    for (unsigned long long int i = 0; i < col->TL; i++) {
        if (col->data[i] == NULL) {
            continue;
        }

        switch (col->column_type) {
            case UINT:
                if (*(unsigned int*)(col->data[i]) < *(unsigned int*)valeur) {
                    count++;
                }
                break;
            case INT:
                if (*(int*)(col->data[i]) < *(int*)valeur) {
                    count++;
                }
                break;
            case CHAR:
                if (*(char*)(col->data[i]) < *(char*)valeur) {
                    count++;
                }
                break;
            case FLOAT:
                if (*(float*)(col->data[i]) < *(float*)valeur) {
                    count++;
                }
                break;
            case DOUBLE:
                if (*(double*)(col->data[i]) < *(double*)valeur) {
                    count++;
                }
                break;
            case STRING:
                printf("Impossible de comparer des chaines de caracteres avec cette fonction.\n");
                break;
            default:
                break;
        }
    }
    if (count == 0 && bool == 1) {
        printf("Il n'y a pas de valeurs inferieures dans la colonne.\n");
    } else if (bool == 1){
        printf("Il y a %d valeur(s) inferieure(s) dans la colonne.\n", count);
    }
    return count;
}

/*
 * Fonction : val_egale
 * Rôle : Comparer les valeurs d'une colonne avec une valeur donnée pour trouver les valeurs égales.
 * Paramètres :
 *   - col : Pointeur vers la colonne (COLUMN*).
 *   - valeur : Pointeur vers la valeur de comparaison (void*).
 *   - bool : Indicateur pour afficher le résultat (int).
 * Retour : Nombre de valeurs égales (int).
 */
int val_egale(COLUMN* col, void* valeur, int bool) {
    if (col == NULL || col->data == NULL ) {
        printf("La colonne ou la valeur est NULL.\n");
        return 0;
    }

    int count = 0;

    for (unsigned long long int i = 0; i < col->TL; i++) {
        if (col->data[i] == NULL) {
            continue;
        }

        switch (col->column_type) {
            case UINT:
                if (*(unsigned int*)(col->data[i]) == *(unsigned int*)valeur) {
                    count++;
                }
                break;
            case INT:
                if (*(int*)(col->data[i]) == *(int*)valeur) {
                    count++;
                }
                break;
            case CHAR:
                if (*(char*)(col->data[i]) == *(char*)valeur) {
                    count++;
                }
                break;
            case FLOAT:
                if (*(float*)(col->data[i]) == *(float*)valeur) {
                    count++;
                }
                break;
            case DOUBLE:
                if (*(double*)(col->data[i]) == *(double*)valeur) {
                    count++;
                }
                break;
            case STRING:
                printf("Impossible de comparer des chaines de caracteres avec cette fonction.\n");
                break;
            default:
                break;
        }
    }
    if (count == 0 && bool == 1) {
        printf("Il n'y a pas de valeurs egales dans la colonne.\n");
    } else if (bool == 1){
        printf("Il y a %d valeur(s) egale(s) dans la colonne.\n", count);
    }
    return count;
}
