#include <stdio.h>
#define MAX_M 100
#define MAX_N 100

int countPaths(int m, int n, int matrix[MAX_M][MAX_N], int memo[MAX_M][MAX_N]) {
    if (matrix[m-1][n-1] == 1) {
        return 0;
    }
    if (memo[m-1][n-1] != -1) {
        return memo[m-1][n-1];
    }
    if (m == 1 && n == 1) {
        return 1;
    }
    int fromLeft = (n > 1) ? countPaths(m, n-1, matrix, memo) : 0;
    int fromAbove = (m > 1) ? countPaths(m-1, n, matrix, memo) : 0;
    memo[m-1][n-1] = fromLeft + fromAbove;
    
    return memo[m-1][n-1];
}
int countPathsWrapper(int m, int n, int matrix[MAX_M][MAX_N]) {
    int memo[MAX_M][MAX_N];
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            memo[i][j] = -1;
        }
    }
    return countPaths(m, n, matrix, memo);
}
int main() {
    int m = 3;
    int n = 3;
    int matrix[MAX_M][MAX_N] = {
        {0, 0, 0},
        {0, 1, 0},
        {0, 0, 0}
    };
    int result = countPathsWrapper(m, n, matrix);
    printf("Numero de rutas posibles: %d\n", result);
    
    return 0;
}

