#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#define STRMAX 50


char *TiposProductos[]={"Galletas","Snack","Cigarrillos","Caramelos","Bebidas"};

struct Producto {
int ProductoID; //Numerado en ciclo iterativo
int Cantidad; // entre 1 y 10
char *TipoProducto; // Algún valor del arreglo TiposProductos
float PrecioUnitario; // entre 10 - 100
}typedef Producto;

struct Cliente {
int ClienteID; // Numerado en el ciclo iterativo
char *NombreCliente; // Ingresado por usuario
int CantidadProductosAPedir; // (aleatorio entre 1 y 5)
Producto *Productos; //El tamaño de este arreglo depende de la variable
// “CantidadProductosAPedir”
}typedef Cliente;

float calcularTotal(Producto produc)
{
    return produc.Cantidad * produc.PrecioUnitario;
}

int main()
{
    srand(time(NULL));
    int rpick = rand() % 5;
    int cantCl;
    printf("Ingrese la cantidad de clientes: ");
    scanf("%d", &cantCl);
    getchar();
    Cliente **Clientes = malloc(cantCl * sizeof(Cliente *));
    for (int i = 0; i < cantCl; i++)
    {
        Clientes[i] = malloc(sizeof(Cliente));
        Clientes[i]->ClienteID = i + 1;
        Clientes[i]->NombreCliente = malloc(STRMAX * sizeof(char));
        printf("Ingrese el nombre del cliente: ");
        gets(Clientes[i]->NombreCliente);
        Clientes[i]->CantidadProductosAPedir = 1 + rand() % 5;
        Clientes[i]->Productos = malloc(Clientes[i]->CantidadProductosAPedir * sizeof(Producto));
        for (int k = 0; k < Clientes[i]->CantidadProductosAPedir; k++)
        {
            Clientes[i]->Productos[k].ProductoID = k + 1;
            Clientes[i]->Productos[k].Cantidad = 1 + rand() % 10;
            Clientes[i]->Productos[k].TipoProducto = malloc(STRMAX * sizeof(char));
            Clientes[i]->Productos[k].TipoProducto = strcpy(Clientes[i]->Productos[k].TipoProducto, TiposProductos[rpick]);
            Clientes[i]->Productos[k].PrecioUnitario = (float)(rand() % 900 + 100) / 10.0 + 10;
        }
    }
    for (int i = 0; i < cantCl; i++) // Mostrar en pantalla los datos
    {
        printf("\n-- CLIENTE --\n\n");
        printf("ID del cliente: %d\n", Clientes[i]->ClienteID);
        printf("Nombre del cliente: ");
        puts(Clientes[i]->NombreCliente);
        printf("Cantidad de productos: %d\n", Clientes[i]->CantidadProductosAPedir);
        for (int k = 0; k < Clientes[i]->CantidadProductosAPedir; k++)
        {
            printf("\n-- PRODUCTOS --\n");
            printf("ID del producto: %d\n", Clientes[i]->Productos[k].ProductoID);
            printf("Tipo de producto: ");
            puts(Clientes[i]->Productos[k].TipoProducto);
            printf("Cantidad: %d\n", Clientes[i]->Productos[k].Cantidad);
            printf("Precio unitario: %.2f\n", Clientes[i]->Productos[k].PrecioUnitario);
            printf("Total: %.2f\n\n", calcularTotal(Clientes[i]->Productos[k]));
        }
    }
    
    for (int i = 0; i < cantCl; i++)
    {
        for (int k = 0; k < Clientes[i]->CantidadProductosAPedir; k++)
        {
            free(Clientes[i]->Productos[k].TipoProducto);
        }
        free(Clientes[i]->Productos);
        free(Clientes[i]->NombreCliente);
        free(Clientes[i]);
    }
}
