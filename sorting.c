/************************************
CURSO: Algoritmos y Complejidad
Tarea 3 - Algoritmos de Ordenamiento
*************************************/

// Librerías
#include <time.h>
#include <stdio.h>
#include <stdlib.h>

// Tamaño total del arreglo
// Debes cambiar el valor de N para los experimentos de acuerdo con la descripción (ver PDF)
#define N 100000

// Declaración de funciones
// Funciones para el arreglo
void createArray(int array[N]);
void printArray(int array[N]);

// Declaración de tus funciones de ordenamiento
// Por ejemplo: void bubbleSort(int array[N]);


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
    // ADVERTENCIA: Sólo imprimir el arreglo para propósitos de prueba y si N es pequeño
    // printf("\n\nARREGLO DESORDENADO:\n");
    // printArray(arr);

    // Registrar el tiempo inicial
    t_ini = clock();
    printf("\n\nTiempo inicial: %f", ((double)t_ini));

    // Iniciar el algoritmo de ordenamiento
    // Por ejemplo: bubbleSort(arr);

    // Registrar el tiempo final y calcular el tiempo transcurrido
    t_end = clock() - t_ini;
    printf("\nTiempo final: %f", ((double)t_end));
    t_elapsed = ((double)t_end)/CLOCKS_PER_SEC;
    printf("\nTiempo total: %f segs", t_elapsed);

    // ADVERTENCIA: Sólo imprimir el arreglo para propósitos de prueba y si N es pequeño
    // printf("\n\nARREGLO ORDENADO:\n");
    // printArray(arr);

    return 0;
}

// AÑADE AQUÍ TUS MÉTODOS DE ORDENAMIENTO

// Imprime un arreglo de tamaño N
void printArray(int array[N])
{
    int i;

    printf("\n\n");
    for (i = 0; i < N; i++)
    {
        printf("%d, ", array[i]);
    }
}

// Llena un arreglo existente con valores aleatorios
void createArray(int array[N])
{
    int i;
    time_t t;

    srand((unsigned) time(&t));

    for (i = 0; i < N; i++)
    {
        // NOTA: Si N es grande, intenta usar números grandes en el arreglo
        // de lo contrario, el arreglo contendrá muchos elementos repetidos
        array[i] = rand() % 1000000;
    }
}