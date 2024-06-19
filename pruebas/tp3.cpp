#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

// Función para escribir los dígitos de un número en orden inverso (Pregunta 2)
void escribirDigitosInverso(int n) {
    if (n == 0) return;
    cout << n % 10;
    escribirDigitosInverso(n / 10);
}

// Función iterativa para encontrar el dígito de mayor valor en un número (Pregunta 3)
int digitoMayorIterativo(int n) {
    int maxDigit = 0;
    while (n > 0) {
        int digit = n % 10;
        if (digit > maxDigit) maxDigit = digit;
        n /= 10;
    }
    return maxDigit;
}

// Función recursiva para encontrar el dígito de mayor valor en un número (Pregunta 3)
int digitoMayorRecursivo(int n) {
    if (n < 10) return n;
    int maxResto = digitoMayorRecursivo(n / 10);
    return max(maxResto, n % 10);
}

// Función recursiva para verificar si una palabra es un palíndromo (Pregunta 4)
bool esPalindromo(const char* palabra, int inicio, int fin) {
    if (inicio >= fin) return true;
    if (palabra[inicio] != palabra[fin]) return false;
    return esPalindromo(palabra, inicio + 1, fin - 1);
}

// Función recursiva para verificar si un arreglo está ordenado de forma ascendente (Pregunta 5)
bool estaOrdenadoAscendente(const vector<int>& arreglo, int indice) {
    if (indice == arreglo.size() - 1) return true;
    if (arreglo[indice] > arreglo[indice + 1]) return false;
    return estaOrdenadoAscendente(arreglo, indice + 1);
}

// Estructura de un nodo de la lista enlazada
struct Nodo {
    int dato;
    Nodo* siguiente;
};

// Función recursiva para encontrar la posición del k-ésimo elemento en una lista enlazada (Pregunta 6)
int posicionK(Nodo* nodo, int k) {
    if (k == 0) return nodo->dato;
    return posicionK(nodo->siguiente, k - 1);
}

// Función recursiva para verificar si todos los elementos de una lista están contenidos en otra lista (Pregunta 7)
bool estaContenida(Nodo* lista1, Nodo* lista2) {
    if (lista1 == nullptr) return true;
    if (lista2 == nullptr) return false;
    if (lista1->dato == lista2->dato) return estaContenida(lista1->siguiente, lista2->siguiente);
    return estaContenida(lista1, lista2->siguiente);
}

// Función Divide y Conquista para buscar un par de enteros contiguos en un arreglo ordenado (Pregunta 8)
bool buscaPar(const vector<int>& v, int x, int y, int inicio, int fin) {
    if (inicio >= fin) return false;
    int medio = (inicio + fin) / 2;
    if (v[medio] == x && v[medio + 1] == y) return true;
    if (v[medio] < x) return buscaPar(v, x, y, medio + 1, fin);
    return buscaPar(v, x, y, inicio, medio);
}

int main() {
    // Ejemplos de uso

    // Pregunta 2
    cout << "Digitos en orden inverso de 12345: ";
    escribirDigitosInverso(12345);
    cout << endl;

    // Pregunta 3
    int num = 1823;
    cout << "Digito de mayor valor en " << num << ": " << digitoMayorIterativo(num) << endl;
    cout << "Digito de mayor valor en " << num << ": " << digitoMayorRecursivo(num) << endl;

    // Pregunta 4
    const char* palabra = "radar";
    cout << "¿Es '" << palabra << "' un palindromo? " << (esPalindromo(palabra, 0, strlen(palabra) - 1) ? "Si" : "No") << endl;

    // Pregunta 5
    vector<int> arreglo = {1, 2, 3, 4, 5};
    cout << "¿El arreglo esta ordenado de forma ascendente? " << (estaOrdenadoAscendente(arreglo, 0) ? "Si" : "No") << endl;

    // Pregunta 6 (Uso simplificado de la lista enlazada)
    Nodo* lista = new Nodo{1, new Nodo{2, new Nodo{3, nullptr}}};
    cout << "El elemento en la posicion 1 es: " << posicionK(lista, 1) << endl;

    // Pregunta 7 (Uso simplificado de la lista enlazada)
    Nodo* lista1 = new Nodo{1, new Nodo{2, nullptr}};
    Nodo* lista2 = new Nodo{1, new Nodo{2, new Nodo{3, nullptr}}};
    cout << "¿Los elementos de la primera lista estan contenidos en la segunda lista? " << (estaContenida(lista1, lista2) ? "Si" : "No") << endl;

    // Pregunta 8
    vector<int> v = {1, 2, 3, 5, 7, 8};
    int a = 3, b = 5;
    cout << "¿El par (" << a << ", " << b << ") esta contiguo en el arreglo ordenado? " << (buscaPar(v, a, b, 0, v.size() - 1) ? "Si" : "No") << endl;

    return 0;
}