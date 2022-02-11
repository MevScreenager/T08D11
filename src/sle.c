int sle(double **matrix, int n, int m, double *roots);
void input(double **matrix, int *n, int *m);
int inputN(int *n, int *m);
void output(double **matrix, int n, int m);
void output_roots(double *roots, int n);

void main() {
    int n, m;
    if (inputN(&n, &m)) {
        double **matrix = malloc(n * sizeof(double *));
        for (int i = 0; i < n; i++)
            matrix[i] = malloc(m * sizeof(double));
        if (input(matrix, &n, &m)) {
            res = det(matrix, n);
            printf("%.6lf", res);
            for (int i = 0; i < n; i++)
                free(matrix[i]);
            free(matrix);
        }
    }
    return 0;

}

int inputN(int *n, int *m) {
    char c_1, c_2, c_3;
    scanf("%c%c%c", &c_1, &c_2, &c_3);
    if ((int) c_1 - 48 < 1 || (int) c_1 - 48 > 9) return 0;
    if ((int) c_3 - 48 < 1 || (int) c_3 - 48 > 9) return 0;
    if ((int) c_2 !=  32) return 0;
    *n = (int) c_1 - 48;
    *m = (int) c_3 - 48;
    if (*n != *m) return 0;
    return 1;
}

int input(double **a, int *n, int *m) {
    for (int i = 0; i < *n; i++) {
        for (int j = 0; j < *m; j++) {
            char c;
            if (!scanf("%lf%c", &a[i][j], &c)) return 0;
            if (c != 32 && j < *m - 1) return 0;
            if (c != 10 && j == *m -1) return 0;
        }
    }
    return 1;
}
