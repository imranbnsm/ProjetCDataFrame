#include "fonctions.h"
#include <stdio.h>

int main() {


    char str[5];
    COLUMN *mycol = creer_colonne(CHAR, "Column 1");
    char a = 'A', c = 'C';
    insert_value(mycol, &a);
    insert_value(mycol, NULL);
    insert_value(mycol, &c);
    convert_value(mycol,1,str,5);
    printf("%s",str);
    //afficher_col(mycol);

    //delete_column(&mycol);

    return 0;
}