

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
typedef int item;
const int INDEFINIDO = -9999;
struct nodo {
    item direccion;
    struct nodo *sig;
};

typedef struct CALLSTACK {
    struct nodo *tope;
    int altura;

} cStack;

cStack VACIO() {
    cStack c;
    c.tope = NULL;
    c.altura = 0;
    return c;
}
bool ESTAVACIO(cStack c) {
    if (c.altura == 0) {
        return true;
    } else {
        return false;
    }
}
cStack AGREGAR(cStack c, item direccion) {
    struct nodo *nuevoNodo = (struct nodo *)malloc(sizeof(struct nodo *));
    nuevoNodo->direccion = direccion;
    nuevoNodo->sig = c.tope;
    c.tope = nuevoNodo;
    c.altura++;
    return c;
}

item ULTIMA(cStack c) {
    if (ESTAVACIO(c)) {
        printf("Error %d\n", INDEFINIDO);
        return INDEFINIDO;
    } else {
        return c.tope->direccion;
    }
}

cStack ELIMINAR(cStack c) {
    if (ESTAVACIO(c)) {
        printf("Error %d", INDEFINIDO);
    } else {
        struct nodo *cAux = c.tope;
        c.tope = c.tope->sig;
        free(cAux);
        c.altura--;
    }
    return c;
}

item PRIMERA(cStack c) {
    if (ESTAVACIO(c)) {
        printf("Error %d\n", INDEFINIDO);
        return INDEFINIDO;
    } else {
        if (c.tope->sig == NULL) {
            return c.tope->direccion;
        } else {
            cStack cAux = ELIMINAR(c);
            return PRIMERA(cAux);
        }
    }
}
item CANTIDAD(cStack c) {
    return c.altura;
}
bool pertenece(cStack c, item direccion) {
    cStack aux;
    aux = c;
    if (c.tope->direccion == direccion) {
        return true;
    } else {
        aux = ELIMINAR(aux);
        if (ULTIMA(aux) == direccion) {
            return true;
        } else {
            return pertenece(aux, direccion);
        }
        return false;
    }
}
int main(int argc, char const *argv[]) {
    cStack stack;
    stack = VACIO();

    if (ESTAVACIO(stack)) {
        printf("esta vacio\n");
    } else {
        printf("no esta vacio\n");
    }

    stack = AGREGAR(stack, 1);
    stack = AGREGAR(stack, 2);
    stack = AGREGAR(stack, 3);

    if (ESTAVACIO(stack)) {
        printf("esta vacio\n");
    } else {
        printf("no esta vacio\n");
    }
    printf("Ultima ingresada %d\n", ULTIMA(stack));
    printf("Eliminar ultima ingresada\n");
    stack = ELIMINAR(stack);
    printf("Ultima ingresada %d\n", ULTIMA(stack));
    printf("primera ingresada %d\n", PRIMERA(stack));
    printf("cantidad ingresada%d\n", CANTIDAD(stack));
    printf("la subrutina 1 se encuentra almacenada?\n ");
    if (pertenece(stack, 1)) {
        printf("si\n");
    } else {
        printf("no\n");
    }
    printf("la subrutina 7 se encuentra almacenada?\n ");
    if (pertenece(stack, 7)) {
        printf("si\n");
    } else {
        printf("no\n");
    }
    return 0;
}
