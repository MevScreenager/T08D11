#include<stdio.h>
#include <stdlib.h>

double det(double **matrix, int n, int m);
int input(double **matrix, int *n, int *m);
int inputN(int *n, int *m);
void output(double det);

void main() {
    double **matrix;
    int n, m;
    if (inputN(&n, &m)) {
        matrix = (int **) malloc(n * sizeof(int*));
        for (int i = 0; i < n; i++)
            matrix[i] = (int*) malloc(m * sizeof(int));
        if (input(matrix, &n, &m)) {
            // printf("Good!");
        }
    }
    
}

int inputN(int *n, int *m) {
    char c_1, c_2, c_3;
    scanf("%c%c%c", &c_1, &c_2, &c_3);
    if ((int) c_1 - 48 < 1 || (int) c_1 - 48 > 9) return 0;
    if ((int) c_3 - 48 < 1 || (int) c_3 - 48 > 9) return 0;
    if ((int) c_2 !=  32) return 0;
    *n = (int) c_1 - 48;
    *m = (int) c_3 - 48;
    return 1;
}

int input(double **a, int *n, int *m) {
    for (int i = 0; i < *n; i++) {
        for (int j = 0; j < *m; j++) {
            char c;
            if (!scanf("%lf", &a[i][j])) return 0;
            scanf("%c", &c);
            if (c != 32 && c != 10) return 0;
        }
    }
    return 1;
}
