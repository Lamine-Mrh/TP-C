#include <stdio.h>
#include <stdlib.h>
#include "liste.h"
#include "item.h"


struct maillon *maj_list_bis (struct liste *l){
    struct maillon* courrant = l->premier;
    struct maillon* next = courrant->suivant;
    int occ=1;
    if (courrant == NULL){
        return NULL;
    }
    if (next == NULL)
    {
        return courrant;
    }
    if (l->longueur == 0)
    {
        return NULL;
    }
    if (l->longueur == 1)
    {
        return courrant;
    }
    struct liste* l1 = nouvelle_liste();
    struct liste* l2 = nouvelle_liste();
    for (int i = 0; i < l->longueur; i++)
    {
        struct maillon* m = extraire_maillon_debut_liste(l);
        if (i % 2 == 0)
        {
            ajouter_maillon_fin_liste(l1,m);
        } else {
            ajouter_maillon_fin_liste(l2,m);
        }
    }
    struct maillon* m1 = maj_list_bis(l1);
    struct maillon* m2 = maj_list_bis(l2);

    if (m1 != NULL) {
    return m1;
    } else if (m2 != NULL){
        return m2;
    } else return NULL; 
 }

 