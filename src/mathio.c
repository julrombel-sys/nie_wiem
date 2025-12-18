matrix_t new_matrix(int row, int col) {
	matrix_t matr;
	matr.mat = malloc(row * sizeof(double*));
	if(matr.mat == NULL)
		return matr;
	for(int i = 0; i < row; ++i) {
		matr.mat = malloc(col * sizeof(double));
		if(matr.mat == NULL) {
			for(int j = 0; j < i; ++j)
				free(matr.mat[j]);
			free(matr.mat);
			matr.mat = NULL;
			return matr;
		}
	}
	matr.row = row;
	matr.col = col;
	return matr;
}

matrix_t read_matrix(FILE *file)  {
	matrix_t matr;
	matr.mat = NULL;

	if(fscanf(file, "%d%d", &matr.row, &matr.col) != 2 || matr.col < 2)
		return matr;
	matr.mat = malloc(matr.row * sizeof(double*));
	if(matr.mat == NULL)
		return matr;
	for(int i = 0; i < matr.row; ++i) {
		matr.mat[i] = malloc(matr.col * sizeof(double));
		if(matr.mat[i] == NULL) {
			for(int j = 0; j < i; ++j)
				free(matr.mat[j]);
			free(matr.mat);
			matr.mat = NULL;
			return matr;
		}
		for(int j = 0; j < matr.col; ++j) {
			if(fscanf(file, "%lf", &matr.mat[i][j]) != 1) {
				for(int k = 0; k <= i; ++k)
					free(matr.mat[k]);
				free(matr.mat);
				matr.mat = NULL;
				return matr;
			}
		}
	}
	return matr;
}

void print_matrix(FILE* file, matrix_t matr) {
	fprintf(file, "%dx%d\n", matr.row, matr.col);
	for(int i = 0; i < matr.row; ++i) {
		fputc('[', file);
		for(int j = 0; j < matr.col-1; ++j)
			fprintf(file, "\t%3.5lg", matr.mat[i][j]);
		fprintf(file, "\t|%10lg]\n", matr.mat[i][matr.col-1]);
	}
}

void free_matrix(matrix_t matr) {
	for(int i = 0; i < matr.row; ++i)
		free(matr.mat[i]);
	free(matr.mat);
}
