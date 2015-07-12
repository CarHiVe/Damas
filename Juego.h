/* 
 * File:   Juego.h
 * Author: nelson
 *
 * Created on 3 de junio de 2015, 22:33
 */

#ifndef JUEGO_H
#define	JUEGO_H
#include "Jugador.h"
#include "Tablero.h"
#include "JugadorHumano.h"

using namespace std;

class Juego {
public:
    Tablero *tab;
    Jugador negra;
    JugadorHumano blanca;
    bool player;
    
    Juego();
};

#endif	/* JUEGO_H */

