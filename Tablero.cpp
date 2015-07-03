
#include "Tablero.h"

Tablero::Tablero() {
    setlocale(LC_CTYPE,"");
    comer = 0;
    /*ValPieza = 0;
    X1 = 0;
    Y1 = 0;
    X2 = 0;
    Y2 = 0;*/
    for(int i=0;i<10;i++){
        for(int j=0;j<10;j++){
            if(i<3 && (i+j)%2 != 0){
                tablero[i][j] = 9679;
                tablero2[i][j] = -1;
            }
            else{
                if(i>6 && (i+j)%2 != 0){
                    tablero[i][j] = 9675;
                    tablero2[i][j] = 1;
                }
                else{
                    tablero[i][j] = '-';
                    tablero2[i][j] = 0;
                }
            }
        }
    }
}

Tablero::Tablero(const Tablero& orig) {
    comer = orig.comer;
    ValPieza = orig.ValPieza;
    X1 = orig.X1;
    Y1 = orig.Y1;
    X2 = orig.X2;
    Y2 = orig.Y2;
    for(int i=0;i<10;i++){
        for(int j=0;j<10;j++){
            tablero[i][j] = orig.tablero[i][j];
            tablero2[i][j] = orig.tablero2[i][j];
        }
    }
}

Tablero::Tablero(const Tablero& t, int I, int J, int codigo){
    setlocale(LC_CTYPE,"");
    for(int i=0;i<10;i++){
        for(int j=0;j<10;j++){
            tablero[i][j] = t.tablero[i][j];
            tablero2[i][j] = t.tablero2[i][j];
        }
    }
    
    int valorInt = tablero2[I][J];
    wchar_t valorChar = tablero[I][J];
    
    ValPieza = valorInt;
    X1 = I;
    Y1 = J;
    
    tablero[I][J] = '-';
    tablero2[I][J] = 0;
    
    switch(codigo){
        case(0):
            I = I - 1;
            J = J - 1;
            comer = 0;
            break;
            
        case(1):
            I = I-1;
            J = J+1;
            comer = 0;
            break;
            
        case(2):
            I = I+1;
            J = J-1;
            comer = 0;
            break;
            
        case(3):
            I = I+1;
            J = J+1;
            comer = 0;
            break;
            
        case(4):
            tablero[I-1][J-1] = '-';
            tablero2[I-1][J-1] = 0;
            comer = 2;
            I = I-2;
            J = J-2;
            break;
            
        case(5):
            tablero[I-1][J+1] = '-';
            tablero2[I-1][J+1] = 0;
            comer = 2;
            I = I-2;
            J = J+2;
            break;
            
        case(6):
            tablero[I+1][J-1] = '-';
            tablero2[I+1][J-1] = 0;
            comer = 2;
            I = I+2;
            J = J-2;
            break;
            
        case(7):
            tablero[I+1][J+1] = '-';
            tablero2[I+1][J+1] = 0;
            comer = 2;
            I = I+2;
            J = J+2;
            break;
            
        case(8):
            valorInt = 0;
            valorChar = '-';
        default:
            break;
    }
    X2 = I;
    Y2 = J;
    tablero[I][J] = valorChar;
    tablero2[I][J] = valorInt;
    
    if(I==9 && valorInt == -1){
        tablero[I][J] = 9819;
        tablero2[I][J] *=2;
    }
    if(I==0 && valorInt == 1){
        tablero[I][J] = 9813;
        tablero2[I][J] *=2;
    }
}

