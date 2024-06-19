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

int posicionKRecursiva(Nodo* nodo, int k) {
    if (k == 0) {
        return nodo->valor;
    }
    if (nodo->siguiente == NULL) {
        return -9999;
    }
    return posicionKRecursiva(nodo->siguiente, k - 1);
}

// Función que llama a la versión recursiva
int posicionK(Lista* lista, int k) {
    if (k < 0 || k >= lista->tamano) {
        return -9999;
    }
    return posicionKRecursiva(lista->cabeza, k);
}

/*Como usuario de la lista enlazada implemente una función recursiva estaContenida que,
dadas dos listas enlazadas de números enteros, retorne verdadero si todos los elementos
de la primera lista se encuentran presentes en la segunda, caso contrario retorna falso.*/
bool estaContenidaRecursiva (Nodo* actual,Lista* l2){
    if(actual==NULL){
        return true;
    } else{
        if(!pertenece(l2,actual->valor)){
            return false;
        }else {
           return estaContenidaRecursiva(actual->siguiente,l2);
        }
    }
}


bool estaContenida (Lista* l1,Lista* l2){
    Nodo* actual = l1->cabeza;
    if(esListaVacia(l1)){
        return false;
    } else {
        if(esListaVacia(l2)){
            return false;
        } else {
            return estaContenidaRecursiva(actual,l2);
        }
    }
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

    
    printf("\nElemento que buscaba %d\n",posicionK(lista,2));
    mostrar(lista);

    Lista* lista2 = crearLista();
    insertar(lista2, 7);
    insertar(lista2, 80);
    insertar(lista2, 30);

    Lista* lista3 = crearLista();
    insertar(lista3, 100);
    insertar(lista3, 20);
    insertar(lista3, 60);
    insertar(lista3, 10);
    insertar(lista3, 5);
    insertar(lista3, 25);

    Lista* lista4 = crearLista();

    mostrar(lista);
    mostrar(lista2);
    mostrar(lista3);
    mostrar(lista4);

    if (estaContenida(lista,lista2))
    {
        printf("\nEsta Contenida L1 en L2");
    }else{
        printf("\nNo esta Contenida L1 en L2");
    }

    if (estaContenida(lista,lista3))
    {
        printf("\nEsta Contenida L1 en L3");
    }else{
        printf("\nNo esta Contenida L1 en L3");
    }

    if (estaContenida(lista,lista4))
    {
        printf("\nEsta Contenida L1 en L4");
    }else{
        printf("\nNo esta Contenida L1 en L4");
    }

    liberarLista(lista);
    liberarLista(lista2);
    liberarLista(lista3);
    liberarLista(lista4);
    return 0;
}
