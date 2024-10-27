#include <stdio.h>

#define INF 99999
#define V 5  // Número de vértices

void printSolution(int dist[V][V], int next[V][V]) {
    printf("Distancia más corta entre cada par de nodos:\n");
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            if (dist[i][j] == INF)
                printf("%7s", "INF");
            else
                printf("%7d", dist[i][j]);
        }
        printf("\n");
    }

    printf("\nMatriz de caminos más cortos (P):\n");
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            if (next[i][j] == -1)
                printf("%7s", "N/A");
            else
                printf("%7d", next[i][j] + 1); // Para mostrar nodos como 1-indexados
        }
        printf("\n");
    }
}

void floydWarshall(int graph[V][V]) {
    int dist[V][V], next[V][V];

    // Inicializa las matrices dist y next
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            dist[i][j] = graph[i][j];
            if (graph[i][j] != INF && i != j)
                next[i][j] = j;
            else
                next[i][j] = -1;
        }
    }

    // Itera sobre todos los pares de nodos (k es el nodo intermedio)
    for (int k = 0; k < V; k++) {
        printf("\nPaso %d:\n", k + 1);
        for (int i = 0; i < V; i++) {
            for (int j = 0; j < V; j++) {
                if (dist[i][k] + dist[k][j] < dist[i][j]) {
                    dist[i][j] = dist[i][k] + dist[k][j];
                    next[i][j] = next[i][k];
                }
            }
        }
        printSolution(dist, next);
    }
}

int main() {
    /* Grafo de ejemplo con 4 nodos
       INF significa que no hay conexión directa entre los nodos
       Representa el siguiente grafo:
           (0)---3---(1)
            |         |
            7         1
            |         |
           (2)---2---(3)
    */
    int graph[V][V] = {{0,1,INF,1,5},
                       {9,0,3,2,INF},
                       {INF,INF,0,4,INF},
                       {INF,INF,2,0,3},
                       {3,INF,INF,INF,0}};

    floydWarshall(graph);
    return 0;
}