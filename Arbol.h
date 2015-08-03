/* 
 * File:   Arbol.h
 * Author: nelson
 *
 * Created on 3 de junio de 2015, 21:12
 */

#ifndef ARBOL_H
#define	ARBOL_H
#include <list>
#include <vector>
#include "Tablero.h"

class Arbol {
public:
    Arbol();
    Arbol(const Tablero& t, bool player);
    void Brote(bool player);
    
    bool jugador;
    list<Arbol> hijos;
    Tablero *tab;
};

#endif	/* ARBOL_H */

