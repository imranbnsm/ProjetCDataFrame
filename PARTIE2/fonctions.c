#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "fonctions.h"
#define REALOC_SIZE 256

COLUMN *creer_colonne(ENUM_TYPE type, char* titre) {
    COLUMN *colonne = (COLUMN *) malloc(sizeof(COLUMN));

    if(colonne == NULL){
        return NULL;
    }

    colonne->titre = strdup(titre);
    colonne->TP = 0;
    colonne->TL = 0;
    colonne->column_type = type;
    colonne->data = NULL;
    colonne->index = NULL;

    return colonne;
}


int insert_value(COLUMN *col, void *value) {

    if (col->TL == col->TP) {
        col->TP += REALOC_SIZE;
        col->data = realloc(col->data, col->TP * sizeof(col->column_type));
        col->index = realloc(col->index, col->TP * sizeof(unsigned long long int));
    }
    switch (col->column_type) {
        case INT:
            col->data[col->TL] = malloc(sizeof(int));
            *((int *) col->data[col->TL]) = *((int *) value);
            break;
        case CHAR:
            *((char *) col->data[col->TL]) = *((char *) value);
            break;
        case UINT:
            *((unsigned int *) col->data[col->TL]) = *((unsigned int *) value);
            break;
        case FLOAT:
            *((float *) col->data[col->TL]) = *((float *) value);
            break;
        case DOUBLE:
            *((double *) col->data[col->TL]) = *((double *) value);
            break;
        case STRING:
            *((char **) col->data[col->TL]) = *((char **) value);
            break;
        case STRUCTURE:
            //col->data[col->TL] = (struct *) malloc (sizeof(struct));
            //*((struct*)col->data[col->TL])= *((struct*)value);
            break;
    }
    col->TL++;
    if (col->data[col->TL] == value) {
        return 1;
    } else {
        return 0;
    }
}


void delete_column(COLUMN **col){
    free((*col)->data);
    free((*col));
}


void convert_value(COLUMN *col, unsigned long long int i, char *str, int size) {
    if (i >= col->TL) {
        printf("Index hors limites.\n");
        return;
    }

    switch(col->column_type) {
        case INT:
            snprintf(str, size, "%d", *((int*)col->data[i]));
            break;
        case CHAR:
            snprintf(str, size, "%c", *((char*)col->data[i]));
            break;
        case UINT:
            snprintf(str, size, "%u", *((unsigned int*)col->data[i]));
            break;
        case FLOAT:
            snprintf(str, size, "%.2f", *((float*)col->data[i]));
            break;
        case DOUBLE:
            snprintf(str, size, "%.2lf", *((double*)col->data[i]));
            break;
        case STRING:
            snprintf(str, size, "%s", (char*)col->data[i]);
            break;
        default:
            printf("Type de colonne non géré.\n");
            break;
    }
}





