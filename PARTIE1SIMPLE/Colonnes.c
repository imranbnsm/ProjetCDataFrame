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
