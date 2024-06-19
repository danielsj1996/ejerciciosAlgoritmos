#include <iostream>

struct Nodo
{
    int dato;
    Nodo *siguiente;
};

class Cochera
{
private:
    Nodo *inicio;
    int capacidad;
    int ocupados;

public:
    Cochera(int capacidad)
    {
        this->capacidad = capacidad;
        ocupados = 0;
        inicio = nullptr;
    }

    bool estaVacia()
    {
        return ocupados == 0;
    }

    void estacionar(int autoID)
    {
        if (ocupados < capacidad)
        {
            Nodo *nuevoNodo = new Nodo();
            nuevoNodo->dato = autoID;
            nuevoNodo->siguiente = inicio;
            inicio = nuevoNodo;
            ocupados++;
        }
        else
        {
            std::cout << "La cochera está llena." << std::endl;
        }
    }

    void quitarUltimo()
    {
        if (!estaVacia())
        {
            Nodo *temp = inicio;
            inicio = inicio->siguiente;
            delete temp;
            ocupados--;
        }
        else
        {
            std::cout << "La cochera está vacía." << std::endl;
        }
    }

    void salir(int autoID)
    {
        Nodo *actual = inicio;
        Nodo *anterior = nullptr;
        while (actual != nullptr && actual->dato != autoID)
        {
            anterior = actual;
            actual = actual->siguiente;
        }
        if (actual != nullptr)
        {
            if (anterior != nullptr)
            {
                anterior->siguiente = actual->siguiente;
            }
            else
            {
                inicio = actual->siguiente;
            }
            delete actual;
            ocupados--;
        }
        else
        {
            std::cout << "Auto con ID " << autoID << " no encontrado." << std::endl;
        }
    }

    int ultimo()
    {
        if (!estaVacia())
        {
            return inicio->dato;
        }
        else
        {
            std::cout << "La cochera está vacía." << std::endl;
            return -1; // Retorna un valor inválido en caso de que la cochera esté vacía
        }
    }

    bool estacionado(int autoID)
    {
        Nodo *actual = inicio;
        while (actual != nullptr)
        {
            if (actual->dato == autoID)
            {
                return true;
            }
            actual = actual->siguiente;
        }
        return false;
    }

    int capacidadTotal()
    {
        return capacidad;
    }

    int estacionamientosLibres()
    {
        return capacidad - ocupados;
    }

    void mostrarAutos()
    {
        Nodo *actual = inicio;
        if (estaVacia())
        {
            std::cout << "La cochera está vacía." << std::endl;
            return;
        }
        std::cout << "Autos en la cochera: ";
        while (actual != nullptr)
        {
            std::cout << actual->dato << " ";
            actual = actual->siguiente;
        }
        std::cout << std::endl;
    }
};

bool MOVERAUTOS(Cochera &cochera1, Cochera &cochera2, int n)
{
    if (cochera2.estacionamientosLibres() >= n)
    {
        for (int i = 0; i < n; ++i)
        {
            int autoID = cochera1.ultimo();
            cochera1.quitarUltimo();
            cochera2.estacionar(autoID);
        }
        return true;
    }
    else
    {
        return false;
    }
}
