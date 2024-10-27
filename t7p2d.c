#include <stdio.h>
#include <limits.h>
#include <time.h>
#include <stdlib.h>

#define INF INT_MAX

void menu();
void travel(int n, const int W[n][n], int P[n][1 << (n - 1)], int *min);
void imprimeTour(int n, int P[n][1 << (n - 1)]);
void imprimeMatrizInicial(int n, const int W[n][n]);
void genMatrizAdy(int n, int matriz[n][n]);
void inicializarMatrizP(int n, int P[n][1 << n]);

void main(){
    menu();
}

void menu() {
    clock_t t_ini, t_end;
    double t_elapsed;
    int n;
    printf("Ingrese el número de nodos: ");
    scanf("%d", &n);
    int W[n][n];
    genMatrizAdy(n, W);
    int P[n][1 << n];
    inicializarMatrizP(n, P);
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
    //Inicializacion de variables.
    int D[n][1 << (n - 1)];
    int ind, i, j, k;
    //Inicializacion de matriz.
    for (i = 1; i < n; i++) {
        D[i][0] = W[i][0];
    }
    //Recorrido.
    for (k = 1; k < n; k++) {
        for (ind = 1; ind < (1 << (n - 1)); ind++) {
            //proceso de conjuntos.
            int cot = __builtin_popcount(ind);
            if (cot != k) continue;
            //Recorrido.
            for (i = 1; i < n; i++) {
                //Si el lugar no existe.
                if ((ind & (1 << (i - 1))) == 0) {
                    int min_dist = INF;
                    int min_index = -1;
                    //Busqueda de la mejor opcion.
                    for (j = 1; j < n; j++) {
                        if (ind & (1 << (j - 1))) {
                            //Calculo de distancia.
                            int dist = W[i][j] + D[j][ind & ~(1 << (j - 1))];
                            //Guarda distancia minima.
                            if (dist < min_dist) {
                                min_dist = dist;
                                min_index = j;
                            }
                        }
                    }
                    //Guarda distancias minimas en las matrices.
                    D[i][ind] = min_dist;
                    P[i][ind] = min_index;
                }
            }
        }
    }
    //Establecimiento de valores para encontrar la minima distancia.
    int final_ind = (1 << (n - 1)) - 1;
    *minlength = INF;
    //Recorrido.
    for (j = 1; j < n; j++) {
        //Calculo de distancia.
        int dist = W[0][j] + D[j][final_ind & ~(1 << (j - 1))];
        //Si distancia actual es menor a distancia minima.
        if (dist < *minlength) {
            //Actualizacion de distancias.
            *minlength = dist;
            P[0][final_ind] = j;
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

void genMatrizAdy(int n, int matriz[n][n]) {
    srand(time(NULL));
    // Genera aristas para el grafo.
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            //Condicion para evitar conexiones con el mismo nodo.
            if (i != j) {
                matriz[i][j] = rand() % 100;
            } else {
                //Inicializacion en 0´s.
                matriz[i][j] = 0;
            }
        }
    }
}

void inicializarMatrizP(int n, int P[n][1 << n]) {
    // Inicializa todos los elementos de P a 0
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < (1 << n); j++) {
            P[i][j] = 0;
        }
    }
}