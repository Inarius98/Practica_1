/* 
 * File:   vehiculo.cpp
 * Author: andre
 * 
 * Created on 10 de febrero de 2018, 16:01
 */

#include "vehiculo.h"



void vehiculos::leePorTeclado(automovil& coche){
    std::cout<<"Introduce la marca del vehiculo(entre 3 y 20 caracteres): "<<std::endl;
    getline(std::cin>>std::ws,coche.Marca);
    if(coche.Marca.length()<3||coche.Marca.length()>20)   {
        throw std::string("ERROR[vehiculos::leePorTeclado]:El número de caracteres de la marca no es válido.");
    } 
    std::cout<<"Introduce el modelo del vehiculo(entre 1 y 30 caracteres): "<<std::endl;
    std::getline(std::cin>>std::ws,coche.Modelo);
    if(coche.Modelo.length()<1||coche.Marca.length()>30){
        throw std::string("ERROR[vehiculos::leePorTeclado]:El número de caracteres del modelo no es válido.");
    }
    std::cout<<"Introduce la matricula del vehiculo(6 caracteres): "<<std::endl;
    std::getline(std::cin>>std::ws,coche.Matricula);
    if(coche.Matricula.length()!=6){
        throw std::string("ERROR[vehiculos::leePorTeclado]:El número de caracteres de la matrícula no es válido.");
    }
    std::cout<<"Introduce el año de fabricación del vehiculo: "<<std::endl;
    std::cin>>coche.Anio;
    if(coche.Anio<1900||coche.Anio>2018){
        throw std::string("ERROR[vehiculos::leePorTeclado]:El año introducido no es válido.");
    }
    std::cout<<"Introduce el precio del vehiculo: "<<std::endl;
    std::cin>>coche.Precio;
    if(coche.Precio<0){
        throw std::string("ERROR[vehiculos::leePorTeclado]:El precio introducido no es válido.");
    }
}

void vehiculos::leePorTeclado(automovil* coche){
    std::cout<<"Introduce la marca del vehiculo(entre 3 y 20 caracteres): "<<std::endl;
    getline(std::cin>>std::ws,coche->Marca);
    if(coche->Marca.length()<3||coche->Marca.length()>20)   {
        throw std::string("ERROR[vehiculos::leePorTeclado]:El número de caracteres de la marca no es válido.");
    } 
    std::cout<<"Introduce el modelo del vehiculo(entre 1 y 30 caracteres): "<<std::endl;
    std::getline(std::cin>>std::ws,coche->Modelo);
    if(coche->Modelo.length()<1||coche->Marca.length()>30){
        throw std::string("ERROR[vehiculos::leePorTeclado]:El número de caracteres del modelo no es válido.");
    }
    std::cout<<"Introduce la matricula del vehiculo(6 caracteres): "<<std::endl;
    std::getline(std::cin>>std::ws,coche->Matricula);
    if(coche->Matricula.length()!=6){
        throw std::string("ERROR[vehiculos::leePorTeclado]:El número de caracteres de la matrícula no es válido.");
    }
    std::cout<<"Introduce el año de fabricación del vehiculo: "<<std::endl;
    std::cin>>coche->Anio;
    if(coche->Anio<1900||coche->Anio>2018){
        throw std::string("ERROR[vehiculos::leePorTeclado]:El año introducido no es válido.");
    }
    std::cout<<"Introduce el precio del vehiculo: "<<std::endl;
    std::cin>>coche->Precio;
    if(coche->Precio<0){
        throw std::string("ERROR[vehiculos::leePorTeclado]:El precio introducido no es válido.");
    }
}

void vehiculos::muestraEnPantalla(const automovil& coche){
    std::cout<<"----------------------------------------------------------------------"<<std::endl;
    std::cout<<"La información del coche es: "<<std::endl;
    std::cout<<"La marca es: "<<coche.Marca<<std::endl;
    std::cout<<"El modelo es: "<<coche.Modelo<<std::endl;
    std::cout<<"La matricula es: "<<coche.Matricula<<std::endl;
    std::cout<<"El año de fabricación es: "<<coche.Anio<<std::endl;
    std::cout<<"El precio es: "<<coche.Precio<<std::endl;
    std::cout<<"----------------------------------------------------------------------"<<std::endl;
}

void vehiculos::muestraEnPantalla(const automovil* coche){
    std::cout<<"La marca es: "<<coche->Marca<<std::endl;
    std::cout<<"El modelo es: "<<coche->Modelo<<std::endl;
    std::cout<<"La matricula es: "<<coche->Matricula<<std::endl;
    std::cout<<"El año de fabricación es: "<<coche->Anio<<std::endl;
    std::cout<<"El precio es: "<<coche->Precio<<std::endl; 
}


void vehiculos::visualiza(automovil v[],int tam){
    for(int i=0;i<tam;i++){
        muestraEnPantalla(v[i]);
    }
}


void vehiculos::maxPrecio(automovil coche,int& max,int& cont,int& i){
    if(coche.Precio>max){
        max=coche.Precio;
        cont=i;
    }
}

void vehiculos::incrementaPrecios(automovil v[],int tam,float porcentaje){
    if(porcentaje<0||porcentaje>5){
        throw std::string("ERROR:[incrementaPrecios]No se ha introducido un valor válido en la variable porcentajes.");//Lanza una excepcion cuando porcentaje es menor que 0 o mayor que 5.
    }
    for(int i=0;i<tam;i++){
    v[i].Precio=v[i].Precio+(v[i].Precio*porcentaje);
    }
}

int vehiculos::rellenarVector( automovil v[], int tamv ){
    int centinela=0;
    int i=0;
        do{
            if(i>=tamv){
                throw std::string("ERROR[vehiculos::rellenarVector]:No puede introducir un número de vehículos mayor que el permitido.");//Lanza una excepción cuando el número de datos introducidos es mayor que el tamaño permitido.
            }
            try{
                leePorTeclado(v[i]);
            }catch(std::string &cad){
                std::cerr<<cad;
            }
            std::cout<<"Pulse 0 para continuar y 1 para parar: "<<std::endl;
            std::cin>>centinela;
            i++;
        }while(centinela!=1);
    return i;
}

void vehiculos::mostrarEnPantalla(const automovil v[],int tamv){
    std::string tecla;
    for(int i=0;i<tamv;i++){
        if(i%5==0){
            std::cout<<"Introduce una tecla para continuar: "<<std::endl;
            std::cin>>tecla;
        }
        std::cout<<v[i].Marca<<"   "<<v[i].Modelo<<"   "<<v[i].Matricula<<"   "<<v[i].Anio<<"   "<<v[i].Precio<<std::endl;
    }
}

int vehiculos::maxPrecio(automovil v[], int tamv){
    int max=0;
    int cont=0;
    for(int i=0;i<tamv;i++){
        if(v[i].Precio>max){
            max=v[i].Precio;
            cont=i;
        }
    }
    return cont;
}

int vehiculos::buscarPorMatricula( std::string matricula, automovil v[], int tamv){
    int cont=0;
    bool es=false;
    for(int i=0;i<tamv;i++){
        if(matricula==v[i].Matricula){
            cont=i;
            es=true;
        }
    }
    if(es){
        return cont;
    }else{
        throw std::string("ERROR[vehiculos::buscarPorMatricula]:La matrícula introducida no se encuentra en la base de datos.");
    }
}



