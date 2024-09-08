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
void ordenamiento_seleccion(int arreglo[], int tam);
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
    ordenamiento_seleccion(arr, N);

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

//Método de ordenamiento por selección - cuadrático
void ordenamiento_seleccion(int arreglo[], int tam) {
    //Recorre el arreglo.
    for(int i=0;i<tam;i++) {
        //indica el elemento "mas pequeño".
        int i_menor = i;
        //Recorre el arreglo desde la posicion siguiente al mas pequeño.
        for(int j=i+1;j<tam;j++) {
            //Verifica si hay otro mas pequeño.
            if(arreglo[j]<arreglo[i_menor]) {
                //Actualiza el "mas pequeño".
                i_menor = j;
            }
        }
        //Ordena en la posición que le toca.
        intercambia(&arreglo[i],&arreglo[i_menor]);
    }
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
