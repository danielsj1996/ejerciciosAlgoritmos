#include <iostream>

struct Nodo
{
    int valor;
    Nodo *siguiente;

    Nodo(int val) : valor(val), siguiente(nullptr) {}
};

class Misterio
{
private:
    Nodo *cabeza;
    int tamano;

public:
    Misterio() : cabeza(nullptr), tamano(0) {}

    void insertar(int valor)
    {
        Nodo *nuevoNodo = new Nodo(valor);

        if (esListaVacia())
        {
            cabeza = nuevoNodo;
            cabeza->siguiente = cabeza; // Lista circular con un solo elemento
        }
        else
        {
            Nodo *actual = cabeza;
            while (actual->siguiente != cabeza)
            {
                actual = actual->siguiente;
            }
            actual->siguiente = nuevoNodo;
            nuevoNodo->siguiente = cabeza; // Nuevo nodo apunta de regreso a la cabeza
        }
        tamano++;
    }

    void mostrar()
    {
        if (esListaVacia())
        {
            std::cout << "Lista vacía" << std::endl;
            return;
        }
        Nodo *actual = cabeza;
        do
        {
            std::cout << actual->valor << " -> ";
            actual = actual->siguiente;
        } while (actual != cabeza);
        std::cout << "NULL" << std::endl;
    }

    bool esListaVacia() const
    {
        return cabeza == nullptr;
    }

    int primerElemento()
    {
        if (esListaVacia())
        {
            throw std::runtime_error("La lista está vacía");
        }
        return cabeza->valor;
    }

    int ultimoElemento()
    {
        if (esListaVacia())
        {
            throw std::runtime_error("La lista está vacía");
        }
        Nodo *actual = cabeza;
        while (actual->siguiente != cabeza)
        {
            actual = actual->siguiente;
        }
        return actual->valor;
    }
    void borrarPrimero()
    {
        if (esListaVacia())
        {
            std::cout << "La lista está vacía, no se puede borrar." << std::endl;
            return;
        }

        Nodo *nodoEliminar = cabeza;

        if (cabeza->siguiente == cabeza)
        { // Caso especial: lista con un solo nodo
            delete cabeza;
            cabeza = nullptr;
        }
        else
        {
            Nodo *siguienteCabeza = cabeza->siguiente;
            Nodo *ultimoNodo = cabeza;
            while (ultimoNodo->siguiente != cabeza)
            {
                ultimoNodo = ultimoNodo->siguiente;
            }

            cabeza = siguienteCabeza;
            ultimoNodo->siguiente = siguienteCabeza;
            delete nodoEliminar;
        }

        tamano--;
    }
    void borrarUltimo()
    {
        if (esListaVacia())
        {
            std::cout << "La lista está vacía, no se puede borrar." << std::endl;
            return;
        }
        if (cabeza->siguiente == cabeza)
        {
            delete cabeza;
            cabeza = nullptr;
        }
        else
        {
            Nodo *actual = cabeza;
            while (actual->siguiente->siguiente != cabeza)
            {
                actual = actual->siguiente;
            }
            Nodo *nodoEliminar = actual->siguiente;
            actual->siguiente = cabeza;
            delete nodoEliminar;
        }
        tamano--;
    }

    int longitud() const
    {
        return tamano;
    }

    bool pertenece(int valor)
    {
        if (esListaVacia())
        {
            return false;
        }
        Nodo *actual = cabeza;
        do
        {
            if (actual->valor == valor)
            {
                return true;
            }
            actual = actual->siguiente;
        } while (actual != cabeza);
        return false;
    }

    Misterio copiar() const
    {
        Misterio nuevaLista;
        if (esListaVacia())
        {
            return nuevaLista;
        }
        Nodo *actual = cabeza;
        do
        {
            nuevaLista.insertar(actual->valor);
            actual = actual->siguiente;
        } while (actual != cabeza);
        return nuevaLista;
    }
};

int main()
{
    Misterio lista;

    // Insertar elementos en la lista
    lista.insertar(10);
    lista.insertar(20);
    lista.insertar(30);
    lista.insertar(40);
    lista.insertar(50);
    lista.insertar(60);

    // Mostrar la lista
    std::cout << "Lista inicial:" << std::endl;
    lista.mostrar(); // Debería mostrar: 10 -> 20 -> 30 -> 40 -> 50 -> 60 -> NULL

    // Ejemplos de uso de las funciones adicionales
    std::cout << "Primer elemento: " << lista.primerElemento() << std::endl; // 10
    std::cout << "Ultimo elemento: " << lista.ultimoElemento() << std::endl; // 60

    lista.borrarPrimero();
    lista.mostrar(); // Debería mostrar: 20 -> 30 -> 40 -> 50 -> 60 -> NULL

    lista.borrarUltimo();
    lista.mostrar(); // Debería mostrar: 20 -> 30 -> 40 -> 50 -> NULL

    std::cout << "Pertenece 30: " << lista.pertenece(30) << std::endl;   // 1 (true)
    std::cout << "Pertenece 100: " << lista.pertenece(100) << std::endl; // 0 (false)

    // Copiar la lista
    Misterio copiaLista = lista.copiar();
    std::cout << "Copia de la lista original:" << std::endl;
    copiaLista.mostrar(); // Debería mostrar: 20 -> 30 -> 40 -> 50 -> NULL

    return 0;
}
