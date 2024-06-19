#include "listacircular.h"
#include <iostream>
#include <queue>

void INVERTIRFILA(std::queue<int>& fila) {
    ListaCircular lc;
    while (!fila.empty()) {
        lc.LCINSERTAR(fila.front());
        fila.pop();
    }
    while (!lc.ESLCVACIA()) {
        fila.push(lc.LCVALOR());
        lc.LCBORRAR();
    }
}

int main() {
    ListaCircular lc;
    lc.LCINSERTAR(1);
    lc.LCINSERTAR(2);
    lc.LCINSERTAR(3);
    std::cout << "Ultimo valor: " << lc.LCVALOR() << std::endl; // 3

    lc.LCBORRAR();
    std::cout << "Ultimo valor despues de borrar: " << lc.LCVALOR() << std::endl; // 2

    lc.LCROTAR();
    std::cout << "Valor despues de rotar: " << lc.LCVALOR() << std::endl; // 1

    ListaCircular lc2;
    lc2.LCINSERTAR(4);
    lc2.LCINSERTAR(5);

    lc.LCUNIR(lc2);
    std::cout << "Valor despues de unir: " << lc.LCVALOR() << std::endl; // 5

    lc.LCROTARN(2);
    std::cout << "Valor despues de rotar 2 veces: " << lc.LCVALOR() << std::endl; // 4

    std::cout << "Contar cuantas veces aparece 2: " << lc.LCCONTARK(2) << std::endl; // 1

    std::queue<int> fila;
    fila.push(1);
    fila.push(2);
    fila.push(3);
    INVERTIRFILA(fila);

    std::cout << "Fila invertida: ";
    while (!fila.empty()) {
        std::cout << fila.front() << " ";
        fila.pop();
    }
    std::cout << std::endl;

    return 0;
}