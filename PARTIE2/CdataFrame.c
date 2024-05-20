/* Projet CdataFrame, auteurs : Imrân Benessam et Antoine Gosse, ce fichier comporte les différentes fonctionnalités d
 * du CdataFrame où le CdataFrame est une liste doublement chaînée*/
#include <stdio.h>
#include <stdlib.h>
#include "CdataFrame.h"
#include "fonctions.h"
#include "list.h"
#define REALLOC_SIZE 256

void vider_buffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

CDATAFRAME *create_cdataframe(ENUM_TYPE *cdftype, int size){
    CDATAFRAME *Cdata=lst_create_list();
    for (int i=0;i<size;i++){
        char title[100];
        int indice_type,valid=0;
        vider_buffer();
        printf("Saisir le titre de la colonne %d:\n",i+1);
        fgets(title,100,stdin);
        while (valid!=1) {
            printf("Quel type de colonne %d: ?\n 0 : pas de type\n 1 : entier positif\n 2 : entier\n 3 : caractere\n 4 : nombre decimal\n 5 : long nombre decimal\n 6 : chaine de caractere\n",
                   i + 1);
            int result = scanf(" %d", &indice_type);
            if (result == 1 && indice_type >= 0 && indice_type <= 6) {
                valid = 1;
            } else {
                printf("Entree invalide. Veuillez reessayer.\n");
                vider_buffer();
            }
        }
        COLUMN *col= creer_colonne(cdftype[indice_type],title);
        LNODE *noeud= lst_create_lnode(col);
        if (i==0){
            lst_insert_head(Cdata,noeud);
        }else{
            lst_insert_after(Cdata,noeud, get_last_node(Cdata));
        }
    }
    return Cdata;
}

void delete_cdataframe(CDATAFRAME *cdf){
    lst_delete_list(cdf);
}

void delete_Column(CDATAFRAME *cdf, const char *col_name){
    char *title=cdf->head->data->titre;
    LNODE*noeud=cdf->head;
    while (*title!=*col_name) {
        noeud=get_next_node(cdf,noeud);
        title=noeud->data->titre;
    }
    delete_column(&noeud->data);
}

int get_cdataframe_cols_size(CDATAFRAME *cdf){
    int size=0;
    LNODE*noeud= get_first_node(cdf);
    while (noeud!=NULL){
        size++;
        noeud= get_next_node(cdf,noeud);
    }
    return size;
}

void remplissage_Cdata(CDATAFRAME *cdf){
    int size = get_cdataframe_cols_size(cdf);
    LNODE*noeud= get_first_node(cdf);
    for (int i=0;i<size;i++){
        int nb_valeurs;
        printf("Nombre de valeurs dans la colonne %d :\n",i+1);
        scanf(" %d",&nb_valeurs);
        vider_buffer();
        for (int j=0;j<nb_valeurs;j++) {
            switch (noeud->data->column_type) {
                case INT:
                {int val1=0;
                    printf("Saisir la valeur %d :\n",j+1);
                    scanf(" %d",&val1);
                    //vider_buffer();
                    insert_value(noeud->data,&val1);
                    break;}
                case CHAR:
                {char val2;
                    printf("Saisir la valeur %d :\n",j+1);
                    scanf(" %c",&val2);
                    vider_buffer();
                    insert_value(noeud->data,&val2);
                    break;}
                case UINT:
                {unsigned int val3=0;
                    printf("Saisir la valeur %d :\n",j+1);
                    scanf(" %u",&val3);
                    vider_buffer();
                    insert_value(noeud->data,&val3);
                    break;}
                case FLOAT:
                {float val4=0;
                    printf("Saisir la valeur %d :\n",j+1);
                    scanf(" %f",&val4);
                    vider_buffer();
                    insert_value(noeud->data,&val4);
                    break;}
                case DOUBLE:
                {double val5=0;
                    printf("Saisir la valeur %d :\n",j+1);
                    scanf(" %lf",&val5);
                    vider_buffer();
                    insert_value(noeud->data,&val5);
                    break;}
                case STRING:
                {char val6[100];
                    printf("Saisir la valeur %d :\n",j+1);
                    fgets(val6,100,stdin);
                    insert_value(noeud->data,val6);
                    break;}
                /*case STRUCTURE:
                    //col->data[col->TL] = (struct *) malloc (sizeof(struct));
                    //*((struct*)col->data[col->TL])= *((struct*)value);
                    break;*/
                case NULLVAL:
                    break;
            }
        }
        noeud=get_next_node(cdf,noeud);
    }
}

