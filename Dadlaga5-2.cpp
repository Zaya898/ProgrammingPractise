#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define N 9

int main() {
    double original[N][N];
    int result[N][N];
    srand(time(0));
    printf("Anhnii sanamsargui 9x9 bodit toon husnegt:\n");
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            original[i][j] = (double)(rand() % 10000) / 100; 
            printf("%6.2f ", original[i][j]);
        }
        printf("\n");
    }

    for (int i = 0; i < N; i++) {
        double diagonal_element = original[i][i]; 
        for (int j = 0; j < N; j++) {
            if (original[i][j] > diagonal_element) {
                result[i][j] = 1;
            } else {
                result[i][j] = 0;
            }
        }
    }
    printf("\nUr dund garsan 9x9 buhel toon husnegt:\n");
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            printf("%d ", result[i][j]);
        }
        printf("\n");
    }
    return 0;
}
