#include <stdio.h>
#include <stdlib.h>


typedef int item;

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