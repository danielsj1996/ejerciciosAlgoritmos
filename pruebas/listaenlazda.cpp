#include <iostream>

struct Nodo {
    int valor;
    Nodo* siguiente;
};

class Lista {
private:
    Nodo* cabeza;
    int tamano;

public:
    Lista() : cabeza(nullptr), tamano(0) {}

    bool esListaVacia() {
        return cabeza == nullptr;
    }

    void mostrar() {
        Nodo* actual = cabeza;
        while (actual != nullptr) {
            std::cout << actual->valor << " -> ";
            actual = actual->siguiente;
        }
        std::cout << "NULL" << std::endl;
    }

    int primerElemento() {
        if (esListaVacia()) {
            throw std::runtime_error("La lista está vacía");
        }
        return cabeza->valor;
    }

    void insertar(int valor) {
        Nodo* nuevoNodo = new Nodo{valor, cabeza};
        cabeza = nuevoNodo;
        tamano++;
    }

    void borrar() {
        if (esListaVacia()) {
            throw std::runtime_error("La lista está vacía");
        }
        Nodo* nodoAEliminar = cabeza;
        cabeza = cabeza->siguiente;
        delete nodoAEliminar;
        tamano--;
    }

    int longitud() {
        return tamano;
    }

    bool pertenece(int valor) {
        Nodo* actual = cabeza;
        while (actual != nullptr) {
            if (actual->valor == valor) {
                return true;
            }
            actual = actual->siguiente;
        }
        return false;
    }

    void insertarK(int valor, int k) {
        if (k <= 0 || esListaVacia()) {
            insertar(valor);
            return;
        }
        Nodo* actual = cabeza;
        for (int i = 1; i < k - 1 && actual->siguiente != nullptr; i++) {
            actual = actual->siguiente;
        }
        Nodo* nuevoNodo = new Nodo{valor, actual->siguiente};
        actual->siguiente = nuevoNodo;
        tamano++;
    }
};

int main() {
    Lista lista;
    
    lista.insertar(10);
    lista.insertar(20);
    lista.insertar(30);
    lista.mostrar(); // 30 -> 20 -> 10 -> NULL

    std::cout << "Primer elemento: " << lista.primerElemento() << std::endl; // 30
    std::cout << "Longitud: " << lista.longitud() << std::endl; // 3

    lista.borrar();
    lista.mostrar(); // 20 -> 10 -> NULL

    std::cout << "Pertenece 20: " << lista.pertenece(20) << std::endl; // 1 (true)
    std::cout << "Pertenece 30: " << lista.pertenece(30) << std::endl; // 0 (false)

    lista.insertarK(25, 2);
    lista.mostrar(); // 20 -> 25 -> 10 -> NULL

    lista.insertarK(5, 5);
    lista.mostrar(); // 20 -> 25 -> 10 -> 5 -> NULL

    return 0;
}
