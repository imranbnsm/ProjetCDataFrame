#ifndef PROJETC_COLONNES_H
#define PROJETC_COLONNES_H

typedef struct{
    char* Titre;
    int TP;
    int TL;
    int* Donnees;
}COLONNE;

COLONNE* creer_colonne(char* titre);
int inserer_valeur(COLONNE* col, int valeur);
void supprimer_colonne(COLONNE **col);
void print_col(COLONNE* col);
void print_col_lig(COLONNE* col, int nb_lignes);

int occurences(COLONNE* col, int val);
int val_position(COLONNE* col, int pos);
int nb_val_sup(COLONNE* col, int val);
int nb_val_inf(COLONNE* col, int val);
int nb_val_egal(COLONNE* col, int val);

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



void ajouter_ligne(COLONNE** Cdata, int taille);

#endif //PROJETC_COLONNES_H
