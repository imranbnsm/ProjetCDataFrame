#include <stdio.h>
#include <stdlib.h>
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

int inserer_valeur(COLONNE* col, int valeur){
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

    if(col->Donnees[col->TL-1]==valeur){
        return 1;
    }else{
        return 0;
    }
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
    printf("Combien de colonnes ?");
    scanf("%d",&n);
    if (n>5) {
        realloc(Cdata, n * sizeof(int*));
    }
    for (int i=0;i<n;i++){
        char titre;
        int nb_valeurs;
        COLONNE * p=NULL;
        printf("Nom de la colonne %d :",i+1);
        scanf("%c",&titre);
        printf("Nombre de valeurs dans cette colonne :");
        scanf("%d",&nb_valeurs);
        p=creer_colonne(titre);
        Cdata[i]=p;
        for (int j=0;j<nb_valeurs;j++) {
            int val;
            printf("Valeur %d", i + 1);
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
    p->Donnees[5]={1,2,3,4,5};
    p=creer_colonne("Col2");
    Cdata[1]=p;
    p->TL=5;
    p->Donnees[5]={6,7,8,9,10};
    p=creer_colonne("Col3");
    Cdata[2]=p;
    p->TL=5;
    p->Donnees[5]={11,12,13,14,15};
    p=creer_colonne("Col4");
    Cdata[3]=p;
    p->TL=5;
    p->Donnees[5]={16,17,18,19,20};
    p=creer_colonne("Col5");
    Cdata[4]=p;
    p->TL=5;
    p->Donnees[5]={21,22,23,24,25};
}

