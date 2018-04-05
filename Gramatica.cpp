//
//  Gramatica.cpp
//  ProyectoGramatica
//
//  Created by Mac on 3/13/18.
//  Copyright © 2018 Mac. All rights reserved.
//

#include "Gramatica.hpp"
#include <sstream>
#include <iostream>

Gramatica::Gramatica(){
    cantNoTerminales = 0;
    cantSimbolos = 0;
}

void Gramatica::addNoTerminales(vector<string> noT){
    for(int a = 0; a<noT.size(); a++){
        NoTerminales * nuevo = new NoTerminales(noT.at(a));
        noTerminalesArr.push_back(nuevo);
        cantNoTerminales++;
        if(a == 0){
            inicial = nuevo;
        }
    }
}

void Gramatica::addSimbolos(vector<string> sim){
    for(int a = 0; a<sim.size(); a++){
        NoTerminales * nuevo = new NoTerminales(sim.at(a));
        nuevo->isTerminal();
        simbolosArr.push_back(nuevo);
        cantSimbolos++;
    }
}

NoTerminales * Gramatica::getTerminal(string n){
    for(int a = 0; a<simbolosArr.size(); a++){
        if(simbolosArr.at(a)->name == n){
            return simbolosArr.at(a);
        }
    }
    return nullptr;
}

NoTerminales * Gramatica::getNoTerminal(string n){
    for(int a = 0; a<noTerminalesArr.size(); a++){
        if(noTerminalesArr.at(a)->name == n){
            return noTerminalesArr.at(a);
        }
    }
    return nullptr;
}

bool Gramatica::checkCadena(string cadena){
    if(checking(inicial, inicial, inicial->produccionesArr, cadena, 0) == 1){
        return true;
    } else{
        return false;
    }
}

int Gramatica::checking(NoTerminales * st1, NoTerminales * st2, vector<Producciones *> producciones, string cadena, int contador){
    if(st2->checkIsTerminal()){
        if(cadena.at(contador) == st2->name.at(0)){
            return 2;
        }
    } else {
        for(int a = 0; a<producciones.size(); a++){
            string prTemp = producciones.at(a)->name;
            
            for(int b = 0; b<prTemp.size(); b++){
                if(islower(prTemp.at(b))){ //es terminal
                    stringstream strstream2;
                    string name;
                    strstream2 << prTemp.at(b);
                    strstream2 >> name;
                    st2 = getTerminal(name);
                    int res = checking(st1, st2, producciones, cadena, contador);
                    if(res == 2){
                        contador++;
                        if(contador == cadena.size()){
                            if((prTemp.size()-1) == b){
                                return 1; //YESSS
                            }
                        } else{
                            if((prTemp.size()-1) == b){
                                continue;
                            }
                        }
                    } else if(res == 3){
                        break; //NOPE
                    }
                } else { //es no terminal
                    stringstream strstream3;
                    string name2;
                    strstream3 << prTemp.at(b);
                    strstream3 >> name2;
                    st1 = getNoTerminal(name2);
                    vector<Producciones*> prTempArr = st1->produccionesArr;
                    int res2 = checking(st1, st1, prTempArr, cadena, contador);
                    
                    if(res2 != 1){
                        continue;
                    } else{
                        return res2; //se repite hasta el caso base
                    }
                }
            }
        }
    }
    return 3;
}



