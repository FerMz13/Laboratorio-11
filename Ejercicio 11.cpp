#include <stdio.h>
#define MAX_M 100
#define MAX_N 100

int contar(int m, int n, int matriz[MAX_M][MAX_N], int memoria[MAX_M][MAX_N]) {
    if (matriz[m-1][n-1] == 1) {
        return 0;
    }
    if (memoria[m-1][n-1] != -1) {
        return memoria[m-1][n-1];
    }
    if (m == 1 && n == 1) {
        return 1;
    }
    int Izquierda = 0, Arriba = 0;
    if (n > 1) {
        Izquierda = contar(m, n-1, matriz, memoria);
    }
    if (m > 1) {
        Arriba = contar(m-1, n, matriz, memoria);
    }
    memoria[m-1][n-1] = Izquierda + Arriba;
    
    return memoria[m-1][n-1];
}
int contarRutas(int m, int n, int matriz[MAX_M][MAX_N]) {
    int memoria[MAX_M][MAX_N];
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            memoria[i][j] = -1;
        }
    }
    return contar(m, n, matriz, memoria);
}
int main() {
    int m = 3;
    int n = 3;
    int matriz[MAX_M][MAX_N] = {
        {0, 0, 0},
        {0, 1, 0},
        {0, 0, 0}
    };
    
    int resultado = contarRutas(m, n, matriz);
    printf("Numero de rutas posibles: %d\n", resultado);
    
    return 0;
}


