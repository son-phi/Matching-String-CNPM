#include <string.h>

#include "algorithms.h"
#include "utils.h"

int Not_So_Naive(const char *X, int m, const char *Y, int n) {
    int j, k, ell;
    int matches = 0;

    if (m < 2) {
        return Brute_Force(X, m, Y, n);
    }

    /* preprocessing */
    if (X[0] == X[1]) {k = 2; ell = 1;} 
    else { k = 1; ell = 2;}

    /* search */
    j = 0;
    while (j <= n - m) {
        if (X[1] != Y[j + 1]) {
            j += k;
        } else {
            if (memcmp(X + 2, Y + j + 2, m - 2) == 0 && X[0] == Y[j]) {
                OUTPUT(j);
                ++matches;
            }

            j += ell;
        }
    }

    return matches;
}
