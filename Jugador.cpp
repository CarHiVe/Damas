/* 
 * File:   Jugador.cpp
 * Author: Nelson Cariqueo, Camila Vera, Diego Higuera
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

Tablero& Jugador::movimientoNegra(bool player){
    vector<Tablero> seleccionados;
    vector<int> gana;
    int ganaOempate = 0;
    int pierde = 0;
    
    list<Arbol>::iterator ini = miArbol.hijos.begin();
    list<Arbol>::iterator fin = miArbol.hijos.end();
    
    int cuentas = 0;
    while(ini != fin){
        if(ini->tab->cuantasCome > cuentas)
            cuentas = ini->tab->cuantasCome;
        ini++;
    }
    
    
    ini = miArbol.hijos.begin();
    fin = miArbol.hijos.end();
    
    while(ini != fin){
        ganaOempate = 0;
        pierde = 0;
        if(!ini->hijos.empty()){
            list<Arbol>::iterator ini2 = ini->hijos.begin();
            list<Arbol>::iterator fin2 = ini->hijos.end();
            
            while(ini2 != fin2){
                int totalNodos = 0;
                if(!ini2->hijos.empty()){
                    list<Arbol>::iterator ini3 = ini2->hijos.begin();
                    list<Arbol>::iterator fin3 = ini2->hijos.end();
                    
                    while(ini3 != fin3){
                        
                        if(!ini3->hijos.empty()){
                            list<Arbol>::iterator ini4 = ini3->hijos.begin();
                            list<Arbol>::iterator fin4 = ini3->hijos.end();
                            
                            totalNodos+=ini3->hijos.size();
                            
                            while(ini4 != fin4){
                                if(ini4->tab->heuristic(player, !player) >= 0)
                                    ganaOempate += 1;
                                
                                if(ini4->tab->heuristic(player, !player) < 0)
                                    pierde += 1;
                                ini4++;
                            }
                        }else{
                            if(ini3->tab->juegoTerminado(!player) || ini3->tab->cantPiezas(!player) < ini->tab->cantPiezas(!player) || ini3->tab->cantPiezas(!player) <= ini3->tab->cantPiezas(player))
                                seleccionados.push_back(*ini->tab);
                            
                        }
                        
                        /*if(ini3->tab->heuristic(!player, player) < 0)
                            pierde+=1;*/
                        
                        ini3++;
                    }
                }else{
                    if(ini2->tab->juegoTerminado(!player) || ini2->tab->cantPiezas(!player) < ini->tab->cantPiezas(!player) || ini2->tab->cantPiezas(!player) <= ini2->tab->cantPiezas(player))
                        seleccionados.push_back(*ini->tab);
                }
                if((ganaOempate*100)/totalNodos >= 80 || (pierde*100)/totalNodos <=20 /*&& ini->tab->cuantasCome == cuentas*/){
                    seleccionados.push_back(*ini->tab);
                    gana.push_back(ganaOempate);
                    break;
                }
                /*if(ini2->tab->heuristic(player, !player) >= 0)
                    ganaOempate+=1;*/
                
            
                ini2++;
            }
        }else{
            if(ini->tab->juegoTerminado(!player) || ini->tab->cantPiezas(!player) < miArbol.tab->cantPiezas(!player) || ini->tab->cantPiezas(!player) <= ini->tab->cantPiezas(player))
                seleccionados.push_back(*ini->tab);
        }
        
        /*if(ini->tab->heuristic(!player, player) < 0)
            pierde+=1;
        
        if(ganaOempate > pierde)
            seleccionados.push_back(*ini->tab);*/
        
        ini++;
    }
    
    int tempInt;
    Tablero *aux = new Tablero();
    
    for(int i=1; i<gana.size(); i++){
        for(int j=0; j<gana.size()-i; j++){
            if(gana[j] > gana[j+1]){
                tempInt = gana[j];
                gana[j] = gana[j+1];
                gana[j+1] = tempInt;
                
                aux->operator =(seleccionados[j]);
                seleccionados[j].operator =(seleccionados[j+1]);
                seleccionados[j+1].operator =(*aux);
            }
        }
    }
    Tablero *tmp = new Tablero(seleccionados[0]);
    /*int eleccion = 0, tamanio = seleccionados.size();
    vector<Tablero> comen;
    Tablero *aux;
    for(int i=0; i<seleccionados.size(); i++){
        if(seleccionados[i].comer == 2){
            comen.push_back(seleccionados[i]);
        }
    }
    
    if(comen.empty()){
        srand(time(NULL));
        
        eleccion = int(rand()%tamanio);
        aux = new Tablero(seleccionados[eleccion]);
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
    }*/
    
    return /**aux*/*tmp;
}

