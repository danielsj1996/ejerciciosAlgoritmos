#include "fila.h"

// Constructor
Fila::Fila() : frente(nullptr), final(nullptr), longitud(0) {}

// Destructor
Fila::~Fila() {
    while (!esFilaVacia()) {
        deFila();
    }
}

// Verificar si la fila es vacía
bool Fila::esFilaVacia() {
    return frente == nullptr;
}

// Mostrar el frente de la fila
int Fila::frenteFila() {
    if (!esFilaVacia()) {
        return frente->data;
    }
    throw std::runtime_error("La fila está vacía");
}

// Ingresar un item a la fila
void Fila::enFila(int item) {
    Nodo* nuevoNodo = new Nodo{item, nullptr};
    if (esFilaVacia()) {
        frente = nuevoNodo;
    } else {
        final->next = nuevoNodo;
    }
    final = nuevoNodo;
    longitud++;
}

// Eliminar un elemento de la fila y devolver la fila modificada
void Fila::deFila() {
    if (!esFilaVacia()) {
        Nodo* temp = frente;
        frente = frente->next;
        delete temp;
        longitud--;
        if (esFilaVacia()) {
            final = nullptr;
        }
    } else {
        throw std::runtime_error("La fila está vacía");
    }
}

// Devolver el largo de la fila
int Fila::getLongitud() {
    return longitud;
}

// Verificar si el item ingresado pertenece a la fila
bool Fila::pertenece(int item) {
    Nodo* actual = frente;
    while (actual != nullptr) {
        if (actual->data == item) {
            return true;
        }
        actual = actual->next;
    }
    return false;
}

// Verificar si dos filas son iguales
bool Fila::igualF(Fila& otraFila) {
    if (longitud != otraFila.getLongitud()) {
        return false;
    }
    Nodo* actual1 = frente;
    Nodo* actual2 = otraFila.frente;
    while (actual1 != nullptr) {
        if (actual1->data != actual2->data) {
            return false;
        }
        actual1 = actual1->next;
        actual2 = actual2->next;
    }
    return true;
}

// Concatenar dos filas
Fila Fila::concat(Fila& otraFila) {
    Fila nuevaFila;
    Nodo* actual = frente;
    while (actual != nullptr) {
        nuevaFila.enFila(actual->data);
        actual = actual->next;
    }
    actual = otraFila.frente;
    while (actual != nullptr) {
        nuevaFila.enFila(actual->data);
        actual = actual->next;
    }
    return nuevaFila;
}

// Invertir una fila utilizando una pila auxiliar
Fila Fila::invertir() {
    Fila nuevaFila;
    std::stack<int> pila;
    Nodo* actual = frente;
    while (actual != nullptr) {
        pila.push(actual->data);
        actual = actual->next;
    }
    while (!pila.empty()) {
        nuevaFila.enFila(pila.top());
        pila.pop();
    }
    return nuevaFila;
}

// Función recursiva para mezclar dos filas ordenadas
Fila Fila::mezclar(Fila& fila1, Fila& fila2) {
    Fila resultado;
    Nodo* actual1 = fila1.frente;
    Nodo* actual2 = fila2.frente;
    while (actual1 != nullptr && actual2 != nullptr) {
        if (actual1->data < actual2->data) {
            resultado.enFila(actual1->data);
            actual1 = actual1->next;
        } else {
            resultado.enFila(actual2->data);
            actual2 = actual2->next;
        }
    }
    while (actual1 != nullptr) {
        resultado.enFila(actual1->data);
        actual1 = actual1->next;
    }
    while (actual2 != nullptr) {
        resultado.enFila(actual2->data);
        actual2 = actual2->next;
    }
    return resultado;
}

// Mostrar los elementos de la fila
void Fila::mostrarFila() {
    Nodo* actual = frente;
    while (actual != nullptr) {
        std::cout << actual->data << " ";
        actual = actual->next;
    }
    std::cout << std::endl;
}