/** @file Bicicleta.hh
    @brief Especificacion de la clase Bicicleta
*/

#ifndef BICICLETA_HH
#define BICICLETA_HH

#ifndef NO_DIAGRAM
#include <iostream>
#include <vector>
#include <string>
using namespace std;
#endif

/** @class Bicicleta
    @brief Representa una bicicleta con sus atributos y sus funciones
*/

class Bicicleta {

private:
    /** @brief id de la bici*/
    string id_bici; 
    /** @brief vector con los viajes de la bici*/
    vector<pair<string,string>>viajes; 
    /** @brief id de la estacion en la que se encuentra la bici*/
    string ubi; 

public:

    /** @brief Creadora por defecto
        @pre cierto
        @post Crea una bici sin id, sin viajes y sin ubicacion
    */
    Bicicleta();

    /** @brief Creadora de bicicleta
        @pre cierto
        @post Crea una bici con id y ubicacion
    */
    Bicicleta(const string& id, const string& est_act);

    /** @brief consultar id bici
        @pre la bici existe
        @post devuelve el id del parametro implicito
    */
    string consultar_id_bici();

    /** @brief consultar la ubicacion de una bici
        @pre la bici existe
        @post devuelve la ubicacion del parametro implicito
    */
    string consultar_ubi();

    /** @brief cambiar la ubicacion de una bici
        @pre la bici existe
        @post sustituye la ubicacion actual del parametro implicito por
              nueva
    */
    void cambiar_ubicacion(const string& nueva);

    /** @brief devuelve los viajes de una bici
        @pre la bici existe
        @post saca por pantalla los viajes de una bici 
    */
    void consultar_viajes();

    /** @brief añadir nuevo viaje a una bici
        @pre la bici existe
        @post crea un nuevo viaje de la estacion actual a id_estacion
    */
    void nuevo_viaje(const string& id_estacion);
};
#endif