#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define STRMAX 50

int main()
{
    int cantidad;
    printf("Ingrese una cantidad para ingresar: ");
    scanf("%d", &cantidad);
    char *arreglo[cantidad];
    for (int i = 0; i < cantidad; i++)
    {
        arreglo[i] = (char*) malloc(STRMAX * sizeof(char*));
        printf("Ingrese un nombre: ");
        fflush(stdin);
        gets(arreglo[i]);
        printf("Nombre ingresado: ");
        puts(arreglo[i]);
        printf("\n");
        free(arreglo[i]);
    }
    
}