/*
* Merah Mohamed Lamine
* 12213408
* TP4
*/
#include <stdio.h>
#include <stdlib.h>
#include "liste.h"
#include "item.h"

int tab_maj_bis(int n, item t[]) {
    if (n == 1) {
        return 0;
    }
    if(n==0){
        return -1;
    }

    int mid = n  / 2 ;
    int i1 = tab_maj_bis(mid  , t);
    int i2 = tab_maj_bis(n - mid, t + mid);

    if (i1 == -1 && i2 == -1) {
        return -1;
    } else if (i1 == -1) {
        i1 = i2;
    } else if (i2 == -1) {
        i2 = i1;
    }

    int count1 = 1, count2 = 1;
    for (int i = 0; i <= n; i++) {
        if (t[i] == t[i1]) {
            count1++;
        } else if (t[i] == t[i2]) {
            count2++;
        }
    }
    if (count1 > n / 2) {
        return i1;
    } else if (count2 > n / 2) {
        return i2;
    } else {
        return -1;
    }
}

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