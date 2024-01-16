//
//  main.c
//  riciclatore
//
//  Created by Rosa Pia Esposito on 11/01/24.
//

#include <stdio.h>
#include <stdlib.h>
#include "recylelib.h"

int main(void) {
    recycler recycler;
    recycler_reset(&recycler);
    float budget = 0;
    printf("Inserire il budget iniziale: ");
    scanf("%f", &budget);
    printf("Il budget è %f\n", budget);
    int choice;
    while (1){
        printf("cosa vuoi fare?\n");
        printf("1. Inserisci un prodotto\n2. Fine giornata\n3. Esci dal programma\n");
        scanf("%d", &choice);
        switch (choice){
            case 1 :
                add_product(&recycler, &budget);
                break;
            case 2 :
                day_end(&recycler, &budget);
                break;
            case 3 : 
                printf("grazie per aver usato il riciclatore!!\n");
                return 0;
                break;
            default : 
                fprintf(stderr, "Inserisci un valore valido\n");
                break;
        }
    }
    
    
    return 0;
}
