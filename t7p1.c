#include <stdio.h>
#include <limits.h>
#include <time.h>
#include <stdlib.h>

#define INF INT_MAX

void menu();
void travel(int n, const int W[n][n], int P[n][1 << (n - 1)], int *minlength);
void imprimeTour(int n, int P[n][1 << (n - 1)]);
void imprimeMatrizInicial(int n, const int W[n][n]);

void main(){
    menu();
}

void menu() {
    clock_t t_ini, t_end;
    double t_elapsed;
    int n = 5;
    int W[5][5] = {
        {0, 12, 10, 19, 8},
        {12, 0, 3, 7, 2},
        {10, 3, 0, 6, 20},
        {19, 7, 6, 0, 4},
        {8, 2, 20, 4, 0}
    };
    int P[5][1 << (5 - 1)] = {{0}};
    int minlength;
    imprimeMatrizInicial(n, W);
    //t-inicial
    t_ini = clock();
    //t-inicial
    travel(n, W, P, &minlength);
    //t-finales
    t_end = clock() - t_ini;
    t_elapsed = ((double)t_end)/CLOCKS_PER_SEC;
    printf("\nTiempo total: %f segs \n", t_elapsed);
    //t-finales
    printf("Longitud mínima del tour: %d\n", minlength);
    imprimeTour(n, P);
}


void travel(int n, const int W[n][n], int P[n][1 << (n - 1)], int *minlength) {
    int D[n][1 << (n - 1)];
    int subset, i, j, k;

    // Inicializar D[i][vacío] = W[i][1] para cada i desde 2 hasta n
    for (i = 1; i < n; i++) {
        D[i][0] = W[i][0];
    }

    // Iterar sobre el número de elementos en el subconjunto
    for (k = 1; k < n - 1; k++) {
        for (subset = 1; subset < (1 << (n - 1)); subset++) {
            // Solo procesar subconjuntos con k elementos
            int count = __builtin_popcount(subset);
            if (count != k) continue;

            for (i = 1; i < n; i++) {
                if ((subset & (1 << (i - 1))) == 0) {
                    int min_dist = INF, min_index = -1;
                    for (j = 1; j < n; j++) {
                        if (subset & (1 << (j - 1))) {
                            int dist = W[i][j] + D[j][subset & ~(1 << (j - 1))];
                            if (dist < min_dist) {
                                min_dist = dist;
                                min_index = j;
                            }
                        }
                    }
                    D[i][subset] = min_dist;
                    P[i][subset] = min_index;
                }
            }
        }
    }

    // Calcular la distancia mínima desde la ciudad inicial
    int final_subset = (1 << (n - 1)) - 1;
    *minlength = INF;
    for (j = 1; j < n; j++) {
        int dist = W[0][j] + D[j][final_subset & ~(1 << (j - 1))];
        if (dist < *minlength) {
            *minlength = dist;
            P[0][final_subset] = j;
        }
    }
}

void imprimeTour(int n, int P[n][1 << (n - 1)]) {
    //Subconjunto con toda ciudad visitada.
    int ind = (1 << (n - 1)) - 1;
    //Posicion en el lugar inicial.
    int lug = P[0][ind];
    //Imprime el lugar inicial.
    printf("Tour óptimo: 0 -> ");
    for (int i = 1; i < n; i++) {
        //Imprime el lugar.
        printf("%d -> ", lug);
        //Elimina el lugar.
        ind &= ~(1 << (lug - 1));
        //Avanza el lugar.
        lug = P[lug][ind];
    }
    //Regresa al lugar inicial.
    printf("0\n");
}

void imprimeMatrizInicial(int n, const int W[n][n]) {
    printf("Matriz de distancias:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%3d ", W[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}