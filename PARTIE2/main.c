/* Projet CdataFrame, auteurs : Imrân Benessam et Antoine Gosse, ce fichier rassemble l'ensemble des fonctionnalités
 * créées et est le fichier principal du projet.*/
#include <stdio.h>
#include <string.h>
#include "fonctions.h"
#include "list.h"
#include "CdataFrame.h"



int main() {
    int boucle=1,boucle2=1;
    while(boucle==1){
        int choix, valid = 0, size;
        ENUM_TYPE list_type[]={(ENUM_TYPE ) NULLVAL, (ENUM_TYPE ) UINT, (ENUM_TYPE ) INT, (ENUM_TYPE ) CHAR, (ENUM_TYPE ) FLOAT, (ENUM_TYPE ) DOUBLE, (ENUM_TYPE ) STRING, (ENUM_TYPE ) STRUCTURE};
        char c;
        CDATAFRAME* cdata=NULL;
        while (valid!=1) {
            printf("Bonjour, voulez-vous :\n 1 : creer un CdataFrame et le remplir \n 2 : creer un CdataFrame deja rempli prealablement\n 3 : Quitter\n");
            int result = scanf(" %d", &choix);
            if (result == 1 && choix >= 1 && choix <= 3) {
                valid = 1;
            } else {
                printf("Entree invalide. Veuillez reessayer.\n");
                c=getchar();
            }
        }
        valid=0;
        if (choix==1){
            while (valid!=1) {
                printf("Combien de colonnes ?\n");
                int result = scanf(" %d", &size);
                if (result == 1) {
                    valid = 1;
                } else {
                    printf("Entree invalide. Veuillez reessayer.\n");
                    c=getchar();
                }
            }
            valid=0;
            cdata = creer_cdataframe(list_type, size);
            remplissage_Cdata(cdata);
        } else if(choix==2){
            cdata = remplissage_Cdata_dur();
        }else{
            boucle=0;
            break;
        }
        vider_buffer();
        boucle2=1;
        while(boucle2==1){
            int choix2;
            while (valid!=1) {
                printf("Maintenant, voulez-vous :\n 1 : Modifier le CdataFrame\n 2 : Afficher le CdataFrame\n 3 : Avoir des informations sur le CdataFrame\n 4 : Retour\n");
                int result = scanf(" %d", &choix2);
                if (result == 1 && choix2 >= 1 && choix2 <= 4) {
                    valid = 1;
                } else {
                    printf("Entree invalide. Veuillez reessayer.\n");
                    c=getchar();
                }
            }
            valid=0;
            if (choix2==1){
                int choix3;
                while (valid!=1) {
                    printf("Voulez-vous :\n 1 : Supprimer le CdataFrame\n 2 : Supprimer une colonne\n 3 : Supprimer une ligne\n 4 : Ajouter une colonne\n 5 : Ajouter une ligne\n 6 : Renommer une colonne\n 7 : Retour\n");
                    int result = scanf(" %d", &choix3);
                    if (result == 1 && choix3 >= 1 && choix3 <= 7) {
                        valid = 1;
                    } else {
                        printf("Entree invalide. Veuillez reessayer.\n");
                        c=getchar();
                    }
                }
                valid=0;
                if (choix3==1){
                    supprimer_cdataframe(cdata);
                    break;
                } else if(choix3==2){
                    char titre[100];
                    LNODE *noeud=cdata->head;
                    for (int i=0;i<avoir_cdataframe_nb_col(cdata);i++){
                        printf("[%d] %s\n",i,noeud->data->titre);
                        noeud = get_next_node(cdata,noeud);
                    }
                    vider_buffer();
                    printf("Quelle colonne voulez-vous supprimer (donnez le titre): ?\n");
                    fgets(titre,100,stdin);
                    size_t len = strcspn(titre, "\n");
                    if (titre[len] == '\n') {
                        titre[len] = '\0';
                    }
                    supprimer_Colonne(cdata,titre);
                }else if (choix3==3){
                    supprimer_ligne(cdata);
                }else if (choix3==4){
                    ajouter_colonne(cdata,list_type);
                }else if (choix3==5){
                    ajouter_ligne(cdata);
                }else if (choix3==6){
                    renommer_colonne(cdata);
                }else{
                    continue;
                }
            } else if (choix2==2) {
                int choix4;
                while (valid != 1) {
                    printf("Voulez-vous :\n 1 : Afficher le CdataFrame\n 2 : Afficher un nombre precis de lignes\n 3 : Afficher un nombre precis de colonnes\n 4 : Retour\n");
                    int result = scanf(" %d", &choix4);
                    if (result == 1 && choix4 >= 1 && choix4 <= 4) {
                        valid = 1;
                    } else {
                        printf("Entree invalide. Veuillez reessayer.\n");
                        c = getchar();
                    }
                }
                valid = 0;
                if (choix4==1){
                    affichage_Cdata(cdata);
                    printf("\n");
                }else if (choix4==2){
                    affichage_partiel_lignes(cdata);
                    printf("\n");
                }else if (choix4==3){
                    affichage_partiel_colonnes(cdata);
                    printf("\n");
                }else{
                    continue;
                }
            } else if(choix2==3){
                int choix5;
                while (valid != 1) {
                    printf("Voulez_vous :\n 1 : Remplacer une valeur\n 2 : Savoir le nombre de lignes\n 3 : Savoir le nombre de colonnes\n 4 : Afficher le noms des colonnes\n 5 : Savoir si une valeur est presente dans le CdataFrame\n 6 : Savoir combien de fois une valeur est presente dans le CdataFrame\n 7 : Savoir combien de valeurs sont inferieures a une valeur dans le CdataFrame\n 8 : Savoir combien de valeurs sont superieures a une valeur dans le CdataFrame\n 9 : Retour\n");
                    int result = scanf(" %d", &choix5);
                    if (result == 1 && choix >= 1 && choix5 <= 9) {
                        valid = 1;
                    } else {
                        printf("Entree invalide. Veuillez reessayer.\n");
                        c = getchar();
                    }
                }
                valid = 0;
                if (choix5 == 1) {
                    int num_lig,num_col;
                    affichage_Cdata(cdata);
                    printf("Dans quelle colonne voulez-vous remplacer une valeur (entre 1 et %d) : ?\n",avoir_cdataframe_nb_col(cdata));
                    scanf("%d",&num_col);
                    LNODE *noeud=cdata->head;
                    for(int i=0;i<num_col-1;i++){
                        noeud = get_next_node(cdata,noeud);
                    }
                    afficher_col(noeud->data);
                    printf("Quelle est la ligne de la valeur que vous cherchez a remplacer (entre 0 et %d) : ?\n",noeud->data->TL-1);
                    scanf(" %d",&num_lig);
                    switch (noeud->data->column_type) {
                        case INT: {
                            int val1 = 0;
                            printf("Saisir la nouvelle valeur :\n");
                            scanf(" %d", &val1);
                            vider_buffer();
                            acces_remplacer_valeur(cdata,num_lig,num_col-1,&val1);
                            break;
                        }
                        case CHAR: {
                            char val2;
                            printf("Saisir la nouvelle valeur :\n");
                            scanf(" %c", &val2);
                            vider_buffer();
                            acces_remplacer_valeur(cdata,num_lig,num_col-1,&val2);
                            break;
                        }
                        case UINT: {
                            unsigned int val3 = 0;
                            printf("Saisir la nouvelle valeur :\n");
                            scanf(" %u", &val3);
                            vider_buffer();
                            acces_remplacer_valeur(cdata,num_lig,num_col-1,&val3);
                            break;
                        }
                        case FLOAT: {
                            float val4 = 0;
                            printf("Saisir la nouvelle valeur :\n");
                            scanf(" %f", &val4);
                            vider_buffer();
                            acces_remplacer_valeur(cdata,num_lig,num_col-1,&val4);
                            break;
                        }
                        case DOUBLE: {
                            double val5 = 0;
                            printf("Saisir la nouvelle valeur :\n");
                            scanf(" %lf", &val5);
                            vider_buffer();
                            acces_remplacer_valeur(cdata,num_lig,num_col-1,&val5);
                            break;
                        }
                        case STRING: {
                            char val6[100];
                            printf("Saisir la nouvelle valeur :\n");
                            fgets(val6, 100, stdin);
                            size_t len = strcspn(val6, "\n");
                            if (val6[len] == '\n') {
                                val6[len] = '\0';
                            }
                            acces_remplacer_valeur(cdata,num_lig,num_col-1,val6);
                            break;
                        }
                            /*case STRUCTURE:
                                //col->data[col->TL] = (struct *) malloc (sizeof(struct));
                                //*((struct*)col->data[col->TL])= *((struct*)value);
                                break;*/
                        case NULLVAL:
                            break;
                    }
                }else if (choix5==2){
                    afficher_nb_lignes(cdata);
                }else if (choix5==3) {
                    afficher_nb_col(cdata);
                }else if (choix5==4) {
                    afficher_noms_colonnes(cdata);
                }else if (choix5==5){
                    int indice_type, valid=0;
                    while (valid!=1) {
                        printf("Quel type de valeur : ?\n 0 : pas de type\n 1 : entier positif\n 2 : entier\n 3 : caractere\n 4 : nombre decimal\n 5 : long nombre decimal\n 6 : chaine de caractere\n");
                        int result = scanf(" %d", &indice_type);
                        if (result == 1 && indice_type >= 0 && indice_type <= 6) {
                            valid = 1;
                        } else {
                            printf("Entree invalide. Veuillez reessayer.\n");
                            vider_buffer();
                        }
                    }
                    switch (list_type[indice_type]) {
                        case INT: {
                            int val1 = 0;
                            printf("Saisir la valeur :\n");
                            scanf(" %d", &val1);
                            vider_buffer();
                            recherche_valeur(cdata,&val1);
                            break;
                        }
                        case CHAR: {
                            char val2;
                            printf("Saisir la valeur :\n");
                            scanf(" %c", &val2);
                            vider_buffer();
                            recherche_valeur(cdata,&val2);
                            break;
                        }
                        case UINT: {
                            unsigned int val3 = 0;
                            printf("Saisir la valeur :\n");
                            scanf(" %u", &val3);
                            vider_buffer();
                            recherche_valeur(cdata,&val3);
                            break;
                        }
                        case FLOAT: {
                            float val4 = 0;
                            printf("Saisir la valeur :\n");
                            scanf(" %f", &val4);
                            vider_buffer();
                            recherche_valeur(cdata,&val4);
                            break;
                        }
                        case DOUBLE: {
                            double val5 = 0;
                            printf("Saisir la valeur :\n");
                            scanf(" %lf", &val5);
                            vider_buffer();
                            recherche_valeur(cdata,&val5);
                            break;
                        }
                        case STRING: {
                            char val6[100];
                            printf("Saisir la valeur :\n");
                            fgets(val6, 100, stdin);
                            size_t len = strcspn(val6, "\n");
                            if (val6[len] == '\n') {
                                val6[len] = '\0';
                            }
                            recherche_valeur(cdata,val6);
                            break;
                        }
                            /*case STRUCTURE:
                                //col->data[col->TL] = (struct *) malloc (sizeof(struct));
                                //*((struct*)col->data[col->TL])= *((struct*)value);
                                break;*/
                        case NULLVAL:
                            break;
                    }
                }else if (choix5==6){
                    int indice_type, valid=0;
                    while (valid!=1) {
                        printf("Quel type de valeur : ?\n 0 : pas de type\n 1 : entier positif\n 2 : entier\n 3 : caractere\n 4 : nombre decimal\n 5 : long nombre decimal\n 6 : chaine de caractere\n");
                        int result = scanf(" %d", &indice_type);
                        if (result == 1 && indice_type >= 0 && indice_type <= 6) {
                            valid = 1;
                        } else {
                            printf("Entree invalide. Veuillez reessayer.\n");
                            vider_buffer();
                        }
                    }
                    switch (list_type[indice_type]) {
                        case INT: {
                            int val1 = 0;
                            printf("Saisir la valeur :\n");
                            scanf(" %d", &val1);
                            vider_buffer();
                            nb_cellule_egale(cdata,&val1);
                            break;
                        }
                        case CHAR: {
                            char val2;
                            printf("Saisir la valeur :\n");
                            scanf(" %c", &val2);
                            vider_buffer();
                            nb_cellule_egale(cdata,&val2);
                            break;
                        }
                        case UINT: {
                            unsigned int val3 = 0;
                            printf("Saisir la valeur :\n");
                            scanf(" %u", &val3);
                            vider_buffer();
                            nb_cellule_egale(cdata,&val3);
                            break;
                        }
                        case FLOAT: {
                            float val4 = 0;
                            printf("Saisir la valeur :\n");
                            scanf(" %f", &val4);
                            vider_buffer();
                            nb_cellule_egale(cdata,&val4);
                            break;
                        }
                        case DOUBLE: {
                            double val5 = 0;
                            printf("Saisir la valeur :\n");
                            scanf(" %lf", &val5);
                            vider_buffer();
                            nb_cellule_egale(cdata,&val5);
                            break;
                        }
                        case STRING: {
                            char val6[100];
                            printf("Saisir la valeur :\n");
                            fgets(val6, 100, stdin);
                            size_t len = strcspn(val6, "\n");
                            if (val6[len] == '\n') {
                                val6[len] = '\0';
                            }
                            nb_cellule_egale(cdata,val6);
                            break;
                        }
                            /*case STRUCTURE:
                                //col->data[col->TL] = (struct *) malloc (sizeof(struct));
                                //*((struct*)col->data[col->TL])= *((struct*)value);
                                break;*/
                        case NULLVAL:
                            break;
                    }
                }else if (choix5==7){
                    int indice_type, valid=0;
                    while (valid!=1) {
                        printf("Quel type de valeur : ?\n 0 : pas de type\n 1 : entier positif\n 2 : entier\n 3 : caractere\n 4 : nombre decimal\n 5 : long nombre decimal\n 6 : chaine de caractere\n");
                        int result = scanf(" %d", &indice_type);
                        if (result == 1 && indice_type >= 0 && indice_type <= 6) {
                            valid = 1;
                        } else {
                            printf("Entree invalide. Veuillez reessayer.\n");
                            vider_buffer();
                        }
                    }
                    switch (list_type[indice_type]) {
                        case INT: {
                            int val1 = 0;
                            printf("Saisir la valeur :\n");
                            scanf(" %d", &val1);
                            vider_buffer();
                            nb_cellule_inf(cdata,&val1);
                            break;
                        }
                        case CHAR: {
                            char val2;
                            printf("Saisir la valeur :\n");
                            scanf(" %c", &val2);
                            vider_buffer();
                            nb_cellule_inf(cdata,&val2);
                            break;
                        }
                        case UINT: {
                            unsigned int val3 = 0;
                            printf("Saisir la valeur :\n");
                            scanf(" %u", &val3);
                            vider_buffer();
                            nb_cellule_inf(cdata,&val3);
                            break;
                        }
                        case FLOAT: {
                            float val4 = 0;
                            printf("Saisir la valeur :\n");
                            scanf(" %f", &val4);
                            vider_buffer();
                            nb_cellule_inf(cdata,&val4);
                            break;
                        }
                        case DOUBLE: {
                            double val5 = 0;
                            printf("Saisir la valeur :\n");
                            scanf(" %lf", &val5);
                            vider_buffer();
                            nb_cellule_inf(cdata,&val5);
                            break;
                        }
                        case STRING: {
                            char val6[100];
                            printf("Saisir la valeur :\n");
                            fgets(val6, 100, stdin);
                            size_t len = strcspn(val6, "\n");
                            if (val6[len] == '\n') {
                                val6[len] = '\0';
                            }
                            nb_cellule_inf(cdata,val6);
                            break;
                        }
                            /*case STRUCTURE:
                                //col->data[col->TL] = (struct *) malloc (sizeof(struct));
                                //*((struct*)col->data[col->TL])= *((struct*)value);
                                break;*/
                        case NULLVAL:
                            break;
                    }
                }else if (choix5==8){
                    int indice_type, valid = 0;
                    while (valid != 1) {
                        printf("Quel type de valeur : ?\n 0 : pas de type\n 1 : entier positif\n 2 : entier\n 3 : caractere\n 4 : nombre decimal\n 5 : long nombre decimal\n 6 : chaine de caractere\n");
                        int result = scanf(" %d", &indice_type);
                        if (result == 1 && indice_type >= 0 && indice_type <= 6) {
                            valid = 1;
                        } else {
                            printf("Entree invalide. Veuillez reessayer.\n");
                            vider_buffer();
                        }
                    }
                    switch (list_type[indice_type]) {
                        case INT: {
                            int val1 = 0;
                            printf("Saisir la valeur :\n");
                            scanf(" %d", &val1);
                            vider_buffer();
                            nb_cellule_sup(cdata, &val1);
                            break;
                        }
                        case CHAR: {
                            char val2;
                            printf("Saisir la valeur :\n");
                            scanf(" %c", &val2);
                            vider_buffer();
                            nb_cellule_sup(cdata, &val2);
                            break;
                        }
                        case UINT: {
                            unsigned int val3 = 0;
                            printf("Saisir la valeur :\n");
                            scanf(" %u", &val3);
                            vider_buffer();
                            nb_cellule_sup(cdata, &val3);
                            break;
                        }
                        case FLOAT: {
                            float val4 = 0;
                            printf("Saisir la valeur :\n");
                            scanf(" %f", &val4);
                            vider_buffer();
                            nb_cellule_sup(cdata, &val4);
                            break;
                        }
                        case DOUBLE: {
                            double val5 = 0;
                            printf("Saisir la valeur :\n");
                            scanf(" %lf", &val5);
                            vider_buffer();
                            nb_cellule_sup(cdata, &val5);
                            break;
                        }
                        case STRING: {
                            char val6[100];
                            printf("Saisir la valeur :\n");
                            fgets(val6, 100, stdin);
                            size_t len = strcspn(val6, "\n");
                            if (val6[len] == '\n') {
                                val6[len] = '\0';
                            }
                            nb_cellule_sup(cdata, val6);
                            break;
                        }
                            /*case STRUCTURE:
                                //col->data[col->TL] = (struct *) malloc (sizeof(struct));
                                //*((struct*)col->data[col->TL])= *((struct*)value);
                                break;*/
                        case NULLVAL:
                            break;
                    }
                }else{
                    continue;
                }
            }else{
                boucle2=0;
            }
        }
    }
    return 0;
}