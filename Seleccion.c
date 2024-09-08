//Metodo de ordenamiento 1 - Selección. - cuadratico.
void ordenamiento_seleccion(int arreglo[], int tam)
{
    //Recorre el arreglo.
    for(int i=0;i<tam;i++)
    {
        //indica el elemento "mas pequeño".
        int i_menor = i;
        //Recorre el arreglo desde la posicion siguiente al mas pequeño.
        for(int j=i+1;j<tam;j++)
        {
            //Verifica si hay otro mas pequeño.
            if(arreglo[j]<arreglo[i_menor])
            {
                //Actualiza el "mas pequeño".
                i_menor = j;
            }
        }
        //Ordena en la posición que le toca.
        intercambia(&arreglo[i],&arreglo[i_menor]);
    }
}

//Funcion para intercambiar valores.
void intercambia(int *a, int *b)
{
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