Tablero::Tablero(const Tablero& t, int I1, int J1, int I2, int J2, int codigo){
    setlocale(LC_CTYPE,"");
    for(int i=0;i<10;i++){
        for(int j=0;j<10;j++){
            tablero[i][j] = t.tablero[i][j];
            tablero2[i][j] = t.tablero2[i][j];
        }
    }
    
    int valorInt= tablero2[I1][J1];
    wchar_t valorChar = tablero[I1][J1];
    
    tablero[I1][J1] = '-';
    tablero2[I1][J1] = 0;
    
    switch(codigo){
        case(0):
            tablero[I2][J2] = valorChar;
            tablero2[I2][J2] = valorInt;
            comer = 0;
            break;
            
        case(1):
            tablero[I1-1][J1-1] = '-';
            tablero2[I1-1][J1-1] = 0;
            tablero[I2][J2] = valorChar;
            tablero2[I2][J2] = valorInt;
            comer = 0;
            break;
            
        case(2):
            tablero[I1-1][J1+1] = '-';
            tablero2[I1-1][J1+1] = 0;
            tablero[I2][J2] = valorChar;
            tablero2[I2][J2] = valorInt;
            comer = 0;
            break;
            
        case(3):
            tablero[I1+1][J1-1] = '-';
            tablero2[I1+1][J1-1] = 0;
            tablero[I2][J2] = valorChar;
            tablero2[I2][J2] = valorInt;
            comer = 0;
            break;
            
        case(4):
            tablero[I1+1][J1+1] = '-';
            tablero2[I1+1][J1+1] = 0;
            tablero[I2][J2] = valorChar;
            tablero2[I2][J2] = valorInt;
            comer = 0;
            break;
            
        default:
            break;
    }
    
    if(I2==9 && valorInt == -1){
        tablero[I2][J2] = 9819;
        tablero2[I2][J2] *=2;
    }
    if(I2==0 && valorInt == 1){
        tablero[I2][J2] = 9813;
        tablero2[I2][J2] *=2;
    }
}

void Tablero::mostrar(){
    wcout << "\t";
    for(int i=0;i<10;i++){
        wcout << i << "\t";
    }
    cout << endl << endl;
    for(int i=0;i<10;i++){
        char t = i+65;
        wcout << t;
        for(int j=0;j<10;j++){
            
            wcout << "\t" << tablero[i][j];
            if(j==9)
                cout << endl << endl;
        }
    }
}

list<Tablero> Tablero::getMovimiento(bool player){
    list<Tablero> moves;
    
    for(int i=0;i<10;i++){
        for(int j=0;j<10;j++){
            if((player && tablero2[i][j] == 1) || (!player && tablero2[i][j] == -1)){
                list<Tablero> aux; 
                aux.operator=(this->getSalto(i, j, tablero2[i][j], 4));
                list<Tablero>::iterator ini = aux.begin();
                list<Tablero>::iterator fin = aux.end();
                
                while(ini != fin){
                    moves.push_back(*ini);
                    ini++;
                }
            }else{
                if((player && tablero2[i][j] == 2) || (!player && tablero2[i][j] == -2)){
                    list <Tablero> aux;
                    aux.operator=(this->getEatReina(i, j));
                    list<Tablero>::iterator ini = aux.begin();
                    list<Tablero>::iterator fin = aux.end();
                    
                    while(ini != fin){
                        moves.push_back(*ini);
                        ini++;
                    }
                }
            }
        }
    }
    
    if(moves.empty()){
        for(int i=0;i<10;i++){
            for(int j=0;j<10;j++){
                int pieza = tablero2[i][j];
                
                if(player && pieza == 1){
                    if(abierto(i-1, j-1)){
                        moves.push_back(Tablero(*this, i, j, 0));
                    }
                    if(abierto(i-1, j+1)){
                        moves.push_back(Tablero(*this, i, j, 1));
                    }
                }else{
                    if(player && pieza == 2){
                        if(abierto(i-1, j-1)){
                            Tablero auxiliar = Tablero(*this, i, j, 0);
                            list<Tablero> aux;
                            aux.operator =(auxiliar.getMovimientoDerivado(i-1, j-1, 0));
                                list<Tablero>::iterator ini = aux.begin();
                                list<Tablero>::iterator fin = aux.end();
                        
                                while(ini != fin){
                                    moves.push_back(*ini);
                                    ini++;
                                }
                        }
                        
                        if(abierto(i-1, j+1)){
                            Tablero auxiliar = Tablero(*this, i, j, 1);
                            list<Tablero> aux;
                            aux.operator =(auxiliar.getMovimientoDerivado(i-1, j+1, 1));
                                list<Tablero>::iterator ini = aux.begin();
                                list<Tablero>::iterator fin = aux.end();
                        
                                while(ini != fin){
                                    moves.push_back(*ini);
                                    ini++;
                                }
                        }
                        
                        if(abierto(i+1, j-1)){
                            Tablero auxiliar = Tablero(*this, i, j, 2);
                            list<Tablero> aux;
                            aux.operator =(auxiliar.getMovimientoDerivado(i+1, j-1, 2));
                                list<Tablero>::iterator ini = aux.begin();
                                list<Tablero>::iterator fin = aux.end();
                        
                                while(ini != fin){
                                    moves.push_back(*ini);
                                    ini++;
                                }
                        }
                        
                        if(abierto(i+1, j+1)){
                            Tablero auxiliar = Tablero(*this, i, j, 3);
                            list<Tablero> aux;
                            aux.operator =(auxiliar.getMovimientoDerivado(i+1, j+1, 3));
                                list<Tablero>::iterator ini = aux.begin();
                                list<Tablero>::iterator fin = aux.end();
                        
                                while(ini != fin){
                                    moves.push_back(*ini);
                                    ini++;
                                }
                        }
                    }
                }
                
                if(!player && pieza == -1){
                    if(abierto(i+1, j-1)){
                        moves.push_back(Tablero(*this, i, j, 2));
                    }
                        
                    if(abierto(i+1, j+1)){
                        moves.push_back(Tablero(*this, i, j, 3));
                    }
                }else{
                    if(!player && pieza == -2){
                        if(abierto(i-1, j-1)){
                            Tablero auxiliar = Tablero(*this, i, j, 0);
                            list<Tablero> aux;
                            aux.operator =(auxiliar.getMovimientoDerivado(i-1, j-1, 0));
                                list<Tablero>::iterator ini = aux.begin();
                                list<Tablero>::iterator fin = aux.end();
                        
                                while(ini != fin){
                                    moves.push_back(*ini);
                                    ini++;
                                }
                        }
                        
                        if(abierto(i-1, j+1)){
                            Tablero auxiliar = Tablero(*this, i, j, 1);
                            list<Tablero> aux;
                            aux.operator =(auxiliar.getMovimientoDerivado(i-1, j+1, 1));
                                list<Tablero>::iterator ini = aux.begin();
                                list<Tablero>::iterator fin = aux.end();
                        
                                while(ini != fin){
                                    moves.push_back(*ini);
                                    ini++;
                                }
                        }
                        
                        if(abierto(i+1, j-1)){
                            Tablero auxiliar = Tablero(*this, i, j, 2);
                            list<Tablero> aux;
                            aux.operator =(auxiliar.getMovimientoDerivado(i+1, j-1, 2));
                                list<Tablero>::iterator ini = aux.begin();
                                list<Tablero>::iterator fin = aux.end();
                        
                                while(ini != fin){
                                    moves.push_back(*ini);
                                    ini++;
                                }
                        }
                        
                        if(abierto(i+1, j+1)){
                            Tablero auxiliar = Tablero(*this, i, j, 3);
                            list<Tablero> aux;
                            aux.operator =(auxiliar.getMovimientoDerivado(i+1, j+1, 3));
                                list<Tablero>::iterator ini = aux.begin();
                                list<Tablero>::iterator fin = aux.end();
                        
                                while(ini != fin){
                                    moves.push_back(*ini);
                                    ini++;
                                }
                        }
                    }
                }
            }
        }
    }
    
    return moves;
}

