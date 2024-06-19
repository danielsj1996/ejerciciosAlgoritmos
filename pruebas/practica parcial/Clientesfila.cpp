#include <iostream>
#include <string>

using namespace std;

typedef string item;

struct Nodo
{
    item dato;
    Nodo *siguiente;
};

class ListaClientes
{

private:
    Nodo *frente;
    Nodo *final;

public:
    ListaClientes() : frente(nullptr), final(nullptr) {}

    bool esFilaVacia() const
    {
        return frente == nullptr;
    }

    void llegar_cliente(const item &nombre)
    {
        Nodo *nuevo = new Nodo();
        nuevo->dato = nombre;
        nuevo->siguiente = nullptr;
        if (esFilaVacia())
        {
            frente = final = nuevo;
        }
        else
        {
            final->siguiente = nuevo;
            final = nuevo;
        }
    }

    void atender_cliente(ListaClientes &atendidos)
    {
        if (!esFilaVacia())
        {
            Nodo *atendido = frente;
            frente = frente->siguiente;
            if (frente == nullptr)
            {
                final = nullptr;
            }
            atendido->siguiente = atendidos.frente;
            atendidos.frente = atendido;
        }
    }

    string cliente_en_espera() const
    {

        if (!esFilaVacia())
        {
            return frente->dato;
        }
        return "";
    }

    void mostrar_Pendientes() const
    {
        Nodo *actual = frente;
        cout << "\nLista de Clientes en Espera: ";
        while (actual != nullptr)
        {
            cout << actual->dato << " ";
            actual = actual->siguiente;
        }
        cout << "\n\n";
    }
        void mostrar_atendidos() const
    {
        Nodo *actual = frente;
        cout << "\nLista de Clientes Atendidos: ";
        while (actual != nullptr)
        {
            cout << actual->dato << " ";
            actual = actual->siguiente;
        }
        cout << "\n\n";
    }

    void reiniciarFila()
    {
        while (frente != nullptr)
        {
            Nodo *temp = frente;
            frente = frente->siguiente;
            delete temp;
        }
        frente = final = nullptr;
        cout << "\n Reinicio de fila realizado con exito";
    }
};

int main()
{

    ListaClientes lista_de_Espera;
    ListaClientes lista_de_Atendidos;

    lista_de_Espera.llegar_cliente("alberto");
    lista_de_Espera.llegar_cliente("jose");
    lista_de_Espera.llegar_cliente("carlos");
    lista_de_Espera.llegar_cliente("alex");
    lista_de_Espera.llegar_cliente("daniel");
    lista_de_Espera.llegar_cliente("juan");
    lista_de_Espera.llegar_cliente("ruben");
    lista_de_Espera.llegar_cliente("pablo");
    lista_de_Espera.llegar_cliente("miguel");

    lista_de_Espera.mostrar_Pendientes();

    lista_de_Espera.atender_cliente(lista_de_Atendidos);
    lista_de_Espera.atender_cliente(lista_de_Atendidos);
    lista_de_Espera.atender_cliente(lista_de_Atendidos);
    lista_de_Espera.atender_cliente(lista_de_Atendidos);
    lista_de_Espera.atender_cliente(lista_de_Atendidos);

    lista_de_Espera.mostrar_Pendientes();
    lista_de_Atendidos.mostrar_atendidos();

    cout << "\nProximo cliente en la fila: " << lista_de_Espera.cliente_en_espera() << endl;

    lista_de_Espera.reiniciarFila();
    lista_de_Atendidos.reiniciarFila();
    cout << "\nFilas de clientes luego del reinicio de las mismas " << endl;
    lista_de_Espera.mostrar_Pendientes ();
    lista_de_Atendidos.mostrar_atendidos();
}