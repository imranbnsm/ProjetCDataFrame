#ifndef PROJETC_COLONNES_H
#define PROJETC_COLONNES_H

enum enum_type
{
    NULLVAL = 1 , UINT, INT, CHAR, FLOAT, DOUBLE, STRING, STRUCTURE
};
typedef enum enum_type ENUM_TYPE;


union column_type{
    unsigned int uint_value;
    signed int int_value;
    char char_value;
    float float_value;
    double double_value;
    char* string_value;
    void* struct_value;
};
typedef union column_type COL_TYPE ;


struct column {
    char *titre;
    unsigned int TL;
    unsigned int TP;
    ENUM_TYPE column_type;
    COL_TYPE **data; // array of pointers to stored data
    unsigned long long int *index; // array of integers
};
typedef struct column COLUMN;

COLUMN * creer_colonne(ENUM_TYPE type, char* titre);
int insert_value(COLUMN *col, void *value);
void delete_column(COLUMN **col);
void convert_value(COLUMN *col, unsigned long long int i, char *str, int size);
void afficher_col(COLUMN*col);

#endif // PROJETC_COLONNES_H