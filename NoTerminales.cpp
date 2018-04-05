//
//  NoTerminales.cpp
//  ProyectoGramatica
//
//  Created by Mac on 3/20/18.
//  Copyright © 2018 Mac. All rights reserved.
//

#include "NoTerminales.hpp"

NoTerminales::NoTerminales(string n){
    name = n;
    terminal = false;
    cantProducciones = 0;
}

void NoTerminales::produce(vector<string> prod){
    for(int a = 0; a<prod.size(); a++){
        Producciones * nuevo = new Producciones(prod.at(a));
        produccionesArr.push_back(nuevo);
        cantProducciones++;
    }
}

void NoTerminales::isTerminal(){
    terminal = true;
}

bool NoTerminales::checkIsTerminal(){
    if(terminal){
        return true;
    } else{
        return false;
    }
}
