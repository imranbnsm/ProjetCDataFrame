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
int occurences(COLONNE* col, int val);
int val_position(COLONNE* col, int pos);

#endif //PROJETC_COLONNES_H