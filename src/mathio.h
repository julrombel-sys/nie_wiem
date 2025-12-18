#ifndef _MATHIO_H__
#define _MATHIO_H__

#include <stdio.h>
#include <stdlib.h>

typedef struct Matrix {
	int row, col;
	double **mat;
} matrix_t;

matrix_t new_matrix(int, int);

matrix_t read_matrix(FILE*);

void print_matrix(FILE*, matrix_t);

void free_matrix(matrix_t);

#endif //_MATHIO_H__
