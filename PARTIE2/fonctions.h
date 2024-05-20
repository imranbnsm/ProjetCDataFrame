#ifndef PROJETC_COLONNES_H
#define PROJETC_COLONNES_H

/*
 * Projet : CDataframe
 * Auteurs : Antoine Gosse, Imrân Benessam
 * Rôle : Ce fichier définit les structures et les fonctions pour manipuler les colonnes d'un CDataframe.
 * Il inclut des définitions de types, des unions pour les types de données des colonnes,
 * et des prototypes de fonctions pour créer, insérer, supprimer et manipuler les colonnes.
 */

enum enum_type
{
    NULLVAL = 1, UINT, INT, CHAR, FLOAT, DOUBLE, STRING, STRUCTURE
};
typedef enum enum_type ENUM_TYPE;

union column_type {
    unsigned int uint_value;
    signed int int_value;
    char char_value;
    float float_value;
    double double_value;
    char* string_value;
    void* struct_value;
};
typedef union column_type COL_TYPE;

struct column {
    char *titre;                     // Titre de la colonne
    unsigned int TL;                 // Taille logique
    unsigned int TP;                 // Taille physique
    ENUM_TYPE column_type;           // Type des données de la colonne
    COL_TYPE **data;                 // Tableau de pointeurs vers les données stockées
    unsigned long long int *index;   // Tableau d'index
};
typedef struct column COLUMN;

/*
 * Fonction : creer_colonne
 * Rôle : Créer une nouvelle colonne avec un type et un titre spécifiés.
 * Paramètres :
 *   - type : Type des données de la colonne (ENUM_TYPE).
 *   - titre : Titre de la colonne (char*).
 * Retour : Pointeur vers la nouvelle colonne (COLUMN*).
 */
COLUMN *creer_colonne(ENUM_TYPE type, char* titre);

/*
 * Fonction : insert_value
 * Rôle : Insérer une valeur dans une colonne.
 * Paramètres :
 *   - col : Pointeur vers la colonne (COLUMN*).
 *   - value : Pointeur vers la valeur à insérer (void*).
 * Retour : 1 si l'insertion est réussie, 0 sinon (int).
 */
int insert_value(COLUMN *col, void *value);

/*
 * Fonction : delete_column
 * Rôle : Supprimer une colonne et libérer la mémoire associée.
 * Paramètres :
 *   - col : Pointeur vers le pointeur de la colonne à supprimer (COLUMN**).
 * Retour : Aucun.
 */
void delete_column(COLUMN **col);

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
void convert_value(COLUMN *col, unsigned long long int i, char *str, int size);

/*
 * Fonction : afficher_col
 * Rôle : Afficher le contenu d'une colonne.
 * Paramètres :
 *   - col : Pointeur vers la colonne (COLUMN*).
 * Retour : Aucun.
 */
void afficher_col(COLUMN* col);

/*
 * Fonction : nb_occurences
 * Rôle : Compter le nombre d'occurrences d'une valeur dans une colonne.
 * Paramètres :
 *   - col : Pointeur vers la colonne (COLUMN*).
 *   - value : Pointeur vers la valeur à rechercher (void*).
 * Retour : Nombre d'occurrences de la valeur dans la colonne (int).
 */
int nb_occurences(COLUMN* col, void* value);

/*
 * Fonction : val_position
 * Rôle : Afficher la valeur d'une cellule à une position spécifique.
 * Paramètres :
 *   - col : Pointeur vers la colonne (COLUMN*).
 *   - position : Position de la cellule (int).
 * Retour : Aucun.
 */
void val_position(COLUMN* col, int position);

/*
 * Fonction : val_sup
 * Rôle : Comparer les valeurs d'une colonne pour vérifier si elles sont supérieures à une valeur donnée.
 * Paramètres :
 *   - col : Pointeur vers la colonne (COLUMN*).
 *   - valeur : Pointeur vers la valeur à comparer (void*).
 *   - bool : Indicateur booléen (int).
 * Retour : Nombre de valeurs supérieures (int).
 */
int val_sup(COLUMN* col, void* valeur, int bool);

/*
 * Fonction : val_inf
 * Rôle : Comparer les valeurs d'une colonne pour vérifier si elles sont inférieures à une valeur donnée.
 * Paramètres :
 *   - col : Pointeur vers la colonne (COLUMN*).
 *   - valeur : Pointeur vers la valeur à comparer (void*).
 *   - bool : Indicateur booléen (int).
 * Retour : Nombre de valeurs inférieures (int).
 */
int val_inf(COLUMN* col, void* valeur, int bool);

/*
 * Fonction : val_egale
 * Rôle : Comparer les valeurs d'une colonne pour vérifier si elles sont égales à une valeur donnée.
 * Paramètres :
 *   - col : Pointeur vers la colonne (COLUMN*).
 *   - valeur : Pointeur vers la valeur à comparer (void*).
 *   - bool : Indicateur booléen (int).
 * Retour : Nombre de valeurs égales (int).
 */
int val_egale(COLUMN* col, void* valeur, int bool);

#endif //PROJETC_COLONNES_H