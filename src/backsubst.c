#include "backsubst.h"
#include <stdio.h>

/* Implementacja wstawiania wstecznego */
int backsubst(matrix_t A, double *x) {
    int i, j;

    for (i = A.row - 1; i >= 0; i--) {

        /* Sprawdzenie elementu na przekatnej */
        if (A.mat[i][i] == 0.0) {
            return 1; /* blad */
        }

        x[i] = A.mat[i][A.col-1];

        for (j = i + 1; j < A.row; j++) {
            x[i] -= A.mat[i][j] * x[j];
        }

        x[i] /= A.mat[i][i];
    }

    return 0; /* sukces */
}