CDATAFRAME* remplissage_Cdata_dur(){
    CDATAFRAME* cdf = lst_create_list();
    COLUMN* col = creer_colonne(INT,"Col1");
    col->data=malloc(5*sizeof(int));
    for (int i=0;i<5;i++){
        insert_value(col, &i);
    }
    LNODE* noeud= lst_create_lnode(col);
    lst_insert_head(cdf,noeud);
    col= creer_colonne(CHAR,"Col2");
    col->data= malloc(5*sizeof(char));
    char str='a';
    insert_value(col, &str);
    str='b';
    insert_value(col, &str);
    str='c';
    insert_value(col, &str);
    str='d';
    insert_value(col, &str);
    str='e';
    insert_value(col, &str);
    LNODE* noeud1 = lst_create_lnode(col);
    lst_insert_after(cdf,noeud1,noeud);
    return cdf;
}

void affichage_Cdata(CDATAFRAME *cdf){
    int size = get_cdataframe_cols_size(cdf);
    if (size==0){
        printf("Le Cdataframe est vide.");
    }else{
        LNODE *noeud= get_first_node(cdf);
        for (int i=0;i<size;i++){
            afficher_col(noeud->data);
            noeud = get_next_node(cdf,noeud);
        }
    }
}

void affichage_partiel_lignes(CDATAFRAME *cdf){
    int size = get_cdataframe_cols_size(cdf);
    int nb_lig = 0;
    char str[100];
    printf("Combien de lignes voulez-vous afficher :?\n");
    scanf("%d",&nb_lig);
    if(size == 0){
        printf("Le Cdataframe est vide.");
    }else{
        LNODE*noeud = get_first_node(cdf);
        for (int i = 0; i<size;i++){
            printf("%s\n",noeud->data->titre);
            for(int j = 0; j<nb_lig; j++){
                convert_value(noeud->data, j,str, 100);
                printf("[%d] %s\n",j,str);
            }
            noeud= get_next_node(cdf,noeud);
        }
    }
}

void affichage_partiel_colonnes(CDATAFRAME *cdf){
    int size = get_cdataframe_cols_size(cdf);
    int nb_col = 0;
    char str[100];
    printf("Combien de colonnes voulez-vous afficher :?\n");
    scanf("%d",&nb_col);
    if(size == 0){
        printf("Le Cdataframe est vide.");
    }else{
        LNODE*noeud = get_first_node(cdf);
        for (int i = 0; i<size;i++){
            printf("%s\n",noeud->data->titre);
            afficher_col(noeud->data);
            noeud = get_next_node(cdf,noeud);
        }
    }
}


