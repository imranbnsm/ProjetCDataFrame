#include "Colonnes.h"

int main(){
    COLONNE** a = creer_CDataframe();
    remplissage_Cdata(a);
    nombre_cellules_egales_x(a,1,5);

    return 0;
}
