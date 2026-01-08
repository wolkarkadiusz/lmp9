#include "back.h"

void backSubstitution(int n, double A[n][n], double b[n], double x[n]) {
    // Oblicz ostatnią zmienną
    x[n-1] = b[n-1] / A[n-1][n-1];

    // Pętla od przedostatniej do pierwszej zmiennej
    for (int i = n - 2; i >= 0; i--) {
        double sum = 0.0;

        // Sumujemy znane już wartości
        for (int j = i + 1; j < n; j++) {
            sum += A[i][j] * x[j];
        }

        // Obliczamy x_i
        x[i] = (b[i] - sum) / A[i][i];
    }
}
