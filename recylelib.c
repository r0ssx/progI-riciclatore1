//
//  recylelib.c
//  riciclatore
//
//  Created by Rosa Pia Esposito on 14/01/24.
//

#include "recylelib.h"

void add_product(recycler *recyler, float *budget){
    product to_add;
    printf("Inserisci il nome del prodotto: ");
    scanf("%s", to_add.product_name);
    printf("Inserisci la categoria del prodotto: ");
    printf("glass = 0, paper = 1, plastic = 2, waste = 3, organic = 4\n");
    scanf("%d", &to_add.code);
    printf("Inserisci il prezzo del prodotto: ");
    scanf("%f", &to_add.price);
    product2recycler(recyler, to_add, budget);
}

void product2recycler(recycler *recycler, product product, float *budget){
    //si controlla se c'è budget a sufficienza per inserire il prodotto
    //se non c'è budget, non si inserisce e si ritorna immediatamente
    if(product.price > *budget - recycler->total_price){
        return;
    }
    //si legge la categoria alla quale appartiene il prodotto
    category code = product.code;
    //si ottiene l'indice dei prodotti di categoria "code" già inseriti
    //l'indice mi tiene traccia della prima casella libera
    int index = recycler->indexes[code];
    //se sono stati inseriti 20 prodotti, non si inserisce e si ritorna
    if(index > 19){
        return;
    }
    //si inserisce il prodotto nel riciclatore copiando i campi della struct
    recycler->data[code][index].code = code;
    recycler->data[code][index].price = product.price;
    strcpy(recycler->data[code][index].product_name, product.product_name);
    //si incrementa l'indice della categoria di prodotto inserita
    recycler->indexes[code]++;
    //si aggiorna il prezzo totale dei prodotti da riciclare
    recycler->total_price += product.price;
}

void print_products(recycler recycler) {
    for (int code = GLASS; code <= ORGANIC; code++) {
        int added = recycler.indexes[code];
        for (int index = 0; index < added; index++) {
            printf("Nome: %s\n", recycler.data[code][index].product_name);
            switch (recycler.data[code][index].code) {
                case GLASS:
                    printf("Categoria: VETRO\n");
                    break;
                case PAPER:
                    printf("Categoria: CARTA\n");
                    break;
                case ORGANIC:
                    printf("Categoria: UMIDO\n");
                    break;
                case WASTE:
                    printf("Categoria: SECCO NON RICICLABILE\n");
                    break;
                case PLASTIC:
                    printf("Categoria: PLASTICA\n");
                    break;
                default:
                    printf("Categoria: SCONOSCIUTA\n");
                    break;
            }
            printf("Prezzo: %f\n", recycler.data[code][index].price);
        }
    }
}

void day_end(recycler *recycler, float *budget){
    //si chiede la password
    char password[40];
    do {
        printf("Inserisci la password: ");
        scanf("%s", password);
    } while(strcmp(PASSWORD, password) != 0);
    //si stampano i prodotti riciclati
    print_products(*recycler);
    //si spende parte del budget attuale per riciclare i prodotti
    *budget-=recycler->total_price;
    //si svuota il riciclatore
    recycler_reset(recycler);
    //si aggiunge denaro al budget
    printf("Quanto vuoi aggiungere al budget (ora è %f)? ", *budget);
    float budgetadd = 0;
    scanf("%f", &budgetadd);
    *budget += budgetadd;
}

//il riciclatore viene svuotato
void recycler_reset(recycler * recycler){
    recycler->total_price = 0;
    recycler->indexes[GLASS] = recycler->indexes[PAPER] = recycler->indexes[PLASTIC] = recycler->indexes[WASTE] = recycler->indexes[ORGANIC] = 0;
}
           
