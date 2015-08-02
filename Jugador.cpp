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
    
    
    /*vector<Tablero> seleccionados;
    vector<int> profundidad;
    
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
                            
                            int ganaOempate = 0;
                            int gana = 0;
                            int empate = 0;
                            while(ini4 != fin4){
                                if(ini4->tab->heuristic() >= 0)
                                    ganaOempate += 1;
                                if(ini4->tab->heuristic() > 0)
                                    gana += 1;
                                ini4++;
                            }
                            if(((ganaOempate*100)/ini3->hijos.size()) >= 90){
                                seleccionados.push_back(*ini->tab);
                                profundidad.push_back((gana*100)/ini3->hijos.size());
                            }
                        }else{
                            if(ini3->tab->juegoTerminado(!player) || ini3->tab->cantPiezas(!player) < ini->tab->cantPiezas(!player) || ini3->tab->cantPiezas(!player) <= ini3->tab->cantPiezas(player))
                                seleccionados.push_back(*ini->tab);
                        }
                
                        ini3++;
                    }
                }else{
                    if(ini2->tab->juegoTerminado(!player) || ini2->tab->cantPiezas(!player) < ini->tab->cantPiezas(!player) || ini2->tab->cantPiezas(!player) <= ini2->tab->cantPiezas(player))
                        seleccionados.push_back(*ini->tab);
                }
            
                ini2++;
            }
        }else{
            if(ini->tab->juegoTerminado(!player) || ini->tab->cantPiezas(!player) < miArbol.tab->cantPiezas(!player) || ini->tab->cantPiezas(!player) <= ini->tab->cantPiezas(player))
                seleccionados.push_back(*ini->tab);
        }
        
        ini++;
    }
    vector<Tablero> comen;
    Tablero *aux;
    for(int i=0; i<seleccionados.size(); i++){
        if(seleccionados[i].comer > 2){
            comen.push_back(seleccionados[i]);
        }
    }
    srand(time(NULL));
    if(comen.empty()){
        aux = new Tablero(seleccionados[rand()%(seleccionados.size())]);
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
    }else{
        aux = new Tablero(comen[rand()%(comen.size())]);
        
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
                    aux = new Tablero(comen[rand()%comen.size()]);
                    cont = 0;
                }
            }while(cont != 0);
        }
    }
    
    return *aux;*/
}

void Jugador::Actualizar(const Tablero& t, int prof){
    miArbol = Arbol(t, jugador);
    
    while(prof > 0){
        miArbol.Brote(jugador);
        prof--;
    }
}

/*void Jugador::mostrar(){
    wcout << "Jugador " << miArbol.jugador << " PRofundidad 0" <<endl;
    miArbol.tab->mostrar();
    cin.ignore().get();
    system("clear");
    
    list<Arbol>::iterator ini = miArbol.hijos.begin();
    list<Arbol>::iterator fin = miArbol.hijos.end();
    
    while(ini != fin){
        wcout << "Jugador " << ini->jugador << " PRofundidad 1" <<endl;
        wcout << "cercania = " << ini->tab->verificarCercania(ini->jugador) << endl;
        ini->tab->mostrar();
        cin.ignore().get();
        system("clear");
        
        list<Arbol>::iterator ini2 = ini->hijos.begin();
        list<Arbol>::iterator fin2 = ini->hijos.end();
        
        while(ini2 != fin2){
            wcout << "Jugador " << ini2->jugador << " PRofundidad 2\n" <<endl;
            wcout << "cercania = " << ini2->tab->verificarCercania(ini->jugador) << endl;
            ini2->tab->mostrar();
            cin.ignore().get();
            system("clear");
            
            list<Arbol>::iterator ini3 = ini2->hijos.begin();
            list<Arbol>::iterator fin3 = ini2->hijos.end();
            
            while(ini3 != fin3){
                wcout << "Jugador " << ini3->jugador << " PRofundidad 3" <<endl;
                wcout << "cercania = " << ini3->tab->verificarCercania(ini->jugador) << endl;
                ini3->tab->mostrar();
                cin.ignore().get();
                system("clear");
                
                list<Arbol>::iterator ini4 = ini3->hijos.begin();
                list<Arbol>::iterator fin4 = ini3->hijos.end();
                
                while(ini4 != fin4){
                    wcout << "Jugador " << ini4->jugador << " PRofundidad 4" <<endl;
                    wcout << "cercania = " << ini4->tab->verificarCercania(ini->jugador) << endl;
                    ini4->tab->mostrar();
                    cin.ignore().get();
                    system("clear");
                    ini4++;
                }
                ini3++;
            }
            ini2++;
        }
        ini++;
    }
}*/