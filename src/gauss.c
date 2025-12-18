#include <stdio.h>
#include <math.h>
#include "gauss.h"

// Wybór pivota w kolumnie k
// Jeśli znajdzie wiersz z większym modułem w kolumnie k,
// zamienia wiersze w macierzy A i wektorze b
void choose_pivot(double **A, double *b, int n, int k) {
	int max = k;
	// Szukanie wiersza z największym elementem w kolumnie k
	for (int i = k + 1; i < n; i++) {
		if (fabs(A[i][k]) > fabs(A[max][k])) {
			max = i;
		}
	}

	// Jeśli największy element nie jest w bieżącym wierszu,
	// zamieniamy wiersze
	if (max != k) {
		double *tmp = A[k];
		A[k] = A[max];
		A[max] = tmp;

		double tb = b[k];
		b[k] = b[max];
		b[max] = tb;
	}
}

// Eliminacja Gaussa
// Redukowanie macierzy do postaci górnotrójkątnej
void gaussian_elimination(double **A, double *b, int n) {
	for (int k = 0; k < n - 1; k++) {
		// Wybór pivota dla bieżącej kolumny
		choose_pivot(A, b, n, k);

		// Eliminacja wierszy poniżej wiersza k
		for (int i = k + 1; i < n; i++) {
			double m = A[i][k] / A[k][k]; // Współczynnik mnożenia
			for (int j = k; j < n; j++) {
				A[i][j] -= m * A[k][j]; // Aktualizacja elementów w wierszu
			}
			b[i] -= m * b[k]; // Aktualizacja wektora wyrazów wolnych
		}
	}
}
