/* 
 * File:   Juego.cpp
 * Author: nelson
 * 
 * Created on 3 de junio de 2015, 22:33
 */

#include "Juego.h"
#include <cstdlib>
#include <iostream>
using namespace std;


/*Juego::Juego() {
    player = true;
    tab = new Tablero();
    blanca = JugadorHumano(player);
    negra = Jugador(*tab, 4, !player);
     
    while(!tab->juegoTerminado(player)){
        tab->mostrar();
        
        tab->operator =(player? blanca->movimiento(*tab) : negra->movimiento(false));
        system("clear");
        negra->Actualizar(*tab, 4);
        player = !player;
        
    }
    if(player == true){
        wcout << "\nGano CPU Negra" << endl;
    }else{
        wcout << "\nGano CPU Blanca" << endl;
    }
    
}*/