void ajouter_ligne(CDATAFRAME*cdf){
    int size= get_cdataframe_cols_size(cdf);
    LNODE* noeud = get_first_node(cdf);
    for(int i = 0; i<size; i++){
        printf("Ajout de ligne dans la colonne '%s'\n",noeud->data->titre);
        switch (noeud->data->column_type) {
            case INT:
            {int val1=0;
                printf("Saisir la valeur :\n");
                scanf(" %d",&val1);
                vider_buffer();
                insert_value(noeud->data,&val1);
                break;}
            case CHAR:
            {char val2;
                printf("Saisir la valeur :\n");
                scanf(" %c",&val2);
                vider_buffer();
                insert_value(noeud->data,&val2);
                break;}
            case UINT:
            {unsigned int val3=0;
                printf("Saisir la valeur :\n");
                scanf(" %u",&val3);
                vider_buffer();
                insert_value(noeud->data,&val3);
                break;}
            case FLOAT:
            {float val4=0;
                printf("Saisir la valeur :\n");
                scanf(" %f",&val4);
                vider_buffer();
                insert_value(noeud->data,&val4);
                break;}
            case DOUBLE:
            {double val5=0;
                printf("Saisir la valeur :\n");
                scanf(" %lf",&val5);
                vider_buffer();
                insert_value(noeud->data,&val5);
                break;}
            case STRING:
            {char val6[100];
                printf("Saisir la valeur :\n");
                fgets(val6,100,stdin);
                insert_value(noeud->data,val6);
                break;}
                /*case STRUCTURE:
                    //col->data[col->TL] = (struct *) malloc (sizeof(struct));
                    //*((struct*)col->data[col->TL])= *((struct*)value);
                    break;*/
            case NULLVAL:
                break;
        }
        noeud = get_next_node(cdf,noeud);
    }
}

void supprimer_ligne(CDATAFRAME *cdf){
    int ligne = 0;
    printf("Quelle ligne voulez vous supprimer: ?\n");
    scanf("%d",&ligne);
    int size= get_cdataframe_cols_size(cdf);
    LNODE* noeud = get_first_node(cdf);
    for(int i = 0; i<size; i++){
        free(noeud->data->data[ligne]);
            }
    }


void ajouter_colonne(CDATAFRAME *cdf, ENUM_TYPE* list_type){
    char titre[100];
    int indice_type, valid=0;
    LNODE* tail = get_last_node(cdf);
    printf("Quel nom voulez-vous donner a votre colonne: ?\n");
    fgets(titre,100,stdin);
    while (valid!=1) {
        printf("Quel type de colonne : ?\n 0 : pas de type\n 1 : entier positif\n 2 : entier\n 3 : caractere\n 4 : nombre decimal\n 5 : long nombre decimal\n 6 : chaine de caractere\n");
        int result = scanf(" %d", &indice_type);
        if (result == 1 && indice_type >= 0 && indice_type <= 6) {
            valid = 1;
        } else {
            printf("Entree invalide. Veuillez reessayer.\n");
            vider_buffer();
        }
    }
    COLUMN* c = creer_colonne(list_type[indice_type],titre);
    int nb_valeur=tail->data->TL;
    for (int j=0;j<nb_valeur;j++) {
        switch (c->column_type) {
            case INT:
            {int val1=0;
                printf("Saisir la valeur %d :\n",j+1);
                scanf(" %d",&val1);
                vider_buffer();
                insert_value(c ,&val1);
                break;}
            case CHAR:
            {char val2;
                printf("Saisir la valeur %d :\n",j+1);
                scanf(" %c",&val2);
                vider_buffer();
                insert_value(c,&val2);
                break;}
            case UINT:
            {unsigned int val3=0;
                printf("Saisir la valeur %d :\n",j+1);
                scanf(" %u",&val3);
                vider_buffer();
                insert_value(c,&val3);
                break;}
            case FLOAT:
            {float val4=0;
                printf("Saisir la valeur %d :\n",j+1);
                scanf(" %f",&val4);
                vider_buffer();
                insert_value(c,&val4);
                break;}
            case DOUBLE:
            {double val5=0;
                printf("Saisir la valeur %d :\n",j+1);
                scanf(" %lf",&val5);
                vider_buffer();
                insert_value(c,&val5);
                break;}
            case STRING:
            {char val6[100];
                printf("Saisir la valeur %d :\n",j+1);
                fgets(val6,100,stdin);
                insert_value(c,val6);
                break;}
                /*case STRUCTURE:
                    //col->data[col->TL] = (struct *) malloc (sizeof(struct));
                    //*((struct*)col->data[col->TL])= *((struct*)value);
                    break;*/
            case NULLVAL:
                break;
        }
    }
    LNODE* noeud= lst_create_lnode(c);
    lst_insert_after(cdf,noeud,tail);
}


