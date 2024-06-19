#include <iostream>
#include <string>

using namespace std;

typedef string item;

struct Nodo {
    item dato;
    Nodo* siguiente;

    Nodo(const item& d) : dato(d), siguiente(nullptr) {}
};

class ListaEnlazadaClientes {
private:
    Nodo* cabeza;

public:
    ListaEnlazadaClientes() : cabeza(nullptr) {}

    ~ListaEnlazadaClientes() {
        reiniciarLista();
    }

    bool esListaVacia() const {
        return cabeza == nullptr;
    }

    void agregar_cliente(const item& nombre) {
        Nodo* nuevo = new Nodo(nombre);
        nuevo->siguiente = cabeza;
        cabeza = nuevo;
    }

    void atender_cliente(ListaEnlazadaClientes& atendidos) {
        if (!esListaVacia()) {
            Nodo* atendido = cabeza;
            cabeza = cabeza->siguiente;

            // Insertar el cliente atendido en la lista de atendidos
            atendido->siguiente = atendidos.cabeza;
            atendidos.cabeza = atendido;
        }
    }

    string cliente_en_espera() const {
        if (!esListaVacia()) {
            return cabeza->dato;
        }
        return "";
    }

    void mostrar_Clientes() const {
        Nodo* actual = cabeza;
        cout << "\nLista de Clientes en espera: ";
        while (actual != nullptr) {
            cout << actual->dato << " ";
            actual = actual->siguiente;
        }
        cout << "\n\n";
    }
        void mostrar_Atendidos() const {
        Nodo* actual = cabeza;
        cout << "\nLista de Clientes Atendidos: ";
        while (actual != nullptr) {
            cout << actual->dato << " ";
            actual = actual->siguiente;
        }
        cout << "\n\n";
    }

    void reiniciarLista() {
        while (cabeza != nullptr) {
            Nodo* temp = cabeza;
            cabeza = cabeza->siguiente;
            delete temp;
        }
        cout << "\nReinicio de lista realizado con exito";
    }
};

int main() {
    ListaEnlazadaClientes lista_de_Espera;
    ListaEnlazadaClientes lista_de_Atendidos;

    lista_de_Espera.agregar_cliente("alberto");
    lista_de_Espera.agregar_cliente("jose");
    lista_de_Espera.agregar_cliente("carlos");
    lista_de_Espera.agregar_cliente("alex");
    lista_de_Espera.agregar_cliente("daniel");
    lista_de_Espera.agregar_cliente("juan");
    lista_de_Espera.agregar_cliente("ruben");
    lista_de_Espera.agregar_cliente("pablo");
    lista_de_Espera.agregar_cliente("miguel");

    lista_de_Espera.mostrar_Clientes();

    lista_de_Espera.atender_cliente(lista_de_Atendidos);
    lista_de_Espera.atender_cliente(lista_de_Atendidos);
    lista_de_Espera.atender_cliente(lista_de_Atendidos);

    lista_de_Espera.mostrar_Clientes();
    lista_de_Atendidos.mostrar_Atendidos();

    cout << "\nProximo cliente en la lista de espera: " << lista_de_Espera.cliente_en_espera() << endl;

    lista_de_Espera.reiniciarLista();
    lista_de_Atendidos.reiniciarLista();
    cout << "\nListas de clientes luego del reinicio:" << endl;
    lista_de_Espera.mostrar_Clientes();
    lista_de_Atendidos.mostrar_Atendidos();

    return 0;
}