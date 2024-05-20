#ifndef PROJETCDATAFRAME_CDATAFRAME_H
#define PROJETCDATAFRAME_CDATAFRAME_H

#include "list.h"
#include "fonctions.h"

/*
 * Projet : CDataframe
 * Auteurs : Antoine Gosse, Imrân Benessam
 * Rôle : Ce fichier définit les structures et les fonctions pour manipuler un dataframe en C.
 */




/*
 * Type : CDATAFRAME
 * Description : Un dataframe contenant une liste de colonnes.
 */
typedef struct list CDATAFRAME;

/*
 * Fonction : vider_buffer
 * Rôle : Vider le buffer d'entrée.
 * Paramètres : Aucun.
 * Retour : Aucun.
 */
void vider_buffer();

/*
 * Fonction : creer_cdataframe
 * Rôle : Créer un nouveau dataframe avec des colonnes spécifiées.
 * Paramètres :
 *   - cdftype : Tableau des types des colonnes (ENUM_TYPE*).
 *   - size : Nombre de colonnes (int).
 * Retour : Pointeur vers le nouveau dataframe (CDATAFRAME*).
 */
CDATAFRAME *creer_cdataframe(ENUM_TYPE *cdftype, int size);

/*
 * Fonction : supprimer_cdataframe
 * Rôle : Supprimer un dataframe et libérer la mémoire associée.
 * Paramètres :
 *   - cdf : Pointeur vers le dataframe à supprimer (CDATAFRAME*).
 * Retour : Aucun.
 */
void supprimer_cdataframe(CDATAFRAME *cdf);

/*
 * Fonction : supprimer_Colonne
 * Rôle : Supprimer une colonne d'un dataframe par son nom.
 * Paramètres :
 *   - cdf : Pointeur vers le dataframe (CDATAFRAME*).
 *   - col_name : Nom de la colonne à supprimer (const char*).
 * Retour : Aucun.
 */
void supprimer_Colonne(CDATAFRAME *cdf, const char *col_name);

/*
 * Fonction : avoir_cdataframe_nb_col
 * Rôle : Obtenir le nombre de colonnes dans un dataframe.
 * Paramètres :
 *   - cdf : Pointeur vers le dataframe (CDATAFRAME*).
 * Retour : Nombre de colonnes (int).
 */
int avoir_cdataframe_nb_col(CDATAFRAME *cdf);

/*
 * Fonction : remplissage_Cdata
 * Rôle : Remplir un dataframe avec des données.
 * Paramètres :
 *   - cdf : Pointeur vers le dataframe (CDATAFRAME*).
 * Retour : Aucun.
 */
void remplissage_Cdata(CDATAFRAME *cdf);

/*
 * Fonction : remplissage_Cdata_dur
 * Rôle : Remplir un dataframe avec des données fixes (dur).
 * Paramètres : Aucun.
 * Retour : Pointeur vers le dataframe rempli (CDATAFRAME*).
 */
CDATAFRAME* remplissage_Cdata_dur();

/*
 * Fonction : affichage_Cdata
 * Rôle : Afficher le contenu d'un dataframe.
 * Paramètres :
 *   - cdf : Pointeur vers le dataframe (CDATAFRAME*).
 * Retour : Aucun.
 */
void affichage_Cdata(CDATAFRAME *cdf);

/*
 * Fonction : affichage_partiel_lignes
 * Rôle : Afficher partiellement les lignes d'un dataframe.
 * Paramètres :
 *   - cdf : Pointeur vers le dataframe (CDATAFRAME*).
 * Retour : Aucun.
 */
void affichage_partiel_lignes(CDATAFRAME *cdf);

/*
 * Fonction : affichage_partiel_colonnes
 * Rôle : Afficher partiellement les colonnes d'un dataframe.
 * Paramètres :
 *   - cdf : Pointeur vers le dataframe (CDATAFRAME*).
 * Retour : Aucun.
 */
void affichage_partiel_colonnes(CDATAFRAME *cdf);

/*
 * Fonction : ajouter_ligne
 * Rôle : Ajouter une ligne à un dataframe.
 * Paramètres :
 *   - cdf : Pointeur vers le dataframe (CDATAFRAME*).
 * Retour : Aucun.
 */
void ajouter_ligne(CDATAFRAME*cdf);

