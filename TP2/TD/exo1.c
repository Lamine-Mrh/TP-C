#include <stdio.h>
#include <stdlib.h>


typedef int item;

struct maillon {
    item val;
    struct maillon *svt;
};

struct list
{
    struct maillon *prm;
    int l;
};

int tab_maj (int n, item* t);
struct maillon* list_maj (struct list *l);

int main(int argc, char const *argv[])
{
    item *t = (item *) malloc(sizeof (item)*5);
    t[0]= 5;
    t[1]= 3;
    t[2]= 5;
    t[3]= 5;
    t[4]= 4;
    int inx;
    inx = tab_maj(5, t);
    if (inx == -1){
        printf("Y'a pas de valeur absolument majorante\n");
    } else {
        printf("La valeur absolument majorante est %d dans la position %d\n", t[inx], inx);
    }

    free(t);

    struct list *l = (struct list*)malloc(sizeof(struct list));
    struct maillon *m = (struct maillon*)malloc(sizeof(struct maillon));
    struct maillon *n = (struct maillon*)malloc(sizeof(struct maillon));
    struct maillon *f = (struct maillon*)malloc(sizeof(struct maillon));
    struct maillon *p = (struct maillon*)malloc(sizeof(struct maillon));
    struct maillon *r = NULL;

    l->l = 4;
    l->prm = m;
    m->val = 2;
    m->svt = n;
    n->val = 3;
    n->svt = f;
    f->val = 3;
    f->svt = p;
    p->val = 3;
    p->svt = NULL;

    r = list_maj(l);
    if (r == NULL) {
        printf("Y'a pas de valeur absolument majorante\n");
    } else {
        printf("La valeur absolument majorante est %d dans son adresse est %p\n", r->val, (void *)r);
    }
    free(p);
    free(f);
    free(n);
    free(m);
    free(l);

    return 0;
}

int tab_maj (int n, item* t){
    int occ = 0;
    int i=0;
    while(i<n){
        for (int j = i+1; j < n; j++)
        {
            if (t[i]==t[j]){
                occ++;
            } 
        }
        if (occ >= n/2){
            return i;
        } else { 
            occ=0;
            i++;
            }
    }
    return -1;
}

struct maillon* list_maj (struct list *l){
      if (l == NULL || l->prm == NULL) {
        return NULL; // Check for NULL list or empty list
    }

    struct maillon* current = l->prm;
    while (current != NULL) {
        int occ = 1; 
        struct maillon* next = current->svt;
        while (next != NULL && current->val == next->val) {
            occ++;
            next = next->svt;
        }
        if (occ > l->l / 2) {
            return current;
        }
        current = current->svt;
    }

    return NULL;
}