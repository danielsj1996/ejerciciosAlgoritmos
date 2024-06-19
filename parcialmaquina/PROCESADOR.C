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
    return (p.primera == NULL && p.ultima == NULL);
}

Procesador AGREGAR(Procesador P, aplicacion a) {
    struct nodo *nuevo;
    nuevo = (struct nodo *)malloc(sizeof(struct nodo *));
    nuevo->tiempo = a;
    nuevo->siguiente = NULL;
    if (ESTAINACTIVO(P)) {
        P.primera = nuevo;
        P.ultima = nuevo;
    } else {
        P.ultima->siguiente = nuevo;
        P.ultima = nuevo;
    }

    P.cantidad++;
    return P;
}

aplicacion SIGUIENTE(Procesador P) {
    if (ESTAINACTIVO(P)) {
        printf("%d error", -9999);
        return -9999;
    }
    return P.primera->siguiente->tiempo;
}

Procesador OTORGAR(Procesador P) {
    if (ESTAINACTIVO(P)) {
        return INACTIVO();
    } else {
        nodo *aux = P.primera;
        P.primera = P.primera->siguiente;
        free(aux);
        P.cantidad--;
        return P;
    }
}

aplicacion ULTIMA(Procesador P) {
    if (ESTAINACTIVO(P)) {
        printf("%d error", -9999);
        return -9999;
    } else {
        return P.ultima->tiempo;
    }
}

int CANTIDAD(Procesador P) {
    return P.cantidad;
}

int atendio(Procesador P, aplicacion tiempoX, int cant) {
    if (P.primera == NULL || tiempoX < P.primera->tiempo) {
        return cant;
    }

    tiempoX -= P.primera->tiempo;
    cant++;
    P = OTORGAR(P);
    return atendio(P, tiempoX, cant);
}

Resultado atendio(Procesador P, aplicacion tiempoX, int cantAtendidas, int cantNoAtendidas) {
    if (P.primera == NULL) {
        Resultado resultado;
        resultado.cantAtendidas = cantAtendidas;
        resultado.cantNoAtendidas = cantNoAtendidas + P.cantidad;
        return resultado;
    }

    if (tiempoX >= P.primera->tiempo) {
        tiempoX -= P.primera->tiempo;
        cantAtendidas++;
        P = OTORGAR(P);
    } else {
        cantNoAtendidas++;
    }

    return atendio(P, tiempoX, cantAtendidas, cantNoAtendidas);
}
int main(int argc, char const *argv[]) {
    Procesador P;
    aplicacion a;
    P = INACTIVO();
    if (ESTAINACTIVO(P)) {
        printf("\n Esta vacio");
    } else {
        printf("\n No Esta vacio");
    }

    P = AGREGAR(P, 1);
    P = AGREGAR(P, 2);
    P = AGREGAR(P, 3);
    P = AGREGAR(P, 5);
    P = AGREGAR(P, 4);

    printf("\nEl primero es: %d y el siguiente es %d: ", P.primera->tiempo, SIGUIENTE(P));
    printf("\nEl ultimo es: %d", ULTIMA(P));
    printf("\nLa cantidad es: %d", CANTIDAD(P));
    printf("\nLa cantidad de aplicaciones que proceso en 10 minutos es: %d", atendio(P, 1, 0));

    Resultado resultado = atendio(P, 10, 0, 0);
    printf("\nCantidad de aplicaciones atendidas: %d", resultado.cantAtendidas);
    printf("\nCantidad de aplicaciones no atendidas: %d", resultado.cantNoAtendidas);

    return 0;
}
