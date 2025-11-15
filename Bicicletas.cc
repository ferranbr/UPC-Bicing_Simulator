#include "Bicicletas.hh"

Bicicletas::Bicicletas(map<string,Bicicleta>& m) : cjt_bicis(m){}
    
string Bicicletas::consultar_ubicacion(const string& idb) {
    return cjt_bicis[idb].consultar_ubi();
}

void Bicicletas::nueva_bici(const string& idb,const string& ide) {
    Bicicleta b(idb,ide);
    cjt_bicis[idb] = b;
}

void Bicicletas::quitar_bici(const string& idb) {
    cjt_bicis.erase(idb);
}

Bicicleta Bicicletas::bici_concreta(const string& idb) {
    return cjt_bicis[idb];
}

bool Bicicletas::buscar_bicicleta(const string& idb) {
    if (cjt_bicis.find(idb) != cjt_bicis.end()) return true;
    else return false;
}

void Bicicletas::nueva_ubi(const string& idb,const string& new_ide) {
    cjt_bicis[idb].nuevo_viaje(new_ide);
}  

void Bicicletas::cambiar_la_ubi(const string& idb,const string& nueva) {
    cjt_bicis[idb].cambiar_ubicacion(nueva);
}

void Bicicletas::sacar_viajes(const string& idb) {
    cjt_bicis[idb].consultar_viajes();
}