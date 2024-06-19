#include "cochera.cpp"

int main()
{
    Cochera cochera1(5);

    cochera1.estacionar(1);
    cochera1.estacionar(2);
    cochera1.estacionar(3);
    cochera1.estacionar(4);
    cochera1.estacionar(5);

    std::cout << "Ultimo auto estacionado en cochera 1: " << cochera1.ultimo() << std::endl;

    cochera1.mostrarAutos();

    Cochera cochera2(3);

    bool movido = MOVERAUTOS(cochera1, cochera2, 3);
    if (movido)
    {
        std::cout << "Se movieron los autos exitosamente." << std::endl;
    }
    else
    {
        std::cout << "No se pudieron mover los autos." << std::endl;
    }

    cochera1.mostrarAutos();
    cochera2.mostrarAutos();

    std::cout << "Capacidad total de cochera 1: " << cochera1.capacidadTotal() << std::endl;
    std::cout << "Estacionamientos libres en cochera 1: " << cochera1.estacionamientosLibres() << std::endl;
    std::cout << "Auto 2 esta estacionado en cochera 1: " << (cochera1.estacionado(2) ? "Si" : "No") << std::endl;

    cochera1.salir(2);
    std::cout << "Auto 2 sale de la cochera 1." << std::endl;
    cochera1.mostrarAutos();

    return 0;
}