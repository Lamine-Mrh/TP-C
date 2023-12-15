#include <stdio.h> /* pour printf, scanf */
#include <stdlib.h> /* pour EXIT_SUCCESS */
                    /* rand, srand, RAND_MAX */
#include <time.h> /* pour time */

#define N 100

typedef int item;

void echanger_item (item *, item *);
int rechercher_pos_min (item *, int);
void trier_par_selection (item *, int);
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
  trier_par_selection (tab, taille);
  /* affichage du tableau après le tri */
  printf ("Tableau après tri (seulement 20 premières valeurs si taille > 20): \n");
  afficher_tab_vingt (tab, taille);

  return EXIT_SUCCESS;
}

/** Fonction qui trie selon l'ordre croissant un tableau t d'items, */
/* dont l'adresse est reçue comme comme premier paramètre d'entrée */
/* et dont la taille est reçue comme deuxième paramètre d'entrée */
/** Le nombre total de comparaisons de valeurs est : */
/* (taille-1) + (taille-2) + ... + 2 + 1 = taille(taille-1)/2 */
void trier_par_selection (item *t, int taille) {
  int i, pos_min;
  /* après l'itération i de la boucle suivante, */
  /* les cases d'indice 0 à i contiennent les i+1 plus petites valeurs du tableau, */
  /* rangées dans l'ordre croissant */
  for (i = 0; i < taille - 1; ++i) {
    pos_min = rechercher_pos_min (t + i, taille - i);
    echanger_item (t + i, t + i + pos_min);
  }
}

/** Fonction qui renvoie l'indice du plus petit élément d'un tableau t d'items */
/* dont l'adresse est reçue comme premier argument */
/* et la taille n est reçue comme deuxième argument */
/** La fonction balaie le tableau des indices 1 à taille-1 ==> taille-1 comparaisons de valeurs */
int rechercher_pos_min (item *t, int taille) {
  int i, pos_min = 0;
  for (i = 1; i < taille; ++i)
    if (t[i] < t[pos_min]) { pos_min = i; }
  return pos_min;
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
