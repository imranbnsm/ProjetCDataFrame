#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Colonnes.h"

#define REALOC_SIZE 256


COLONNE* creer_colonne(char* titre){
    COLONNE* colonne = (COLONNE*)malloc(sizeof(COLONNE));
    colonne->Titre = titre;
    colonne->TP = 256;
    colonne->TL=0;
    colonne->Donnees = NULL;
    return colonne;
}

void inserer_valeur(COLONNE* col, int valeur){
    if(col->Donnees == NULL){
        col->Donnees = (int*)malloc(col->TP * sizeof(int));
        col->Donnees[col->TL]=valeur;
        (col->TL)++;
    }

    else if(col->TP == col->TL){
        col->TP += REALOC_SIZE;
        col->Donnees = (int*)realloc(col->Donnees,col->TP);
        col->Donnees[col->TL]=valeur;
        (col->TL)++;
    }else{
        col->Donnees[col->TL]=valeur;
        (col->TL)++;
    }

//if(col->Donnees[col->TL-1]==valeur){
    // return 1;
    // }else{
    //  return 0;
    //}
}

void supprimer_colonne(COLONNE **col){
    free((*col)->Donnees);
    free((*col));
}

void print_col(COLONNE* col){
    int i = 0;
    for(i;i<col->TL;i++){
        printf("[%d] %d\n",i,col->Donnees[i]);
    }
    printf("\n");
}

void print_col_lig(COLONNE* col, int nb_lignes){
    int i,j = 0;
    for( i ; i<nb_lignes; i++){
        if(col->TL < nb_lignes){
            for(j; j<col->TL; j++){
                printf("[%d] %d\n", j, col->Donnees[j]);
            }
            printf("[%d] NULL\n",j);
            break;
        }else{
            printf("[%d] %d\n", i, col->Donnees[i]);
        }
    }
    printf("\n");
}

int occurences(COLONNE* col, int val){
    int occ = 0;
    int i = 0;
    for(i; i<col->TL;i++){
        if(col->Donnees[i]==val){
            occ++;
        }
    }
    return occ;
}

int val_position(COLONNE* col, int pos){
    int val = 0;
    int i = 0;
    for(i; i<col->TL;i++){
        if(i==pos){
            val = col->Donnees[i];
            break;
        }
    }
    return val;
}

int nb_val_sup(COLONNE* col, int val){
    int occ=0;
    for (int i=0;i<col->TL;i++){
        if (col->Donnees[i]>val){
            occ++;
        }
    }
    return occ;
}

int nb_val_inf(COLONNE* col, int val){
    int occ=0;
    for (int i=0;i<col->TL;i++){
        if (val>col->Donnees[i]){
            occ++;
        }
    }
    return occ;
}

int nb_val_egal(COLONNE* col, int val){
    int occ=0;
    for (int i=0;i<col->TL;i++){
        if (col->Donnees[i]==val){
            occ++;
        }
    }
    return occ;
}

COLONNE ** creer_CDataframe() {
    COLONNE ** Cdata = malloc(5 * sizeof(COLONNE*));
    return Cdata;
}

void remplissage_Cdata(COLONNE ** Cdata){
    int n;
    printf("Combien de colonnes ? :\n");
    scanf("%d",&n);
    if (n>5) {
        Cdata = realloc(Cdata, n * sizeof(COLONNE*));
    }
    for (int i=0;i<n;i++){
        char titre[100];
        int nb_valeurs;

        printf("Nom de la colonne %d :\n",i+1);
        scanf("%s",titre);

        printf("Nombre de valeurs dans cette colonne :\n");
        scanf("%d",&nb_valeurs);

        COLONNE*p = creer_colonne(&titre);
        Cdata[i]=p;

        for (int j=0;j<nb_valeurs;j++) {
            int val;
            printf("Valeur %d :\n", j + 1);
            scanf("%d", &val);
            inserer_valeur(p, val);
        }
    }
}

void remplissage_dur(COLONNE** Cdata){
    COLONNE* p=NULL;
    p=creer_colonne("Col1");
    Cdata[0]=p;
    p->TL=5;
    memcpy(p->Donnees, (int[]){1, 2, 3, 4, 5}, 5 * sizeof(int));
    p=creer_colonne("Col2");
    Cdata[1]=p;
    p->TL=5;
    memcpy(p->Donnees, (int[]){6, 7, 8, 9, 10}, 5 * sizeof(int));
    p=creer_colonne("Col3");
    Cdata[2]=p;
    p->TL=5;
    memcpy(p->Donnees, (int[]){11,12,13,14,15}, 5 * sizeof(int));
    p=creer_colonne("Col4");
    Cdata[3]=p;
    p->TL=5;
    memcpy(p->Donnees, (int[]){16, 17, 18, 19, 20}, 5 * sizeof(int));
    p=creer_colonne("Col5");
    Cdata[4]=p;
    p->TL=5;
    memcpy(p->Donnees, (int[]){21, 22, 23, 24, 25}, 5 * sizeof(int));;
}



