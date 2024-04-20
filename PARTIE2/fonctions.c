#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "fonctions.h"
#define REALOC_SIZE 256

COLUMN * creer_colonne(ENUM_TYPE type, char* titre) {
    COLUMN *colonne = (COLUMN *) malloc(sizeof(COLUMN));
    colonne->titre = titre;
    colonne->TP = 256;
    colonne->TL = 0;
    colonne->column_type = type;
    colonne->data = NULL;
    colonne->index = NULL;
    return colonne;
}
int insert_value(COLUMN *col, void *value){
    if(col->TL==col->TP){
        col->TP+=REALOC_SIZE;
    }
    switch(col->column_type){
        case INT:
            col->data[col->TL] = (int*) malloc (sizeof(int));
            *((int*)col->data[col->TL])= *((int*)value);
            break;
        case CHAR:
            col->data[col->TL] = (char*) malloc (sizeof(char));
            *((char*)col->data[col->TL])= *((char*)value);
            break;
        case UINT:
            col->data[col->TL] = (unsigned int*) malloc (sizeof(unsigned int));
            *((unsigned int*)col->data[col->TL])= *((unsigned int*)value);
            break;
        case FLOAT:
            col->data[col->TL] = (float*) malloc (sizeof(float));
            *((float*)col->data[col->TL])= *((float *)value);
            break;
        case DOUBLE:
            col->data[col->TL] = (double *) malloc (sizeof(double));
            *((double*)col->data[col->TL])= *((double*)value);
            break;
        case STRING:
            col->data[col->TL] = (char**) malloc (sizeof(char*));
            *((char**)col->data[col->TL])= *((char**)value);
            break;
        //case STRUCTURE:
            //col->data[col->TL] = (struct *) malloc (sizeof(struct));
            //*((struct*)col->data[col->TL])= *((struct*)value);
            //break;
    }
    col->TL++;
    // !!! ne pas oublier d'effectuer le test pour savoir si l'insertion est réussi ou pas
}

void delete_column(COLUMN **col){
    free((*col)->data);
    free((*col));
}





