/** @file program.cc
   @brief Programa principal para probar todas las operaciones involucradas en el sistema. 
*/

#include "Bicicletas.hh"
#include "Estaciones.hh"
#ifndef NO_DIAGRAM  
#include "Bicicleta.hh"
#include "Estacion.hh"
using namespace std;
#endif

int main () {
    BinTree<string>ids_estaciones;
    map<string,Estacion> estaciones;
    map<string,Bicicleta> bicis;
    Bicicletas bicicletas(bicis);
    Estaciones ests(ids_estaciones,estaciones,bicicletas);
    ests.leer(ids_estaciones,estaciones);
    string command;
    
    while (command != "fin") {
        int capacidad;
        string id_bici, id_est;
        
        if (command == "alta_bici" or command == "ab") {
            cin >> id_bici >> id_est;
            cout << "#ab " << id_bici << " " << id_est << endl;
            if (bicicletas.buscar_bicicleta(id_bici)) cout << "error: la bici ya existe" << endl;
            else if (!ests.existe_estacion(ids_estaciones,id_est)) cout << "error: la estacion no existe" << endl;
            else if (estaciones[id_est].sitios_libres() == 0) cout << "error: la bici no cabe" << endl;
            else {
                ests.alta(id_bici,id_est);
            }
        }
        
        else if (command == "baja_bici" or command == "bb") {
            cin >> id_bici;
            cout << "#bb " << id_bici << endl;
            if (!bicicletas.buscar_bicicleta(id_bici)) cout << "error: la bici no existe" << endl;
            else {
                ests.eliminar_bicicleta(id_bici);
            }
        }
        
        else if (command == "estacion_bici" or command == "eb") {
            cin >> id_bici;
            cout << "#eb " << id_bici << endl;
            if (!bicicletas.buscar_bicicleta(id_bici)) cout << "error: la bici no existe" << endl;
            else cout << bicicletas.consultar_ubicacion(id_bici) << endl;
        }
        
        else if (command == "viajes_bici" or command == "vb") {
            cin >> id_bici;
            cout << "#vb " << id_bici << endl;
            if (!bicicletas.buscar_bicicleta(id_bici)) cout << "error: la bici no existe" << endl;
            else {
                bicicletas.sacar_viajes(id_bici);
            }
        }
        
        else if (command == "mover_bici" or command == "mb") {
            cin >> id_bici >> id_est;
            cout << "#mb " << id_bici << " " << id_est << endl;
            if (!bicicletas.buscar_bicicleta(id_bici)) cout << "error: la bici no existe" << endl;
            else if (!ests.existe_estacion(ids_estaciones,id_est)) cout << "error: la estacion no existe" << endl;
            else if(bicicletas.consultar_ubicacion(id_bici) == id_est) cout << "error: la bici ya esta en el sitio" << endl;
            else if (estaciones[id_est].sitios_libres() == 0) cout << "error: la bici no cabe" << endl;
            else {
                ests.cambiar_ubi(id_bici,id_est);
            }
        }
        
        else if (command == "bicis_estacion" or command == "be") {
            cin >> id_est;
            cout << "#be " << id_est << endl;
            if (!ests.existe_estacion(ids_estaciones,id_est)) cout << "error: la estacion no existe" << endl;
            else {
                estaciones[id_est].sacar_bicis();
            }
        }
        
        else if (command == "modificar_capacidad" or command == "mc") {
            cin >> id_est >> capacidad;
            cout << "#mc " << id_est << " " << capacidad << endl;
            if (!ests.existe_estacion(ids_estaciones,id_est)) cout << "error: la estacion no existe" << endl;
            else if (capacidad < estaciones[id_est].ocupacion()) cout << "error: capacidad insuficiente" << endl;
            else {
                ests.mod_libres(id_est,capacidad);
                estaciones[id_est].mod_capacidad(capacidad);
            }
        }
        
        else if (command == "plazas_libres" or command == "pl") {
            cout << "#pl" << endl;
            ests.consultar_libres();
        }
        
        else if (command == "subir_bicis" or command == "sb") {
            cout << "#sb" << endl;
            ests.reestructurar_ubis(ids_estaciones);
        }
        
        else if (command == "asignar_estacion" or command == "ae") {
            cin >> id_bici;
            cout << "#ae " << id_bici << endl;
            if (bicicletas.buscar_bicicleta(id_bici)) cout << "error: la bici ya existe" << endl;
            else if(!ests.hay_hueco()) cout << "error: no hay plazas libres" << endl;
            else {
                string id_est_correcto = "";
                ests.assig_est(id_est_correcto);
                ests.alta(id_bici,id_est_correcto);
                cout << id_est_correcto << endl;
            }
        }
        
        cin >> command;
    }
}