list<Tablero> Tablero::getSalto(int i, int j, int pieza, int direccion){
    list<Tablero> moves;
    if(pieza == 1 || pieza == 2 || pieza == -2){
        if(salto(i, j, i-1, j-1)){
            Tablero nuevoTablero = Tablero(*this, i, j, 4);
            list <Tablero> saltosDerivados;
            saltosDerivados.operator=(nuevoTablero.getSalto(i-2, j-2, pieza, 0));
            if(saltosDerivados.empty())
                moves.push_back(nuevoTablero);
            else{
                list<Tablero>::iterator ini = saltosDerivados.begin();
                list<Tablero>::iterator fin = saltosDerivados.end();
                while(ini != fin){
                    moves.push_back(*ini);
                    ini++;
                }
            }
        }
        
        if(salto(i, j, i-1, j+1)){
            Tablero nuevoTablero = Tablero(*this, i, j, 5);
            list <Tablero> saltosDerivados;
            saltosDerivados.operator=(nuevoTablero.getSalto(i-2, j+2, pieza, 1));
            if(saltosDerivados.empty())
                moves.push_back(nuevoTablero);
            else{
                list<Tablero>::iterator ini = saltosDerivados.begin();
                list<Tablero>::iterator fin = saltosDerivados.end();
                while(ini != fin){
                    moves.push_back(*ini);
                    ini++;
                }
            }
        }
    }
    
    if(pieza == -1 || pieza == -2 || pieza == 2){
        if(salto(i, j, i+1, j-1)){
            Tablero nuevoTablero = Tablero(*this, i, j, 6);
            list <Tablero> saltosDerivados;
            saltosDerivados.operator=(nuevoTablero.getSalto(i+2, j-2, pieza, 2));
            if(saltosDerivados.empty())
                moves.push_back(nuevoTablero);
            else{
                list<Tablero>::iterator ini = saltosDerivados.begin();
                list<Tablero>::iterator fin = saltosDerivados.end();
                while(ini != fin){
                    moves.push_back(*ini);
                    ini++;
                }
            }
        }
        
        if(salto(i, j, i+1, j+1)){
            Tablero nuevoTablero = Tablero(*this, i, j, 7);
            list <Tablero> saltosDerivados;
            saltosDerivados.operator=(nuevoTablero.getSalto(i+2, j+2, pieza, 3));
            if(saltosDerivados.empty())
                moves.push_back(nuevoTablero);
            else{
                list<Tablero>::iterator ini = saltosDerivados.begin();
                list<Tablero>::iterator fin = saltosDerivados.end();
                while(ini != fin){
                    moves.push_back(*ini);
                    ini++;
                }
            }
        }
    }
   
    return moves;
}

