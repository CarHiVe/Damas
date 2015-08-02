/* 
 * File:   Arbol.cpp
 * Author: nelson
 * 
 * Created on 3 de junio de 2015, 21:12
 */

#include "Arbol.h"

Arbol::Arbol(){

}

Arbol::Arbol(const Tablero& t, bool player) {
    hijos = list<Arbol>();
    tab = new Tablero(t);
    jugador = player;
}

void Arbol::Brote(bool player){
    list<Arbol>::iterator ini = hijos.begin();
    list<Arbol>::iterator fin = hijos.end();
    
    while(ini != fin){
        ini->Brote(!player);
        ini++;
    }
    
    if(hijos.empty()){
        list<Tablero> moves;
        moves.operator =(tab->getMovimiento(player));
        
        list<Tablero>::iterator ini = moves.begin();
        list<Tablero>::iterator fin = moves.end();
        
        while(ini != fin){
            Arbol aux = Arbol(*ini, player);
            hijos.push_back(aux);
            ini++;
        }
    }
}

double Arbol::minimax(bool player){
    if(hijos.empty())
        return tab->heuristic(player, !player);
    
    if(player){
        double a = 0;
        list<Arbol>::iterator ini = hijos.begin();
        list<Arbol>::iterator fin = hijos.end();
        while(ini != fin){
            a = (a > ini->minimax(!player)? a : ini->minimax(!player));
            ini++;
        }
        return a;
    }
    else{
        double a = 999999;
        list<Arbol>::iterator ini = hijos.begin();
        list<Arbol>::iterator fin = hijos.end();
        while(ini != fin){
            a = (a < ini->minimax(!player)? a : ini->minimax(!player));
            ini++;
        }
        return a;
    }
}

list<Tablero> Arbol::movimiento(bool player){
    list<Tablero> movimientos;
    if(player){
        double a = 0;
        list<Arbol>::iterator ini = hijos.begin();
        list<Arbol>::iterator fin = hijos.end();
        while(ini != fin){
            double valor = ini->minimax(!player);
            if(a == 0 || valor > a){
                a = valor;
                movimientos.push_back(*ini->tab);
            }
            ini++;
        }
    }else{
        double a = 9999;
        list<Arbol>::iterator ini = hijos.begin();
        list<Arbol>::iterator fin = hijos.end();
        while(ini != fin){
            double valor = ini->minimax(!player);
            if(a == 9999 || valor < a){
                a = valor;
                movimientos.push_back(*ini->tab);
            }
            ini++;
        }
    }
    return movimientos;
}