Tablero& Jugador::movimientoBlanca(bool player){
    vector<Tablero> seleccionados;
    vector<int> gana;
    int ganaOempate = 0;
    int pierde = 0;
    
    list<Arbol>::iterator ini = miArbol.hijos.begin();
    list<Arbol>::iterator fin = miArbol.hijos.end();
    
    while(ini != fin){
        ganaOempate = 0;
        pierde = 0;
        if(!ini->hijos.empty()){
            list<Arbol>::iterator ini2 = ini->hijos.begin();
            list<Arbol>::iterator fin2 = ini->hijos.end();
            
            while(ini2 != fin2){
                int totalNodos = 0;
                if(!ini2->hijos.empty()){
                    list<Arbol>::iterator ini3 = ini2->hijos.begin();
                    list<Arbol>::iterator fin3 = ini2->hijos.end();
                    
                    while(ini3 != fin3){
                        
                        if(!ini3->hijos.empty()){
                            list<Arbol>::iterator ini4 = ini3->hijos.begin();
                            list<Arbol>::iterator fin4 = ini3->hijos.end();
                            
                            totalNodos+=ini3->hijos.size();
                            
                            while(ini4 != fin4){
                                if(ini4->tab->heuristic(player, !player) >= 0)
                                    ganaOempate += 1;
                                
                                if(ini4->tab->heuristic(player, !player) < 0)
                                    pierde += 1;
                                ini4++;
                            }
                        }else{
                            if(ini3->tab->juegoTerminado(!player) || ini3->tab->cantPiezas(!player) < ini->tab->cantPiezas(!player) || ini3->tab->cantPiezas(!player) <= ini3->tab->cantPiezas(player))
                                seleccionados.push_back(*ini->tab);
                            
                        }
                        
                        /*if(ini3->tab->heuristic(!player, player) < 0)
                            pierde+=1;*/
                        
                        ini3++;
                    }
                }else{
                    if(ini2->tab->juegoTerminado(!player) || ini2->tab->cantPiezas(!player) < ini->tab->cantPiezas(!player) || ini2->tab->cantPiezas(!player) <= ini2->tab->cantPiezas(player))
                        seleccionados.push_back(*ini->tab);
                }
                if((ganaOempate*100)/totalNodos >= 80 || (pierde*100)/totalNodos <=20){
                    seleccionados.push_back(*ini->tab);
                    gana.push_back(ganaOempate);
                    break;
                }
                /*if(ini2->tab->heuristic(player, !player) >= 0)
                    ganaOempate+=1;*/
                
            
                ini2++;
            }
        }else{
            if(ini->tab->juegoTerminado(!player) || ini->tab->cantPiezas(!player) < miArbol.tab->cantPiezas(!player) || ini->tab->cantPiezas(!player) <= ini->tab->cantPiezas(player))
                seleccionados.push_back(*ini->tab);
        }
        
        /*if(ini->tab->heuristic(!player, player) < 0)
            pierde+=1;
        
        if(ganaOempate > pierde)
            seleccionados.push_back(*ini->tab);*/
        
        ini++;
    }
    
    int tempInt;
    Tablero *aux = new Tablero();
    
    for(int i=1; i<gana.size(); i++){
        for(int j=0; j<gana.size()-i; j++){
            if(gana[j] > gana[j+1]){
                tempInt = gana[j];
                gana[j] = gana[j+1];
                gana[j+1] = tempInt;
                
                aux->operator =(seleccionados[j]);
                seleccionados[j].operator =(seleccionados[j+1]);
                seleccionados[j+1].operator =(*aux);
            }
        }
    }
    Tablero *tmp = new Tablero(seleccionados[0]);
    /*int eleccion = 0, tamanio = seleccionados.size();
    vector<Tablero> comen;
    Tablero *aux;
    for(int i=0; i<seleccionados.size(); i++){
        if(seleccionados[i].comer == 2){
            comen.push_back(seleccionados[i]);
        }
    }
    
    if(comen.empty()){
        srand(time(NULL));
        
        eleccion = int(rand()%tamanio);
        aux = new Tablero(seleccionados[eleccion]);
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
    }*/
    
    return /**aux*/*tmp;
}

void Jugador::Actualizar(const Tablero& t, int prof){
    miArbol = Arbol(t, jugador);
    
    while(prof > 0){
        miArbol.Brote(jugador);
        prof--;
    }
}