/*
 * Fonction : supprimer_ligne
 * Rôle : Supprimer une ligne d'un dataframe.
 * Paramètres :
 *   - cdf : Pointeur vers le dataframe (CDATAFRAME*).
 * Retour : Aucun.
 */
void supprimer_ligne(CDATAFRAME *cdf);

/*
 * Fonction : ajouter_colonne
 * Rôle : Ajouter une colonne à un dataframe.
 * Paramètres :
 *   - cdf : Pointeur vers le dataframe (CDATAFRAME*).
 *   - list_type : Type de la colonne à ajouter (ENUM_TYPE*).
 * Retour : Aucun.
 */
void ajouter_colonne(CDATAFRAME *cdf, ENUM_TYPE* list_type);

/*
 * Fonction : renommer_colonne
 * Rôle : Renommer une colonne d'un dataframe.
 * Paramètres :
 *   - cdf : Pointeur vers le dataframe (CDATAFRAME*).
 * Retour : Aucun.
 */
void renommer_colonne(CDATAFRAME *cdf);

/*
 * Fonction : recherche_valeur
 * Rôle : Rechercher une valeur dans un dataframe.
 * Paramètres :
 *   - cdf : Pointeur vers le dataframe (CDATAFRAME*).
 *   - valeur : Pointeur vers la valeur à rechercher (void*).
 * Retour : Aucun.
 */
void recherche_valeur(CDATAFRAME*cdf, void* valeur);

/*
 * Fonction : acces_remplacer_valeur
 * Rôle : Accéder et remplacer une valeur dans un dataframe.
 * Paramètres :
 *   - cdf : Pointeur vers le dataframe (CDATAFRAME*).
 *   - n_lig : Numéro de la ligne (int).
 *   - n_col : Numéro de la colonne (int).
 *   - value : nouvelle valeur (tous types).
 * Retour : Aucun.
 */
void acces_remplacer_valeur(CDATAFRAME *cdf, int n_lig, int n_col, void* value);

/*
 * Fonction : afficher_noms_colonnes
 * Rôle : Afficher les noms des colonnes d'un dataframe.
 * Paramètres :
 *   - cdf : Pointeur vers le dataframe (CDATAFRAME*).
 * Retour : Aucun.
 */
void afficher_noms_colonnes(CDATAFRAME *cdf);

/*
 * Fonction : afficher_nb_lignes
 * Rôle : Afficher le nombre de lignes d'un dataframe.
 * Paramètres :
 *   - cdf : Pointeur vers le dataframe (CDATAFRAME*).
 * Retour : Aucun.
 */
void afficher_nb_lignes(CDATAFRAME* cdf);

/*
 * Fonction : afficher_nb_col
 * Rôle : Afficher le nombre de colonnes d'un dataframe.
 * Paramètres :
 *   - cdf : Pointeur vers le dataframe (CDATAFRAME*).
 * Retour : Aucun.
 */
void afficher_nb_col(CDATAFRAME* cdf);

/*
 * Fonction : nb_cellule_egale
 * Rôle : Compter le nombre de cellules égales à une valeur donnée dans un dataframe.
 * Paramètres :
 *   - cdf : Pointeur vers le dataframe (CDATAFRAME*).
 *   - value : Pointeur vers la valeur à rechercher (void*).
 * Retour : Aucun.
 */
void nb_cellule_egale(CDATAFRAME* cdf, void* value);

/*
 * Fonction : nb_cellule_sup
 * Rôle : Compter le nombre de cellules supérieures à une valeur donnée dans un dataframe.
 * Paramètres :
 *   - cdf : Pointeur vers le dataframe (CDATAFRAME*).
 *   - value : Pointeur vers la valeur de comparaison (void*).
 * Retour : Aucun.
 */
void nb_cellule_sup(CDATAFRAME* cdf, void* value);

/*
 * Fonction : nb_cellule_inf
 * Rôle : Compter le nombre de cellules inférieures à une valeur donnée dans un dataframe.
 * Paramètres :
 *   - cdf : Pointeur vers le dataframe (CDATAFRAME*).
 *   - value : Pointeur vers la valeur de comparaison (void*).
 * Retour : Aucun.
 */
void nb_cellule_inf(CDATAFRAME* cdf, void* value);


#endif // PROJETCDATAFRAME_CDATAFRAME_H