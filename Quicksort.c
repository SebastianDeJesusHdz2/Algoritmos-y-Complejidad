//Metodo de ordenamiento 3 - Quick Sort. - logaritmico.
void quicksort(int arreglo[], int izq, int der)
{
    //Verifica si el subarreglo tiene más de un elemento.
    if(izq<der)
    {
        // Realiza la partición del arreglo y obtiene el índice del pivote.
        int pivote = particion(arreglo,izq,der);
        //Ordena recursivamente la mitad izquierda del pivote.
        quicksort(arreglo,izq,pivote-1);
        //Ordena recursivamente la mitad derecha del pivote.
        quicksort(arreglo,pivote+1,der);
    }
}

// Función de partición estándar para Quick Sort.
int particion(int arreglo[], int izq, int der)
{
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

//Funcion para intercambiar valores.
void intercambia(int *a, int *b)
{
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