list<Tablero> Tablero::getSaltoDerivado(int i, int j, int direccion){
    list<Tablero> moves;
    
    if(salto(i, j, i-1, j-1) && (direccion == 0 || direccion == 4)){
        Tablero nuevoTablero = Tablero(*this, i, j, 4);
        list <Tablero> saltosDerivados;
        saltosDerivados.operator=(nuevoTablero.getMovimientoDerivado(i-2, j-2, 0));
        if(saltosDerivados.empty())
            moves.push_back(nuevoTablero);
        else{
            list<Tablero>::iterator ini = saltosDerivados.begin();
            list<Tablero>::iterator fin = saltosDerivados.end();
            while(ini != fin){
                moves.push_back(*ini);
                ini++;
            }
        }
    }
        
        if(salto(i, j, i-1, j+1) && (direccion == 1 || direccion == 4)){
            Tablero nuevoTablero = Tablero(*this, i, j, 5);
            list <Tablero> saltosDerivados;
            
            saltosDerivados.operator=(nuevoTablero.getMovimientoDerivado(i-2, j+2, 1));
            if(saltosDerivados.empty())
                moves.push_back(nuevoTablero);
            else{
                list<Tablero>::iterator ini = saltosDerivados.begin();
                list<Tablero>::iterator fin = saltosDerivados.end();
                while(ini != fin){
                    moves.push_back(*ini);
                    ini++;
                }
            }
        }
        
        if(salto(i, j, i+1, j-1) && (direccion == 2 || direccion == 4)){
            Tablero nuevoTablero = Tablero(*this, i, j, 6);
            list <Tablero> saltosDerivados;
            saltosDerivados.operator=(nuevoTablero.getMovimientoDerivado(i+2, j-2, 2));
            if(saltosDerivados.empty())
                moves.push_back(nuevoTablero);
            else{
                list<Tablero>::iterator ini = saltosDerivados.begin();
                list<Tablero>::iterator fin = saltosDerivados.end();
                while(ini != fin){
                    moves.push_back(*ini);
                    ini++;
                }
            }
        }
        
        if(salto(i, j, i+1, j+1) && (direccion == 3 || direccion == 4)){
            Tablero nuevoTablero = Tablero(*this, i, j, 7);
            list <Tablero> saltosDerivados;
            saltosDerivados.operator=(nuevoTablero.getMovimientoDerivado(i+2, j+2, 3));
            if(saltosDerivados.empty())
                moves.push_back(nuevoTablero);
            else{
                list<Tablero>::iterator ini = saltosDerivados.begin();
                list<Tablero>::iterator fin = saltosDerivados.end();
                while(ini != fin){
                    moves.push_back(*ini);
                    ini++;
                }
            }
        }
    
    return moves;
}

