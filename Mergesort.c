//Metodo de ordenamiento 3 - Merge Sort. - logaritmico.
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

