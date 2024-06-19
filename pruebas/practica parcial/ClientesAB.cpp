#include <iostream>
#include <string>

using namespace std;

typedef string item;

struct Nodo
{
    item dato;
    Nodo *izquierdo;
    Nodo *derecho;

    Nodo(const item &d) : dato(d), izquierdo(nullptr), derecho(nullptr) {}
};

class ArbolClientes
{
private:
    Nodo *raiz;

    void insertar(Nodo *&nodo, const item &nombre)
    {
        if (nodo == nullptr)
        {
            nodo = new Nodo(nombre);
        }
        else if (nombre < nodo->dato)
        {
            insertar(nodo->izquierdo, nombre);
        }
        else if (nombre > nodo->dato)
        {
            insertar(nodo->derecho, nombre);
        }
    }

    void inOrden(Nodo *nodo) const
    {
        if (nodo != nullptr)
        {
            inOrden(nodo->izquierdo);
            cout << nodo->dato << " ";
            inOrden(nodo->derecho);
        }
    }

    Nodo *buscarMin(Nodo *nodo) const
    {
        while (nodo->izquierdo != nullptr)
        {
            nodo = nodo->izquierdo;
        }
        return nodo;
    }

    Nodo *eliminar(Nodo *&nodo, const item &nombre)
    {
        if (nodo == nullptr)
        {
            return nodo;
        }
        else if (nombre < nodo->dato)
        {
            nodo->izquierdo = eliminar(nodo->izquierdo, nombre);
        }
        else if (nombre > nodo->dato)
        {
            nodo->derecho = eliminar(nodo->derecho, nombre);
        }
        else
        {
            if (nodo->izquierdo == nullptr)
            {
                Nodo *temp = nodo->derecho;
                delete nodo;
                return temp;
            }
            else if (nodo->derecho == nullptr)
            {
                Nodo *temp = nodo->izquierdo;
                delete nodo;
                return temp;
            }
            Nodo *temp = buscarMin(nodo->derecho);
            nodo->dato = temp->dato;
            nodo->derecho = eliminar(nodo->derecho, temp->dato);
        }
        return nodo;
    }

    void destruirArbol(Nodo *nodo)
    {
        if (nodo != nullptr)
        {
            destruirArbol(nodo->izquierdo);
            destruirArbol(nodo->derecho);
            delete nodo;
        }
    }

public:
    ArbolClientes() : raiz(nullptr) {}

    ~ArbolClientes()
    {
        destruirArbol(raiz);
    }

    void agregar_cliente(const item &nombre)
    {
        insertar(raiz, nombre);
    }

    void atender_cliente(ArbolClientes &atendidos)
    {
        if (raiz != nullptr)
        {
            Nodo *minNode = buscarMin(raiz);
            atendidos.agregar_cliente(minNode->dato);
            raiz = eliminar(raiz, minNode->dato);
        }
    }

    void mostrar_en_Espera() const
    {
        cout << "\nArbol de Clientes en Espera(inorden): ";
        inOrden(raiz);
        cout << "\n\n";
    }
    void mostrar_Atendidos() const
    {
        cout << "\nArbol de Clientes Atendidos(inorden): ";
        inOrden(raiz);
        cout << "\n\n";
    }
    item cliente_en_espera() const
    {
        if (raiz != nullptr)
        {
            Nodo *minNode = buscarMin(raiz);
            return minNode->dato;
        }
        return "";
    }

    void reiniciarArbol()
    {
        destruirArbol(raiz);
        raiz = nullptr;
        cout << "\nReinicio del Arbol realizado con Exito";
    }
};

int main()
{
    ArbolClientes arbol_de_Espera;
    ArbolClientes arbol_de_Atendidos;

    arbol_de_Espera.agregar_cliente("alberto");
    arbol_de_Espera.agregar_cliente("jose");
    arbol_de_Espera.agregar_cliente("carlos");
    arbol_de_Espera.agregar_cliente("alex");
    arbol_de_Espera.agregar_cliente("daniel");
    arbol_de_Espera.agregar_cliente("juan");
    arbol_de_Espera.agregar_cliente("ruben");
    arbol_de_Espera.agregar_cliente("pablo");
    arbol_de_Espera.agregar_cliente("miguel");

    arbol_de_Espera.mostrar_en_Espera();

    arbol_de_Espera.atender_cliente(arbol_de_Atendidos);
    arbol_de_Espera.atender_cliente(arbol_de_Atendidos);
    arbol_de_Espera.atender_cliente(arbol_de_Atendidos);

    arbol_de_Espera.mostrar_en_Espera();
    arbol_de_Atendidos.mostrar_Atendidos();

    cout << "\nProximo cliente en el árbol de espera: " << arbol_de_Espera.cliente_en_espera() << endl;

    arbol_de_Espera.reiniciarArbol();
    arbol_de_Atendidos.reiniciarArbol();
    cout << "\nArboles de clientes luego del reinicio:" << endl;
    arbol_de_Espera.mostrar_en_Espera();
    arbol_de_Atendidos.mostrar_Atendidos();

    return 0;
}