void affichage_entier(COLONNE** Cdata, int nb_lignes) {
    for (int i = 0; i<nb_lignes; i++){
        printf("Colonne %d : \n",i+1);
        print_col(Cdata[i]);
    }
}

void affichage_partiel_col(COLONNE** Cdata) {

    printf("Combien de colonnes voulez-vous afficher : ?\n");
    int nb_col = 0;
    scanf("%d",&nb_col);

    for (int i = 0; i<nb_col; i++){
        printf("Colonne %d : \n",i+1);
        print_col(Cdata[i]);
    }
}

void affichage_partiel_lig(COLONNE** Cdata, int taille) {

    printf("Combien de lignes voulez-vous afficher : ?\n");
    int nb_lignes = 0;
    scanf("%d",&nb_lignes);
    int j = 1;
    for(int i=0 ; i<taille; i++){
        printf("Colonne %d ligne %d : \n",i+1,j);
        print_col_lig(Cdata[i],nb_lignes);
        j++;
    }
}

void supprimer_ligne(COLONNE** Cdata, int taille){
    for(int i =0; i<taille; i++) {
        Cdata[i]->Donnees[Cdata[i]->TL] = (int) NULL;
        Cdata[i]->TL -= 1;
    }
}

void ajouter_colonne(COLONNE** Cdata, int taille){
    Cdata = realloc(Cdata, (taille + 1) * sizeof(COLONNE *));
    taille+=1;
    char titre[100];
    printf("Quel nom souhaitez-vous attribuer à votre nouvelle colonne : ?\n");
    scanf("%s",titre);
    Cdata[taille]= creer_colonne(titre);
}

void supprimer_colonne_Cdataframe(COLONNE** Cdata, int taille){
    supprimer_colonne(Cdata[taille]);
    taille-=1;
    Cdata = realloc(Cdata,taille * sizeof (COLONNE*));
}

void renommer_colonne(COLONNE** Cdata, int taille){
    int num = 0;
    char titre[100];
    printf("Quelle colonne voulez vous renommer: ?\n");
    scanf("%d",&num);
    printf("Quel nom voulez vous donner à votre nouvelle colonne: ?\n");
    scanf("%s",titre);
    Cdata[num]->Titre = titre;
}

void recherche_valeur(COLONNE** Cdata, int taille, int valeur){
    printf("\n");
    int presence = -1;
    for(int i = 0; i < taille; i++){
        int occ = occurences(Cdata[i],valeur);
        if (occ > 0){
            presence = 1;
            break;
        }
    }
    if(presence == -1){
        printf("La valeur est absente du CDataframe.");
    }else{
        printf("La valeur est presente dans le CDataframe.");
    }
}

int acces_valeur(COLONNE** Cdata, int taille, int indice_col, int indice_lig){
    return Cdata[indice_col]->Donnees[indice_lig];
}

void noms_colonnes(COLONNE** Cdata, int taille){
    for (int i = 0; i < taille; i++)
        printf("%s", Cdata[i]->Titre);
}

void nombre_lignes(COLONNE** Cdata, int taille){
    int nb = 0;
    int temp = 0;
    for (int i =0; i<taille; i++){
        for(int j=0; j<Cdata[i]->TL; j++){
            temp+=1;
        }
        if(temp>=nb){
            nb=temp;
        }
        temp=0;
    }
    printf("Il y a %d lignes dans la plus grande colonne de votre CDataFrame.",nb);
}

void nombre_colonnes(COLONNE** Cdata, int taille){
    int nb = 0;
    for (int i =0; i<taille; i++){
            nb+=1;
        }
    printf("Il y a %d colonnes dans votre CDataFrame.",nb);
}

void nombre_cellules_egales_x(COLONNE** Cdata,int taille, int x){
    int nb = 0;
    for (int i =0; i<taille; i++){
        nb += nb_val_egal(Cdata[i],x);
    }
    printf("Il y a %d cellules contentant une valeur égale à %d.",nb,x);
}

void nombre_cellules_sup_x(COLONNE** Cdata,int taille, int x){
    int nb = 0;
    for (int i =0; i<taille; i++){
        nb += nb_val_sup(Cdata[i],x);
    }
    printf("Il y a %d cellules contentant une valeur supérieure à %d.",nb,x);
}

void nombre_cellules_inf_x(COLONNE** Cdata,int taille, int x){
    int nb = 0;
    for (int i =0; i<taille; i++){
        nb += nb_val_inf(Cdata[i],x);
    }
    printf("Il y a %d cellules contentant une valeur inférieure à %d.",nb,x);
}













//Problème à régler
// void ajouter_ligne(COLONNE** Cdata, int taille){
//int val=0;
//for(int i=0; i<taille; i++){
//    printf("Quelle valeur voulez vous ajouter : ?\n");
//   scanf("%d",&val);
//    inserer_valeur(Cdata[i],val);
// }
//}









