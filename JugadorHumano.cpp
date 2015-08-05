/* 
 * File:   JugadorHumano.cpp
 * Author: Nelson Cariqueo, Diego Higuera, Camila Vera
 * 
 * Created on 18 de junio de 2015, 9:40
 */

#include "JugadorHumano.h"

JugadorHumano::JugadorHumano(bool player){
    jugador = player;
}

Tablero& JugadorHumano::movimientoBlanca(const Tablero& t){
    bool accion = false;
    list<Tablero> auxiliar;
    
    wchar_t move[4];
    wchar_t opcion, es = 9675;
    int desdeX;
    int desdeY;
    Tablero *aux = new Tablero(t);
        do{
            list<Tablero> come;
            auxiliar.operator =(aux->getMovimiento(jugador));
            list<Tablero>::iterator ini = auxiliar.begin();
            list<Tablero>::iterator fin = auxiliar.end();
            while(ini != fin){
                
                if(ini->comer > 0){
                    desdeX = ini->X1;
                    desdeY = ini->Y1;
                    come.push_back(*ini);
                    break;
                }
                ini++;
            }
            move[0] = 'n';
            move[1] = 'n';
            move[2] = 'n';
            move[3] = 'n';
            int invalido = 0;
            /*Si la lista comer no está vacía, entonces comienza esta sección
            que sirve para comer*/
            if(!come.empty()){
                wcout << "\nUsted es " << es << ". Ingrese coordenadas (por ejemplo: h4g3): ";
                wcin >> setw(1) >> move[0];
                wcin >> setw(1) >> move[1];
                wcin >> setw(1) >> move[2];
                wcin >> setw(1) >> move[3];
                wcin.ignore(256,'\n');    
                move[0] = toupper(move[0]);
                move[1] = toupper(move[1]);
                move[2] = toupper(move[2]);
                move[3] = toupper(move[3]);
                X1 = (int)move[0] - 65;
                X2 = (int)move[2] - 65;
                Y1 = (int)move[1] - 48;
                Y2 = (int)move[3] - 48;
                if(((int)move[0] > 64 && (int)move[0] < 75) && ((int)move[2] > 64 && (int)move[2] < 75)){
                    if((Y1 >= 0 && Y1 < 10) && (Y2 >= 0 && Y2 < 10)){
                        int pieza = aux->tablero2[X1][Y1];
                    
                        if(pieza == 1){
                            int direccion = 0;
                            if(X2-X1 < 0 && Y2-Y1 < 0)
                                direccion = 0;
                            if(X2-X1 < 0 && Y2-Y1 > 0)
                                direccion = 1;
                        
                            if(aux->salto(X1, Y1, X1-1, Y1-1) && X1-2 == X2 && Y1-2 == Y2){
                                aux = new Tablero(*aux, X1, Y1, 4);
                                
                                list<Tablero>::iterator iniCome = come.begin();
                                list<Tablero>::iterator finCome = come.end();
                                bool existe = false;
                                
                                /*while(iniCome != finCome){
                                    if(iniCome->equals(*aux) == true)
                                        existe = true;
                                    ini++;
                                }*/
                                
                                //if(existe == true){
                                    list<Tablero> comer;
                                    auxiliar.operator =(aux->getMovimiento(jugador));
                                    list<Tablero>::iterator ini = auxiliar.begin();
                                    list<Tablero>::iterator fin = auxiliar.end();
                                    while(ini != fin){
                                        if(ini->comer > 0 && X2 == ini->X1 && Y2 == ini->Y1 && /*ini->tablero2[X2][Y2] != 2*/ X2 != 0)
                                            comer.push_back(*ini);
                                        ini++;
                                    }
                                    if(comer.empty())
                                        return *aux;
                                    else{
                                        system("clear");
                                        aux->mostrar();
                                    }
                                /*}
                                else{
                                    wcout << "Movimiento invalido." << endl;
                                }*/
                            }else{
                                if(aux->salto(X1, Y1, X1-1, Y1+1) && X1-2 == X2 && Y1+2 == Y2 ){
                                    aux = new Tablero(*aux, X1, Y1, 5);
                                    
                                    list<Tablero>::iterator iniCome = come.begin();
                                    list<Tablero>::iterator finCome = come.end();
                                    bool existe = false;
                                
                                    /*while(iniCome != finCome){
                                        if(iniCome->equals(*aux) == true)
                                            existe = true;
                                        ini++;
                                    }*/
                                
                                    //if(existe == true){
                                        list<Tablero> comer;
                                        auxiliar.operator =(aux->getMovimiento(jugador));
                                        list<Tablero>::iterator ini = auxiliar.begin();
                                        list<Tablero>::iterator fin = auxiliar.end();
                                        while(ini != fin){
                                            if(ini->comer > 0 && X2 == ini->X1 && Y2 == ini->Y1 && X2 != 0 /*ini->tablero2[X2][Y2] != 2*/)
                                                comer.push_back(*ini);
                                            ini++;
                                        }
                                        if(comer.empty())
                                            return *aux;
                                        else{
                                            system("clear");
                                            aux->mostrar();
                                        }
                                    /*}else{
                                        wcout << "Movimiento invalido." << endl;
                                    }*/
                                }else{
                                    if(desdeX == X1 && desdeY == Y1){
                                        desdeX = X2;
                                        desdeY = Y2;
                                    }
                                    for(int a=1;a<20;a++){
                                        if(aux->abierto(X1-a, Y1-a) && direccion == 0){
                                            if((X1-a == X2 && Y1-a == Y2)){
                                                aux = new Tablero(*aux, X1, Y1, X2, Y2, 0);
                                                //aux = new Tablero(*aux, desdeX, desdeY, 8);
                                                return *aux;
                                            }
                                        }else{                            
                                            if(aux->abierto(X1-a, Y1+a) && direccion == 1){
                                                if((X1-a == X2 && Y1+a == Y2)){
                                                    aux = new Tablero(*aux, X1, Y1, X2, Y2, 0);
                                                    //aux = new Tablero(*aux, desdeX, desdeY, 8);
                                                    return *aux;
                                                }
                                            }else{
                                                if(aux->abierto(X1+a, Y1-a) && direccion == 2){
                                                    if((X1+a == X2 && Y1-a == Y2)){
                                                        aux = new Tablero(*aux, X1, Y1, X2, Y2, 0);
                                                        //aux = new Tablero(*aux, desdeX, desdeY, 8);
                                                        return *aux;
                                                    }
                                                }else{
                                                    if(aux->abierto(X1+a, Y1+a) && direccion == 3){
                                                        if((X1+a == X2 && Y1+a == Y2)){
                                                            aux = new Tablero(*aux, X1, Y1, X2, Y2, 0);
                                                            //aux = new Tablero(*aux, desdeX, desdeY, 8);
                                                            return *aux;
                                                        }
                                                    }else{
                                                        invalido = 1;
                                                        break;
                                                    }
                                                }
                                            }
                                        }
                                    }
                                }
                            }    
                        }

                        if(pieza == 2){
                            int direccion = 0;
                            if(X2-X1 < 0 && Y2-Y1 < 0)
                                direccion = 0;
                            if(X2-X1 < 0 && Y2-Y1 > 0)
                                direccion = 1;
                            if(X2-X1 > 0 && Y2-Y1 < 0)
                                direccion = 2;
                            if(X2-X1 > 0 && Y2-Y1 > 0)
                                direccion = 3;

                            Tablero temporal;
                            temporal.operator =(*aux);
                            int auxX1 = X1;
                            int auxY1 = Y1;
                            for(int i=1;i<10;i++){
                                if(temporal.abierto(X1-1, Y1-1) && direccion == 0){
                                    temporal = Tablero(temporal, X1, Y1, 0);
                                    X1 = X1-1;
                                    Y1 = Y1-1;
                                }else{
                                    if(temporal.salto(X1, Y1, X1-1, Y1-1) && X1-2 == X2 && Y1-2 == Y2 && direccion == 0){
                                        aux = new Tablero(temporal, X1, Y1, 4);
                                        list<Tablero> comer;
                                        auxiliar.operator =(aux->getMovimiento(jugador));
                                        list<Tablero>::iterator ini = auxiliar.begin();
                                        list<Tablero>::iterator fin = auxiliar.end();
                                        while(ini != fin){
                                            if(ini->comer > 0 && X2 == ini->X1 && Y2 == ini->Y1)
                                                comer.push_back(*ini);
                                            ini++;
                                        }
                                        if(comer.empty())
                                            return *aux;
                                        else{
                                            system("clear");
                                            aux->mostrar();
                                        }
                                    }else{
                                        if(temporal.abierto(X1-1, Y1+1) && direccion == 1){
                                            temporal = Tablero(temporal, X1, Y1, 1);
                                            X1 = X1-1;
                                            Y1 = Y1+1;
                                        }else{
                                            if(temporal.salto(X1, Y1, X1-1, Y1+1) && X1-2 == X2 && Y1+2 == Y2 && direccion == 1){
                                                aux = new Tablero(temporal, X1, Y1, 5);
                                                list<Tablero> comer;
                                                auxiliar.operator =(aux->getMovimiento(jugador));
                                                list<Tablero>::iterator ini = auxiliar.begin();
                                                list<Tablero>::iterator fin = auxiliar.end();
                                                while(ini != fin){
                                                    if(ini->comer > 0 && X2 == ini->X1 && Y2 == ini->Y1)
                                                        comer.push_back(*ini);
                                                    ini++;
                                                }
                                                if(comer.empty())
                                                    return *aux;
                                                else{
                                                    system("clear");
                                                    aux->mostrar();
                                                }
                                            }else{
                                                if(temporal.abierto(X1+1, Y1-1) && direccion == 2){
                                                    temporal = Tablero(temporal, X1, Y1, 2);
                                                    X1 = X1+1;
                                                    Y1 = Y1-1;
                                                }else{
                                                    if(temporal.salto(X1, Y1, X1+1, Y1-1) && X1+2 == X2 && Y1-2 == Y2 && direccion == 2){
                                                        aux = new Tablero(temporal, X1, Y1, 6);
                                                        list<Tablero> comer;
                                                        auxiliar.operator =(aux->getMovimiento(jugador));
                                                        list<Tablero>::iterator ini = auxiliar.begin();
                                                        list<Tablero>::iterator fin = auxiliar.end();
                                                        while(ini != fin){
                                                            if(ini->comer > 0 && X2 == ini->X1 && Y2 == ini->Y1)
                                                                comer.push_back(*ini);
                                                            ini++;
                                                        }
                                                        if(comer.empty())
                                                            return *aux;
                                                        else{
                                                            system("clear");
                                                            aux->mostrar();
                                                        }
                                                    }else{
                                                        if(temporal.abierto(X1+1, Y1+1) && direccion == 3){
                                                            temporal = Tablero(temporal, X1, Y1, 3);
                                                            X1 = X1+1;
                                                            Y1 = Y1+1;
                                                        }else{
                                                            if(temporal.salto(X1, Y1, X1+1, Y1+1) && X1+2 == X2 && Y1+2 == Y2 && direccion == 3){
                                                                aux = new Tablero(temporal, X1, Y1, 7);
                                                                list<Tablero> comer;
                                                                auxiliar.operator =(aux->getMovimiento(jugador));
                                                                list<Tablero>::iterator ini = auxiliar.begin();
                                                                list<Tablero>::iterator fin = auxiliar.end();
                                                                while(ini != fin){
                                                                    if(ini->comer > 0 && X2 == ini->X1 && Y2 == ini->Y1)
                                                                        comer.push_back(*ini);
                                                                    ini++;
                                                                }
                                                                if(comer.empty())
                                                                    return *aux;
                                                                else{
                                                                    system("clear");
                                                                    aux->mostrar();
                                                                }   
                                                            }else{
                                                                if(desdeX == auxX1 && desdeY == auxY1){
                                                                    desdeX = X2;
                                                                    desdeY = Y2;
                                                                }
                                                                for(int a=1;a<20;a++){
                                                                    if(aux->abierto(auxX1-a, auxY1-a) && direccion == 0){
                                                                        if((auxX1-a == X2 && auxY1-a == Y2)){
                                                                            aux = new Tablero(*aux, auxX1, auxY1, X2, Y2, 0);
                                                                            aux = new Tablero(*aux, desdeX, desdeY, 8);
                                                                            return *aux;
                                                                        }
                                                                    }else{                            
                                                                        if(aux->abierto(auxX1-a, auxY1+a) && direccion == 1){
                                                                            if((auxX1-a == X2 && auxY1+a == Y2)){
                                                                                aux = new Tablero(*aux, auxX1, auxY1, X2, Y2, 0);
                                                                                aux = new Tablero(*aux, desdeX, desdeY, 8);
                                                                                return *aux;
                                                                            }
                                                                        }else{
                                                                            if(aux->abierto(auxX1+a, auxY1-a) && direccion == 2){
                                                                                if((auxX1+a == X2 && auxY1-a == Y2)){
                                                                                    aux = new Tablero(*aux, auxX1, auxY1, X2, Y2, 0);
                                                                                    aux = new Tablero(*aux, desdeX, desdeY, 8);
                                                                                    return *aux;
                                                                                }
                                                                            }else{
                                                                                if(aux->abierto(auxX1+a, auxY1+a) && direccion == 3){
                                                                                    if((auxX1+a == X2 && auxY1+a == Y2)){
                                                                                        aux = new Tablero(*aux, auxX1, auxY1, X2, Y2, 0);
                                                                                        aux = new Tablero(*aux, desdeX, desdeY, 8);
                                                                                        return *aux;
                                                                                    }
                                                                                }else{
                                                                                    invalido = 1;
                                                                                    break;
                                                                                }
                                                                            }
                                                                        }
                                                                    }
                                                                }
                                                            }
                                                        }
                                                    }
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                        if(invalido == 1)
                             wcout << "Movimiento invalido" << endl;
                    }
                } 
            }else{
                wcout << "\nUsted es " << es << ". Ingrese coordenadas (por ejemplo: h4g3): ";
                wcin >> setw(1) >> move[0];
                wcin >> setw(1) >> move[1];
                wcin >> setw(1) >> move[2];
                wcin >> setw(1) >> move[3];
                wcin.ignore(256,'\n');
                move[0] = toupper(move[0]);
                move[1] = toupper(move[1]);
                move[2] = toupper(move[2]);
                move[3] = toupper(move[3]);
                X1 = (int)move[0] - 65;
                X2 = (int)move[2] - 65;
                Y1 = (int)move[1] - 48;
                Y2 = (int)move[3] - 48;
                if(((int)move[0] > 64 && (int)move[0] < 75) && ((int)move[2] > 64 && (int)move[2] < 75)){
                    if((Y1 >= 0 && Y1 < 10) && (Y2 >= 0 && Y2 < 10)){
                        int pieza = aux->tablero2[X1][Y1];
                        if(pieza == 1){
                            int direccion = 0;
                            if(X2-X1 < 0 && Y2-Y1 < 0)
                                direccion = 0;
                            if(X2-X1 < 0 && Y2-Y1 > 0)
                                direccion = 1;
                            if(aux->abierto(X1-1, Y1-1) && X1-1 == X2 && Y1-1 == Y2 && direccion == 0){
                                aux = new Tablero(*aux, X1, Y1, 0);
                                return *aux;
                            }else{
                                if(aux->abierto(X1-1, Y1+1) && X1-1 == X2 && Y1+1 == Y2 && direccion == 1){
                                    aux = new Tablero(*aux, X1, Y1, 1);
                                    return *aux;
                                }
                            }
                        }

                        if(pieza == 2){
                            int direccion = 0;
                            if(X2-X1 < 0 && Y2-Y1 < 0)
                                direccion = 0;
                            if(X2-X1 < 0 && Y2-Y1 > 0)
                                direccion = 1;
                            if(X2-X1 > 0 && Y2-Y1 < 0)
                                direccion = 2;
                            if(X2-X1 > 0 && Y2-Y1 > 0)
                                direccion = 3;

                            for(int i=1;i<10;i++){
                                if(aux->abierto(X1-i, Y1-i) && direccion == 0){
                                    if((X1-i == X2 && Y1-i == Y2)){
                                        aux = new Tablero(*aux, X1, Y1, X2, Y2, 0);
                                        return *aux;
                                    }
                                }else{                            
                                    if(aux->abierto(X1-i, Y1+i) && direccion == 1){
                                        if((X1-i == X2 && Y1+i == Y2)){
                                            aux = new Tablero(*aux, X1, Y1, X2, Y2, 0);
                                            return *aux;
                                        }
                                    }else{
                                        if(aux->abierto(X1+i, Y1-i) && direccion == 2){
                                            if((X1+i == X2 && Y1-i == Y2)){
                                                aux = new Tablero(*aux, X1, Y1, X2, Y2, 0);
                                                return *aux;
                                            }
                                        }else{
                                            if(aux->abierto(X1+i, Y1+i) && direccion == 3){
                                                if((X1+i == X2 && Y1+i == Y2)){
                                                    aux = new Tablero(*aux, X1, Y1, X2, Y2, 0);
                                                    return *aux;
                                                }
                                            }else
                                                break;
                                        }
                                    }
                                }
                            }
                        }
                        wcout << "Movimiento invalido." << endl;
                    }else
                        wcout << "Ingrese valores entre 0 y 9." << endl;
                }else
                    wcout << "Ingrese valores entre A y J, o, a y j." << endl;
            }
        }while(accion == false);
}                      

Tablero JugadorHumano::movimientoNegra(const Tablero& t){
    bool accion = false;
    list<Tablero> auxiliar;
    
    wchar_t move[4];
    wchar_t opcion, es = 9679;
    int desdeX;
    int desdeY;
    Tablero aux = Tablero(t);
    
        do{
            list<Tablero> comer;
            auxiliar.operator =(aux.getMovimiento(jugador));
            list<Tablero>::iterator ini = auxiliar.begin();
            list<Tablero>::iterator fin = auxiliar.end();
            while(ini != fin){
                if(ini->comer > 0){
                    desdeX = ini->X1;
                    desdeY = ini->Y1;
                    comer.push_back(*ini);
                    break;
                }
                ini++;
            }
            move[0] = 'n';
            move[1] = 'n';
            move[2] = 'n';
            move[3] = 'n';
            int invalido = 0;
            /*Si la lista comer no está vacía, entonces comienza esta sección
            que sirve para comer*/
            if(!comer.empty()){
                wcout << "\nUsted es " << es << ". Ingrese coordenadas (por ejemplo: h4g3): ";
                wcin >> setw(1) >> move[0];
                wcin >> setw(1) >> move[1];
                wcin >> setw(1) >> move[2];
                wcin >> setw(1) >> move[3];
                wcin.ignore(256,'\n');    
                move[0] = toupper(move[0]);
                move[1] = toupper(move[1]);
                move[2] = toupper(move[2]);
                move[3] = toupper(move[3]);
                X1 = (int)move[0] - 65;
                X2 = (int)move[2] - 65;
                Y1 = (int)move[1] - 48;
                Y2 = (int)move[3] - 48;
                if(((int)move[0] > 64 && (int)move[0] < 75) && ((int)move[2] > 64 && (int)move[2] < 75)){
                    if((Y1 >= 0 && Y1 < 10) && (Y2 >= 0 && Y2 < 10)){
                        int pieza = aux.tablero2[X1][Y1];
                    
                        if(pieza == -1){
                            int direccion = 0;
                            if(X2-X1 > 0 && Y2-Y1 < 0)
                                direccion = 0;
                            if(X2-X1 > 0 && Y2-Y1 > 0)
                            direccion = 1;
                        
                            if(aux.salto(X1, Y1, X1+1, Y1-1) && X1+2 == X2 && Y1-2 == Y2){
                                aux = Tablero(aux, X1, Y1, 6);
                                list<Tablero> comer;
                                auxiliar.operator =(aux.getMovimiento(jugador));
                                list<Tablero>::iterator ini = auxiliar.begin();
                                list<Tablero>::iterator fin = auxiliar.end();
                                while(ini != fin){
                                    if(ini->comer > 0 && X2 == ini->X1 && Y2 == ini->Y1 && /*ini->tablero2[X2][Y2] != 2*/ X2 != 9)
                                        comer.push_back(*ini);
                                    ini++;
                                }
                                if(comer.empty())
                                    return aux;
                                else{
                                    system("clear");
                                    aux.mostrar();
                                }
                            }else{
                                if(aux.salto(X1, Y1, X1+1, Y1+1) && X1+2 == X2 && Y1+2 == Y2 ){
                                    aux = Tablero(aux, X1, Y1, 7);
                                    list<Tablero> comer;
                                    auxiliar.operator =(aux.getMovimiento(jugador));
                                    list<Tablero>::iterator ini = auxiliar.begin();
                                    list<Tablero>::iterator fin = auxiliar.end();
                                    while(ini != fin){
                                        if(ini->comer > 0 && X2 == ini->X1 && Y2 == ini->Y1 && X2 != 9 /*ini->tablero2[X2][Y2] != 2*/)
                                            comer.push_back(*ini);
                                        ini++;
                                    }
                                    if(comer.empty())
                                        return aux;
                                    else{
                                        system("clear");
                                        aux.mostrar();
                                    }
                                }else{
                                    if(desdeX == X1 && desdeY == Y1){
                                        desdeX = X2;
                                        desdeY = Y2;
                                    }
                                    for(int a=1;a<20;a++){
                                        if(aux.abierto(X1-a, Y1-a) && direccion == 0){
                                            if((X1-a == X2 && Y1-a == Y2)){
                                                aux = Tablero(aux, X1, Y1, X2, Y2, 0);
                                                aux = Tablero(aux, desdeX, desdeY, 8);
                                                return aux;
                                            }
                                        }else{                            
                                            if(aux.abierto(X1-a, Y1+a) && direccion == 1){
                                                if((X1-a == X2 && Y1+a == Y2)){
                                                    aux = Tablero(aux, X1, Y1, X2, Y2, 0);
                                                    aux = Tablero(aux, desdeX, desdeY, 8);
                                                    return aux;
                                                }
                                            }else{
                                                if(aux.abierto(X1+a, Y1-a) && direccion == 2){
                                                    if((X1+a == X2 && Y1-a == Y2)){
                                                        aux = Tablero(aux, X1, Y1, X2, Y2, 0);
                                                        aux = Tablero(aux, desdeX, desdeY, 8);
                                                        return aux;
                                                    }
                                                }else{
                                                    if(aux.abierto(X1+a, Y1+a) && direccion == 3){
                                                        if((X1+a == X2 && Y1+a == Y2)){
                                                            aux = Tablero(aux, X1, Y1, X2, Y2, 0);
                                                            aux = Tablero(aux, desdeX, desdeY, 8);
                                                            return aux;
                                                        }
                                                    }else{
                                                        invalido = 1;
                                                        break;
                                                    }
                                                }
                                            }
                                        }
                                    }
                                }
                            }    
                        }

                        if(pieza == -2){
                            int direccion = 0;
                            if(X2-X1 < 0 && Y2-Y1 < 0)
                                direccion = 0;
                            if(X2-X1 < 0 && Y2-Y1 > 0)
                                direccion = 1;
                            if(X2-X1 > 0 && Y2-Y1 < 0)
                                direccion = 2;
                            if(X2-X1 > 0 && Y2-Y1 > 0)
                                direccion = 3;

                            Tablero temporal;
                            temporal.operator =(aux);
                            int auxX1 = X1;
                            int auxY1 = Y1;
                            for(int i=1;i<10;i++){
                                if(temporal.abierto(X1-1, Y1-1) && direccion == 0){
                                    temporal = Tablero(temporal, X1, Y1, 0);
                                    X1 = X1-1;
                                    Y1 = Y1-1;
                                }else{
                                    if(temporal.salto(X1, Y1, X1-1, Y1-1) && X1-2 == X2 && Y1-2 == Y2 && direccion == 0){
                                        aux = Tablero(temporal, X1, Y1, 4);
                                        list<Tablero> comer;
                                        auxiliar.operator =(aux.getMovimiento(jugador));
                                        list<Tablero>::iterator ini = auxiliar.begin();
                                        list<Tablero>::iterator fin = auxiliar.end();
                                        while(ini != fin){
                                            if(ini->comer > 0 && X2 == ini->X1 && Y2 == ini->Y1)
                                                comer.push_back(*ini);
                                            ini++;
                                        }
                                        if(comer.empty())
                                            return aux;
                                        else{
                                            system("clear");
                                            aux.mostrar();
                                        }
                                    }else{
                                        if(temporal.abierto(X1-1, Y1+1) && direccion == 1){
                                            temporal = Tablero(temporal, X1, Y1, 1);
                                            X1 = X1-1;
                                            Y1 = Y1+1;
                                        }else{
                                            if(temporal.salto(X1, Y1, X1-1, Y1+1) && X1-2 == X2 && Y1+2 == Y2 && direccion == 1){
                                                aux = Tablero(temporal, X1, Y1, 5);
                                                list<Tablero> comer;
                                                auxiliar.operator =(aux.getMovimiento(jugador));
                                                list<Tablero>::iterator ini = auxiliar.begin();
                                                list<Tablero>::iterator fin = auxiliar.end();
                                                while(ini != fin){
                                                    if(ini->comer > 0 && X2 == ini->X1 && Y2 == ini->Y1)
                                                        comer.push_back(*ini);
                                                    ini++;
                                                }
                                                if(comer.empty())
                                                    return aux;
                                                else{
                                                    system("clear");
                                                    aux.mostrar();
                                                }
                                            }else{
                                                if(temporal.abierto(X1+1, Y1-1) && direccion == 2){
                                                    temporal = Tablero(temporal, X1, Y1, 2);
                                                    X1 = X1+1;
                                                    Y1 = Y1-1;
                                                }else{
                                                    if(temporal.salto(X1, Y1, X1+1, Y1-1) && X1+2 == X2 && Y1-2 == Y2 && direccion == 2){
                                                        aux = Tablero(temporal, X1, Y1, 6);
                                                        list<Tablero> comer;
                                                        auxiliar.operator =(aux.getMovimiento(jugador));
                                                        list<Tablero>::iterator ini = auxiliar.begin();
                                                        list<Tablero>::iterator fin = auxiliar.end();
                                                        while(ini != fin){
                                                            if(ini->comer > 0 && X2 == ini->X1 && Y2 == ini->Y1)
                                                                comer.push_back(*ini);
                                                            ini++;
                                                        }
                                                        if(comer.empty())
                                                            return aux;
                                                        else{
                                                            system("clear");
                                                            aux.mostrar();
                                                        }
                                                    }else{
                                                        if(temporal.abierto(X1+1, Y1+1) && direccion == 3){
                                                            temporal = Tablero(temporal, X1, Y1, 3);
                                                            X1 = X1+1;
                                                            Y1 = Y1+1;
                                                        }else{
                                                            if(temporal.salto(X1, Y1, X1+1, Y1+1) && X1+2 == X2 && Y1+2 == Y2 && direccion == 3){
                                                                aux = Tablero(temporal, X1, Y1, 7);
                                                                list<Tablero> comer;
                                                                auxiliar.operator =(aux.getMovimiento(jugador));
                                                                list<Tablero>::iterator ini = auxiliar.begin();
                                                                list<Tablero>::iterator fin = auxiliar.end();
                                                                while(ini != fin){
                                                                    if(ini->comer > 0 && X2 == ini->X1 && Y2 == ini->Y1)
                                                                        comer.push_back(*ini);
                                                                    ini++;
                                                                }
                                                                if(comer.empty())
                                                                    return aux;
                                                                else{
                                                                    system("clear");
                                                                    aux.mostrar();
                                                                }   
                                                            }else{
                                                                if(desdeX == auxX1 && desdeY == auxY1){
                                                                    desdeX = X2;
                                                                    desdeY = Y2;
                                                                }
                                                                for(int a=1;a<20;a++){
                                                                    if(aux.abierto(auxX1-a, auxY1-a) && direccion == 0){
                                                                        if((auxX1-a == X2 && auxY1-a == Y2)){
                                                                            aux = Tablero(aux, auxX1, auxY1, X2, Y2, 0);
                                                                            aux = Tablero(aux, desdeX, desdeY, 8);
                                                                            return aux;
                                                                        }
                                                                    }else{                            
                                                                        if(aux.abierto(auxX1-a, auxY1+a) && direccion == 1){
                                                                            if((auxX1-a == X2 && auxY1+a == Y2)){
                                                                                aux = Tablero(aux, auxX1, auxY1, X2, Y2, 0);
                                                                                aux = Tablero(aux, desdeX, desdeY, 8);
                                                                                return aux;
                                                                            }
                                                                        }else{
                                                                            if(aux.abierto(auxX1+a, auxY1-a) && direccion == 2){
                                                                                if((auxX1+a == X2 && auxY1-a == Y2)){
                                                                                    aux = Tablero(aux, auxX1, auxY1, X2, Y2, 0);
                                                                                    aux = Tablero(aux, desdeX, desdeY, 8);
                                                                                    return aux;
                                                                                }
                                                                            }else{
                                                                                if(aux.abierto(auxX1+a, auxY1+a) && direccion == 3){
                                                                                    if((auxX1+a == X2 && auxY1+a == Y2)){
                                                                                        aux = Tablero(aux, auxX1, auxY1, X2, Y2, 0);
                                                                                        aux = Tablero(aux, desdeX, desdeY, 8);
                                                                                        return aux;
                                                                                    }
                                                                                }else{
                                                                                    invalido = 1;
                                                                                    break;
                                                                                }
                                                                            }
                                                                        }
                                                                    }
                                                                }
                                                            }
                                                        }
                                                    }
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                        if(invalido == 1)
                             wcout << "Movimiento invalido" << endl;
                    }
                } 
            }else{
                wcout << "\nUsted es " << es << ". Ingrese coordenadas (por ejemplo: h4g3): ";
                wcin >> setw(1) >> move[0];
                wcin >> setw(1) >> move[1];
                wcin >> setw(1) >> move[2];
                wcin >> setw(1) >> move[3];
                wcin.ignore(256,'\n');
                move[0] = toupper(move[0]);
                move[1] = toupper(move[1]);
                move[2] = toupper(move[2]);
                move[3] = toupper(move[3]);
                X1 = (int)move[0] - 65;
                X2 = (int)move[2] - 65;
                Y1 = (int)move[1] - 48;
                Y2 = (int)move[3] - 48;
                if(((int)move[0] > 64 && (int)move[0] < 75) && ((int)move[2] > 64 && (int)move[2] < 75)){
                    if((Y1 >= 0 && Y1 < 10) && (Y2 >= 0 && Y2 < 10)){
                        int pieza = aux.tablero2[X1][Y1];
                        
                        if(pieza == -1){
                            int direccion = 0;
                            if(X2-X1 > 0 && Y2-Y1 < 0)
                                direccion = 0;
                            if(X2-X1 > 0 && Y2-Y1 > 0)
                                direccion = 1;
                            if(aux.abierto(X1+1, Y1-1) && X1+1 == X2 && Y1-1 == Y2 && direccion == 0){
                                aux = Tablero(aux, X1, Y1, 2);
                                return aux;
                            }else{
                                if(aux.abierto(X1+1, Y1+1) && X1+1 == X2 && Y1+1 == Y2 && direccion == 1){
                                    aux = Tablero(aux, X1, Y1, 3);
                                    return aux;
                                }
                            }
                        }

                        if(pieza == -2){
                            int direccion = 0;
                            if(X2-X1 < 0 && Y2-Y1 < 0)
                                direccion = 0;
                            if(X2-X1 < 0 && Y2-Y1 > 0)
                                direccion = 1;
                            if(X2-X1 > 0 && Y2-Y1 < 0)
                                direccion = 2;
                            if(X2-X1 > 0 && Y2-Y1 > 0)
                                direccion = 3;

                            for(int i=1;i<10;i++){
                                if(aux.abierto(X1-i, Y1-i) && direccion == 0){
                                    if((X1-i == X2 && Y1-i == Y2)){
                                        aux = Tablero(aux, X1, Y1, X2, Y2, 0);
                                        return aux;
                                    }
                                }else{                            
                                    if(aux.abierto(X1-i, Y1+i) && direccion == 1){
                                        if((X1-i == X2 && Y1+i == Y2)){
                                            aux = Tablero(aux, X1, Y1, X2, Y2, 0);
                                            return aux;
                                        }
                                    }else{
                                        if(aux.abierto(X1+i, Y1-i) && direccion == 2){
                                            if((X1+i == X2 && Y1-i == Y2)){
                                                aux = Tablero(aux, X1, Y1, X2, Y2, 0);
                                                return aux;
                                            }
                                        }else{
                                            if(aux.abierto(X1+i, Y1+i) && direccion == 3){
                                                if((X1+i == X2 && Y1+i == Y2)){
                                                    aux = Tablero(aux, X1, Y1, X2, Y2, 0);
                                                    return aux;
                                                }
                                            }else
                                                break;
                                        }
                                    }
                                }
                            }
                        }
                        wcout << "Movimiento invalido." << endl;
                    }else
                        wcout << "Ingrese valores entre 0 y 9." << endl;
                }else
                    wcout << "Ingrese valores entre A y J, o, a y j." << endl;
            }
        }while(accion == false);
}                            