#include "fonctions.h"
#include <stdio.h>

int main() {


    //char str[5];
    COLUMN *mycol = creer_colonne(CHAR, "Column 1");
    char a = 'A', c = 'a';
    insert_value(mycol, &a);
    insert_value(mycol, NULL);
    insert_value(mycol, &c);
    //convert_value(mycol,3,str,5);
    //printf("%s",str);
    //afficher_col(mycol);
    //nb_occurences(mycol,(void *) NULL);
    //val_position(mycol,2);

    val_inf(mycol, (void*) 'z');

    return 0;
}