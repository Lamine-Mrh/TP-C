#include <stdio.h> /* pour printf, scanf */
#include <stdlib.h> /* pour EXIT_SUCCESS */
                    /* rand, srand, RAND_MAX */
#include <time.h> /* pour time */

#define N 100

typedef int item;

void echanger_item (item *, item *);
void trier_par_insertion (item *, int);
void initialiser_alea_tab (item *, int);
void afficher_tab_vingt (item *, int);
int saisir_entier (int, int);

int main () {
  item tab[N];
  int taille = saisir_entier(0, N);

  /* germe pour le générateur pseudo-aléatoire */
  srand (time (NULL));
  /* initialisation des valeurs du tableau à des entiers dans l'intervalle [0,99], */
  initialiser_alea_tab (tab, taille);
  /* affichage du tableau avant le tri */
  printf("Tableau (seulement 20 premières valeurs si taille > 20): \n");
  afficher_tab_vingt (tab, taille);
  /* appel du tri */
  trier_par_insertion (tab, taille);
  /* affichage du tableau après le tri */
  printf ("Tableau après tri (seulement 20 premières valeurs si taille > 20): \n");
  afficher_tab_vingt (tab, taille);

  return EXIT_SUCCESS;
}

/** Fonction qui trie selon l'ordre croissant un tableau t d'items, */
/* dont l'adresse est reçue comme comme premier paramètre d'entrée */
/* et dont la taille est reçue comme deuxième paramètre d'entrée */
/** Dans le cas le plus défavorable, le nombre total de comparaisons de valeurs est : */
/* 1 + 2 + ... + (taille-2) + (taille-1) = taille(taille-1)/2 */
/** Dans le cas le plus favorable, le nombre total de comparaisons de valeurs est : */
/* 1 + 1 + ... + 1 + 1 (taille-1 termes) = taille-1 */
void trier_par_insertion (item *t, int taille) {
  int i, j;
  /* après l'itération i de la boucle suivante, */
  /* les valeurs occupant les cases d'indice 0 à i sont rangées dans l'ordre croissant */
  for (i = 1; i < taille; ++i) {
    j = i;
    while (j > 0 && t[j] < t[j-1]) {
      echanger_item (t + j, t + j - 1);
      --j;
    }
  }
}

/** Fonction qui échange les valeurs de deux items */
/* dont les adresses sont reçues comme premier et deuxième paramètres d'entrée */
void echanger_item (item *x, item *y) {
  item tmp = *x;
  *x = *y;
  *y = tmp;
}

/** Fonction qui initialise de façon pseudo-aléatoire un tableau t */
/* dont la taille est reçue comme 2e paramètre d'entrée */
void initialiser_alea_tab (item *t, int taille) {
  int i;
  for (i = 0; i < taille; ++i) { t[i] = rand()%100; }
}

/** Fonction qui affiche les vingt premières valeurs d'un tableau t */
/* dont la taille est reçue comme 2e paramètre d'entrée */
void afficher_tab_vingt (item *t, int taille) {
  int i;
  taille = taille > 20 ? 20 : taille;
  for (i = 0; i < taille; ++i) { printf("%5d", t[i]); }
  printf("\n");
}

/** Fonction qui saisit et renvoie un entier compris entre vmin et vmax */
int saisir_entier (int vmin, int vmax) {
  int res, n;
  char c;
  do {
    printf("Tapez une valeur entière comprise entre %d et %d : ", vmin, vmax);
    n = scanf("%d", &res);
    if (1 == n && res >= 0 && res <= vmax)
      return res;
    if (0 == n) {
			do { scanf("%c", &c); }
			while (c != ' ' && c != '\t' && c != '\n');
		}
    printf("Erreur ! Recommencez !");
  }
  while (1);
}
