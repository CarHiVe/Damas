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
#include <ctype.h>
#include <stdio.h>
#include <iomanip>
#include <cstdlib>
#include <locale>
#include <fstream>
#include <string>
#include <unistd.h>
#include <time.h>
using namespace std;

int main(int argc, char** argv) {
    /*Configuracion para utilizar unicode*/
    system("clear");
    setlocale(LC_CTYPE, "");
    wchar_t opcion = 'n';
    //Archivo para guardar los movimientos
    do{
        
        opcion = 'n';
        wcout << "========== BIENVENIDO A CHILE CHECKERS ==========\n\n";
        wcout << "(1) 1 Player (pieza blanca) versus CPU (pieza negra)\n\n";
        wcout << "(2) CPU (pieza blanca) versus 1 Player (pieza negra) \n\n";
        wcout << "(3) 2 player \n\n";
        wcout << "(4) Salir \n\n";
        wcout << "Ingrese opcion : ";
        wcin >> setw(1) >> opcion;
        wcin.ignore(256,'\n'); 
        switch (opcion){
            case '1':{
                system("clear");
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
                    usleep(800000);
                    tab->operator =(player? blanca.movimientoBlanca(*tab) : negra.movimientoNegra(false));
                    
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
                break;
            }
            
            case '2':{
                ofstream moves;
                string nombre_archivo = "Movimientos.txt";
    
                moves.open(nombre_archivo.c_str());
                moves << "====== MOVIMIENTOS REALIZADOS ======\n\n";
    
                //Preparacion de los jugadores
                bool player = true;
                Tablero *tab = new Tablero();
                Jugador blanca = Jugador(*tab, player, 4);
                JugadorHumano negra = JugadorHumano(!player);
     
                while(!tab->juegoTerminado(player)){ //Mientras hayan movimientos disponibles
                    tab->mostrar();
        
                    tab->operator =(player? blanca.movimientoBlanca(true) : negra.movimientoNegra(*tab));
        
                    if(player == true)
                        moves << "Blanca\tmovio de " << char(tab->X1+65) << tab->Y1 << " a " << char(tab->X2+65) << tab->Y2 << endl << endl;
                    else
                        moves << "Negra\tmovio de " << char(tab->X1+65) << tab->Y1 << " a " << char(tab->X2+65) << tab->Y2 << endl << endl;
        
                    system("clear");
                    blanca.Actualizar(*tab, 4);
                    player = !player;
        
                }
    
                moves.close();
                if(player == true){
                    wcout << "\nGano CPU :C" << endl;
                }else{
                    wcout << "\nUSTED GANO, FELICITACIONES! C:" << endl;
                }
                break;
            }
            
            case '3':{
                ofstream moves;
                string nombre_archivo = "Movimientos.txt";
    
                moves.open(nombre_archivo.c_str());
                moves << "====== MOVIMIENTOS REALIZADOS ======\n\n";
    
                //Preparacion de los jugadores
                bool player = true;
                Tablero *tab = new Tablero();
                JugadorHumano blanca = JugadorHumano(player);
                JugadorHumano negra = JugadorHumano(!player);
     
                while(!tab->juegoTerminado(player)){ //Mientras hayan movimientos disponibles
                    tab->mostrar();
        
                    tab->operator =(player? blanca.movimientoBlanca(*tab) : negra.movimientoNegra(*tab));
        
                    if(player == true)
                        moves << "Blanca\tmovio de " << char(tab->X1+65) << tab->Y1 << " a " << char(tab->X2+65) << tab->Y2 << endl << endl;
                    else
                        moves << "Negra\tmovio de " << char(tab->X1+65) << tab->Y1 << " a " << char(tab->X2+65) << tab->Y2 << endl << endl;
        
                    system("clear");
                    player = !player;
        
                }
    
                moves.close();
                if(player == true){
                    wcout << "\nGano CPU :C" << endl;
                }else{
                    wcout << "\nUSTED GANO, FELICITACIONES! C:" << endl;
                }
                break;
            }
            
            case '4':
                system("clear");
                wcout << "ADIOS\n\n";
                break;
                
            default:
                system("clear");
                wcout << "Opcion invalida, ingrese otra opcion." << endl;
                usleep(2000000);
                system("clear");
                break;
        }
    }while(opcion != '4');
    return 0;
}

