#include<stdio.h>
#include<stdlib.h>
#include<time.h>


typedef int item;

void echanger_item (item *, item *);
int rechercher_pos_min (item *, int);
int trier_par_selection (item *, int);
int trier_par_insertion (item *, int);


int main(int argc, char const *argv[])
{
    int n, mode;

    float *tab[n];
    *tab =(float*) malloc(sizeof(float)*n);
    srand(time(NULL));
    printf("Saisir la taille du tableau:\n");
    scanf("%d",&n);
    printf("Veillez choisir le mode d'insertion\n");
    do
    {
        printf("Insertion aléatoire: 1\n");
        printf("Insertion manuelle: 2\n");
        scanf("%d",&mode);
    } while (mode != 1 && mode != 2);


    if (mode == 1){
        printf ("Insertion aléatoire:\n");
        for (size_t i = 0; i < n; i++)
        {
            tab[i] = (float *)malloc(sizeof(float));
            *tab[i] = ((float)rand() / RAND_MAX) * 100;     
        }
        for (int j = 0; j < n; j++)
    {
        printf("Valleur %d: %.2f\n", j+1, *tab[j]);
    }
    if (trier_par_insertion(tab, n) > trier_par_selection(tab, n))
    {
        printf("Le trie par insertion est plus rapide que le trie par selection tel que par selection a fait %d d'operation et l'autre %d d'operations\n", trier_par_insertion(tab, n),trier_par_selection(tab, n));
    } else if (trier_par_insertion(tab, n) < trier_par_selection(tab, n)){
                printf("Le trie par insertion est plus lent que le trie par selection tel que par selection a fait %d d'operation et l'autre %d d'operations\n", trier_par_insertion(tab, n),trier_par_selection(tab, n));
    } else printf("Les deux ont la meme vitesse avec %d d'operation\n",trier_par_insertion(tab, n));
    

        
    } else if (mode == 2){
        printf ("Insertion manuelle:\n");
        for (size_t i = 0; i < n; i++)
        {
            tab[i] = (float *)malloc(sizeof(float));
            printf("Insérez la valeur %d:\n", i+1);
            scanf("%f", &tab[i]);
        }
        for (size_t i = 0; i < n; i++)
    {
        printf("%f\n", tab[i]);
    }
        
    }  
    return 0;
}




int trier_par_selection (item *t, int taille) {
  int i, pos_min;
      int numOp1 =0;

  for (i = 0; i < taille - 1; ++i) {
    pos_min = rechercher_pos_min (t + i, taille - i);
    echanger_item (t + i, t + i + pos_min);
    numOp1++;
  }
  return numOp1;
}

int trier_par_insertion (item *t, int taille) {
  int i, j;
  int numOp2 =0;
  for (i = 1; i < taille; ++i) {
    j = i;
    while (j > 0 && t[j] < t[j-1]) {
      echanger_item (t + j, t + j - 1);
      numOp2++;
      --j;
    }
  }
  return numOp2;
}

int rechercher_pos_min (item *t, int taille) {
  int i, pos_min = 0;
  for (i = 1; i < taille; ++i)
    if (t[i] < t[pos_min]) { pos_min = i; }
  return pos_min;
}

void echanger_item (item *x, item *y) {
  item tmp = *x;
  *x = *y;
  *y = tmp;
}