/** @file Bicicletas.hh
    @brief Especificacion de la clase Bicicletas
*/

#ifndef BICICLETAS_HH
#define BICICLETAS_HH
#include "Bicicleta.hh"
#ifndef NO_DIAGRAM
#include <iostream>
#include <map>
using namespace std;
#endif

/** @class Bicicletas
    @brief Representa el conjunto de todas las bicicletas y sus funciones
*/

class Bicicletas {

private:
    /** @brief map que contiene todas las bicis del sistema*/
    map<string,Bicicleta>& cjt_bicis;

public:
    /** @brief constructora de Bicicletas
        @pre cierto
        @post el map m pasa a ser el map que contiene las bicis
    */
    Bicicletas(map<string,Bicicleta>& m);
    
    /** @brief consultar ubicacion de una bici
        @pre la bici con id = idb existe
        @post devuelve la ubicacion en la que esta la bici con id = idb 
    */
    string consultar_ubicacion(const string& idb);

    /** @brief añadir nueva bici
        @pre la bici con id = idb no existe, la estacion con id = ide existe
             y no esta llena
        @post se añade una nueva bici que esta en la estacion con id=ide al conjunto 
    */
    void nueva_bici(const string& idb,const string& ide);

    /** @brief borrar bici
        @pre la bici con id = idb existe
        @post la bici con id = idb se borra del conjunto
    */
    void quitar_bici(const string& idb);

    /** @brief devolver bici
        @pre la bici cn id = idb existe
        @post devueve la bici con id = idb
    */
    Bicicleta bici_concreta(const string& idb);

    /** @brief indicar si una bici existe
        @pre cierto
        @post devuelve true si la bici con id = idb existe en el conjunto
              false en caso contrario
    */
    bool buscar_bicicleta(const string& idb);

    /** @brief añadir nuevo viaje
        @pre la bici con id=idb existe y no esta en la estacion de destino
             y esta misma existe
        @post la bici con id=idb va de su ubicacion actual a la que tiene un
              id=new_est
    */
    void nueva_ubi(const string& idb, const string& new_ide);

    /** @brief cambiar la ubicacion
        @pre la bici con id=idb existe y no esta en la estacion nueva
             y esta misma existe
        @post a la bici con id=idb se le cambia la ubicacion de la actual
              a la que tiene id=nueva
    */
    void cambiar_la_ubi(const string& idb,const string& nueva);  

    /** @brief sacar los viajes de una bici
        @pre la bici con id=idb existe
        @post se sacan por pantalla los viajes de la bici
              con id=idb
    */
    void sacar_viajes(const string& idb);
};
#endif