#include <stdio.h>
#include <stdlib.h>
#include <time.h>

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
    printf("Posicion : %d \n", rest+1);
}

int location(int S[], int low, int high, int x) {
    int mid = (low + high) / 2; //Establece la mitad.
    if (x == S[mid]) { //verifica si el buscado esta en la mitad.
        return mid; // regresa posicion del buscado.
    }
    if (x < S[mid]) { //si el buscado es menor al elemento en la mitad.
        return location(S, low, mid - 1, x); //busca en el subarreglo izq.
    }
    return location(S, mid + 1, high, x); // busca en el subarreglo der.
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

int location2(int S[], int low, int high, int x) { 
   int mid; 
   if (low > high) { 
      return -1; 
   } 
      mid = (low + high) / 2; 
   if (x == S[mid]) { 
      return mid; 
   } 
   if (x < S[mid]) { 
      return location(S, low, mid - 1, x); 
   } 
   return location(S, mid + 1, high, x); 
}

