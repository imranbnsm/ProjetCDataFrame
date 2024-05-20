/* Projet CdataFrame, auteurs : Imrân Benessam et Antoine Gosse, ce fichier comporte les différentes fonctionnalités d
 * du CdataFrame où le CdataFrame est une liste doublement chaînée*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "CdataFrame.h"
#include "fonctions.h"
#include "list.h"
#define REALLOC_SIZE 256

/*
 * Fonction : vider_buffer
 * Rôle : Vider le buffer d'entrée.
 * Paramètres : Aucun.
 * Retour : Aucun.
 */
void vider_buffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

/*
 * Fonction : create_cdataframe
 * Rôle : Créer un nouveau dataframe avec des colonnes spécifiées.
 * Paramètres :
 *   - cdftype : Tableau des types des colonnes (ENUM_TYPE*).
 *   - size : Nombre de colonnes (int).
 * Retour : Pointeur vers le nouveau dataframe (CDATAFRAME*).
 */
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

/*
 * Fonction : delete_cdataframe
 * Rôle : Supprimer un dataframe et libérer la mémoire associée.
 * Paramètres :
 *   - cdf : Pointeur vers le dataframe à supprimer (CDATAFRAME*).
 * Retour : Aucun.
 */
void delete_cdataframe(CDATAFRAME *cdf){
    lst_delete_list(cdf);
}

/*
 * Fonction : delete_Column
 * Rôle : Supprimer une colonne d'un dataframe par son nom.
 * Paramètres :
 *   - cdf : Pointeur vers le dataframe (CDATAFRAME*).
 *   - col_name : Nom de la colonne à supprimer (const char*).
 * Retour : Aucun.
 */
void delete_Column(CDATAFRAME *cdf, const char *col_name){
    char *title=cdf->head->data->titre;
    LNODE*noeud=cdf->head;
    while (*title!=*col_name) {
        noeud=get_next_node(cdf,noeud);
        title=noeud->data->titre;
    }
    delete_column(&noeud->data);
}

/*
 * Fonction : get_cdataframe_cols_size
 * Rôle : Obtenir le nombre de colonnes dans un dataframe.
 * Paramètres :
 *   - cdf : Pointeur vers le dataframe (CDATAFRAME*).
 * Retour : Nombre de colonnes (int).
 */
int get_cdataframe_cols_size(CDATAFRAME *cdf){
    int size=0;
    LNODE*noeud= get_first_node(cdf);
    while (noeud!=NULL){
        size++;
        noeud= get_next_node(cdf,noeud);
    }
    return size;
}

/*
 * Fonction : remplissage_Cdata
 * Rôle : Remplir un dataframe avec des données.
 * Paramètres :
 *   - cdf : Pointeur vers le dataframe (CDATAFRAME*).
 * Retour : Aucun.
 */
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

/*
 * Fonction : remplissage_Cdata_dur
 * Rôle : Remplir un dataframe avec des données fixes (dur).
 * Paramètres : Aucun.
 * Retour : Pointeur vers le dataframe rempli (CDATAFRAME*).
 */
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

/*
 * Fonction : affichage_Cdata
 * Rôle : Afficher le contenu d'un dataframe.
 * Paramètres :
 *   - cdf : Pointeur vers le dataframe (CDATAFRAME*).
 * Retour : Aucun.
 */
void affichage_Cdata(CDATAFRAME *cdf){
    int size = get_cdataframe_cols_size(cdf);
    if (size==0){
        printf("Le Cdataframe est vide.");
    }else{
        LNODE *noeud = get_first_node(cdf);
        printf("\n");
        for (int i=0;i<size;i++){
            afficher_col(noeud->data);
            noeud = get_next_node(cdf,noeud);
            printf("\n");
        }
    }
}

/*
 * Fonction : affichage_partiel_lignes
 * Rôle : Afficher partiellement les lignes d'un dataframe.
 * Paramètres :
 *   - cdf : Pointeur vers le dataframe (CDATAFRAME*).
 * Retour : Aucun.
 */
