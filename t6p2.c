#include <time.h>
#include <stdio.h>
#include <stdlib.h>

void menu();
int bin2_DP (int n, int k);
int bin2_DC (int n, int k);

void main() {
    int opc=1;
    while(opc==1) {
        menu();
        printf("Quiere continuar 1)SI C)NO\n");
        scanf("%d",&opc);
    }
}

void menu() {
    clock_t t_ini, t_end;
    double t_elapsed;
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

    printf("Resultado de Divide y Venceras:");
    t_ini = clock();
    int rest = bin2_DC(n, k);
    t_end = clock() - t_ini;
    t_elapsed = ((double)t_end)/CLOCKS_PER_SEC;
    printf("\nTiempo total: %f segs\n", t_elapsed);
    printf("C(%d, %d) = %d\n", n, k, rest);

    printf("\nResultado de Programacion Dinamica:");
    t_ini = clock();
    rest = bin2_DP(n, k);
    t_end = clock() - t_ini;
    t_elapsed = ((double)t_end)/CLOCKS_PER_SEC;
    printf("\nTiempo total: %f segs\n", t_elapsed);
    printf("C(%d, %d) = %d\n", n, k, rest);
}

//Funcion para coeficiente binomial Programación Dinamica.
int bin2_DP (int n, int k) {
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

//Funcion para coeficiente Divide y Venceras.
int bin2_DC(int n, int k) {
    // Casos base
    if (k == 0 || k == n) {
        return 1;
    }
    // Llamadas recursivas para dividir el problema
    return bin2_DC(n - 1, k - 1) + bin2_DC(n - 1, k);
}