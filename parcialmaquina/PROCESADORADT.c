#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "Procesador.h"

Procesador INACTIVO() {
    Procesador procesador;
    procesador.cantidad = 0;
    procesador.primera = NULL;
    procesador.ultima = NULL;
    return procesador;
}

bool ESTAINACTIVO(Procesador p) {
    if (p.primera == NULL && p.ultima == NULL) {
        return true;
    } else {
        return false;
    }
}

Procesador AGREGAR(Procesador P, aplicacion a) {
    struct nodo *nuevo;
    nuevo = (struct nodo *)malloc(sizeof(struct nodo *));
    nuevo->siguiente = NULL;
    nuevo->tiempo = a;
    // printf("%d", nuevo->tiempo);
    if (ESTAINACTIVO(P)) {
        P.primera = nuevo;
        P.ultima = nuevo;
        P.cantidad++;

        return P;
    } else {
        P.cantidad++;
        P.ultima->siguiente = nuevo;
        P.ultima->siguiente = NULL;
    }
    return P;
}

aplicacion SIGUIENTE(Procesador P) {
    if (ESTAINACTIVO(P)) {
        return printf("%d error", -9999);
    }

    if (ESTAINACTIVO(P)) {
        return P.primera->siguiente->tiempo;
    } else {
        return SIGUIENTE(P);
    }
}

Procesador OTORGAR(Procesador P) {
    if (ESTAINACTIVO(P)) {
        return INACTIVO();
    } else {
        P = AGREGAR(P, 1);
        return P;
    }
}

aplicacion ULTIMA(Procesador P) {
    if (ESTAINACTIVO(P)) {
        printf("%d error", -9999);
    } else {
        return P.ultima->tiempo;
    }
}

int CANTIDAD(Procesador P) {
    if (ESTAINACTIVO(P)) {
        return 0;
    } else {
        return P.cantidad;
    }
}

int atendio(Procesador P, aplicacion tiempoX, int cant) {
    nodo *aux;
    aux = P.primera;
    if (tiempoX >= P.primera->tiempo) {
        P.primera = P.primera->siguiente;
        free(aux);
        tiempoX -= P.primera->tiempo;
        cant++;
        return atendio(P, tiempoX, cant);
    } else {
        return cant;
    }
}