list<Tablero> Tablero::getMovimientoDerivado(int i, int j, int direccion){
    list<Tablero> moves;
    
    moves.operator =(this->getSaltoDerivado(i,j,direccion));
    
    if(moves.empty()){
    if(abierto(i-1, j-1) && (direccion == 0 || direccion == 4)){
        Tablero nuevoTablero = Tablero(*this,i,j,0);
        list<Tablero> der;
        der.operator=(nuevoTablero.getMovimientoDerivado(i-1, j-1, direccion));  
        if(der.empty())
            moves.push_back(nuevoTablero);
        else{
            list<Tablero>::iterator ini = der.begin();
            list<Tablero>::iterator fin = der.end();
            while(ini != fin){
                moves.push_back(*ini);
                ini++;
            }
        }      
    }
        
    if(abierto(i-1, j+1) && (direccion == 1 || direccion == 4)){
        Tablero nuevoTablero = Tablero(*this,i,j,1);
        list<Tablero> der;
        der.operator=(nuevoTablero.getMovimientoDerivado(i-1, j+1, direccion));  
        if(der.empty())
            moves.push_back(nuevoTablero);
        else{
            list<Tablero>::iterator ini = der.begin();
            list<Tablero>::iterator fin = der.end();
            while(ini != fin){
                moves.push_back(*ini);
                ini++;
            }
        }   
    }
        
    if(abierto(i+1, j-1) && (direccion == 2 || direccion == 4)){
        Tablero nuevoTablero = Tablero(*this,i,j,2);
        list<Tablero> der;
        der.operator=(nuevoTablero.getMovimientoDerivado(i+1, j-1, direccion));
        if(der.empty())
            moves.push_back(nuevoTablero);
        else{
            list<Tablero>::iterator ini = der.begin();
            list<Tablero>::iterator fin = der.end();
            while(ini != fin){
                moves.push_back(*ini);
                ini++;
            }
        } 
    }
     
    if(abierto(i+1, j+1) && (direccion == 3 || direccion == 4)){
        Tablero nuevoTablero = Tablero(*this,i,j,3);
        list<Tablero> der;
        der.operator=(nuevoTablero.getMovimientoDerivado(i+1, j+1, direccion));
        if(der.empty())
            moves.push_back(nuevoTablero);
        else{
            list<Tablero>::iterator ini = der.begin();
            list<Tablero>::iterator fin = der.end();
            while(ini != fin){
                moves.push_back(*ini);
                ini++;
            }
        }   
    }
    }
    return moves;
}

double Tablero::valorTablero(){
    double valor = 0;
    
    int valores[10][10] = {{5,5,5,5,5,5,5,5,5,5},
                           {5,4,4,4,4,4,4,4,4,5},
                           {5,4,3,3,3,3,3,3,4,5},
                           {5,4,3,2,2,2,2,3,4,5},
                           {5,4,3,2,1,1,2,3,4,5},
                           {5,4,3,2,1,1,2,3,4,5},
                           {5,4,3,2,2,2,2,3,4,5},
                           {5,4,3,3,3,3,3,3,4,5},
                           {5,4,4,4,4,4,4,4,4,5},
                           {5,5,5,5,5,5,5,5,5,5}};
    
    for(int i=0;i<10;i++){
        for(int j=0;j<10;j++){
            valor += tablero2[i][j] * valores[i][j];
        }
    }
    
    return valor;
}

bool Tablero::salto(int i1, int j1, int i2, int j2){
    return abierto(2*i2 - i1, 2*j2 - j1) && dentro(i2, j2) && signo(tablero2[i2][j2]) == -signo(tablero2[i1][j1]);
}

bool Tablero::abierto(int i, int j){
    return dentro(i, j) && tablero2[i][j] == 0;
}

bool Tablero::dentro(int i, int j){
    return i>=0 && i<10 && j>=0 && j<10;
}

Tablero& Tablero::operator =(const Tablero& t){
    setlocale(LC_CTYPE, "");
    if(this != &t){
        for(int i=0;i<10;i++){
            for(int j=0;j<10;j++){
                this->tablero[i][j] = t.tablero[i][j];
                this->tablero2[i][j] = t.tablero2[i][j];
            }
        }
        this->X1 = t.X1;
        this->Y1 = t.Y1;
        this->X2 = t.X2;
        this->Y2 = t.Y2;
        this->comer = t.comer;
        this->ValPieza = t.ValPieza;
    }
    
    return *this;
}

bool Tablero::juegoTerminado(bool player){
    return this->getMovimiento(player).empty();
}

int Tablero::signo(int f){
    if(f > 0)
        return 1;
    else{
        if(f < 0)
            return -1;
        else
            return 0;
    }
}

bool Tablero::equals(const Tablero& t){
    setlocale(LC_CTYPE, "");
    for(int i=0;i<10;i++){
        for(int j=0;j<10;j++){
            if(tablero[i][j] != t.tablero[i][j]){
                return false;
            }
        }
    }
    return true;
}

int Tablero::enDiagonal(int i, int j, int x, int y){
    int distanciaX = x-i;
    int distanciaY = y-j;
    
    if(distanciaX < 0)
        distanciaX*=-1;
    
    if(distanciaY < 0)
        distanciaY*=-1;
    
    if(distanciaX == distanciaY)
        return distanciaX;
    
    return 0;
}

