/* 
 * File:   main.cpp
 * Author: nelson
 *
 * Created on 31 de mayo de 2015, 21:43
 */
#include "Tablero.h"

#include "Juego.h"
#include "JugadorHumano.h"
#include <iostream>
#include <cstdlib>
#include <locale>

#include <unistd.h>
using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    system("clear");
    setlocale(LC_CTYPE, "");
    bool player = true;
    Tablero *tab = new Tablero();
    JugadorHumano blanca = JugadorHumano(player);
    Jugador negra = Jugador(*tab, !player, 4);
     
    while(!tab->juegoTerminado(player)){
        tab->mostrar();
        
        tab->operator =(player? blanca.movimiento(*tab) : negra.movimiento(false));
        system("clear");
        negra.Actualizar(*tab, 4);
        player = !player;
        
    }
    if(player == true){
        wcout << "\nGano CPU Negra" << endl;
    }else{
        wcout << "\nGano CPU Blanca" << endl;
    }
    return 0;
}

