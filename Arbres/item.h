#ifndef _ITEM_H
#define _ITEM_H

typedef int item;

#define key(A) (A)
#define less(A, B) (key(A) < key(B))
#define eq(A, B) (!less(A, B) && !less(B, A))
#define exch(A, B) { item tmp = A; A = B; B = tmp; }
#define display(A) { printf("%d ", key(A)); }
#define destroy(A)




#endif
