#include "fonctions.h"
#include <stdio.h>

int main() {
    COLUMN *col = creer_colonne(INT, "MaColonne");
    if (col == NULL) {
        printf("Erreur lors de la création de la colonne.\n");
        return 1;
    }

    int value = 42;
    insert_value(col,&value);
    printf("%d",col->data[0]);

    return 0;
}