void renommer_colonne(CDATAFRAME *cdf){
    char titre[100];
    char titre2[100];
    printf("Quel est le nom de la colonne a modifier: ?\n");
    scanf("%s",titre);
    printf("Quel nouveau nom voulez-vous donner a votre colonne: ?\n");
    scanf("%s",titre2);
    char *title=cdf->head->data->titre;
    LNODE* noeud = cdf->head;
    while (*title!=*titre) {
        noeud=get_next_node(cdf,noeud);
        title=noeud->data->titre;
    }
    noeud->data->titre = titre2;
}

void recherche_valeur(CDATAFRAME * cdf,void* value){
    int presence = -1, size= get_cdataframe_cols_size(cdf);
    LNODE* noeud= get_first_node(cdf);
    for(int i = 0; i < size; i++){
        int occ = nb_occurences(noeud->data,value);
        if (occ > 0){
            presence = 1;
            break;
        }
    }
    if(presence == -1){
        printf("La valeur est absente du CDataframe.\n");
    }else{
        printf("La valeur est presente dans le CDataframe.\n");
    }
}

void afficher_noms_colonnes(CDATAFRAME *cdf){
    int size= get_cdataframe_cols_size(cdf);
    LNODE* noeud = get_first_node(cdf);
    for(int i = 0; i<size; i++){
        printf("%s",noeud->data->titre);
    }
}

void afficher_nb_lignes(CDATAFRAME* cdf){
    LNODE* noeud= get_first_node(cdf);
    if (noeud==NULL){
        printf("Le Cdataframe est vide.\n");
    }else {
        printf("Il y a %d lignes dans le Cdataframe.\n",noeud->data->TL);
    }
}

void afficher_nb_col(CDATAFRAME* cdf){
    int size= get_cdataframe_cols_size(cdf);
    if (size==0){
        printf("Le Cdataframe est vide.\n");
    }else {
        printf("Il y a %d colonnes dans le Cdataframe.\n",size);
    }
}

void nb_cellule_egale(CDATAFRAME* cdf, void* value){
    int size= get_cdataframe_cols_size(cdf),occ=0;
    LNODE* noeud= get_first_node(cdf);
    for (int i=0;i<size;i++){
        occ+=val_egale(noeud->data,value,0);
        noeud= get_next_node(cdf,noeud);
    }
    if (occ == 0) {
        printf("Il n'y a pas de valeurs egales dans le Cdataframe.\n");
    } else {
        printf("Au total, il y a %d valeur(s) egale(s) dans le Cdataframe.\n", occ);
    }
}

void nb_cellule_sup(CDATAFRAME* cdf, void* value){
    int size= get_cdataframe_cols_size(cdf),occ=0;
    LNODE* noeud= get_first_node(cdf);
    for (int i=0;i<size;i++){
        occ+=val_sup(noeud->data,value,0);
        noeud= get_next_node(cdf,noeud);
    }
    if (occ == 0) {
        printf("Il n'y a pas de valeurs superieurs dans le Cdataframe.\n");
    } else {
        printf("Au total, il y a %d valeur(s) superieur(s) dans le Cdataframe.\n", occ);
    }
}

void nb_cellule_inf(CDATAFRAME* cdf, void* value){
    int size= get_cdataframe_cols_size(cdf),occ=0;
    LNODE* noeud= get_first_node(cdf);
    for (int i=0;i<size;i++){
        occ+=val_inf(noeud->data,value,0);
        noeud= get_next_node(cdf,noeud);
    }
    if (occ == 0) {
        printf("Il n'y a pas de valeurs inferieures dans le Cdataframe.\n");
    } else {
        printf("Au total, il y a %d valeur(s) inferieur(s) dans le Cdataframe.\n", occ);
    }
}

