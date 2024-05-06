#ifndef PROJETCDATAFRAME_CDATAFRAME_H
#define PROJETCDATAFRAME_CDATAFRAME_H
#include "list.h"
#include "fonctions.h"
typedef list CDATAFRAME;
CDATAFRAME *create_cdataframe(ENUM_TYPE *cdftype, int size);
void delete_cdataframe(CDATAFRAME *cdf);
void delete_Column(CDATAFRAME *cdf, char *col_name);
int get_cdataframe_cols_size(CDATAFRAME *cdf);
CDATAFRAME *creer_Cdata_vide();
void remplissage_Cdata(CDATAFRAME *cdf);
void remplissage_Cdata_dur(CDATAFRAME *cdf);
void affichage_Cdata(CDATAFRAME *cdf);

#endif //PROJETCDATAFRAME_CDATAFRAME_H
