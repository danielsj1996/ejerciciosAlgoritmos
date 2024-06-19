#ifndef PILA_H
#define PILA_H

#include <iostream>

struct Nodo
{
    int dato;
    Nodo *siguiente;
};

class Pila
{
private:
    Nodo *tope;
    int altura;

public:
    Pila();
    ~Pila();

    void push(int e);
    int pop();
    bool EsPilaVacia() const;
    int top() const;
    int Altura() const;
    int Fondo() const;
    void POPF();
    void REEMP(int viejo, int nuevo);
    bool IGUALP(const Pila &otra) const;
    Pila APILARP(const Pila &otra) const;
    void mostrarPila() const;

    // Función para convertir infija a posfija
    std::string convertirInfijaAPosfija(const std::string &expresion);
};

#endif