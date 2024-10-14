#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <limits.h>

#define INF INT_MAX

void menu();
void genMatrizAdy(int n, int matriz[n][n]);
void imprimirMatriz(int n, int matriz[n][n]);
void floydWarshall(int n, int dist[n][n]);

void main() {
    int opc=1;
    while(opc==1) {
        menu();
        printf("Quiere continuar 1)SI C)NO\n");
        scanf("%d",&opc);
    }
}

void menu() {
    clock_t t_ini, t_end;
    double t_elapsed;
    int n;
    printf("Ingrese el número de nodos: ");
    scanf("%d", &n);
    int matriz[n][n];
    genMatrizAdy(n, matriz);
    printf("Matriz de adyacencia del grafo dirigido:\n");
    imprimirMatriz(n, matriz);
    t_ini = clock();
    floydWarshall(n, matriz);
    t_end = clock() - t_ini;
    t_elapsed = ((double)t_end)/CLOCKS_PER_SEC;
    printf("\nTiempo total: %f segs\n", t_elapsed);
    printf("Matriz de distancias mínimas después del método Floyd:\n");
    imprimirMatriz(n, matriz);
}

void genMatrizAdy(int n, int matriz[n][n]) {
    int prob;
    srand(time(NULL));
    // Genera aristas para el grafo.
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            //Condicion para evitar conexiones con el mismo nodo.
            if (i != j) {
                //Estableciendo probabilidad.
                prob = rand() % 100;
                //Si probabilidad menor o mayor a 20.
                if (prob < 20) {
                    //Inicializa un espacio sin relacion
                    matriz[i][j] = INF;
                } else {
                    //Inicializa una relacion.
                    matriz[i][j] = rand() % 1000;
                }
            } else {
                //Inicializacion en 0´s.
                matriz[i][j] = 0;
            }
        }
    }
}

void imprimirMatriz(int n, int matriz[n][n]) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (matriz[i][j] == INF) {
                printf("%4s ", "INF");
            } else {
                printf("%4d ", matriz[i][j]);
            }
        }
        printf("\n");
    }
}

void floydWarshall(int n, int matriz[n][n]) {
    //Matriz temporal. 
    int temp[n][n];
    // Inicializamos la matrz temporal con los valores de la matriz original
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            temp[i][j] = matriz[i][j];
        }
    }
    //Recorrer toda la matriz
    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                //Comprobacion de caminos.
                if (temp[i][k] != INF && temp[k][j] != INF && temp[i][k] + temp[k][j] < temp[i][j]) {
                    //Actualizacion de valores
                    temp[i][j] = temp[i][k] + temp[k][j]; 
                }
            }
        }
    }
    //Copia de resultados
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            matriz[i][j] = temp[i][j];
        }
    }
}