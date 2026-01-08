#include "gauss.h"
#include "backsubst.h"

#include <stdlib.h>

static int all_equal(double *arr, int siz, double val) {
	for(int i = 0; i < siz; ++i)
		if(arr[i] != val)
			return 0;
	return 1;
}

int gauss_elim(matrix_t *mat, double *x) {
	int ax, i, j;
	for(ax = 0; ax < mat->row; ++ax) {
		if(mat->mat[ax][ax] == 0) {
			if(all_equal(mat->mat[ax], mat->col, 0.0)) {
				(mat->row)--;
				free(mat->mat[ax]);
				mat->mat[ax] = mat->mat[mat->row];
				mat->mat[mat->row] = NULL;
				ax--;
				continue;
			}
			return EXIT_FAILURE;
		}
		for(i = ax+1; i < mat->row; ++i) {
			double z = mat->mat[i][ax];
			for(j = 0; j < mat->col; ++j) {
				//fprintf(stderr, "%lg %lg %lg\n", mat->mat[i][ax], mat->mat[ax][j], mat->mat[ax][ax]);
				mat->mat[i][j] -= mat->mat[ax][j] * z / mat->mat[ax][ax];
			}
		}
		//równanie sprzeczne
		if(all_equal(mat->mat[ax], mat->col-1, 0.0) && mat->mat[ax][mat->col-1] != 0)
			return EXIT_FAILURE;
#ifdef DEBUG
		print_matrix(stderr, *mat);
#endif
	}
	return backsubst(*mat, x);
}
