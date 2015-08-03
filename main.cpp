/* 
 * File:   main.cpp
 * Author: Nelson Cariqueo, Camila Vera, Diego Higuera
 *
 * Created on 31 de mayo de 2015, 21:43
 */
#include "Tablero.h"
#include "Jugador.h"
#include "JugadorHumano.h"
#include <iostream>
#include <cstdlib>
#include <locale>
#include <fstream>
#include <string>
#include <unistd.h>
using namespace std;

int main(int argc, char** argv) {
    /*Configuracion para utilizar unicode*/
    system("clear");
    setlocale(LC_CTYPE, "");
    //Archivo para guardar los movimientos
    ofstream moves;
    string nombre_archivo = "Movimientos.txt";
    
    moves.open(nombre_archivo.c_str());
    moves << "====== MOVIMIENTOS REALIZADOS ======\n\n";
    
    //Preparacion de los jugadores
    bool player = true;
    Tablero *tab = new Tablero();
    JugadorHumano blanca = JugadorHumano(player);
    Jugador negra = Jugador(*tab, !player, 4);
     
    while(!tab->juegoTerminado(player)){ //Mientras hayan movimientos disponibles
        tab->mostrar();
        
        tab->operator =(player? blanca.movimientoBlanca(*tab) : negra.movimiento(false));
        
        if(player == true)
            moves << "Blanca\tmovio de " << char(tab->X1+65) << tab->Y1 << " a " << char(tab->X2+65) << tab->Y2 << endl << endl;
        else
            moves << "Negra\tmovio de " << char(tab->X1+65) << tab->Y1 << " a " << char(tab->X2+65) << tab->Y2 << endl << endl;
        
        system("clear");
        negra.Actualizar(*tab, 4);
        player = !player;
        
    }
    
    moves.close();
    if(player == true){
        wcout << "\nGano CPU :C" << endl;
    }else{
        wcout << "\nUSTED GANO, FELICITACIONES! C:" << endl;
    }
    return 0;
}

