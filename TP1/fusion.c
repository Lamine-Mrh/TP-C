#include<stdio.h>
#include<stdlib.h>

int aux[2024]; /* tableau auxiliaire, variable globale */

/** Fonction qui fusionne les segments tab[g...m] et tab[m+1...d] dans tab[g...d] */
/* en utilisant le tableau auxiliaire aux */
/* N.B. 1. Les segments tab[g...m] et tab[m+1...d] sont supposés triés */
/** Si le segment tab[g..d] est de taille n, le nombre de comparaisons de valeurs est n */
void fusion (int * tab, int g, int m, int d) {
	int i, j, k;
	for (i = m + 1; i > g; i--)
		aux[i - 1] = tab[i - 1];
	for (j = m; j < d; j++)
		aux[d + m - j] = tab[j + 1];
	/* on a recopie en renversant l'ordre des cles */
	for (k = g; k <= d; k++)
		if (aux[i] < aux[j])
			tab[k] = aux[i++]; /* ce qui revient a : {tab[k] = aux[i]; i++;} */
		else
			tab[k] = aux[j--]; /* ce qui revient a : {tab[k] = aux[j]; j--;} */
}

/** Fonction qui trie le segment tab[g...d] dans l'ordre croissant des valeurs */
/** On définit C_fus(n) := nombre maximal de comparaisons de valeurs effectuées */
/* quand on appelle tri_fusion sur un segment de tableau de taille n */
/* { C_fus(n) = C_fus(\lceiling n/2 \rceiling) + C_rap(\lfloor n/2 \rfloor) + n */
/* { C_fus(1) = 0 */
/* C_fus(n) = n\log_2 n si n est une puissance de 2 */
/* C_fus(n) ≤ n\lceiling \log_2 n \rceiling dans le cas général */
void tri_fusion (int * tab, int g, int d) {
	int m = (g + d)/2;
	if (d <= g)
		return;
	tri_fusion (tab, g, m);
	tri_fusion (tab, m + 1, d);
	fusion (tab, g, m, d);
}
/* Appel initial : tri_fusion(tab, 0, n-1) pour un tableau de taille n */
int main(int argc, char const *argv[])
{
    printf("hi");
    return 0;
}
