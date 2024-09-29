#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

void maximizarDiferencia(int arr[], int n, int cont, int cont1, int cont2, int sum1, int sum2, int *maxDiff);

int main() {
    int n;
    printf("No. elementos del arreglo:\n");
    scanf("%d", &n);
    int arr[n];
    srand(time(NULL));
    printf("Elementos del arreglo: \n");
    for (int i = 0; i < n; i++) {
        arr[i] = rand() % 1000 + 1;
        printf("%d ", arr[i]);
    }
    printf("\n");
    int maxDiff = 0;
    maximizarDiferencia(arr, n, 0, 0, 0, 0, 0, &maxDiff);
    printf("La máxima diferencia es: %d\n", maxDiff);
}

void maximizarDiferencia(int arr[], int n, int cont, int cont1, int cont2, int sum1, int sum2, int *maxDiff) {
    if (cont1 == n / 2 && cont2 == n / 2) { //Se agregan la mitad de elementos a cada sublista.
        int diff = abs(sum1 - sum2); //Calcula diferencias.
        if (diff > *maxDiff) { // Hay una diferencia mayor o no.
            *maxDiff = diff; //Actualizacion de valores.
        }
        return; //Ya se consiguio el resultado
    } if (cont == n) { //Caso base, todos los elementos se han revisado.
        return;
    } if (cont1 < n / 2) { //Agrega elementos a la 1ra. sublista
        maximizarDiferencia(arr, n, cont + 1, cont1 + 1, cont2, sum1 + arr[cont], sum2, maxDiff);
    } if (cont2 < n / 2) { //Agrega elementos a la 2da. sublista
        maximizarDiferencia(arr, n, cont + 1, cont1, cont2 + 1, sum1, sum2 + arr[cont], maxDiff);
    }
}


/*
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

void maximizarDiferencia(int arr[], int ini, int fin);
int suma(int S[], int ini, int fin);
void ordenar_insercion(int arreglo[], int tam);
void intercambia(int *a, int *b);
void menu();

void main()
{
    menu();
}

void menu()
{
    int maxDiff=0, n;
    srand(time(NULL));
    printf("No.elementos del arreglo:\n");
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
    maximizarDiferencia(arr, 0, n);
}

void maximizarDiferencia(int arr[], int ini, int fin) {
    int mid, sumI, sumD, sumT, dif, contD, contI, temp;
    if(fin - ini == 1) {
        return arr[ini];
    }
    mid = (ini + fin) / 2;
    sumI = maximizarDiferencia(arr, ini, mid);
    sumD = maximizarDiferencia(arr,mid, fin);
    sumT = suma(arr, ini, fin);
    dif = abs(sumI - (sumT - sumI));
    for(contI = ini; contI < mid; contI++) {
        for(contD = mid; contD < fin; contD++) {
            if(arr[contI] > arr[contD]) {
                intercambia(&arr[contI],&arr[contD]);
            }
        }
    }
}

int suma(int S[], int ini, int fin) {
    int sumT = 0;
    for(int i = ini; i<fin ; i++ ) {
        sumT += S[i];
    }
    return sumT;
}

void ordenar_insercion(int arreglo[], int tam) {
    for(int i=1;i<tam;i++) {
        int j=i;
        while(j>0 && arreglo[j]<arreglo[j-1]) {
            intercambia(&arreglo[j],&arreglo[j-1]);
            j = j - 1;
        }
    }
}

void intercambia(int *a, int *b) {
    int tmp = *a;
    *a = *b;
    *b = tmp;
}
*/