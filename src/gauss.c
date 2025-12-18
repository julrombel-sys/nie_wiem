#include "gauss.h"
#include "backsubst.h"

#include <stdlib.h>

int gauss_elim(matrix_t *mat, double *x) {
	int ax, i, j, m = mat->row < mat->col ? mat->row : mat->col;
	for(ax = 0; ax < m; ++ax) {
		if(mat->mat[ax][ax] == 0)
			return EXIT_FAILURE;
		for(i = ax+1; i < mat->row; ++i) {
			double z = mat->mat[i][ax];
			for(j = 0; j < mat->col; ++j) {
				//fprintf(stderr, "%lg %lg %lg\n", mat->mat[i][ax], mat->mat[ax][j], mat->mat[ax][ax]);
				mat->mat[i][j] -= mat->mat[ax][j] * z / mat->mat[ax][ax];
			}
		}
		print_matrix(stderr, *mat);
	}
	return backsubst(*mat, x);
}
