#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

int location(int S[], int low, int high, int x);
void ordenar_insercion(int arreglo[], int tam);
void intercambia(int *a, int *b);
void menu();

void main() {
    menu();
}

void menu() {
    int arr[50];
    int x, rest;
    srand(time(NULL));
    for (int i = 0; i < 50; i++) {
        arr[i] = rand() % 1000 + 1;
    }
    ordenar_insercion(arr,50);
    printf("Arreglo ordenado:\n");
    for (int i = 0; i < 50; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    printf("Introduce un dato(Tiene que estar en el arreglo) :\n");
    scanf("%d", &x);
    rest = location(arr,0,49,x);
    if(rest != -1) {
        printf("Posicion : %d \n", rest+1);
    } else {
        printf("Dato no encontrado\n");
    }
}

void ordenar_insercion(int arreglo[], int tam)
{
    for(int i=1;i<tam;i++)
    {
        int j=i;
        while(j>0 && arreglo[j]<arreglo[j-1])
        {
            intercambia(&arreglo[j],&arreglo[j-1]);
            j = j - 1;
        }
    }
}

void intercambia(int *a, int *b)
{
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

int location(int S[], int low, int high, int x) { 
    int mid, mid1; //Indicadores de los tercios
    if (low > high) { // caso base
      return -1; //No lo encontro
    }  
    mid = floor(low + (high - low) / 3); //Indicador 1er tercio.
    mid1 = floor(high - (high - low) / 3); //Indicador 2do tercio.
    if (x == S[mid]) {  // Comprobacion justo en la 1ra. division.
        return mid; //Regresa posición
    }
    if(x == S[mid1]) { //Comprobacion justo en la 2da. division.
        return mid1; // Regresa posición
    } if (x < S[mid]) {  // Buscado menor al 1er. indicador.
      return location(S, low, mid - 1, x); //Llamada al 1er. tercio.
    } else if (x>S[mid] && x<S[mid1]) { //Buscado mayor al 1er. y menor al 2do. indicadores.
        return location(S, mid+1, mid1-1, x); //Llamada al 2do. tercio.
    } 
    return location(S, mid1 + 1, high, x); //Llamada al 3er. tercio.
}

