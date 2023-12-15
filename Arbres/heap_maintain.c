#include <stdio.h>
#include <stdlib.h>
#include <time.h>
typedef float item;
#define less(A,B) (A < B)

/*************************************************************/
/*   Warning: as the functions in this file maintain the     */
/*   array-based implementation of a heap,                   */
/*   the values in the array correspond to indices >= 1      */
/*   (the value of index 0 will be considered a fake value)  */
/*************************************************************/


/** Restores the heap condition when the priority */
/* of the "node" at index k in the array is increased **/
/* The function moves up the heap, exchanging the node at index k */
/* with its parent if the priority of the former is greater than that of the latter */
/** Complexity : */
/* - there are at most [\log_2(k)] iterations of the while loop; */
/*   (the square brackets stand for the floor function)  */
/* - each iteration involves at most four comparisons and assignments of tab values; */
/* The total cost is at most 4[\log_2(k)], thus O(\log_2(k)) **/
void fix_up_heap(item tab[], int k) {
  while (k > 1 && less(tab[k/2], tab[k])) {
    swap(tab + k, tab + k/2);
    k = k/2;
  }
}

/** Restores the heap condition when the priority */
/* of the "node" (at index k in the array) is decreased */
/* The function moves down the heap, exchanging the node at index k */
/* with the larger of its two children, */
/* and stopping when the bottom of the heap is reached */
/* or when the node at index k is not smaller than either of its children */
/* Index n corresponds to the bottom of the heap */
/** Complexity : */
/* - there are at most [\log_2(n)] iterations of the while loop; */
/* - each iteration involves at most five comparisons and assignments of tab values; */
/* The total cost is at most 5[\log_2(n)+1], thus 0(\log_2(n)) **/
void fix_down_heap(item tab[], int k, int n) {
  int j;
  while (2*k <= n) {
    j = 2*k;
    if (j < n && less(tab[j+1], tab[j])) j++;
    if (!less(tab[k], tab[j])) break;
    swap(tab + k, tab + j);
    k = j;
  }
}
