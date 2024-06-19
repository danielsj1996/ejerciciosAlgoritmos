#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef char* item;

struct Nodo {
    item dato;
    struct Nodo *siguiente;
};

struct ListaClientes {
    struct Nodo *frente;
    struct Nodo *final;
};

struct ListaClientes* crearLista() {
    struct ListaClientes *lista = (struct ListaClientes*) malloc(sizeof(struct ListaClientes));
    lista->frente = NULL;
    lista->final = NULL;
    return lista;
}

int esFilaVacia(struct ListaClientes *lista) {
    return lista->frente == NULL;
}

void llegar_cliente(struct ListaClientes *lista, const item nombre) {
    struct Nodo *nuevo = (struct Nodo*) malloc(sizeof(struct Nodo));
    nuevo->dato = (char*) malloc(strlen(nombre) + 1);
    strcpy(nuevo->dato, nombre);
    nuevo->siguiente = NULL;
    if (esFilaVacia(lista)) {
        lista->frente = lista->final = nuevo;
    } else {
        lista->final->siguiente = nuevo;
        lista->final = nuevo;
    }
}

void atender_cliente(struct ListaClientes *lista, struct ListaClientes *atendidos) {
    if (!esFilaVacia(lista)) {
        struct Nodo *atendido = lista->frente;
        lista->frente = lista->frente->siguiente;
        if (lista->frente == NULL) {
            lista->final = NULL;
        }
        atendido->siguiente = atendidos->frente;
        atendidos->frente = atendido;
    }
}

item cliente_en_espera(struct ListaClientes *lista) {
    if (!esFilaVacia(lista)) {
        return lista->frente->dato;
    }
    return "";
}

void mostrar_Clientes(struct ListaClientes *lista) {
    struct Nodo *actual = lista->frente;
    printf("\nLista de Clientes en espera: ");
    while (actual != NULL) {
        printf("%s ", actual->dato);
        actual = actual->siguiente;
    }
    printf("\n\n");
}

void reiniciarFila(struct ListaClientes *lista) {
    while (lista->frente != NULL) {
        struct Nodo *temp = lista->frente;
        lista->frente = lista->frente->siguiente;
        free(temp->dato);
        free(temp);
    }
    lista->frente = lista->final = NULL;
    printf("\n Reinicio de fila realizado con exito");
}

int main() {
    struct ListaClientes *lista_de_Espera = crearLista();
    struct ListaClientes *lista_de_Atendidos = crearLista();

    llegar_cliente(lista_de_Espera, "alberto");
    llegar_cliente(lista_de_Espera, "jose");
    llegar_cliente(lista_de_Espera, "carlos");
    llegar_cliente(lista_de_Espera, "alex");
    llegar_cliente(lista_de_Espera, "daniel");
    llegar_cliente(lista_de_Espera, "juan");
    llegar_cliente(lista_de_Espera, "ruben");
    llegar_cliente(lista_de_Espera, "pablo");
    llegar_cliente(lista_de_Espera, "miguel");

    mostrar_Clientes(lista_de_Espera);

    atender_cliente(lista_de_Espera, lista_de_Atendidos);
    atender_cliente(lista_de_Espera, lista_de_Atendidos);
    atender_cliente(lista_de_Espera, lista_de_Atendidos);
    atender_cliente(lista_de_Espera, lista_de_Atendidos);
    atender_cliente(lista_de_Espera, lista_de_Atendidos);

    mostrar_Clientes(lista_de_Espera);
    mostrar_Clientes(lista_de_Atendidos);

    printf("\nProximo cliente en la fila: %s\n", cliente_en_espera(lista_de_Espera));

    reiniciarFila(lista_de_Espera);
    reiniciarFila(lista_de_Atendidos);
    printf("\nFilas de clientes luego del reinicio de las mismas \n");
    mostrar_Clientes(lista_de_Espera);
    mostrar_Clientes(lista_de_Atendidos);

    free(lista_de_Espera);
    free(lista_de_Atendidos);

    return 0;
}