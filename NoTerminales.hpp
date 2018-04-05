//
//  NoTerminales.hpp
//  ProyectoGramatica
//
//  Created by Mac on 3/20/18.
//  Copyright © 2018 Mac. All rights reserved.
//

#ifndef NoTerminales_hpp
#define NoTerminales_hpp

#include <stdio.h>
#include <string>
#include <vector>

using namespace std;

struct Producciones {
public:
    Producciones(string n){
        name = n;
    }
    string name;
};

class NoTerminales{
public:
    NoTerminales(string name);
    string name;
    int cantProducciones;
    bool terminal;
    void produce(vector<string> prod);
    void isTerminal();
    bool checkIsTerminal();
    vector<Producciones*> produccionesArr;
};

#endif /* NoTerminales_hpp */
