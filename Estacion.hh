/** @file Estacion.hh
    @brief Especificacion de la clase Estacion
*/

#ifndef ESTACION_HH
#define ESTACION_HH
#include "Bicicleta.hh"
#ifndef NO_DIAGRAM
#include <map>
using namespace std;
#endif

/** @class Estacion
    @brief Representa una estacion con sus atributos y sus funciones
*/

class Estacion {

private:
    /** map que contiene las bicis de la estacion*/
    map<string,Bicicleta>bicis;
    /** id de la estacion*/
    string id_estacion;
    /** numero maximo de bicis que puede tener la estacion*/
    int capacidad;

public:
    /** @brief constructora de una estacion vacia
        @pre cierto
        @post se crea una estacion sin id, con capacidad=0 y
              el map vacio
    */
    Estacion();

    /** @brief constructora de una estacion
        @pre cierto
        @post crea una estacion con id=ide y capacidad=c
    */
    Estacion(const string& ide,const int& c);
    
    /** @brief consultar el id
        @pre la estacion existe
        @post devuelve el id de la estacion
    */
    string consultar_id_est();

    /** @brief borrar bici
        @pre la bici con id = idb existe y esta en la estacion
        @post la bici con id=idb queda eliminada de la estacion
    */
    void borrar_bici(const string& idb);

    /** @brief sacar las bicis
        @pre la estacion existe
        @post se sacan por pantalla las bicis que tiene la estacion
    */
    void sacar_bicis();

    /** @brief consultora del  numero de bicis
        @pre la estacion existe
        @post devuelve el numero de bicis que tiene la estacion
    */
    int ocupacion();

    /** @brief consultar capacidad
        @pre la estacion existe
        @post devielve la capacidad de la estacion
    */
    int cap();

    /** @brief consultar primera bici
        @pre la estacion existe y tiene al menos una bici
        @post devuelve el id de la primera bici de la estacion
    */
    string primera_bici();

    /** @brief añadir nueva bici
        @pre la bicicleta b no esta en la estacion
        @post se añade la bicicleta b a la estacion
    */
    void insertar_bici(Bicicleta b);

    /** @brief modificar capacidad
        @pre la estacion existe y la nueva capacidad es mas grande 
             que la anterior
        @post la capacidad de la estacion se ha cambiado por nueva_capacidad
    */
    void mod_capacidad(const int& nueva_capacidad);

    /** @brief consultar sitios libres
        @pre la estacion existe
        @post devuelve los sitios libres de la estacion
    */
    int sitios_libres();
};
#endif