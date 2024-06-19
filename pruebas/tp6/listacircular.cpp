#include "listacircular.h"
#include <iostream>

ListaCircular::ListaCircular() : ultimo(nullptr) {}

ListaCircular::~ListaCircular() {
    while (!ESLCVACIA()) {
        LCBORRAR();
    }
}

void ListaCircular::LCVACIA() {
    ultimo = nullptr;
}

void ListaCircular::LCINSERTAR(int valor) {
    Nodo* nuevo = new Nodo(valor);
    if (ESLCVACIA()) {
        nuevo->siguiente = nuevo;
        ultimo = nuevo;
    } else {
        nuevo->siguiente = ultimo->siguiente;
        ultimo->siguiente = nuevo;
        ultimo = nuevo;
    }
}

void ListaCircular::LCBORRAR() {
    if (!ESLCVACIA()) {
        Nodo* temp = ultimo->siguiente;
        if (ultimo->siguiente == ultimo) {
            delete temp;
            LCVACIA();
        } else {
            ultimo->siguiente = temp->siguiente;
            delete temp;
        }
    }
}

int ListaCircular::LCVALOR() {
    if (!ESLCVACIA()) {
        return ultimo->siguiente->valor;
    }
    throw std::runtime_error("La lista está vacía");
}

bool ListaCircular::ESLCVACIA() {
    return ultimo == nullptr;
}

void ListaCircular::LCROTAR() {
    if (!ESLCVACIA()) {
        ultimo = ultimo->siguiente;
    }
}

void ListaCircular::LCUNIR(ListaCircular& otra) {
    if (otra.ESLCVACIA()) return;
    if (ESLCVACIA()) {
        ultimo = otra.ultimo;
    } else {
        Nodo* temp = ultimo->siguiente;
        ultimo->siguiente = otra.ultimo->siguiente;
        otra.ultimo->siguiente = temp;
        ultimo = otra.ultimo;
    }
    otra.LCVACIA();
}

void ListaCircular::LCROTARN(int n) {
    for (int i = 0; i < n; ++i) {
        LCROTAR();
    }
}

int ListaCircular::LCCONTARK(int k) {
    if (ESLCVACIA()) return 0;
    int count = 0;
    Nodo* current = ultimo->siguiente;
    do {
        if (current->valor == k) {
            ++count;
        }
        current = current->siguiente;
    } while (current != ultimo->siguiente);
    return count;
}