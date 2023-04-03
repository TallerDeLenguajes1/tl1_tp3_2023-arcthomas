#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void cargarMatriz(int matriz[5][12])
{
    int prom = 0;
    int vMax = 0, vMin = 0;
    int anMax, anMin, mesMax, mesMin;
    srand(time(NULL));
    printf("Valores de la matriz:\n\n");
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 12; j++)
        {

            matriz[i][j] = 10000 + rand() % (50000 - 10000 + 1);
            printf("%d ",matriz[i][j]);

            if (vMax == 0) // Inicializar valor minimo y máximo con el primer valor de la matriz
            {
                vMax = matriz[i][j];
                vMin = matriz[i][j];
                anMax = i;
                anMin = i;
                mesMax = j;
                mesMin = j;
            }
            if (matriz[i][j] > vMax) // Si el valor de la celda es mayor que el maximo, el maximo adopta el valor
            {
                vMax = matriz[i][j];
                anMax = i; // Guarda el año y el mes en ambos casos
                mesMax = j;
            }
            if (matriz[i][j] < vMin) // Si el valor de la celda es menor que el minimo, el minimo adopta el valor
            {
                vMin = matriz[i][j];
                anMin = i;
                mesMin = j;
            }
            
            prom += matriz[i][j];
        }
        printf(" Promedio anual: %d", (prom / 12));
        printf("\n");
        prom = 0;
    }
    printf("\nValor maximo: %d, año: %d, mes: %d\n", vMax, (anMax + 1), (mesMax + 1));
    printf("\nValor minimo: %d, año: %d, mes: %d\n", vMin, (anMin + 1), (mesMin + 1));
}

int main()
{
    int matriz[5][12];
    cargarMatriz(matriz);
}