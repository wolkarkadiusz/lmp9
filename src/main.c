#include <stdio.h>
#include "gauss.h"

int main() {
    int n = 2;

    // Macierz testowa 2x2
    double a0[] = {2, 1};
    double a1[] = {5, 7};
    double *A[] = {a0, a1};

    // Wektor wyrazów wolnych
    double b[] = {11, 13};

    // Wykonanie eliminacji Gaussa
    gaussian_elimination(A, b, n);

    // Wypisanie macierzy po eliminacji górnotrójkątnej
    printf("Macierz po eliminacji:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%8.3f ", A[i][j]);
        }
        printf("| %8.3f\n", b[i]);
    }

    return 0;
}


