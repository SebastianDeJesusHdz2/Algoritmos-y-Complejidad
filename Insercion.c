//Metodo de ordenamiento 2 - Inserción. - cuadratico.
void ordenar_insercion(int arreglo[], int tam)
{
    //Recorre el arreglo desde la 2da. posición.
    for(int i=1;i<tam;i++)
    {
        //Marca el elemento.
        int j=i;
        //Ordena el elemento en el arreglo.
        while(j>0 && arreglo[j]<arreglo[j-1])
        {
            //Hace intercambios si es menor.
            intercambia(&arreglo[j],&arreglo[j-1]);
            //Cambia de posición.
            j = j - 1;
        }
    }
}

//Funcion para intercambiar valores.
void intercambia(int *a, int *b)
{
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

