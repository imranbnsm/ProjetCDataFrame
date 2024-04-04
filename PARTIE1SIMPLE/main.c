#include <stdio.h>
#include "Colonnes.h"

int main(){
    COLONNE *mycol = creer_colonne("My column");
    inserer_valeur(mycol, 52);
    inserer_valeur(mycol, 44);
    inserer_valeur(mycol, 15);
    printf("%d",val_position(mycol,1));
}
