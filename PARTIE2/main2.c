#include "fonctions.h"
#include <stdio.h>

int main() {

    char value[5];
    COLUMN *col = creer_colonne(STRING, "MaColonne");
    int a = 52, b = 44, c = 15, d = 18;
    insert_value(col,&a);
    insert_value(col,&b);
    insert_value(col,&c);
    insert_value(col,&d);
    convert_value(col,2,value,5);
    printf("%s ",value);


    return 0;
}
