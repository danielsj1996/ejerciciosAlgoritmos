#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Nodo {
    int valor;
    struct Nodo* siguiente;
} Nodo;

typedef struct Lista {
    Nodo* cabeza;
    int tamano;
} Lista;

Lista* crearLista() {
    Lista* lista = (Lista*)malloc(sizeof(Lista));
    lista->cabeza = NULL;
    lista->tamano = 0;
    return lista;
}

bool esListaVacia(Lista* lista) {
    return lista->cabeza == NULL;
}

void mostrar(Lista* lista) {
    Nodo* actual = lista->cabeza;
    while (actual != NULL) {
        printf("%d -> ", actual->valor);
        actual = actual->siguiente;
    }
    printf("NULL\n");
}

int primerElemento(Lista* lista) {
    if (esListaVacia(lista)) {
        fprintf(stderr, "La lista está vacía\n");
        exit(EXIT_FAILURE);
    }
    return lista->cabeza->valor;
}

void insertar(Lista* lista, int valor) {
    Nodo* nuevoNodo = (Nodo*)malloc(sizeof(Nodo));
    nuevoNodo->valor = valor;
    nuevoNodo->siguiente = lista->cabeza;
    lista->cabeza = nuevoNodo;
    lista->tamano++;
}

void borrar(Lista* lista) {
    if (esListaVacia(lista)) {
        fprintf(stderr, "La lista está vacía\n");
        exit(EXIT_FAILURE);
    }
    Nodo* nodoAEliminar = lista->cabeza;
    lista->cabeza = lista->cabeza->siguiente;
    free(nodoAEliminar);
    lista->tamano--;
}

int longitud(Lista* lista) {
    return lista->tamano;
}

bool pertenece(Lista* lista, int valor) {
    Nodo* actual = lista->cabeza;
    while (actual != NULL) {
        if (actual->valor == valor) {
            return true;
        }
        actual = actual->siguiente;
    }
    return false;
}

void insertarK(Lista* lista, int valor, int k) {
    if (k <= 0 || esListaVacia(lista)) {
        insertar(lista, valor);
        return;
    }
    Nodo* actual = lista->cabeza;
    for (int i = 1; i < k - 1 && actual->siguiente != NULL; i++) {
        actual = actual->siguiente;
    }
    Nodo* nuevoNodo = (Nodo*)malloc(sizeof(Nodo));
    nuevoNodo->valor = valor;
    nuevoNodo->siguiente = actual->siguiente;
    actual->siguiente = nuevoNodo;
    lista->tamano++;
}

void liberarLista(Lista* lista) {
    while (!esListaVacia(lista)) {
        borrar(lista);
    }
    free(lista);
}

int main() {
    Lista* lista = crearLista();
    
    insertar(lista, 10);
    insertar(lista, 20);
    insertar(lista, 30);
    mostrar(lista); // 30 -> 20 -> 10 -> NULL

    printf("Primer elemento: %d\n", primerElemento(lista)); // 30
    printf("Longitud: %d\n", longitud(lista)); // 3

    borrar(lista);
    mostrar(lista); // 20 -> 10 -> NULL

    printf("Pertenece 20: %d\n", pertenece(lista, 20)); // 1 (true)
    printf("Pertenece 30: %d\n", pertenece(lista, 30)); // 0 (false)

    insertarK(lista, 25, 2);
    mostrar(lista); // 20 -> 25 -> 10 -> NULL

    insertarK(lista, 5, 5);
    mostrar(lista); // 20 -> 25 -> 10 -> 5 -> NULL

    /*Como usuario de la lista enlazada, implemente una función posiciónK que, dada una lista enlazada
de números enteros y un número natural k, retorne el valor del elemento que se encuentra en la
posición K de la lista, caso contrario retorna -9999.*/

    int k=2;
    if(k>lista->tamano){
        printf("\n-9999");
    } else{
        while (k!=1)
        {
            borrar(lista);
            k=k-1;
        }
        printf("\nEL elemento es: %d\n",primerElemento(lista));
    }

    mostrar(lista);
    liberarLista(lista);
    return 0;
}
