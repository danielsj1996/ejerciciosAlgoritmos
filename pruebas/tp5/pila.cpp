#include "pila.h"
#include <stack>
#include <cctype>

Pila::Pila() : tope(nullptr), altura(0) {}

Pila::~Pila()
{
    while (!EsPilaVacia())
    {
        pop();
    }
}

void Pila::push(int e)
{
    Nodo *nuevoNodo = new Nodo{e, tope};
    tope = nuevoNodo;
    altura++;
}

int Pila::pop()
{
    if (EsPilaVacia())
    {
        std::cerr << "Error: pila vacía." << std::endl;
        return -1; // Se puede manejar mejor el error según sea necesario
    }
    int valor = tope->dato;
    Nodo *nodoAEliminar = tope;
    tope = tope->siguiente;
    delete nodoAEliminar;
    altura--;
    return valor;
}

bool Pila::EsPilaVacia() const
{
    return tope == nullptr;
}

int Pila::top() const
{
    if (EsPilaVacia())
    {
        std::cerr << "Error: pila vacía." << std::endl;
        return -1; // Se puede manejar mejor el error según sea necesario
    }
    return tope->dato;
}

int Pila::Altura() const
{
    return altura;
}

int Pila::Fondo() const
{
    if (EsPilaVacia())
    {
        std::cerr << "Error: pila vacía." << std::endl;
        return -1; // Se puede manejar mejor el error según sea necesario
    }
    Nodo *actual = tope;
    while (actual->siguiente != nullptr)
    {
        actual = actual->siguiente;
    }
    return actual->dato;
}

void Pila::POPF()
{
    if (EsPilaVacia())
    {
        std::cerr << "Error: pila vacía." << std::endl;
        return;
    }
    if (tope->siguiente == nullptr)
    {
        pop();
        return;
    }
    Nodo *actual = tope;
    while (actual->siguiente->siguiente != nullptr)
    {
        actual = actual->siguiente;
    }
    delete actual->siguiente;
    actual->siguiente = nullptr;
    altura--;
}

void Pila::REEMP(int viejo, int nuevo)
{
    Nodo *actual = tope;
    while (actual != nullptr)
    {
        if (actual->dato == viejo)
        {
            actual->dato = nuevo;
        }
        actual = actual->siguiente;
    }
}

bool Pila::IGUALP(const Pila &otra) const
{
    Nodo *actual1 = tope;
    Nodo *actual2 = otra.tope;
    while (actual1 != nullptr && actual2 != nullptr)
    {
        if (actual1->dato != actual2->dato)
        {
            return false;
        }
        actual1 = actual1->siguiente;
        actual2 = actual2->siguiente;
    }
    return actual1 == nullptr && actual2 == nullptr;
}

Pila Pila::APILARP(const Pila &otra) const
{
    Pila nuevaPila;
    
    // Apilar elementos de this en orden correcto
    Nodo *actual = tope;
    Pila auxThis;
    while (actual != nullptr)
    {
        auxThis.push(actual->dato);
        actual = actual->siguiente;
    }
    while (!auxThis.EsPilaVacia())
    {
        nuevaPila.push(auxThis.pop());
    }
    
    // Apilar elementos de otra en orden correcto
    actual = otra.tope;
    Pila auxOtra;
    while (actual != nullptr)
    {
        auxOtra.push(actual->dato);
        actual = actual->siguiente;
    }
    while (!auxOtra.EsPilaVacia())
    {
        nuevaPila.push(auxOtra.pop());
    }
    
    return nuevaPila;
}


void Pila::mostrarPila() const
{
    Nodo *actual = tope;
    while (actual != nullptr)
    {
        std::cout << actual->dato << std::endl;
        actual = actual->siguiente;
    }
}
int precedencia(char op)
{
    switch (op)
    {
    case '+':
    case '-':
        return 1;
    case '*':
    case '/':
        return 2;
    case '~':
        return 3; // Operador unario ~
    default:
        return 0;
    }
}

bool esOperador(char c)
{
    return c == '+' || c == '-' || c == '*' || c == '/' || c == '~';
}

std::string Pila::convertirInfijaAPosfija(const std::string &expresion)
{
    std::stack<char> operadores;
    std::string salida;
    for (char c : expresion)
    {
        if (std::isspace(c))
        {
            continue;
        }
        if (std::isalnum(c))
        {
            salida += c;
            salida += ' '; // Agregar un espacio después de cada variable o número
        }
        else if (c == '(')
        {
            operadores.push(c);
        }
        else if (c == ')')
        {
            while (!operadores.empty() && operadores.top() != '(')
            {
                salida += operadores.top();
                salida += ' '; // Agregar un espacio después de cada operador
                operadores.pop();
            }
            operadores.pop(); // Eliminar el paréntesis izquierdo '('
        }
        else if (esOperador(c))
        {
            while (!operadores.empty() && precedencia(operadores.top()) >= precedencia(c))
            {
                salida += operadores.top();
                salida += ' '; // Agregar un espacio después de cada operador
                operadores.pop();
            }
            operadores.push(c);
        }
        else if (c == '=')
        {
            while (!operadores.empty())
            {
                salida += operadores.top();
                salida += ' '; // Agregar un espacio después de cada operador
                operadores.pop();
            }
        }
    }
    // Eliminar el último espacio en blanco si existe
    if (!salida.empty() && salida.back() == ' ')
    {
        salida.pop_back();
    }
    return salida;
}