/* 
 * File:   JugadorHumano.h
 * Author: Nelson Cariqueo, Camila Vera, Diego Higuera
 *
 * Created on 18 de junio de 2015, 9:40
 */

#ifndef JUGADORHUMANO_H
#define	JUGADORHUMANO_H
#include <list>
#include <ctype.h>
#include <stdio.h>
#include "Tablero.h"
#include <iostream>
#include <cstdlib>
#include <iomanip>
#include <unistd.h>
using namespace std;

class JugadorHumano {
public:
    JugadorHumano(bool player);
    Tablero& movimientoBlanca(const Tablero& t);
    Tablero movimientoNegra(const Tablero& t);
    
    bool jugador;
    int X1;
    int Y1;
    int X2;
    int Y2;
};

#endif	/* JUGADORHUMANO_H */

