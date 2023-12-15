#include<stdio.h>
#include<stdlib.h>

void swap (int *x, int *y) {
  int temp = *x;
  *x = *y;
  *y = temp;
}

/** Fonction qui partitionne le segment de tableau tab[g..d] */
/* en fonction de la valeur-pivot tab[n] */
/* et renvoie la position du pivot après partitionnement */
/** On définit C_part(n) := nombre maximal de comparaisons de valeurs effectuées */
/* quand on appelle partition sur un segment de tableau de taille n */
/* C_part(n) = n+1 */
int partition(int * tab, int g, int d) {
	int i = g-1, j = d; int pivot = tab[d];
	for (;;) {
		while (tab[++i] < pivot) ;
		while (pivot < tab[--j])
			if (j == g) break;
		if (i >= j) break;
		swap(&tab[i], &tab[j]);
	}
	swap(&tab[i], &tab[d]);
	return i;
}

/** Fonction qui trie le segment tab[g...d] dans l'ordre croissant des valeurs */
/** On définit C_rap(n) := nombre maximal de comparaisons de valeurs effectuées */
/* quand on appelle tri_rapide sur un segment de tableau de taille n */
/* { C_rap(n) = C_part(n) + C_rap(n-1) */
/* { C_rap(1) = 0 */
/* C_rap(n) = (n+2)(n+1)/2 - 3 (~ n^2/2) */
void tri_rapide(int * tab, int g, int d) {
	int i;
	if (d <= g) return;
	i = partition(tab, g, d);
	tri_rapide(tab, g, i-1);
	tri_rapide(tab, i+1, d);
}
/* Appel initial : tri_rapide(tab, 0, n-1) pour un tableau de taille n */
int main(int argc, char const *argv[])
{
    printf("hi");
    return 0;
}
