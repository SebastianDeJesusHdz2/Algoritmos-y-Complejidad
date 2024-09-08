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
void quicksort(int arreglo[], int izq, int der);
int particion(int arreglo[], int izq, int der);
void intercambia(int *a, int *b);

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
    quicksort(arr, 0,N-1);

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

//Método de ordenamiento por quick sort - logarítmico
void quicksort(int arreglo[], int izq, int der) {
    //Verifica si el subarreglo tiene más de un elemento.
    if(izq<der) {
        //Realiza la partición del arreglo y obtiene el índice del pivote.
        int pivote = particion(arreglo,izq,der);
        //Ordena recursivamente la mitad izquierda del pivote.
        quicksort(arreglo,izq,pivote-1);
        //Ordena recursivamente la mitad derecha del pivote.
        quicksort(arreglo,pivote+1,der);
    }
}

//Función de partición estándar para Quick Sort.
int particion(int arreglo[], int izq, int der) {
    //Selecciona el último elemento como pivote.
    int pivote = arreglo[der];
    //Inicializa el índice del menor elemento en el subarreglo.
    int i = izq - 1; 
    //Recorre el subarreglo desde el índice izquierdo hasta el penúltimo.
    for (int j = izq; j <= der - 1; j++) {
        //Si el elemento actual es menor o igual que el pivote.
        if (arreglo[j] <= pivote) {
            //Incrementa el índice del menor elemento.
            i++;
            //Realiza el intercambio de elementos.
            intercambia(&arreglo[i], &arreglo[j]);
        }
    }
    //Intercambia el pivote con el elemento en la posición de menor índice + 1.
    intercambia(&arreglo[i + 1], &arreglo[der]);
    //Devuelve el índice del pivote en su posición final.
    return (i + 1);
}

//Función para intercambiar valores
void intercambia(int *a, int *b) {
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

// Imprime un arreglo de tamaño N
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
