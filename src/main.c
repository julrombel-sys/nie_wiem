#include <stdio.h>
#include <stdlib.h>

#include "mathio.h"
#include "gauss.h"

int main(int argc, char *argv[]) {
	if(argc != 2) {
		fprintf(stderr, "%s: Należy podać nazwę 1 pliku do wczytania macierzy.\n", argv[0]);
		return 1;
	}

	FILE *file = fopen(argv[1], "r");
	if(file == NULL) {
		fprintf(stderr, "%s: Nie można otworzyć pliku \"%s\"!\n", argv[0], argv[1]);
		return 1;
	}

	matrix_t matr = read_matrix(file);
	fclose(file);
	if(matr.mat == NULL) {
		fprintf(stderr, "%s: Nie można utworzyć macierzy!\n", argv[0]);
		return 1;
	}

	puts("Podana macierz:");
	print_matrix(stdout, matr);
	double *x = malloc(matr.row * sizeof(double));
	if(x == NULL) {
		fprintf(stderr, "Błąd pamięci\n");
		free_matrix(matr);
		return 1;
	}
	if(gauss_elim(&matr, x) != EXIT_SUCCESS) {
		fprintf(stderr, "%s: Nie udało się rozwiązać układu równań!\n", argv[0]);
		free_matrix(matr);
		free(x);
		return 1;
	}
	if(matr.row == 0) {
		puts("Macierz jest zerowa, nie można podać rozwiązań");
		free_matrix(matr);
		free(x);
		return 0;
	}
	puts("Po elimacji Gaussa:");
	print_matrix(stdout, matr);

	puts("Rozwiązania:");
	for(int i = 0; i < matr.row; ++i)
		printf("x_%d: %lg\n", i+1, x[i]);

	free(x);
	free_matrix(matr);
	return 0;
}
