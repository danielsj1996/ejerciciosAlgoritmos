#include <iostream>
#include <string>

using namespace std;

typedef string item;

struct Nodo
{
    item dato;
    Nodo *siguiente;
};

class PilaClientes
{

private:
    Nodo *tope;

public:
    PilaClientes() : tope(nullptr) {}

    bool esPilaVacia() const
    {
        return tope == nullptr;
    }

    void agregar_cliente(const item &nombre)
    {
        Nodo *nuevo = new Nodo();
        nuevo->dato = nombre;
        nuevo->siguiente = tope;
        tope = nuevo;
    }

    void atender_cliente(PilaClientes &atendidos)
    {
        if (!esPilaVacia())
        {
            Nodo *atendido = tope;
            tope = tope->siguiente;
            atendido->siguiente = atendidos.tope;
            atendidos.tope = atendido;
        }
    }

    string cliente_en_espera() const
    {
        if (!esPilaVacia())
        {
            return tope->dato;
        }
        return "";
    }

    void mostrar_en_Espera() const
    {
        Nodo *actual = tope;
        cout << "\nPila de Clientes en espera: ";
        while (actual != nullptr)
        {
            cout << actual->dato << " ";
            actual = actual->siguiente;
        }
        cout << "\n\n";
    }
        void mostrar_Atendidos() const
    {
        Nodo *actual = tope;
        cout << "\nPila de Clientes Atendidos: ";
        while (actual != nullptr)
        {
            cout << actual->dato << " ";
            actual = actual->siguiente;
        }
        cout << "\n\n";
    }

    void reiniciarPila()
    {
        while (tope != nullptr)
        {
            Nodo *temp = tope;
            tope = tope->siguiente;
            delete temp;
        }
        tope = nullptr;
        cout << "\nReinicio de pila realizado con exito";
    }
};

int main()
{

    PilaClientes pila_de_Espera;
    PilaClientes pila_de_Atendidos;

    pila_de_Espera.agregar_cliente("alberto");
    pila_de_Espera.agregar_cliente("jose");
    pila_de_Espera.agregar_cliente("carlos");
    pila_de_Espera.agregar_cliente("alex");
    pila_de_Espera.agregar_cliente("daniel");
    pila_de_Espera.agregar_cliente("juan");
    pila_de_Espera.agregar_cliente("ruben");
    pila_de_Espera.agregar_cliente("pablo");
    pila_de_Espera.agregar_cliente("miguel");

    pila_de_Espera.mostrar_en_Espera();

    pila_de_Espera.atender_cliente(pila_de_Atendidos);
    pila_de_Espera.atender_cliente(pila_de_Atendidos);
    pila_de_Espera.atender_cliente(pila_de_Atendidos);
    pila_de_Espera.atender_cliente(pila_de_Atendidos);
    pila_de_Espera.atender_cliente(pila_de_Atendidos);

    pila_de_Espera.mostrar_en_Espera();
    pila_de_Atendidos.mostrar_Atendidos();

    cout << "\nProximo cliente en la pila: " << pila_de_Espera.cliente_en_espera() << endl;

    pila_de_Espera.reiniciarPila();
    pila_de_Atendidos.reiniciarPila();
    cout << "\nPilas de clientes luego del reinicio de las mismas " << endl;
    pila_de_Espera.mostrar_en_Espera();
    pila_de_Atendidos.mostrar_Atendidos();
}