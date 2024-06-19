#ifndef LISTACIRCULAR_H
#define LISTACIRCULAR_H

struct Nodo {
    int valor;
    Nodo* siguiente;
    Nodo(int v) : valor(v), siguiente(nullptr) {}
};

class ListaCircular {
private:
    Nodo* ultimo;

public:
    ListaCircular();
    ~ListaCircular();
    void LCVACIA();
    void LCINSERTAR(int valor);
    void LCBORRAR();
    int LCVALOR();
    bool ESLCVACIA();
    void LCROTAR();
    void LCUNIR(ListaCircular& otra);
    void LCROTARN(int n);
    int LCCONTARK(int k);
};

#endif // LISTACIRCULAR_H