#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
typedef int item;

typedef struct Nodo
{
    item dato;
    struct Nodo *siguiente;
} Nodo;

typedef Nodo *Lista;

Nodo *crearLista();
int esListaVacia(Nodo *);
void mostrarLista(Nodo *Lista);
Nodo *insertarNodo(Nodo *Lista, int dato);
void primerElemento(Nodo *Lista);
int longitudLista(Nodo *Lista);
int pertenece(Nodo *Lista, int dato);
Nodo *borrarNodoInicio(Nodo *Lista);
Nodo *BorrarUltimoNodo(Nodo *Lista);
int iguales(Nodo *Lista, Nodo *Lista2);

int main()
{
    Nodo *Lista = crearLista();
    Nodo *Lista2 = crearLista();

    int cant, pert;

    mostrarLista(Lista);

    Lista = insertarNodo(Lista, 6);
    Lista = insertarNodo(Lista, 5);
    Lista = insertarNodo(Lista, 7);
    Lista = insertarNodo(Lista, 4);
    Lista = insertarNodo(Lista, 2);

    Lista2 = insertarNodo(Lista2, 6);
    Lista2 = insertarNodo(Lista2, 5);
    Lista2 = insertarNodo(Lista2, 7);
    Lista2 = insertarNodo(Lista2, 4);
    Lista2 = insertarNodo(Lista2, 2);

    mostrarLista(Lista);
    mostrarLista(Lista2);

    primerElemento(Lista);

    cant = longitudLista(Lista);
    printf("\nla cantidad de nodos que hay en la lista es: %d\n", cant);

    pert = pertenece(Lista, 5);

    pert = pertenece(Lista, 9);

    if (iguales(Lista, Lista2))
    {
        printf("\nLas Listas son iguales\n");
    }
    else
    {
        printf("\nLas Listas no son iguales\n");
    }

    Lista = borrarNodoInicio(Lista);
    mostrarLista(Lista);

    Lista2 = BorrarUltimoNodo(Lista2);
    mostrarLista(Lista2);

    if (iguales(Lista, Lista2))
    {
        printf("Las Listas son iguales\n");
    }
    else
    {
        printf("Las Listas no son iguales\n");
    }
    return 0;
}

Nodo *crearLista()
{
    return NULL;
}

int esListaVacia(Nodo *Lista)
{
    return Lista == NULL;
}

Nodo *insertarNodo(Nodo *Lista, item dato)
{

    Nodo *nuevo = (Nodo *)malloc(sizeof(Nodo));
    nuevo->dato = dato;
    nuevo->siguiente = Lista;
    Lista = nuevo;
    printf("Nuevo nodo Insertado\n");
    return Lista;
}

void mostrarLista(Nodo *Lista)
{
    while (esListaVacia(Lista) != true)
    {
        printf("\t%d\t", Lista->dato);
        Lista = Lista->siguiente;
    }
    printf("\n\n");
}

void primerElemento(Nodo *Lista)
{
    if (esListaVacia(Lista) == true)
    {
        printf("La lista se encuentra Vacia");
    }
    else
    {
        printf("\nEl Primer elemento de la lista es: %d\n", Lista->dato);
    }
}

Nodo *borrarNodoInicio(Nodo *Lista)
{
    if (esListaVacia(Lista))
    {
        printf("---La lista esta vacia\n");
        return Lista;
    }
    else
    {
        Nodo *aux = Lista;
        Lista = Lista->siguiente;
        free(aux);
        printf("\n Nodo Eliminado Correctamente \n");
        return Lista;
    }
}
int longitudLista(Nodo *Lista)
{
    int contador = 0;
    if (esListaVacia(Lista) == 0)
    {
        while (esListaVacia(Lista) != 1)
        {
            contador++;
            Lista = Lista->siguiente;
        }
    }
    return contador;
}

int pertenece(Nodo *Lista, item i)
{
    if (esListaVacia(Lista) == true)
    {
        printf("\nLista Vacia");
    }
    else
    {
        while (esListaVacia(Lista) != true)
        {
            if (i == Lista->dato)
            {
                printf("\nEl Nro %d pertenece a la lista \n", i);
                return 0;
            }
            Lista = Lista->siguiente;
        }
        printf("\nEl Nro %d No pertenece a la lista\n", i);
    }
}

Nodo *BorrarUltimoNodo(Nodo *Lista)
{

    if (esListaVacia(Lista) == true)
    {
        printf("La Lista se encuentra vacía");
        return Lista;
    }
    else if (Lista->siguiente == NULL)
    {
        free(Lista);
        printf("El ultimo nodo ha sido eliminado correctamente\n");
        return NULL;
    }
    else
    {

        Nodo *actual = Lista;
        while (actual->siguiente->siguiente != NULL)
        {
            actual = actual->siguiente;
        }
        Nodo *borrar = actual->siguiente;
        actual->siguiente = NULL;
        free(borrar);
        printf("El ultimo nodo ha sido eliminado correctamente\n");
        return Lista;
    }
}

// Función para saber si son iguales
int iguales(Nodo *Lista, Nodo *Lista2)
{
    while (Lista != NULL && Lista2 != NULL)
    { // mientras que ambas listas estan vacias siga recorriendo
        if (Lista->dato != Lista2->dato)
        { // pregunto si los valor de las listas son distintos retorna 0 para decir que no son iguales
            return 0;
        }
        // muevo los punteros de ambas listas al siguiente valor
        Lista = Lista->siguiente;
        Lista2 = Lista2->siguiente;
    }
    return (Lista == NULL && Lista2 == NULL); // retorno si ambas listas llegaron al final
}


