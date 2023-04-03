#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define STRMAX 50

int main()
{
    char *arreglo[5];
    for (int i = 0; i < 5; i++)
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