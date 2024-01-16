//
//  recylelib.h
//  riciclatore
//
//  Created by Rosa Pia Esposito on 14/01/24.
//

#ifndef recylelib_h
#define recylelib_h
#include <stdio.h>
#include <string.h>

#define CATEGORIES 5
#define MAX_PRODUCTS 20
#define PASSWORD "ecosostenibile"

//categorie valide per i prodotti da riciclare
typedef enum {
    GLASS, PAPER, PLASTIC, WASTE, ORGANIC
} category;

//struct che identifica un prodotto
typedef struct {
    char product_name[40];
    category code;
    float price;
} product;

//struct che identifica il riciclatore
typedef struct {
    product data[CATEGORIES][MAX_PRODUCTS];
    int indexes[CATEGORIES];
    float total_price;
} recycler;

//funzione per aggiungere un prodotto
//recycler: struct che identifica il riciclatore
//budget: budget
void add_product(recycler *recycler, float *budget);

//funzione per aggiungere prodotto al riciclatore
//recycler: struct che identifica il riciclatore
//product: struct che identifica un prodotto
//budget: budget
void product2recycler(recycler *recycler, product product, float *budget);

//funzione per stampare tutti i prodotti inseriti nel riciclatore
//recycler: struct che identifica il riciclatore
void print_products(recycler recycler);

//funzione per la fine della giornata
//recycler: struct che identifica il riciclatore
//budget: budget
void day_end(recycler *recycler, float *budget);

//funzione per svuotare il riciclatore
//recycler: struct che identifica il riciclatore
void recycler_reset(recycler * recycler);


#endif /* recylelib_h */
