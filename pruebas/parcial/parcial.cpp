#include <iostream>

struct Nodo {
    int valor;
    Nodo* siguiente;

    Nodo(int val) : valor(val), siguiente(nullptr) {}
};

class Misterio {
private:
    Nodo* cabeza;
    int tamano;

public:
    Misterio() : cabeza(nullptr), tamano(0) {}

    bool esListaVacia() {
        return cabeza == nullptr;
    }

    void insertar(int valor) {
        Nodo* nuevoNodo = new Nodo(valor);

        if (esListaVacia()) {
            cabeza = nuevoNodo;
            cabeza->siguiente = cabeza; // Lista circular con un solo elemento
        } else {
            Nodo* actual = cabeza;
            while (actual->siguiente != cabeza) {
                actual = actual->siguiente;
            }
            actual->siguiente = nuevoNodo;
            nuevoNodo->siguiente = cabeza; // Nuevo nodo apunta de regreso a la cabeza
        }
        tamano++;
    }

    void mostrar() {
        if (esListaVacia()) {
            std::cout << "Lista vacía" << std::endl;
            return;
        }
        Nodo* actual = cabeza;
        do {
            std::cout << actual->valor << " -> ";
            actual = actual->siguiente;
        } while (actual != cabeza);
        std::cout << "NULL" << std::endl;
    }
};

int main() {
    Misterio lista;

    // Insertar elementos en la lista
    lista.insertar(10);
    lista.insertar(20);
    lista.insertar(30);
    lista.insertar(40);
    lista.insertar(50);
    lista.insertar(60);

    // Mostrar la lista
    lista.mostrar(); // Debería mostrar: 10 -> 20 -> 30 -> 40 -> 50 -> 60 -> NULL

    return 0;
}