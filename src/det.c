#include<stdio.h>
#include <stdlib.h>

double det(double **matrix, int n);
double ** colum(double **matrix, double **resalt, int colum, int n);
double ** row(double **matrix, double **resalt, int colum, int n);
int input(double **matrix, int *n);
int inputN(int *n);
void output(double det);

int main() {
    double res;
    int n;
    if (inputN(&n)) {
        double **matrix = malloc(n * sizeof(double *));
        for (int i = 0; i < n; i++)
            matrix[i] = malloc(n * sizeof(double));
        if (input(matrix, &n)) {
            res = det(matrix, n);
            output(res);
            for (int i = 0; i < n; i++)
                free(matrix[i]);
            free(matrix);
        }
    }
    return 0;
    
}

int inputN(int *n) {
    int m;
    char c_1, c_2, c_3;
    scanf("%c%c%c", &c_1, &c_2, &c_3);
    if ((int) c_1 - 48 < 1 || (int) c_1 - 48 > 9) return 0;
    if ((int) c_3 - 48 < 1 || (int) c_3 - 48 > 9) return 0;
    if ((int) c_2 !=  32) return 0;
    *n = (int) c_1 - 48;
    m = (int) c_3 - 48;
    if (*n != m) return 0;
    return 1;
}

int input(double **a, int *n) {
    for (int i = 0; i < *n; i++) {
        for (int j = 0; j < *n; j++) {
            char c;
            if (!scanf("%lf%c", &a[i][j], &c)) return 0;
            if (c != 32 && j < *n - 1) return 0;
            if (c != 10 && j == *n -1) return 0;
        }
    }
    return 1;
}

double det(double **matrix, int n) {
    if (n == 2)
        return matrix[0][0] * matrix[1][1] - matrix[0][1] * matrix[1][0];
    double resultN = 0, resaltC[n - 1][n - 1], resaltR[n - 1][n];
    // row(matrix, (double **) resaltR, 0, n);
    for (int k = 0; k < n - 1; k++)
        for (int l = 0; l < n; l++)
            resaltR[k][l] = k < 1 ? matrix[k][l] : matrix[k + 1][l];
    for (int j = 0; j < n; j++) {
        for (int k = 0; k < n - 1; k++)
            for (int l = 0; l < n - 1; l++)
                resaltC[k][l] = l < j ? matrix[k][l] : matrix[k][l + 1];
        // colum((double **) resaltR, (double **) resaltC, j, n);
        resultN += (j % 2 == 1 ? 1 : -1) * matrix[1][j] * det((double **) resaltC, n);
    }
    return resultN;
}

// double ** colum(double **matrix, double **resalt, int colum, int n) {
//     for (int i = 0; i < n - 1; i++)
//         for (int j = 0; j < n - 1; j++)
//             resalt[i][j] = j < colum ? matrix[i][j] : matrix[i][j + 1];
//     return resalt;
// }

// double ** row(double **matrix, double **resalt, int row, int n) {
//     for (int i = 0; i < n - 1; i++) {
//         for (int j = 0; j < n; j++)
//             resalt[i][j] = i < row ? matrix[i][j] : matrix[i + 1][j];
//     }
//     return resalt;
// }

void output(double det) {
    printf("%.6lf", det);
}