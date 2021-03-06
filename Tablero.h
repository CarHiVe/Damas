/* 
 * File:   Tablero.h
 * Author: Nelson Cariqueo, Camila Vera, Diego Higuera
 *
 * Created on 31 de mayo de 2015, 21:44
 */

#ifndef TABLERO_H
#define	TABLERO_H
#include <cstdlib>
#include <iostream>
#include <list>
#include <locale>
#include <unistd.h>
using namespace std;

class Tablero {
public:
    Tablero();
    Tablero(const Tablero& orig);
    Tablero(const Tablero& t, int I, int J, int codigo);
    Tablero(const Tablero& t, int I1, int J1, int I2, int J2, int codigo);
    void mostrar();
    list<Tablero> getMovimiento(bool player, bool humano);
    list<Tablero> getSalto(int i, int j, int pieza, int ptr, int direccion, bool humano);
    list<Tablero> getMovimientoDerivado(int i, int j, int direccion);
    Tablero& operator =(const Tablero& t);
    
    bool salto(int i1, int j1, int i2, int j2);
    bool abierto(int i, int j);
    bool dentro(int i, int j);
    bool juegoTerminado(bool player);
    int signo(int f);
    bool equals(const Tablero& t);
    int enDiagonal(int i, int j, int x, int y);
    list<Tablero> getEatReina(int i, int j, int ptr, bool humano);
    int cantPiezas(bool jugador);
    int heuristic(bool player1, bool player2);
    
    wchar_t tablero[10][10];
    int tablero2[10][10];
    int cuantasCome;
    bool reinaBlanca;
    bool reinaNegra;
    int comer;
    int ValPieza;
    int X1;
    int Y1;
    int X2;
    int Y2;
};

#endif	/* TABLERO_H */

