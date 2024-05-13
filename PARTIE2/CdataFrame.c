#include <stdio.h>
#include <stdlib.h>
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
        printf("Quel type de colonne %d ?",i+1);
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
    while (noeud!=NULL && noeud->next!=NULL){
        noeud= get_next_node(cdf,noeud);
        size++;
    }
    return size;
}

void remplissage_Cdata(CDATAFRAME *cdf){
    int size = get_cdataframe_cols_size(cdf);
    LNODE*noeud= get_first_node(cdf);
    for (int i=0;i<size;i++){
        int nb_valeurs;
        printf("Nombre de valeurs dans cette colonne :\n");
        scanf(" %d",&nb_valeurs);
        for (int j=0;j<nb_valeurs;j++) {
            switch (noeud->data->column_type) {
                case INT:
                    int val1=0;
                    printf("Saisir la valeur %d :\n",i);
                    scanf(" %d",&val1);
                    insert_value(noeud->data,&val1);
                    break;
                case CHAR:
                    char val2;
                    printf("Saisir la valeur %d :\n",i);
                    scanf(" %c",&val2);
                    insert_value(noeud->data,&val2);
                    break;
                case UINT:
                    unsigned int val3=0;
                    printf("Saisir la valeur %d :\n",i);
                    scanf(" %u",&val3);
                    insert_value(noeud->data,&val3);
                    break;
                case FLOAT:
                    float val4=0;
                    printf("Saisir la valeur %d :\n",i);
                    scanf(" %f",&val4);
                    insert_value(noeud->data,&val4);
                    break;
                case DOUBLE:
                    double val5=0;
                    printf("Saisir la valeur %d :\n",i);
                    scanf(" %lf",&val5);
                    insert_value(noeud->data,&val5);
                    break;
                case STRING:
                    char val6[100];
                    printf("Saisir la valeur %d :\n",i);
                    scanf(" %s",&val6);
                    insert_value(noeud->data,&val6);
                    break;
                case STRUCTURE:
                    //col->data[col->TL] = (struct *) malloc (sizeof(struct));
                    //*((struct*)col->data[col->TL])= *((struct*)value);
                    break;
                case NULLVAL:
                    break;
            }
        }
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
    int size= get_cdataframe_cols_size(cdf);
    if (size==0){
        printf("Le Cdataframe est vide.");
    }else{
        LNODE *noeud= get_first_node(cdf);
        for (int i=1;i<size;i++){
            afficher_col(noeud->data);
            noeud= get_next_node(cdf,noeud);
        }
    }
}























/*void ajouter_ligne(CDATAFRAME*cdf){
    int size= get_cdataframe_cols_size(cdf);
    for(int i = 0; i<size; i++){
        printf("Quelle valeur voulez vous insérer : ?\n");
        scanf("")
        insert_value(cdf);
        cdf = get_next_node(cdf,get_first_node(cdf));
    }
}*/

