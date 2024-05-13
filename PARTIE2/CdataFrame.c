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
        COLUMN *col= creer_colonne(cdftype[i],title);
        LNODE *noeud= lst_create_lnode(col);
        if (i==0){
            lst_insert_head(Cdata,noeud);
        }
        else if(i==size-1){
            lst_insert_after(Cdata,noeud, get_first_node(Cdata));
        }else{
            lst_insert_tail(Cdata,noeud);
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
CDATAFRAME *creer_Cdata_vide(){
    int size;
    printf("Combien de colonnes ?\n");
    scanf("%d",&size);
    ENUM_TYPE *type[size],*list_type[]={(ENUM_TYPE *) NULLVAL, (ENUM_TYPE *) UINT, (ENUM_TYPE *) INT, (ENUM_TYPE *) CHAR, (ENUM_TYPE *) FLOAT, (ENUM_TYPE *) DOUBLE, (ENUM_TYPE *) STRING, (ENUM_TYPE *) STRUCTURE};
    for (int i=0;i<size;i++){
        int j;
        printf("Quel type pour la colonne  %d ?\n",i);
        scanf(" %d",&j);
        type[i]=list_type[j];
    }
    CDATAFRAME *cdata= create_cdataframe((ENUM_TYPE *) type, size);
    return cdata;
}
void remplissage_Cdata(CDATAFRAME *cdf){
    int size= get_cdataframe_cols_size(cdf);
    LNODE*noeud= get_first_node(cdf);
    for (int i=0;i<size;i++){
        int nb_valeurs;

        printf("Nombre de valeurs dans cette colonne :\n");
        scanf("%d",&nb_valeurs);

        for (int j=0;j<nb_valeurs;j++) {
            void *val = NULL;
            printf("Valeur %d :\n", j + 1);
            scanf(" %p", &val);
            insert_value(noeud->data, val);
        }
        noeud= get_next_node(cdf,noeud);
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

