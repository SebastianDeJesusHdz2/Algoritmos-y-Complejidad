#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

int location(int S[], int low, int high, int x);
void mergeSort(int arreglo[], int tam);
void merge(int arr[], int ini, int med, int fin);
void menu();

void main()
{
    menu();
}

void menu()
{
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
    mergeSort(arr,50);
    printf("\nArreglo ordenado:\n");
    for (int i = 0; i < 50; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void mergeSort(int arr[], int tam) {
    int med, fin; //Declaración.
    for (int i = 1; i < tam; i *= 2) { //Recorrido para fusionar.
        for (int ini = 0; ini < tam; ini += 2 * i) { //Recorrido para subarreglos.
            med = ini + i - 1; //Indicador de medio.
            fin = ini + 2 * i - 1; //Indicador de fin.
            if (fin >= tam) { //Ajuste para no salirse.
                fin = tam - 1; //Ajuste en final.
            }
            if (med >= tam) { //Ajuste para no salirse.
                break; //Romper ciclo.
            }
            merge(arr, ini, med, fin); //Función de apoyo.
        }
    }
}

void merge(int arr[], int ini, int med, int fin) {
    int t1, t2, a1=0, a2=0, a3=ini; //Declaración.
    t1 = med - ini + 1; //Tamaño del subarreglo 1.
    t2 = fin - med; //Tamaño del subarreglo 2.
    int izq[t1], der[t2]; //Crea subarreglos.
    for (int cont = 0; cont < t1; cont++) { //Rellena subarreglo izq.
        izq[cont] = arr[ini + cont];
    }
    for (int cont2 = 0; cont2 < t2; cont2++) { //Rellena subarreglo der.
        der[cont2] = arr[med + 1 + cont2];
    }
    while (a1 < t1 && a2 < t2) { //Fusion de subarreglos.
        if (izq[a1] <= der[a2]) {
            arr[a3] = izq[a1];
            a1++;
        } else {
            arr[a3] = der[a2];
            a2++;
        }
        a3++;
    }
    while (a1 < t1) { //Copiar residuos izq.
        arr[a3] = izq[a1];
        a1++, a3++;
    }
    while (a2 < t2) { //Copiar residuos der.
        arr[a3] = der[a2];
        a2++, a3++;
    }
}

/*
//Funcion NO recursiva de Merge-Sort
void mergeSort(int arr[], int tam) {
    int med, fin, t1, t2;// Declaración.
    for (int i = 1; i < tam; i *= 2) {// Recorrido para fusionar.
        for (int ini = 0; ini < tam; ini += 2 * i) {// Recorrido para subarreglos.
            med = ini + i - 1;// Indicador de medio.
            fin = ini + 2 * i - 1;// Indicador de fin.
            if (fin >= tam) {// Ajuste para no salirse
                fin = tam - 1;// Ajuste en final.
            }
            if (med >= tam) {// Ajuste para no salirse
                break;// romper ciclo.
            }
            t1 = med - ini + 1;// Tamaño del subarreglo 1.
            t2 = fin - med;// Tamaño del subarreglo 2.
            int izq[t1], der[t2];// Crea subarreglos.
            for (int cont = 0; cont < t1; cont++) {// Rellena subarreglo izq.
                izq[cont] = arr[ini + cont];
            }
            for (int cont2 = 0; cont2 < t2; cont2++) {// Rellena subarreglo der.
                der[cont2] = arr[med + 1 + cont2];
            }
            int a1 = 0, a2 = 0, a3 = ini;// Variables de apoyo.
            while (a1 < t1 && a2 < t2) {// Fusion de subarreglos.
                if (izq[a1] <= der[a2]) {
                    arr[a3] = izq[a1];
                    a1++;
                } else {
                    arr[a3] = der[a2];
                    a2++;
                }
                a3++;
            }
            while (a1 < t1) {// Copiar residuos izq.
                arr[a3] = izq[a1];
                a1++;
                a3++;
            }
            while (a2 < t2) {// Copiar residuos der.
                arr[a3] = der[a2];
                a2++;
                a3++;
            }
        }
    }
}
*/