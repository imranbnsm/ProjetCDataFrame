#include <stdio.h>
#include "fonctions.h"
#include "list.h"
#include "cdataframe.h"



int main() {
    /*char str[5];
    COLUMN *mycol = creer_colonne(CHAR, "Column 1");
    char a = 'A', c = 'a';
    insert_value(mycol, &a);
    insert_value(mycol, NULL);
    insert_value(mycol, &c);
    convert_value(mycol,3,str,5);
    printf("%s",str);
    afficher_col(mycol);
    nb_occurences(mycol,(void *) NULL);
    val_position(mycol,2);
    val_inf(mycol, (void*) 'z');*/
    CDATAFRAME *cdf=creer_Cdata_vide();
    remplissage_Cdata(cdf);
    affichage_Cdata(cdf);
    return 0;
}