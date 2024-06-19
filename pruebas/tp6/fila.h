#ifndef FILA_H
#define FILA_H

#include <iostream>
#include <stack>

struct Nodo {
    int data;
    Nodo* next;
};

class Fila {
private:
    Nodo* frente;
    Nodo* final;
    int longitud;

public:
    Fila();
    ~Fila();
    bool esFilaVacia();
    int frenteFila();
    void enFila(int item);
    void deFila();
    int getLongitud();
    bool pertenece(int item);
    bool igualF(Fila& otraFila);
    Fila concat(Fila& otraFila);
    Fila invertir();
    void mostrarFila();

    static Fila mezclar(Fila& fila1, Fila& fila2);
};

#endif // FILA_H