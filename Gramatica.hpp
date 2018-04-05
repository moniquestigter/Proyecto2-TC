//
//  Gramatica.hpp
//  ProyectoGramatica
//
//  Created by Mac on 3/13/18.
//  Copyright © 2018 Mac. All rights reserved.
//

#ifndef Gramatica_hpp
#define Gramatica_hpp

#include <stdio.h>
#include <string>
#include <vector>
#include "NoTerminales.hpp"


using namespace std;

class Gramatica{
public:
    Gramatica();
    
    int cantNoTerminales;
    int cantSimbolos;
    
    NoTerminales * inicial;
    vector<NoTerminales *> simbolosArr;
    vector<NoTerminales * > noTerminalesArr;
    
    void addNoTerminales(vector<string> noT);
    void addSimbolos(vector<string> sim);

    NoTerminales * getTerminal(string n);
    NoTerminales * getNoTerminal(string n);
    bool checkCadena(string cadena);
    
private:
    int checking(NoTerminales * st1, NoTerminales * st2, vector<Producciones *> producciones, string cadena, int c);
    
    
    
};

#endif /* Gramatica_hpp */
