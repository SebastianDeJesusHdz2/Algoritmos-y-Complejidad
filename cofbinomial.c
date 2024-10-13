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
int bin2 (int n, int k) {
    int B[n + 1][k + 1];
    for (int i=0;i<=n;i++) {
        for (int j=0;j<=(i < k ? i : k);j++) {
            if (j==0 || j==i) {
                B[i][j]=1;
            } else {
                B[i][j]=B[i-1][j-1]+B[i-1][j];
            }
        }
    }
    return B[n][k];
}