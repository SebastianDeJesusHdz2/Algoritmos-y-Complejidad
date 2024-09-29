#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

void maximizarDiferencia(int arr[], int n, int idx, int count1, int count2, int sum1, int sum2, int *maxDiff);

int main() {
    int n;
    printf("No. elementos del arreglo:\n");
    scanf("%d", &n);
    int arr[n];
    srand(time(NULL));
    printf("Elementos del arreglo: \n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    printf("\n");
    
    int maxDiff = 0; // Inicializa maxDiff
    maximizarDiferencia(arr, n, 0, 0, 0, 0, 0, &maxDiff); // Llama a la función
    printf("La máxima diferencia es: %d\n", maxDiff);
}

void maximizarDiferencia(int arr[], int n, int idx, int count1, int count2, int sum1, int sum2, int *maxDiff) {
    // Condición de parada
    if (count1 == n / 2 && count2 == n / 2) {
        int diff = abs(sum1 - sum2);
        if (diff > *maxDiff) {
            *maxDiff = diff; // Actualiza maxDiff
        }
        return;
    }
    if (idx == n) {
        return; // Se alcanza el final del arreglo
    }

    // Podar si ya tenemos una solución óptima
    if (count1 < n / 2) {
        maximizarDiferencia(arr, n, idx + 1, count1 + 1, count2, sum1 + arr[idx], sum2, maxDiff);
    }
    if (count2 < n / 2) {
        maximizarDiferencia(arr, n, idx + 1, count1, count2 + 1, sum1, sum2 + arr[idx], maxDiff);
    }
}

/*
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

void maximizarDiferencia(int arr[], int ini, int fin, int *maxDiff);
int suma(int S[], int ini, int fin);
void intercambia(int *a, int *b);
void menu();

void main()
{
    menu();// Retorna 0 al final
}

void menu()
{
    int n;
    srand(time(NULL));
    printf("No. elementos del arreglo:\n");
    scanf("%d", &n);
    int arr[n];
    printf("Elementos del arreglo: \n");
    for (int i = 0; i < n; i++)
    {
       scanf("%d", &arr[i]);
    }
    printf("Arreglo original:\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
    
    int maxDiff = 0; // Inicializa maxDiff
    maximizarDiferencia(arr, 0, n, &maxDiff); // Pasa maxDiff por referencia
    printf("La máxima diferencia es: %d\n", maxDiff);
}

void maximizarDiferencia(int arr[], int ini, int fin, int *maxDiff) {
    if (fin - ini < 2) { // Condición de terminación
        return;
    }

    int mid = (ini + fin) / 2;
    int sumI = suma(arr, ini, mid);
    int sumD = suma(arr, mid, fin);
    int sumT = suma(arr, ini, fin);
    
    // Calcular la diferencia
    int dif = abs(sumI - sumD);
    if (dif > *maxDiff) {
        *maxDiff = dif; // Actualiza maxDiff
    }

    maximizarDiferencia(arr, ini, mid, maxDiff); // Recursión para la primera mitad
    maximizarDiferencia(arr, mid, fin, maxDiff); // Recursión para la segunda mitad
}

int suma(int S[], int ini, int fin) {
    int sumT = 0;
    for(int i = ini; i < fin; i++) {
        sumT += S[i];
    }
    return sumT;
}

void intercambia(int *a, int *b) {
    int tmp = *a;
    *a = *b;
    *b = tmp;
}
*/
/*
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

void maximizarDiferencia(int arr[], int n, int idx, int count1, int count2, int sum1, int sum2, int *maxDiff);

int main() {
    int n;
    printf("No. elementos del arreglo:\n");
    scanf("%d", &n);
    int arr[n];
    srand(time(NULL));
    printf("Elementos del arreglo: \n");
    for (int i = 0; i < n; i++) {
        arr[i] = rand() % 100 + 1;
        printf("%d ", arr[i]);
    }
    printf("\n");
    
    int maxDiff = 0;
    maximizarDiferencia(arr, n, 0, 0, 0, 0, 0, &maxDiff);
    printf("La máxima diferencia es: %d\n", maxDiff);
}

void maximizarDiferencia(int arr[], int n, int idx, int count1, int count2, int sum1, int sum2, int *maxDiff) {
    if (count1 == n / 2 && count2 == n / 2) {
        int diff = abs(sum1 - sum2);
        if (diff > *maxDiff) {
            *maxDiff = diff;
        }
        return;
    }
    if (idx == n) {
        return;
    }
    // Agregar a la primera sublista
    if (count1 < n / 2) {
        maximizarDiferencia(arr, n, idx + 1, count1 + 1, count2, sum1 + arr[idx], sum2, maxDiff);
    }
    // Agregar a la segunda sublista
    if (count2 < n / 2) {
        maximizarDiferencia(arr, n, idx + 1, count1, count2 + 1, sum1, sum2 + arr[idx], maxDiff);
    }
}
*/
/*
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

void maximizarDiferencia(int arr[], int n, int idx, int count1, int count2, int sum1, int sum2, int *maxDiff);
int max(int a, int b);
int absDiff(int a, int b);
void menu();

void main()
{
    menu();
}

void menu()
{
    int maxDiff=0;
    int arr[50];
    srand(time(NULL));
    for (int i = 0; i < 50; i++)
    {
        arr[i] = rand() % 1000 + 1;
    }
    printf("Arreglo original:\n");
    for (int i = 0; i < 50; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
    maximizarDiferencia(arr, 50, 0, 0, 0, 0, 0, &maxDiff);
    printf("La máxima diferencia es: %d\n", maxDiff);
}

void maximizarDiferencia(int arr[], int n, int idx, int count1, int count2, int sum1, int sum2, int *maxDiff) {
    if (idx == n) {
        if (count1 == n / 2 && count2 == n / 2) {
            int diff = absDiff(sum1, sum2);
            *maxDiff = max(*maxDiff, diff);
        }
        return;
    }

    // Agregar a la primera sublista
    if (count1 < n / 2) {
        maximizarDiferencia(arr, n, idx + 1, count1 + 1, count2, sum1 + arr[idx], sum2, maxDiff);
    }

    // Agregar a la segunda sublista
    if (count2 < n / 2) {
        maximizarDiferencia(arr, n, idx + 1, count1, count2 + 1, sum1, sum2 + arr[idx], maxDiff);
    }
}

int max(int a, int b) {
    return (a > b) ? a : b;
}

int absDiff(int a, int b) {
    return abs(a - b);
}
*/