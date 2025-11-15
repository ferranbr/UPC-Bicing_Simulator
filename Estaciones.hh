/** @file Estaciones.hh
    @brief Especificacion de la clase Estaciones
*/

#ifndef ESTACIONES_HH
#define ESTACIONES_HH
#include "Bicicletas.hh"
#include "Estacion.hh"
#ifndef NO_DIAGRAM
#include "BinTree.hh"
using namespace std;
#endif

/** @class Estaciones
    @brief Representa el conjuto de todas las estaciones y sus funciones
*/

class Estaciones {

private:
    /** @brief arbol con la jerarqui de estaciones y sus ids */
    BinTree<string>&ids_estaciones;
    /** @brief map que contiene las estaciones del sistema*/
    map<string,Estacion>&estaciones;
    /** @brief conjunto de bicicletas*/
    Bicicletas &bicicletas;
    /** @brief nuemro total de plazas libres del sistema*/
    int plazas_libres = 0;

public:
    /** @brief constructora de estaciones
        @pre cierto
        @post la bici con id = idb se borra del conjunto
    */
    Estaciones(BinTree<string>&ids_estaciones, map<string,Estacion>&estaciones, Bicicletas&bicicletas);

    /** @brief dar de alta
        @pre la bici con id = idb existe y lo mismo con la estacion de id=ide
        @post la bici con id=idb y la estacion con id=ide se da de alta en dicha estacion
    */
    void alta(const string& idb,const string& ide);

    /** @brief consultar existencia de estacion
        @pre cierto
        @post devuelve true si la estacion de id=ide existe, false en caso contrario
    */
    bool existe_estacion(const BinTree<string>&ids,const string& id);

    /** @brief consultar plazas libres totales
        @pre cierto
        @post saca por pantalla las plazas libres totales del sistema
    */
    void consultar_libres();

    /** @brief añadir nuevo viaje
        @pre la bici con id=idb existe
        @post se le añade un nuveo viaje a la bici con id=idb des de su estacion actual a new_est
    */
    void cambiar_ubi(const string& idb,const string& new_est);

    /** @brief eliminar bici
        @pre la bici con id = idb existe
        @post la bici con id = idb queda borrada del sistema
    */
    void eliminar_bicicleta(const string& idb);

    /** @brief consultar si hay algu hueco
        @pre cierto
        @post devueve true si queda algun hueco en el sistema, false en caso contrario
    */
    bool hay_hueco();

    /** @brief reestructurar ubicaciones
        @pre true
        @post cada estacion ha quedado llenada con las bicis de las dos contiguas
    */
    void reestructurar_ubis(const BinTree<string>& ids);

    /** @brief determinar estacion con meyor coeficiente de desocupacion
        @pre cierto
        @post la estacion con mayor coeficiente de desocupacion queda almacenada en ide
    */
    void assig_est_aux(const BinTree<string>&ids,int&ests,int&libres,double&max_desocup,string&ide);

    /** @brief asignar estacion
        @pre cierto
        @post guarda en ide la estacion con mayor coeficiente de desocupacion
    */
    void assig_est(string&ide);

    /** @brief operacion de lectura
        @pre en el canal de entrada hay una jerarquia de ids de estaciones junto a su capacidad
        @post la jerarquia queda almacenada en el arbol a y las estaciones en el map m
    */
    void leer(BinTree<string>& a, map<string,Estacion>& m);

    /** @brief actualizar plazas libres
        @pre cierto
        @post el numero de plazas libres del sistema se ha actualizado dada la nueva capacidad c
    */
    void mod_libres(const string &ide,const int& c);
};
#endif