void affichage_partiel_lignes(CDATAFRAME *cdf){
    int size = get_cdataframe_cols_size(cdf);
    int nb_lig = 0;
    char str[100];
    printf("Combien de lignes voulez-vous afficher (entre 1 et %d) :?\n",cdf->head->data->TL);
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

/*
 * Fonction : affichage_partiel_colonnes
 * Rôle : Afficher partiellement les colonnes d'un dataframe.
 * Paramètres :
 *   - cdf : Pointeur vers le dataframe (CDATAFRAME*).
 * Retour : Aucun.
 */
void affichage_partiel_colonnes(CDATAFRAME *cdf){
    int size = get_cdataframe_cols_size(cdf);
    int nb_col = 0;
    char str[100];
    printf("Combien de colonnes voulez-vous afficher (entre 1 et %d) :?\n", get_cdataframe_cols_size(cdf));
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

/*
 * Fonction : ajouter_ligne
 * Rôle : Ajouter une ligne à un dataframe.
 * Paramètres :
 *   - cdf : Pointeur vers le dataframe (CDATAFRAME*).
 * Retour : Aucun.
 */
void ajouter_ligne(CDATAFRAME*cdf){
    int size= get_cdataframe_cols_size(cdf);
    LNODE* noeud = get_first_node(cdf);
    for(int i = 0; i<size; i++){
        char type[100];
        switch(noeud->data->column_type) {
            case INT:
                strcpy(type,"entier");
                break;
            case CHAR:
                strcpy(type,"caractere");
                break;
            case UINT:
                strcpy(type,"entier positif");
                break;
            case FLOAT:
                strcpy(type,"nombre decimal");
                break;
            case DOUBLE:
                strcpy(type,"long nombre decimal");
                break;
            case STRING:
                strcpy(type,"chaine de caractere");
                break;
            default:
                break;
        }
        printf("Ajout de ligne dans la colonne '%s' de type %s\n",noeud->data->titre,type);
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

/*
 * Fonction : supprimer_ligne
 * Rôle : Supprimer une ligne d'un dataframe.
 * Paramètres :
 *   - cdf : Pointeur vers le dataframe (CDATAFRAME*).
 * Retour : Aucun.
 */
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

/*
 * Fonction : ajouter_colonne
 * Rôle : Ajouter une colonne à un dataframe.
 * Paramètres :
 *   - cdf : Pointeur vers le dataframe (CDATAFRAME*).
 *   - list_type : Type de la colonne à ajouter (ENUM_TYPE*).
 * Retour : Aucun.
 */
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
                insert_value(c ,&val1);
                break;}
            case CHAR:
            {char val2;
                printf("Saisir la valeur %d :\n",j+1);
                scanf(" %c",&val2);
                insert_value(c,&val2);
                break;}
            case UINT:
            {unsigned int val3=0;
                printf("Saisir la valeur %d :\n",j+1);
                scanf(" %u",&val3);
                insert_value(c,&val3);
                break;}
            case FLOAT:
            {float val4=0;
                printf("Saisir la valeur %d :\n",j+1);
                scanf(" %f",&val4);
                insert_value(c,&val4);
                break;}
            case DOUBLE:
            {double val5=0;
                printf("Saisir la valeur %d :\n",j+1);
                scanf(" %lf",&val5);
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

/*
 * Fonction : renommer_colonne
 * Rôle : Renommer une colonne d'un dataframe.
 * Paramètres :
 *   - cdf : Pointeur vers le dataframe (CDATAFRAME*).
 * Retour : Aucun.
 */
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

/*
 * Fonction : recherche_valeur
 * Rôle : Rechercher une valeur dans un dataframe.
 * Paramètres :
 *   - cdf : Pointeur vers le dataframe (CDATAFRAME*).
 *   - valeur : Pointeur vers la valeur à rechercher (void*).
 * Retour : Aucun.
 */
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

/*
 * Fonction : acces_remplacer_valeur
 * Rôle : Accéder et remplacer une valeur dans un dataframe.
 * Paramètres :
 *   - cdf : Pointeur vers le dataframe (CDATAFRAME*).
 *   - n_lig : Numéro de la ligne (int).
 *   - n_col : Numéro de la colonne (int).
 *   - value : nouvelle valeur (tous types).
 * Retour : Aucun.
 */
void acces_remplacer_valeur(CDATAFRAME *cdf, int n_lig, int n_col, void* value) {
    LNODE *noeud = get_first_node(cdf);
    for (int i=0;i<=n_col;i++){
        noeud= get_next_node(cdf,noeud);
    }
    COLUMN* col=noeud->data;
    switch (col->column_type) {
        case INT:
            col->data[n_lig] = malloc(sizeof(int));
            *((int *) col->data[n_lig]) = *((int *) value);
            break;
        case CHAR:
            col->data[n_lig] = malloc(sizeof(char));
            *((char *) col->data[n_lig]) = *((char *) value);
            break;
        case UINT:
            col->data[n_lig] = malloc(sizeof(unsigned int));
            *((unsigned int *) col->data[n_lig]) = *((unsigned int *) value);
            break;
        case FLOAT:
            col->data[n_lig] = malloc(sizeof(float));
            *((float *) col->data[n_lig]) = *((float *) value);
            break;
        case DOUBLE:
            col->data[n_lig] = malloc(sizeof(double));
            *((double *) col->data[n_lig]) = *((double *) value);
            break;
        case STRING:
            col->data[n_lig] = malloc(strlen((char *)value) + 1); // Allouer de la mémoire pour la chaîne de caractères + '\0'
            strcpy((char *)col->data[n_lig], (char *)value);
            break;
        case STRUCTURE:
            // Gestion des structures non implémentée
            break;
    }
}


/*
 * Fonction : afficher_noms_colonnes
 * Rôle : Afficher les noms des colonnes d'un dataframe.
 * Paramètres :
 *   - cdf : Pointeur vers le dataframe (CDATAFRAME*).
 * Retour : Aucun.
 */
void afficher_noms_colonnes(CDATAFRAME *cdf){
    int size= get_cdataframe_cols_size(cdf);
    LNODE* noeud = get_first_node(cdf);
    for(int i = 0; i<size; i++){
        printf("%s",noeud->data->titre);
    }
}

/*
 * Fonction : afficher_nb_lignes
 * Rôle : Afficher le nombre de lignes d'un dataframe.
 * Paramètres :
 *   - cdf : Pointeur vers le dataframe (CDATAFRAME*).
 * Retour : Aucun.
 */
void afficher_nb_lignes(CDATAFRAME* cdf){
    LNODE* noeud= get_first_node(cdf);
    if (noeud==NULL){
        printf("Le Cdataframe est vide.\n");
    }else {
        printf("Il y a %d lignes dans le Cdataframe.\n",noeud->data->TL);
    }
}

/*
 * Fonction : afficher_nb_col
 * Rôle : Afficher le nombre de colonnes d'un dataframe.
 * Paramètres :
 *   - cdf : Pointeur vers le dataframe (CDATAFRAME*).
 * Retour : Aucun.
 */
void afficher_nb_col(CDATAFRAME* cdf){
    int size= get_cdataframe_cols_size(cdf);
    if (size==0){
        printf("Le Cdataframe est vide.\n");
    }else {
        printf("Il y a %d colonnes dans le Cdataframe.\n",size);
    }
}

/*
 * Fonction : nb_cellule_egale
 * Rôle : Compter le nombre de cellules égales à une valeur donnée dans un dataframe.
 * Paramètres :
 *   - cdf : Pointeur vers le dataframe (CDATAFRAME*).
 *   - value : Pointeur vers la valeur à rechercher (void*).
 * Retour : Aucun.
 */
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

/*
 * Fonction : nb_cellule_sup
 * Rôle : Compter le nombre de cellules supérieures à une valeur donnée dans un dataframe.
 * Paramètres :
 *   - cdf : Pointeur vers le dataframe (CDATAFRAME*).
 *   - value : Pointeur vers la valeur de comparaison (void*).
 * Retour : Aucun.
 */
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

/*
 * Fonction : nb_cellule_inf
 * Rôle : Compter le nombre de cellules inférieures à une valeur donnée dans un dataframe.
 * Paramètres :
 *   - cdf : Pointeur vers le dataframe (CDATAFRAME*).
 *   - value : Pointeur vers la valeur de comparaison (void*).
 * Retour : Aucun.
 */
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

