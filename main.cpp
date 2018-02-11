/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Andrés
 *
 * Created on 10 de febrero de 2018, 16:00
 */

#include <iostream>
#include <string>
#include "vehiculo.h"




int main(int argc, char** argv) {
    
    //Definición del vector.
    int tam;
    vehiculos::automovil *v;
    std::cout<<"Introduce el número de vehículos: "<<std::endl;
    std::cin>>tam;
    v=new vehiculos::automovil[tam];
    
    
    //Uso de la función rellenarVector().
    try{
        vehiculos::rellenarVector(v,tam);
    }catch(std::string &error){
        std::cerr<<error;
    }
    
    //Uso de la función mostrarEnPantalla().
    vehiculos::mostrarEnPantalla(v,tam);
    
    std::cout<<std::endl;
    
    //Uso de la función maxPrecio().
    int cont=0;
    cont=vehiculos::maxPrecio(v,tam);
    std::cout<<"El coche con mayor precio es :" <<std::endl;
    vehiculos::muestraEnPantalla(v[cont]);
    
    //Uso de la función buscarPorMatricula().
    cont=0;
    std::string matricula;
    do{
        std::cout<<"Introduce una matrícula para buscarla en la base de datos(6 caracteres): "<<std::endl;
        getline(std::cin>>std::ws,matricula);
    }while(matricula.length()!=6);
    try{
        cont=vehiculos::buscarPorMatricula(matricula,v,tam);
    }catch(std::string &cad){
        std::cerr<<cad;
    }
    if(cont!=0){
        std::cout<<"La información del vehículo con matrícula "<<matricula<<" es:" <<std::endl;
        vehiculos::muestraEnPantalla(v[cont]);
    }
    
    //Elminación del vector.
    delete []v;
    return 0;
}

