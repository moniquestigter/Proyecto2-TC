//
//  main.cpp
//  ProyectoGramatica
//
//  Created by Mac on 3/13/18.
//  Copyright © 2018 Mac. All rights reserved.
//

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include "Gramatica.hpp"


using namespace std;


/*
 S-> aB | bS
 B -> bc
 */

/*
S-> aA | bb | cC
A -> b
C -> S
*/
int main() {
    
    Gramatica * gramatica = new Gramatica();
    
    //PEDIR NO TERMINALES Y AGREGARLAS A LA GRAMATICA
    int cantNoTerminales;
    vector<string> noTerminales;
    string s;
    
    cout<<"Cuantos no terminales serian: ";
    cin>>cantNoTerminales;
    cout<<"Cuales serian los no terminales: ";
    for(int a = 0; a<cantNoTerminales; a++){
        cin>>s;
        noTerminales.push_back(s);
    }
    
    gramatica->addNoTerminales(noTerminales);
    
    
    //PEDIR SIMBOLOS Y AGREGARLAS A LA GRAMATICA
    int cantSimbolos;
    vector<string> simbs;
    string sim;
    
    cout<<"Cuantos simbolos serian: ";
    cin>>cantSimbolos;
    cout<<"Cuales serian los simbolos: ";
    for(int a = 0; a<cantSimbolos; a++){
        cin>>sim;
        simbs.push_back(sim);
    }
    
    gramatica->addSimbolos(simbs);
    
    
    //PEDIR PRODUCCIONES
    int cantProducciones;
    vector<string> prod;
    string p;
    for(int a = 0; a<gramatica->cantNoTerminales; a++){
        cout<<"Cuantas producciones tiene el no terminal "<<gramatica->noTerminalesArr.at(a)->name<<": ";
        cin>>cantProducciones;
        for(int b = 0; b<cantProducciones; b++){
            cout<<"Produce: ";
            cin>>p;
            prod.push_back(p);
        }
        gramatica->noTerminalesArr.at(a)->produce(prod);
        prod.clear();
        
    }
    
    /*
    for(int a = 0; a<gramatica->simbolosArr.size(); a++){
        cout<<gramatica->simbolosArr.at(a)->name<<" isTerminal?: "<<gramatica->simbolosArr.at(a)->terminal<<endl;
    }
    
    for(int a = 0; a<gramatica->noTerminalesArr.size(); a++){
        cout<<gramatica->noTerminalesArr.at(a)->name<<" produce: ";
        for(int b = 0; b<gramatica->noTerminalesArr.at(a)->produccionesArr.size(); b++){
            cout<<gramatica->noTerminalesArr.at(a)->produccionesArr.at(b)->name<<" ";
        }
    }
    
    cout<<"Inicial: "<<gramatica->inicial->name<<endl;
    
    */
    
    /*if(gramatica->checkCadena("abcabab")){
        cout<<"Aceptado"<<endl;
    } else{
        cout<<"not"<<endl;
    }*/
    
    //LEER CADENAS DEL ARCHIVO!!!
    string filename;
    
    string cadena;
    cout<<"Ingrese nombre del archivo: ";
    cin>>filename;
    ifstream inFile(filename);
    
    while(inFile>>cadena){
        
        if(gramatica->checkCadena(cadena)){
            cout<<"Cadena "<<"'"<<cadena<<"'"<<" es aceptada"<<endl;
        } else{
            cout<<"Cadena "<<"'"<<cadena<<"'"<<" no es aceptada"<<endl;
        }
        cadena = "";
        
    }
    inFile.close();
    
    return 0;
}
