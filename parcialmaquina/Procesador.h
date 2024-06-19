/*
 * Procesador.h
 *
 *  Created on: 28 jun. 2023
 *      Author: USUARIO
 */

#ifndef PROCESADOR_H_
#define PROCESADOR_H_

typedef int aplicacion;

struct nodo {
    aplicacion tiempo;
    struct nodo* siguiente;
};
typedef struct {
    struct nodo* primera;
    struct nodo* ultima;
    int cantidad;
} Procesador;

typedef struct {
    int cantAtendidas;
    int cantNoAtendidas;
} Resultado;

#endif /* PROCESADOR_H_ */
