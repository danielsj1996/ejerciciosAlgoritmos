#include <iostream>
#include <cstdlib>

struct Nodo
{
    int tiempo;
    Nodo *siguiente;
};

struct Procesador
{
    int cantidad;
    Nodo *primera;
    Nodo *ultima;
};

struct Resultado
{
    int cantAtendidas;
    int cantNoAtendidas;
};

Procesador INACTIVO()
{
    Procesador procesador;
    procesador.cantidad = 0;
    procesador.primera = nullptr;
    procesador.ultima = nullptr;
    return procesador;
}

bool ESTAINACTIVO(Procesador p)
{
    return (p.primera == nullptr && p.ultima == nullptr);
};

Procesador AGREGAR(Procesador p, int a)
{
    Nodo *nuevo = new Nodo();
    nuevo->tiempo = a;
    nuevo->siguiente = nullptr;
    if (ESTAINACTIVO(p))
    {
        p.primera = nuevo;
        p.ultima = nuevo;
    }
    else
    {
        p.ultima->siguiente = nuevo;
        p.ultima = nuevo;
    }
    p.cantidad++;
    return p;
}
int SIGUIENTE(Procesador p)
{
    if (ESTAINACTIVO(p))
    {
        std::cout << "No se encuentran procesos en ejecucion" << std::endl;
        return -9999;
    }
    return p.primera->siguiente ? p.primera->siguiente->tiempo : -9999;
}

Procesador OTORGAR(Procesador P)
{
    if (ESTAINACTIVO(P))
    {
        return INACTIVO();
    }
    else
    {
        Nodo *aux = P.primera;
        P.primera = P.primera->siguiente;
        free(aux);
        P.cantidad--;
        if (P.cantidad == 0)
        {
            P.ultima = nullptr;
        }
        return P;
    }
}

int ULTIMA(Procesador p)
{
    if (ESTAINACTIVO(p))
    {
        std::cout << "No se encuentran aplicaciones en ejecucion" << std::endl;
        return -9999;
    }
    else
    {
        return p.ultima->tiempo;
    }
}

int CANTIDAD(Procesador p)
{
    return p.cantidad;
}

Resultado ATENDIDO(Procesador P, int tiempoX) {
    int cantAtendidas = 0;
    int totalAplicaciones = P.cantidad;

    while (P.primera != nullptr && tiempoX >= P.primera->tiempo) {
        tiempoX -= P.primera->tiempo;
        P = OTORGAR(P);
        cantAtendidas++;
    }

    Resultado resultado;
    resultado.cantAtendidas = cantAtendidas;
    resultado.cantNoAtendidas = totalAplicaciones - cantAtendidas;
    return resultado;
}

int main()
{

    Procesador p = INACTIVO();

    if (ESTAINACTIVO(p))
    {
        std::cout << "\nEsta vacio" << std::endl;
    }
    else
    {
        std::cout << "\nNo Esta vacio" << std::endl;
    }

    p = AGREGAR(p, 1);
    p = AGREGAR(p, 1);
    p = AGREGAR(p, 2);
    p = AGREGAR(p, 2);
    p = AGREGAR(p, 3);
    p = AGREGAR(p, 6);
    p = AGREGAR(p, 7);
    p = AGREGAR(p, 8);

    std::cout << "\nEl primero es: " << p.primera->tiempo << " y el siguiente es " << SIGUIENTE(p) << std::endl;
    std::cout << "\nEl ultimo es: " << ULTIMA(p) << std::endl;
    std::cout << "\nLa cantidad es: " << CANTIDAD(p) << std::endl;

    Resultado resultado = ATENDIDO(p, 15);
    std::cout << "\nCantidad de aplicaciones atendidas: " << resultado.cantAtendidas << std::endl;
    std::cout << "\nCantidad de aplicaciones no atendidas: " << resultado.cantNoAtendidas << std::endl;

    return 0;
}