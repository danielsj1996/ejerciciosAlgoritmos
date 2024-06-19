#include "fila.h"

int main()
{
    Fila fila1;
    Fila fila2;

    // Probar enFila
    std::cout << "Enfilando elementos en fila1..." << std::endl;
    fila1.enFila(1);
    fila1.enFila(3);
    fila1.enFila(5);
    fila1.mostrarFila();

    std::cout << "Enfilando elementos en fila2..." << std::endl;
    fila2.enFila(2);
    fila2.enFila(4);
    fila2.enFila(6);
    fila2.mostrarFila();

    // Probar esFilaVacia
    std::cout << "fila1 es vacía? " << (fila1.esFilaVacia() ? "Si" : "No") << std::endl;
    std::cout << std::endl;

    std::cout << "fila2 es vacía? " << (fila2.esFilaVacia() ? "Si" : "No") << std::endl;
    std::cout << std::endl;

    // Probar frenteFila
    std::cout << "Frente de fila1: " << fila1.frenteFila() << std::endl;
    std::cout << std::endl;

    std::cout << "Frente de fila2: " << fila2.frenteFila() << std::endl;
    std::cout << std::endl;

    // Probar deFila
    std::cout << "Desenfilando elementos de fila1..." << std::endl;
    fila1.deFila();
    std::cout << "Nuevo frente de fila1: " << fila1.frenteFila() << std::endl;
    fila1.mostrarFila();
    std::cout << std::endl;

    // Probar getLongitud
    std::cout << "Longitud de fila1: " << fila1.getLongitud() << std::endl;
    std::cout << std::endl;

    std::cout << "Longitud de fila2: " << fila2.getLongitud() << std::endl;
    std::cout << std::endl;

    // Probar pertenece
    std::cout << "El elemento 3 pertenece a fila1? " << (fila1.pertenece(3) ? "Si" : "No") << std::endl;
    std::cout << std::endl;

    std::cout << "El elemento 4 pertenece a fila2? " << (fila2.pertenece(4) ? "Si" : "No") << std::endl;
    std::cout << std::endl;

    // Probar igualF
    std::cout << "fila1 y fila2 son iguales? " << (fila1.igualF(fila2) ? "Si" : "No") << std::endl;
    std::cout << std::endl;
    
    // Probar concat
    Fila filaConcatenada = fila1.concat(fila2);
    std::cout << "Fila concatenada: ";
    filaConcatenada.mostrarFila();
    std::cout << std::endl;

    // Probar invertir
    Fila filaInvertida = fila1.invertir();
    std::cout << "Fila invertida: ";
    filaInvertida.mostrarFila();
    std::cout << std::endl;

    // Probar mezclar
    Fila filaMezclada = Fila::mezclar(fila1, fila2);
    std::cout << "Fila mezclada: ";
    filaMezclada.mostrarFila();
    std::cout << std::endl;

    return 0;
}
