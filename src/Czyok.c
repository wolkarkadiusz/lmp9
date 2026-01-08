#include <stdio.h>

void backSubstitution(int n, double A[n][n], double b[n], double x[n]) {
    // Oblicz ostatnią zmienną
    x[n-1] = b[n-1] / A[n-1][n-1];

    // Pętla od przedostatniej do pierwszej zmiennej
    for (int i = n - 2; i >= 0; i--) {
        double sum = 0.0;
        // Sumujemy znane już wartości (x_j * A_ij)
        for (int j = i + 1; j < n; j++) {
            sum += A[i][j] * x[j];
        }
        // Obliczamy x_i
        x[i] = (b[i] - sum) / A[i][i];
    }
}

int main() {
    int n = 3;
    double A[3][3] = {{2, 1, -1}, {0, 3, 1}, {0, 0, 2}}; // Macierz górnotrójkątna
    double b[3] = {8, 10, 4}; // Wektor wyrazów wolnych
    double x[3]; // Wektor rozwiązań

    backSubstitution(n, A, b, x);

    printf("Rozwiązania (x, y, z):\n");
    for (int i = 0; i < n; i++) {
        printf("x[%d] = %f\n", i, x[i]);
    }

    return 0;
}
