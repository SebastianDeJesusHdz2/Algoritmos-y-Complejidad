#include <stdio.h>

void menu();
int bin2 (int n, int k);

void main() {
    int opc=1;
    while(opc==1) {
        menu();
        printf("Quiere continuar 1)SI C)NO\n");
        scanf("%d",&opc);
    }
}

void menu() {
    int n, k;
    printf("Introduce el valor de n: ");
    scanf("%d", &n);
    printf("Introduce el valor de k: ");
    scanf("%d", &k);
    // Validación valores
    if (k > n || n < 0 || k < 0) {
        printf("Valores inválidos. Debe ser 0 <= k <= n.\n");
        return;
    }
    // Llamada a la función bin2 para calcular el coeficiente binomial
    int resultado = bin2(n, k);
    printf("C(%d, %d) = %d\n", n, k, resultado);
}

//Funcion para coeficiente binomial.
int bin2(int n, int k) {
    //Declaracion del arreglo.
    int B[k + 1];
    //Inicializacion en 0´s del arreglo.
    for (int i = 0; i <= k; i++) {
        B[i] = 0;
    }
    //Inicializacion en 1.
    B[0] = 1;
    //Recorrido del arreglo y asignacion de valores.
    for (int i = 1; i <= n; i++) {
        for (int j = (i < k ? i : k); j > 0; j--) {
            //Modificacion de valores.
            B[j] = B[j] + B[j - 1];
        }
    }
    //Retorno del resultado.
    return B[k];
}