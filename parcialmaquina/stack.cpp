#include <iostream>
using namespace std;

typedef int item;
const int indefinido = -9999;

struct Nodo
{
    item direccion;
    Nodo *siguiente;
};

struct cStack
{
    Nodo *tope;
    int altura;
};

cStack VACIO()
{
    cStack c;
    c.tope = nullptr;
    c.altura = 0;
    return c;
}

bool ESTAVACIO(const cStack &c)
{
    return c.altura == 0;
}

cStack AGREGAR(cStack c, item direccion)
{
    Nodo *nuevoNodo = new Nodo();
    nuevoNodo->direccion = direccion;
    nuevoNodo->siguiente = c.tope;
    c.tope = nuevoNodo;
    c.altura++;
    return c;
}

void mostrar(const cStack &c)
{
    Nodo *actual = c.tope;
    cout << "Elementos de la cStack: ";
    while (actual != nullptr)
    {
        cout << actual->direccion << " ";
        actual = actual->siguiente;
    }
    cout << endl;
}

item ULTIMA(const cStack &c)
{
    if (ESTAVACIO(c))
    {
        cout << "Error " << indefinido << endl;
        return indefinido;
    }
    else
    {
        return c.tope->direccion;
    }
}

cStack ELIMINAR(cStack c)
{
    if (ESTAVACIO(c))
    {
        cout << "Error " << indefinido << endl;
    }
    else
    {
        Nodo *aux = c.tope;
        c.tope = c.tope->siguiente;
        delete aux;
        c.altura--;
    }
    return c;
}

item PRIMERA(const cStack &c) {
    if (ESTAVACIO(c)) {
        cout << "Error " << indefinido << endl;
        return indefinido;
    } else {
        return c.tope->direccion; // Devolvemos el elemento del tope de la pila
    }
}

int CANTIDAD(const cStack &c)
{
    return c.altura;
}

bool PERTENECE(const cStack &c, item direccion) {
    Nodo *aux = c.tope; // Empezamos desde el tope de la pila

    while (aux != nullptr) {
        if (aux->direccion == direccion) { // Si encontramos el elemento
            return true; // Retornamos true
        }
        aux = aux->siguiente; // Avanzamos al siguiente nodo
    }

    return false; // Si no encontramos el elemento, retornamos false
}

int main()
{
    cStack stack = VACIO();

    if (ESTAVACIO(stack))
    {
        cout << "El stack se encuentra vacio" << endl;
    }
    else
    {
        cout << "El stack no se encuentra vacio" << endl;
    }

    stack = AGREGAR(stack, 1);
    stack = AGREGAR(stack, 2);
    stack = AGREGAR(stack, 3);
    stack = AGREGAR(stack, 4);
    stack = AGREGAR(stack, 5);
    mostrar(stack);

    if (ESTAVACIO(stack))
    {
        cout << "El stack se encuentra vacio" << endl;
    }
    else
    {
        cout << "El stack no se encuentra vacio" << endl;
    }

    cout << "Ultima ingresada: " << ULTIMA(stack) << endl;
    cout << "Eliminando ultima ingresada.... " << endl;
    stack = ELIMINAR(stack);
    cout << "Ultima ingresada luego de la eliminacin: " << ULTIMA(stack) << endl;
    cout << "Primera ingresada: " << PRIMERA(stack) << endl;
    cout << "Cantidad de ingresados: " << CANTIDAD(stack) << endl;

    // Verificamos si el elemento 2 pertenece a la pila
   
    if (PERTENECE(stack, 2)) {
        cout << "El elemento 2 si pertenece a la pila." << endl;
    } else {
        cout << "El elemento 2 no pertenece a la pila." << endl;
    }

    // Verificamos si el elemento 5 pertenece a la pila
    
    if (PERTENECE(stack, 6)) {
        cout << "El elemento 6 si pertenece a la pila." << endl;
    } else {
        cout << "El elemento 6 no pertenece a la pila." << endl;
    }

    return 0;
}