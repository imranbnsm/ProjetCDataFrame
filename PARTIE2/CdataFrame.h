#ifndef PROJETCDATAFRAME_CDATAFRAME_H
#define PROJETCDATAFRAME_CDATAFRAME_H
#include "list.h"
#include "fonctions.h"

typedef struct list CDATAFRAME;
CDATAFRAME *create_cdataframe(ENUM_TYPE *cdftype, int size);
void delete_cdataframe(CDATAFRAME *cdf);
void delete_Column(CDATAFRAME *cdf, const char *col_name);
int get_cdataframe_cols_size(CDATAFRAME *cdf);
CDATAFRAME *creer_Cdata_vide();
void remplissage_Cdata(CDATAFRAME *cdf);
void remplissage_Cdata_dur(CDATAFRAME *cdf);
void affichage_Cdata(CDATAFRAME *cdf);
void affichage_partiel_lignes(CDATAFRAME *cdf);
void affichage_partiel_colonnes(CDATAFRAME *cdf);





void ajouter_ligne(CDATAFRAME*cdf);

#endif //PROJETCDATAFRAME_CDATAFRAME_H
