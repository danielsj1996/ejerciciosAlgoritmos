#include "pila.h"

int main()
{
    std::cout << std::endl;
    Pila pila1;
    pila1.push(1);
    pila1.push(2);
    pila1.push(3);
    pila1.push(4);

    std::cout << "Pila 1:" << std::endl;
    pila1.mostrarPila();
    std::cout << std::endl;

    Pila pila2;
    pila2.push(1);
    pila2.push(2);
    pila2.push(3);
    pila2.push(4);

    std::cout << "Pila 2:" << std::endl;
    pila2.mostrarPila();
    std::cout << std::endl;

    std::cout << "El tope de la pila 1: " << pila1.top() << std::endl;
    std::cout << std::endl;
    std::cout << "Fondo de la pila 1: " << pila1.Fondo() << std::endl;
    std::cout << std::endl;
    std::cout << "El Altura de la pila 2: " << pila2.Altura() << std::endl;
    std::cout << std::endl;

    // Realizo el control de las pilas antes de realizar el pop de fondo
    bool iguales1 = pila1.IGUALP(pila2);
    std::cout << "La Pila 1 y Pila 2 son iguales? " << (iguales1 ? "Si" : "No") << std::endl;
    std::cout << std::endl;

    pila1.pop();
    std::cout << "Pila 1 despues de realizar un POP de la pila:" << std::endl;
    pila1.mostrarPila();
    std::cout << std::endl;

    pila2.POPF();
    std::cout << "Pila 2 despues de realizar un POP de Fondo:" << std::endl;
    pila2.mostrarPila();
    std::cout << std::endl;

    pila2.REEMP(2, 8);
    std::cout << "Pila 2 despues de reemplazar 2 por 8:" << std::endl;
    pila2.mostrarPila();
    std::cout << std::endl;

    bool iguales2 = pila1.IGUALP(pila2);
    std::cout << "La Pila 1 y Pila 2 son iguales? " << (iguales2 ? "Si" : "No") << std::endl;
    std::cout << std::endl;

    Pila pila3 = pila1.APILARP(pila2);
    std::cout << "Pila 3 (resultado de colocar la pila 2 en la pila 1):" << std::endl;
    pila3.mostrarPila();
    std::cout << std::endl;

    // Convertir una expresión infija a posfija
    std::string expresionInfija = "a + b * (c - d) =";
    std::string expresionPosfija = pila1.convertirInfijaAPosfija(expresionInfija);
    std::cout << "Expresion infija: " << expresionInfija << std::endl;
    std::cout << std::endl;
    std::cout << "Expresion posfija: " << expresionPosfija << std::endl;
    std::cout << std::endl;



    return 0;
}