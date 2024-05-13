#include <stdio.h>
#include "fonctions.h"
#include "list.h"
#include "CdataFrame.h"



int main() {
    //char str[5];
    //COLUMN *mycol = creer_colonne(CHAR, "Column 1");
    //char a = 'A', c = 'a';
    //insert_value(mycol, &a);
    //insert_value(mycol, NULL);
    //insert_value(mycol, &c);
    //afficher_col(mycol);
    //nb_occurences(mycol,(void *) NULL);
    //val_position(mycol,2);
    //val_inf(mycol, (void*) 'z');
    /*int size;
    printf("Combien de colonnes ?\n");
    scanf("%d",&size);*/
    ENUM_TYPE list_type[]={(ENUM_TYPE ) NULLVAL, (ENUM_TYPE ) UINT, (ENUM_TYPE ) INT, (ENUM_TYPE ) CHAR, (ENUM_TYPE ) FLOAT, (ENUM_TYPE ) DOUBLE, (ENUM_TYPE ) STRING, (ENUM_TYPE ) STRUCTURE};
    CDATAFRAME *cdata= create_cdataframe(list_type, 2);
    remplissage_Cdata(cdata);
    afficher_col(cdata->head->data);
    //affichage_Cdata(cdf);
    return 0;
}