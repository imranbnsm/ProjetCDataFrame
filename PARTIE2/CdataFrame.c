#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "CdataFrame.h"
#include "fonctions.h"
#include "list.h"
#define REALLOC_SIZE 256

CDATAFRAME *create_cdataframe(ENUM_TYPE *cdftype, int size){
    CDATAFRAME *Cdata=lst_create_list();
    for (int i=0;i<size;i++){
        char title[100];
        printf("Saisir le titre de la colonne %d:\n",i+1);
        scanf(" %s",title);
        int l;
        printf("Quel type de colonne %d: ?\n",i+1);
        scanf(" %d",&l);
        COLUMN *col= creer_colonne(cdftype[l],title);
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
        for (int j=0;j<nb_valeurs;j++) {
            switch (noeud->data->column_type) {
                case INT:
                {int val1=0;
                    printf("Saisir la valeur %d :\n",j+1);
                    scanf(" %d",&val1);
                    insert_value(noeud->data,&val1);
                    break;}
                case CHAR:
                {char val2;
                    printf("Saisir la valeur %d :\n",j+1);
                    scanf(" %c",&val2);
                    insert_value(noeud->data,&val2);
                    break;}
                case UINT:
                {unsigned int val3=0;
                    printf("Saisir la valeur %d :\n",j+1);
                    scanf(" %u",&val3);
                    insert_value(noeud->data,&val3);
                    break;}
                case FLOAT:
                {float val4=0;
                    printf("Saisir la valeur %d :\n",j+1);
                    scanf(" %f",&val4);
                    insert_value(noeud->data,&val4);
                    break;}
                case DOUBLE:
                {double val5=0;
                    printf("Saisir la valeur %d :\n",j+1);
                    scanf(" %lf",&val5);
                    insert_value(noeud->data,&val5);
                    break;}
                case STRING:
                {char val6[100];
                    printf("Saisir la valeur %d :\n",j+1);
                    scanf(" %s",val6);
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

void remplissage_Cdata_dur(CDATAFRAME *cdf){
    LNODE *noeud= get_first_node(cdf);
    int size= get_cdataframe_cols_size(cdf);
    if(size<3){
        LNODE*nouv_noeud= lst_create_lnode(NULL);
        lst_insert_tail(cdf,nouv_noeud);
    }
    noeud->data=creer_colonne(INT,"Col1");
    noeud->data->TL=5;
    noeud->data->data= malloc(5*sizeof(int));
    for (int i=0;i<5;i++){
        void *p=&i;
        insert_value(noeud->data, p);
    }
    noeud->data=creer_colonne(CHAR,"Col2");
    noeud->data->TL=5;
    noeud->data->data= malloc(5*sizeof(char));
    char str='a';
    void *p= & str;
    insert_value(noeud->data, p);
    str='b';
    void *p1 = &str;
    insert_value(noeud->data, p1);
    str='c';
    void *p2 = &str;
    insert_value(noeud->data, p2);
    str='d';
    void *p3 = &str;
    insert_value(noeud->data, p3);
    str='e';
    void *p4 = &str;
    insert_value(noeud->data, p4);
    noeud->data=creer_colonne(INT,"Col3");
    noeud->data->TL=5;
    noeud->data->data= malloc(5*sizeof(float));
    for (int i=0;i<5;i++){
        float k=0,j=k+0.1;
        k++;
        void *p5=&j;
        insert_value(noeud->data, p5);
    }
}

void affichage_Cdata(CDATAFRAME *cdf){
    int size = get_cdataframe_cols_size(cdf);
    if (size==0){
        printf("Le Cdataframe est vide.");
    }else{
        LNODE *noeud= get_first_node(cdf);
        for (int i=0;i<size;i++){
            afficher_col(noeud->data);
            noeud= get_next_node(cdf,noeud);
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
                insert_value(noeud->data,&val1);
                break;}
            case CHAR:
            {char val2;
                printf("Saisir la valeur :\n");
                scanf(" %c",&val2);
                insert_value(noeud->data,&val2);
                break;}
            case UINT:
            {unsigned int val3=0;
                printf("Saisir la valeur :\n");
                scanf(" %u",&val3);
                insert_value(noeud->data,&val3);
                break;}
            case FLOAT:
            {float val4=0;
                printf("Saisir la valeur :\n");
                scanf(" %f",&val4);
                insert_value(noeud->data,&val4);
                break;}
            case DOUBLE:
            {double val5=0;
                printf("Saisir la valeur :\n");
                scanf(" %lf",&val5);
                insert_value(noeud->data,&val5);
                break;}
            case STRING:
            {char val6[100];
                printf("Saisir la valeur :\n");
                scanf(" %s",val6);
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


void ajouter_colonne(CDATAFRAME *cdf, enum enum_type TYPE){
    char titre[100];
    LNODE* noeud = get_last_node(cdf);
    printf("Quel nom voulez-vous donner à votre colonne: ?\n");
    scanf("%s",titre);
    COLUMN*c = creer_colonne(TYPE,titre);
    noeud->next = c;
}


void renommer_colonne(CDATAFRAME *cdf){
    char titre[100];
    char titre2[100];
    printf("Quel est le nom de la colonne à modifier: ?\n");
    scanf("%s",titre);
    printf("Quel nouveau nom voulez-vous donner à votre colonne: ?\n");
    scanf("%s",titre2);
    char *title=cdf->head->data->titre;
    LNODE* noeud = cdf->head;
    while (*title!=*titre) {
        noeud=get_next_node(cdf,noeud);
        title=noeud->data->titre;
    }
    noeud->data->titre = titre2;
}
void afficher_noms_colonnes(CDATAFRAME *cdf){
    int size= get_cdataframe_cols_size(cdf);
    LNODE* noeud = get_first_node(cdf);
    for(int i = 0; i<size; i++){
        printf("%s",noeud->data->titre);
    }
}
