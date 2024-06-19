#include <iostream>

using namespace std;

typedef int item;

struct Nodo
{
    item dato;
    Nodo *siguiente;
};

Nodo *Lista;

Nodo *crearLista();
bool esListaVacia(Nodo *Lista);
void mostrarLista(Nodo *Lista);
Nodo *insertarNodo(Nodo *Lista, item dato);
void primerElemento(Nodo *Lista);
int longitudLista(Nodo *Lista);
void Pertenece(Nodo *Lista, item dato);
Nodo *borrarNodoInicio(Nodo *Lista);
Nodo *borrarUltimoNodo(Nodo *Lista);
bool sonIguales(Nodo *Lista1, Nodo *Lista2);
Nodo *insertarK(Nodo *Lista, item dato, int k);

int main()
{
    Nodo *Lista = crearLista();
    Nodo *Lista2 = crearLista();

    int cant;

    Lista = insertarNodo(Lista, 6);
    Lista = insertarNodo(Lista, 5);
    Lista = insertarNodo(Lista, 7);
    Lista = insertarNodo(Lista, 4);
    Lista = insertarNodo(Lista, 2);
    mostrarLista(Lista);

    Lista2 = insertarNodo(Lista2, 6);
    Lista2 = insertarNodo(Lista2, 5);
    Lista2 = insertarNodo(Lista2, 7);
    Lista2 = insertarNodo(Lista2, 4);
    Lista2 = insertarNodo(Lista2, 2);

    mostrarLista(Lista2);

    primerElemento(Lista);

    cant = longitudLista(Lista);

    cout << "\n La cantidad de nodos que hay en la lista es: " << cant << endl;

    Pertenece(Lista, 5);

    Pertenece(Lista, 9);

    if (sonIguales(Lista, Lista2))
    {
        cout << "\nLas listas son iguales\n";
    }
    else
    {
        cout << "\nLas listas no son iguales\n";
    }
    Lista = insertarK(Lista, 3, 3); // Insertar 3 en la posición 3
    mostrarLista(Lista);

    Lista = borrarNodoInicio(Lista);
    mostrarLista(Lista);

    Lista2 = borrarUltimoNodo(Lista2);
    mostrarLista(Lista2);

    return 0;
}

Nodo *crearLista()
{
    return nullptr;
}

bool esListaVacia(Nodo *Lista)
{
    return Lista == nullptr;
}

Nodo *insertarNodo(Nodo *Lista, item dato)
{
    Nodo *nuevo = new Nodo();
    nuevo->dato = dato;
    nuevo->siguiente = Lista;
    Lista = nuevo;
    cout << "\nNuevo nodo Insertado\n";
    return Lista;
}

void mostrarLista(Nodo *Lista)
{
    cout << "\n Lista: ";
    while (!esListaVacia(Lista))
    {
        cout << Lista->dato;
        Lista = Lista->siguiente;
    }
    cout << "\n\n";
}

void primerElemento(Nodo *Lista)
{
    if (esListaVacia(Lista))
    {
        cout << "La lista se encuentra Vacia";
    }
    else
    {
        cout << "\n El primer Elemento de la lista es : " << Lista->dato;
    }
}

Nodo *borrarNodoInicio(Nodo *Lista)
{
    if (esListaVacia(Lista))
    {
        cout << "---La lista esta vacia\n";
        return Lista;
    }
    else
    {
        Nodo *aux = Lista;
        Lista = Lista->siguiente;
        delete aux;
        cout << "\n El primer Nodo ha sido Eliminado";
        return Lista;
    }
}

int longitudLista(Nodo *Lista)
{
    int contador = 0;
    while (Lista != nullptr)
    {
        contador++;
        Lista = Lista->siguiente;
    }
    return contador;
}

void Pertenece(Nodo *Lista, item i)
{
    if (esListaVacia(Lista))
    {
        cout << "\nLista Vacia";
    }
    else
    {
        while (Lista != nullptr)
        {
            if (i == Lista->dato)
            {
                cout << "\n " << i << " pertenece a la lista\n";
                return;
            }
            Lista = Lista->siguiente;
        }
        cout << "\n " << i << " No pertenece a la lista\n";
    }
}

Nodo *borrarUltimoNodo(Nodo *Lista)
{
    if (esListaVacia(Lista))
    {
        cout << "La Lista se encuentra vacía";
        return Lista;
    }
    else if (Lista->siguiente == nullptr)
    {
        delete Lista;
        cout << "\nEl ultimo nodo ha sido eliminado correctamente\n";
        return nullptr;
    }
    else
    {
        Nodo *actual = Lista;
        while (actual->siguiente->siguiente != nullptr)
        {
            actual = actual->siguiente;
        }
        Nodo *borrar = actual->siguiente;
        actual->siguiente = nullptr;
        delete borrar;
        cout << "\nEl ultimo nodo ha sido eliminado correctamente\n";
        return Lista;
    }
}

bool sonIguales(Nodo *Lista1, Nodo *Lista2)
{
    while (Lista1 != nullptr && Lista2 != nullptr)
    {
        if (Lista1->dato != Lista2->dato)
        {
            return false;
        }
        Lista1 = Lista1->siguiente;
        Lista2 = Lista2->siguiente;
    }
    return (Lista1 == nullptr && Lista2 == nullptr);
}

Nodo *insertarK(Nodo *Lista, item dato, int k)
{
    if (k <= 0 || Lista == nullptr)
    {
        // Si k <= 0 o la lista está vacía, insertar al principio
        return insertarNodo(Lista, dato);
    }
    else
    {
        Nodo *nuevo = new Nodo();
        nuevo->dato = dato;

        Nodo *actual = Lista;
        int contador = 1;

        while (contador < k - 1 && actual->siguiente != nullptr)
        {
            actual = actual->siguiente;
            contador++;
        }

        // Si actual->siguiente es nullptr, significa que hemos alcanzado el final de la lista
        if (actual->siguiente == nullptr)
        {
            actual->siguiente = nuevo; // Insertar al final
            cout << "\nNuevo nodo Insertado al final\n";
        }
        else
        {
            // Insertar en la posición k-ésima
            nuevo->siguiente = actual->siguiente;
            actual->siguiente = nuevo;
            cout << "\nNuevo nodo Insertado en la posicion " << k << endl;
        }

        return Lista;
    }
}
