#include "Estacion.hh"

Estacion::Estacion() : bicis() {
    id_estacion = "";
    capacidad = 0;
}

Estacion::Estacion(const string& ide,const int& c) {
    id_estacion = ide;
    capacidad = c;
}

string Estacion::consultar_id_est() {
    return id_estacion;
}

void Estacion::borrar_bici(const string& idb) {
    auto i = bicis.find(idb);
    bicis.erase(i);
}

void Estacion::sacar_bicis() {
    for (auto i = bicis.begin(); i != bicis.end(); ++i) {
        cout << i->second.consultar_id_bici() << endl;
    }
}

int Estacion::ocupacion() {
    return bicis.size();
}

int Estacion::cap() {
    return capacidad;
}

string Estacion::primera_bici() {
    auto i = bicis.begin();
    return i -> first;
}

void Estacion::insertar_bici(Bicicleta b) {
    string ide = b.consultar_id_bici();
    bicis[ide] = b;
}
void Estacion::mod_capacidad(const int& nueva_capacidad) {
    capacidad = nueva_capacidad;
}

int Estacion::sitios_libres() {
    return (capacidad - bicis.size());
}