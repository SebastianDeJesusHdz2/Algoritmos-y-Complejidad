#include <stdio.h>

void torrehanoi(int n, int torigen, int tdestino, int taux);
void menu();

int movimientos = 0;

void main() {
    menu();
}

void torrehanoi(int n, int torigen, int tdestino, int taux) {
    if (n == 1) { // comprueba si la cantidad de discos es uno
        movimientos++;//cuenta el numero de movimientos.
        printf("Mover disco 1 de %d a %d\n", torigen, tdestino);
        //Indica a donde se movio el disco.
        return;//regresa.
    }
    torrehanoi(n - 1, torigen, taux, tdestino);
    //recursividad, quitando un disco. 
    movimientos++; //cuenta el numero de movimientos.
    printf("Mover disco %d de %d a %d\n", n, torigen, tdestino);
    //Indica a donde se movio el disco.
    torrehanoi(n - 1, taux, tdestino, torigen);
    //recursividad, quitando un disco.
}

void menu() {
    int n;
    printf("Ingrese el número de discos: ");
    scanf("%d", &n);
    torrehanoi(n, 1, 2, 3);
    printf("Número de discos: %d\n", n);
    printf("Número total de movimientos: %d\n", movimientos);
}