list<Tablero> Tablero::getEatReina(int i, int j){
    list<Tablero> moves;
    for(int x=0; x<10; x++){
        for(int y=0; y<10; y++){
            if(tablero2[i][j] == 2){
                if(tablero2[x][y] < 0){
                    int enLinea = enDiagonal(i, j, x, y);
                    if(enLinea != 0){
                        int direccion;
                        if(x-i < 0 && y-j < 0)
                            direccion = 0;
                        if(x-i < 0 && y-j > 0)
                            direccion = 1;
                        if(x-i > 0 && y-j < 0)
                            direccion = 2;
                        if(x-i > 0 && y-j > 0)
                            direccion = 3;
                        int saltos;
                        int X = i;
                        int Y = j;
                        Tablero *temporal;
                        temporal = &*this;
                        
                        for(saltos=0; saltos < enLinea; saltos++){
                            if(temporal->abierto(X-1, Y-1) && direccion == 0){
                                temporal = new Tablero(*temporal, X, Y, 0);
                                X = X-1;
                                Y = Y-1;
                            }else{
                                if(temporal->salto(X, Y, X-1, Y-1) && direccion == 0){
                                    temporal = new Tablero(*temporal, X, Y, 4);
                                    list<Tablero> derivados;
                                    derivados.operator =(temporal->getEatReina(X-2, Y-2));
                                    moves.push_back(*temporal);
                                    list<Tablero>::iterator ini = derivados.begin();
                                    list<Tablero>::iterator fin = derivados.end();
                                    while(ini != fin){
                                        moves.push_back(*ini);
                                        ini++;
                                    }
                                    
                                    X = X-2;
                                    Y = Y-2;
                                    
                                }else{
                                    if(temporal->abierto(X-1, Y+1) && direccion == 1){
                                        temporal = new Tablero(*temporal, X, Y, 1);
                                        X = X-1;
                                        Y = Y+1;
                                    }else{
                                        if(temporal->salto(X, Y, X-1, Y+1) && direccion == 1){
                                            temporal = new Tablero(*temporal, X, Y, 5);
                                            list<Tablero> derivados;
                                            derivados.operator =(temporal->getEatReina(X-2, Y+2));
                                            moves.push_back(*temporal);
                                            list<Tablero>::iterator ini = derivados.begin();
                                            list<Tablero>::iterator fin = derivados.end();
                                            while(ini != fin){
                                                moves.push_back(*ini);
                                                ini++;
                                            }
                                    
                                            X = X-2;
                                            Y = Y+2;
                                        }else{
                                            if(temporal->abierto(X+1, Y-1) && direccion == 2){
                                                temporal = new Tablero(*temporal, X, Y, 2);
                                                X = X+1;
                                                Y = Y-1;
                                            }else{
                                                if(temporal->salto(X, Y, X+1, Y-1) && direccion == 2){
                                                    temporal = new Tablero(*temporal, X, Y, 6);
                                                    list<Tablero> derivados;
                                                    derivados.operator =(temporal->getEatReina(X+2, Y-2));
                                                    moves.push_back(*temporal);
                                                    list<Tablero>::iterator ini = derivados.begin();
                                                    list<Tablero>::iterator fin = derivados.end();
                                                    while(ini != fin){
                                                        moves.push_back(*ini);
                                                        ini++;
                                                    }
                                    
                                                    X = X+2;
                                                    Y = Y-2;
                                                }else{
                                                    if(temporal->abierto(X+1, Y+1) && direccion == 3){
                                                        temporal = new Tablero(*temporal, X, Y,3);
                                                        X = X+1;
                                                        Y = Y+1;
                                                    }else{
                                                        if(temporal->salto(X, Y, X+1, Y+1) && direccion == 3){
                                                            temporal = new Tablero(*temporal, X, Y, 7);
                                                            list<Tablero> derivados;
                                                            derivados.operator =(temporal->getEatReina(X+2, Y+2));
                                                            moves.push_back(*temporal);
                                                            list<Tablero>::iterator ini = derivados.begin();
                                                            list<Tablero>::iterator fin = derivados.end();
                                                            while(ini != fin){
                                                                moves.push_back(*ini);
                                                                ini++;
                                                            }
                                    
                                                            X = X+2;
                                                            Y = Y+2;
                                                        }
                                                    }
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                        delete(temporal);
                    }
                }
            }
        }
    }
    return moves;
}