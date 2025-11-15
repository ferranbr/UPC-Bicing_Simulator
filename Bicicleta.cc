#include "Bicicleta.hh"


Bicicleta::Bicicleta() {
    id_bici = "";
    ubi = "";
}

Bicicleta::Bicicleta(const string& id, const string& est_act) {
    id_bici = id;
    ubi = est_act;
}

string Bicicleta::consultar_id_bici() {
    return id_bici;
}

string Bicicleta::consultar_ubi() {
    return ubi;
}

void Bicicleta::cambiar_ubicacion(const string& nueva) {
    ubi = nueva;
}

void Bicicleta::consultar_viajes() {
    for (int i = 0; i < viajes.size(); ++i) {
        cout << viajes[i].first << " " << viajes[i].second << endl;
    }
}

void Bicicleta::nuevo_viaje(const string& id_estacion) {
    viajes.push_back(make_pair(ubi,id_estacion));
    ubi = id_estacion;
}