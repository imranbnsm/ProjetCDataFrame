#ifndef PROJETCDATAFRAME_CDATAFRAME_H
#define PROJETCDATAFRAME_CDATAFRAME_H

typedef struct{
    char* Titre;
    int TP;
    int TL;
    int* Donnees;
}COLONNE;

// la structure choisie pour le CdataFrame est un tableau de pointeurs

COLONNE ** creer_CDataframe();
int remplissage_Cdata(COLONNE** Cdata);
int remplissage_dur(COLONNE** Cdata);
void affichage_entier(COLONNE** Cdata, int nb_lignes);
void affichage_partiel_col(COLONNE** Cdata);
void affichage_partiel_lig(COLONNE** Cdata,int taille);

void ajouter_ligne(COLONNE** Cdata, int taille);
void supprimer_ligne(COLONNE** Cdata, int taille);
int ajouter_colonne(COLONNE** Cdata, int taille);
int supprimer_colonne_Cdataframe(COLONNE** Cdata, int taille);
void renommer_colonne(COLONNE** Cdata, int taille);

void recherche_valeur(COLONNE** Cdata, int taille, int valeur);
int acces_valeur(COLONNE** Cdata, int taille, int indiceint, int indice_lig);
void noms_colonnes(COLONNE** Cdata, int taille);
void nombre_lignes(COLONNE** Cdata, int taille);
void nombre_colonnes(COLONNE** Cdata, int taille);
void nombre_cellules_egales_x(COLONNE** Cdata,int taille, int x);
void nombre_cellules_sup_x(COLONNE** Cdata,int taille, int x);
void nombre_cellules_inf_x(COLONNE** Cdata,int taille, int x);

#endif //PROJETCDATAFRAME_CDATAFRAME_H
