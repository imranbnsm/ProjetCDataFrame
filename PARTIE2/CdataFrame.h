#ifndef PROJETCDATAFRAME_CDATAFRAME_H
#define PROJETCDATAFRAME_CDATAFRAME_H
#include "list.h"
#include "fonctions.h"

typedef struct list CDATAFRAME;
CDATAFRAME *create_cdataframe(ENUM_TYPE *cdftype, int size);
void delete_cdataframe(CDATAFRAME *cdf);
void delete_Column(CDATAFRAME *cdf, const char *col_name);
int get_cdataframe_cols_size(CDATAFRAME *cdf);
void remplissage_Cdata(CDATAFRAME *cdf);
CDATAFRAME* remplissage_Cdata_dur();
void affichage_Cdata(CDATAFRAME *cdf);
void affichage_partiel_lignes(CDATAFRAME *cdf);
void affichage_partiel_colonnes(CDATAFRAME *cdf);
void supprimer_ligne(CDATAFRAME *cdf);
void ajouter_colonne(CDATAFRAME *cdf,ENUM_TYPE* list_type);
void supprimer_colonne(CDATAFRAME *cdf);
void renommer_colonne(CDATAFRAME *cdf);
void recherche_valeur(CDATAFRAME*cdf,void* valeur);
void acces_remplacer_valeur(CDATAFRAME *cdf, int n_lig, int n_col);
void afficher_noms_colonnes(CDATAFRAME *cdf);
void afficher_nb_lignes(CDATAFRAME* cdf);
void afficher_nb_col(CDATAFRAME* cdf);
void nb_cellule_egale(CDATAFRAME* cdf, void* value);
void nb_cellule_sup(CDATAFRAME* cdf, void* value);
void nb_cellule_inf(CDATAFRAME* cdf, void* value);




void ajouter_ligne(CDATAFRAME*cdf);

#endif //PROJETCDATAFRAME_CDATAFRAME_H
