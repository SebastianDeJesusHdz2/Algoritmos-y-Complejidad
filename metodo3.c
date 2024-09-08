/************************************
CURSO: Algoritmos y Complejidad
Tarea 3 - Algoritmos de Ordenamiento
Hernández Hernández Sebastian de Jesús.
*************************************/

// Librerías
#include <time.h>
#include <stdio.h>
#include <stdlib.h>

// Tamaño total del arreglo
// Debes cambiar el valor de N para los experimentos de acuerdo con la descripción (ver PDF)
#define N 10 // Cambiado a 10 para pruebas visuales

// Declaración de funciones
// Funciones para el arreglo
void createArray(int array[N]);
void printArray(int array[N]);

// Declaración de funciones de ordenamiento
void mergeSort(int arreglo[], int inicio, int fin);
void fusionar(int arreglo[], int inicio, int medio, int fin);

// Función principal donde se llama al algoritmo de ordenamiento
int main()
{
    // El arreglo es estático para que el compilador pueda almacenarlo de antemano en la memoria
    static int arr[N];
    // Variables para medir el tiempo
    clock_t t_ini, t_end;
    double t_elapsed;

    // Crear el arreglo con elementos aleatorios
    createArray(arr);
    // Imprimir el arreglo desordenado para verificación
    printf("\n\nARREGLO DESORDENADO:\n");
    printArray(arr);

    // Registrar el tiempo inicial
    t_ini = clock();

    // Iniciar el algoritmo de ordenamiento
    mergeSort(arr, 0,N-1);

    // Registrar el tiempo final y calcular el tiempo transcurrido
    t_end = clock();
    t_elapsed = ((double)(t_end - t_ini)) / CLOCKS_PER_SEC;
    
    // Imprimir el tiempo de ejecución
    printf("\nTiempo total: %f segs", t_elapsed);
    
    // Imprimir el arreglo ordenado para verificación
    printf("\n\nARREGLO ORDENADO:\n");
    printArray(arr);

    return 0;
}

//Método de ordenamiento por merge sort - logarítmico
void mergeSort(int arreglo[], int inicio, int fin) {
    if (inicio < fin) {
        //Encontrar el punto medio del arreglo.
        int medio = inicio + (fin - inicio) / 2;
        //Ordenar recursivamente las dos mitades.
        mergeSort(arreglo, inicio, medio);
        mergeSort(arreglo, medio + 1, fin);
        //Fusionar las mitades ordenadas.
        fusionar(arreglo, inicio, medio, fin);
    }
}

//Función auxiliar para fusionar dos subarreglos ordenados.
void fusionar(int arreglo[], int inicio, int medio, int fin) {
    int n1 = medio - inicio + 1;
    int n2 = fin - medio;
    //Crear arreglos temporales.
    int izq[n1], der[n2];
    //Copiar los datos a los arreglos temporales.
    for (int i = 0; i < n1; i++)
        izq[i] = arreglo[inicio + i];
    for (int j = 0; j < n2; j++)
        der[j] = arreglo[medio + 1 + j];
    //Fusionar los arreglos temporales de vuelta en arreglo.
    int i = 0, j = 0, k = inicio;
    while (i < n1 && j < n2) {
        if (izq[i] <= der[j]) {
            arreglo[k] = izq[i];
            i++;
        } else {
            arreglo[k] = der[j];
            j++;
        }
        k++;
    }
    //Copiar los elementos restantes de izq[], si los hay
    while (i < n1) {
        arreglo[k] = izq[i];
        i++;
        k++;
    }
    //Copiar los elementos restantes de der[], si los hay
    while (j < n2) {
        arreglo[k] = der[j];
        j++;
        k++;
    }
}

//Imprime un arreglo de tamaño N
void printArray(int array[N])
{
    for (int i = 0; i < N; i++)
    {
        printf("%d, ", array[i]);
    }
    printf("\n");
}

// Llena un arreglo existente con valores aleatorios
void createArray(int array[N])
{
    int i;
    time_t t;

    srand((unsigned)time(&t));

    for (i = 0; i < N; i++)
    {
        // Nota: Para pruebas, valores más pequeños permiten visualizar mejor los resultados
        array[i] = rand() % 100;
    }
}
