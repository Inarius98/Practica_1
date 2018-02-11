/* 
 * File:   vehiculo.h
 * Author: Andrés
 * Created on 10 de febrero de 2018, 16:01
 */

#ifndef VEHICULO_H
#define VEHICULO_H
#include <iostream>
#include <string>

namespace vehiculos{


            struct automovil{
                std::string Marca;
                std::string Modelo;
                std::string Matricula;
                int Anio;
                float Precio;
            };
            /**
            * @brief Lectura de vehiculos por pantalla(por referencia).
            * @param[in,out] coche de tipo automovil a rellenar.
            * @post Introduce los datos necesarios en cada uno de los campos de la variable coche.
            */
            void leePorTeclado(automovil& coche);
            /**
            * @brief Lectura de vehiculos por pantalla(por punteros).
            * @param[in,out] coche de tipo automovil a rellenar.
            * @post Coloca los datos introducidos en cada uno de los campos de la variable coche.
            */
            void leePorTeclado(automovil* coche);
            /**
            * @brief Muestra los datos de coche en pantalla.(por referencia).
            * @param[in] coche de tipo automovil a leer.
            * @pre Debe haber introducido anteriormente datos en la variable coche.
            * @post Muestra por pantalla los datos introducidos en la variable coche.
            */
            void muestraEnPantalla(const automovil& coche);
            /**
            * @brief Muestra los datos de coche en pantalla.(por punteros).
            * @param[in] coche de tipo automovil a leer.
            * @pre Debe haber introducido anteriormente datos en la variable coche.
            * @post Muestra por pantalla los datos introducidos en la variable coche.
            */
            void muestraEnPantalla(const automovil* coche);
            /**
            * @brief Muestra los datos de un vector por pantalla.
            * @param v vector de tipo automovil a mostrar.
            * @param tam tamaño del vector.
            * @pre Debe haber introducido anteriormente datos en el vector.
            * @post Muestra los datos de la variable vector.
            */
            void visualiza(automovil v[],int tam);
            /**
            * @brief Calcula el máximo precio entre los datos introducidos.
            * @param[in] coche de tipo automovil
            * @param[in,out] max para conocer el maximo
            * @param[in,out] cont para conocer la posicion en la que se encuentra el precio máximo.
            * @param[in,out] i para conocer la posicion en la que se encuentra el precio máximo a través del ciclo for realizado en el main.
            * @pre Debe haber introducido anteriormente datos en la variable coche.
            * @post Calcula el precio máximo de un coche entre los precios introducidos por el usuario.
            */
            void maxPrecio(automovil coche,int& max,int& cont,int& i);
            /**
            * @brief incrementa el precio a través de un porcentaje.
            * @param v vector de automovil.
            * @param tam tamaño del vector.
            * @param porcentaje para aumentar el precio.
            * @pre debe haber introducido un porcentaje anteriormente.
            * @post Calcula el incremento de precio de los coches del vector v a través de un porcentaje.
            */
            void incrementaPrecios(automovil v[],int tam,float porcentaje);
            /**
             * @brief Lee por teclado un vector de vehiculos.
             * @param v[in,out] Vector a rellenar.
             * @param tamv[in] Tamaño del vectro.
             * @post Rellenar el vector con datos de vehículos.
             * @return Devuelve el número de vehículos introducidos.
             */
            int rellenarVector( automovil v[], int tamv );
            /**
             * @brief Muestra por pantalla los vehiculos del vector de 5 en 5.
             * @param v[in] vector de automovil.
             * @param tamv tamaño del vector.
             * @pre Debe haber introducido datos en v amteriormente.
             * @post Muestra por pantalla los vehiculos del vector a vehiculo por linea y de 5 en 5.
             */
            void mostrarEnPantalla(const automovil v[],int tamv);
            /**
             * @brief Calcula el vehiculo de mayor precio.
             * @param v[in] vector de automovil.
             * @param tamv tamaño del vector.
             * @return Devuelve la posición del vehículo de mayor precio.
             * @post Calcula el vehículo de mayor precio y devuelve su posición.
             */
            int maxPrecio(automovil v[], int tamv);
            /**
             * @brief Buscar vehículo a través de matrícula.
             * @param matricula[in] Matrícula del coche a buscar.
             * @param v[in] Vector donde se encuentran los datos.
             * @param tamv[in] Tamaño del vector.
             * @pre Debe haber introducido los datos en el vector.
             * @return Devuelve la posición del vehículo de la matrícula buscada.
             * @post Busca un vehículo a través de una matrícula introducida por el usuario, devolviendo la posición del vehículo.
             */
            int buscarPorMatricula( std::string matricula, automovil v[], int tamv);
};
#endif /* VEHICULO_H */

