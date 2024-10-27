#include <stdio.h>
#include <string.h>

void menu();
void palindromoMasLargo(char *cadena);

void main() {
    menu();
}

void menu() {
    char cadena[100];
    printf("Introduce una cadena: ");
    scanf("%s", cadena);
    palindromoMasLargo(cadena);
}

void palindromoMasLargo(char *cadena) {
    //Inicializacion de datos.
    int n = strlen(cadena);
    int inicio = 0, maxLongitud = 1;
    //Matriz con cadenas para definir palindromos.
    int dp[n][n];
    memset(dp, 0, sizeof(dp));
    //Caso base: Palindromos de 1 caracter.
    for (int i = 0; i < n; i++)
        dp[i][i] = 1;
    //Recorrido de cadenas de longitud 2.
    for (int i = 0; i < n - 1; i++) {
        //Si los 2 caracteres son iguales
        if (cadena[i] == cadena[i + 1]) {
            //Actualiza palindromos.
            dp[i][i + 1] = 1;
            inicio = i;
            maxLongitud = 2;
        }
    }
    //Recorrido de cadenas mayores a longitud 2.
    for (int longitud = 3; longitud <= n; longitud++) {
        for (int i = 0; i < n - longitud + 1; i++) {
            int j = i + longitud - 1;
            //Si se le igual.
            if (cadena[i] == cadena[j] && dp[i + 1][j - 1]) {
                //Actualiza palindromos validos.
                dp[i][j] = 1;
                inicio = i;
                maxLongitud = longitud;
            }
        }
    }
    printf("El palíndromo más largo es: ");
    //Recorrido para imprimir el palindromo mas largo.
    for (int i = inicio; i < inicio + maxLongitud; i++) {
        printf("%c", cadena[i]);
    }
    printf("\n");
}
