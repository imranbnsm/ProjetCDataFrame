#include <stdio.h>
#include "fonctions.h"
#include "list.h"
#include "CdataFrame.h"



int main() {
    char str[5];
    COLUMN *mycol = creer_colonne(CHAR, "Column 1");
    char a = 'A', c = 'a';
    insert_value(mycol, &a);
    insert_value(mycol, NULL);
    insert_value(mycol, &c);
    afficher_col(mycol);
    //nb_occurences(mycol,(void *) NULL);
    //val_position(mycol,2);
    //val_inf(mycol, (void*) 'z');
    //CDATAFRAME *cdf=creer_Cdata_vide();
    //CDATAFRAME *cdf=lst_create_list();
    //LNODE *noeud= lst_create_lnode(NULL);
    //lst_insert_head(cdf,noeud);
    //remplissage_Cdata_dur(cdf);
    //afficher_col(cdf->head->data);
    //affichage_Cdata(cdf);
    return 0;
}