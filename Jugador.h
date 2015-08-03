/* 
 * File:   Jugador.h
 * Author: Nelson Cariqueo, Camila Vera, Diego Higuera
 *
 * Created on 3 de junio de 2015, 21:54
 */

#ifndef JUGADOR_H
#define	JUGADOR_H
#include "Arbol.h"
#include "Tablero.h"
#include <unistd.h>
#include <vector>
using namespace std;

class Jugador {
public:
    Jugador(const Tablero& t, bool player, int prof);
    Tablero& movimiento(bool player);
    void Actualizar(const Tablero& t, int prof);
     
    Arbol miArbol;
    bool jugador;
    list<Tablero> generados;
};

#endif	/* JUGADOR_H */

