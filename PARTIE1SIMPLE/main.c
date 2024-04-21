#include "Colonnes.h"

int main(){
    COLONNE** Cd = creer_CDataframe();
    int C_TL;
    C_TL=remplissage_dur(Cd);
    affichage_entier(Cd,C_TL);
    nombre_cellules_egales_x(Cd,1,5);
    ajouter_ligne(Cd,C_TL);
    affichage_entier(Cd,C_TL);
    return 0;
}
