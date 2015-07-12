/* 
 * File:   Jugador.cpp
 * Author: nelson
 * 
 * Created on 3 de junio de 2015, 21:54
 */

#include "Jugador.h"


Jugador::Jugador(const Tablero& t, bool player, int prof) {
    miArbol = Arbol(t, player);
    jugador = player;
    generados = list<Tablero>();
    while(prof > 0){
        miArbol.Brote(true);
        prof--;
    }
}

Tablero& Jugador::movimiento(bool player){
    vector<Tablero> seleccionados;
    
    
    list<Arbol>::iterator ini = miArbol.hijos.begin();
    list<Arbol>::iterator fin = miArbol.hijos.end();
    
    while(ini != fin){
        if(!ini->hijos.empty()){
            list<Arbol>::iterator ini2 = ini->hijos.begin();
            list<Arbol>::iterator fin2 = ini->hijos.end();
        
            while(ini2 != fin2){
                if(!ini2->hijos.empty()){
                    list<Arbol>::iterator ini3 = ini2->hijos.begin();
                    list<Arbol>::iterator fin3 = ini2->hijos.end();
            
                    while(ini3 != fin3){
                        if(!ini3->hijos.empty()){
                            list<Arbol>::iterator ini4 = ini3->hijos.begin();
                            list<Arbol>::iterator fin4 = ini3->hijos.end();
                
                            while(ini4 != fin4){
                                if(ini4->tab->juegoTerminado(!player) || ini4->tab->cantPiezas(!player) <= ini4->tab->cantPiezas(player))
                                    seleccionados.push_back(*ini->tab);
                    
                                ini4++;
                            }
                        }else{
                            if(ini3->tab->juegoTerminado(!player) || ini3->tab->cantPiezas(!player) <= ini3->tab->cantPiezas(player))
                                seleccionados.push_back(*ini->tab);
                        }
                
                        ini3++;
                    }
                }else{
                    if(ini2->tab->juegoTerminado(!player) || ini2->tab->cantPiezas(!player) <= ini2->tab->cantPiezas(player))
                        seleccionados.push_back(*ini->tab);
                }
            
                ini2++;
            }
        }else{
            if(ini->tab->juegoTerminado(!player) || ini->tab->cantPiezas(!player) <= ini->tab->cantPiezas(player))
                seleccionados.push_back(*ini->tab);
        }
        
        ini++;
    }
    srand(time(NULL));
    Tablero *aux = new Tablero(seleccionados[rand()%(seleccionados.size())]);
    if(generados.empty())
        generados.push_back(*aux);
    else{
        int cont = 0;
        do{
        list<Tablero>::iterator ini = generados.begin();
        list<Tablero>::iterator fin = generados.end();
        cont=0;
        while(ini != fin){
            if(ini->equals(*aux) == true)
                cont++;
            ini++;
        }
        
        if(cont == 0)
            generados.push_back(*aux);
        else{
            aux = new Tablero(seleccionados[rand()%seleccionados.size()]);
            cont = 0;
        }
        }while(cont != 0);
    }
    return *aux;
}

void Jugador::Actualizar(const Tablero& t, int prof){
    miArbol = Arbol(t, jugador);
    
    while(prof > 0){
        miArbol.Brote(jugador);
        prof--;
    }
}

/*void Jugador::mostrar(){
    cout << "Jugador " << miArbol.jugador << " PRofundidad 0" <<endl;
    miArbol.tab->mostrar();
    system("pause");
    system("cls");
    
    list<Arbol>::iterator ini = miArbol.hijos.begin();
    list<Arbol>::iterator fin = miArbol.hijos.end();
    
    while(ini != fin){
        cout << "Jugador " << ini->jugador << " PRofundidad 1" <<endl;
        ini->tab->mostrar();
        system("pause");
        system("cls");
        
        list<Arbol>::iterator ini2 = ini->hijos.begin();
        list<Arbol>::iterator fin2 = ini->hijos.end();
        
        while(ini2 != fin2){
            cout << "Jugador " << ini2->jugador << " PRofundidad 2\n" <<endl;
            ini2->tab->mostrar();
            system("pause");
            system("cls");
            
            list<Arbol>::iterator ini3 = ini2->hijos.begin();
            list<Arbol>::iterator fin3 = ini2->hijos.end();
            
            while(ini3 != fin3){
                cout << "Jugador " << ini3->jugador << " PRofundidad 3" <<endl;
                ini3->tab->mostrar();
                system("pause");
                system("cls");
                
                list<Arbol>::iterator ini4 = ini3->hijos.begin();
                list<Arbol>::iterator fin4 = ini3->hijos.end();
                
                while(ini4 != fin4){
                    cout << "Jugador " << ini4->jugador << " PRofundidad 4" <<endl;
                    ini4->tab->mostrar();
                    system("pause");
                    system("cls");
                    ini4++;
                }
                ini3++;
            }
            ini2++;
        }
        ini++;
    }
}*/