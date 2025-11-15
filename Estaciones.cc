#include "Estaciones.hh"

Estaciones::Estaciones(BinTree<string>& ids_estaciones, map<string, Estacion>& estaciones, Bicicletas &bicicletas) : ids_estaciones(ids_estaciones) ,estaciones(estaciones), bicicletas(bicicletas),plazas_libres(0) {}

void Estaciones::alta(const string& idb,const string& ide) {
    Bicicleta b(idb,ide);
    estaciones[ide].insertar_bici(b);
    bicicletas.nueva_bici(idb,ide);
    --plazas_libres;
}

bool Estaciones::existe_estacion(const BinTree<string>&ids,const string& id) {
    if (ids.value() == id) return true;
    else {
        bool left = false;
        bool right = false;
        if (!ids.left().empty()) left = existe_estacion(ids.left(),id);
        if(!ids.right().empty()) right = existe_estacion(ids.right(),id);
        return left or right;
    }
}

void Estaciones::consultar_libres() {
    cout << plazas_libres << endl;
}

void Estaciones::cambiar_ubi(const string& idb,const string& new_est) {
    string ubi_act = bicicletas.consultar_ubicacion(idb);
    estaciones[ubi_act].borrar_bici(idb);
    estaciones[new_est].insertar_bici(bicicletas.bici_concreta(idb));
    bicicletas.nueva_ubi(idb,new_est);
}

void Estaciones::eliminar_bicicleta(const string& idb) {
    string ide = bicicletas.consultar_ubicacion(idb);
    bicicletas.quitar_bici(idb);
    estaciones[ide].borrar_bici(idb);
    ++plazas_libres;
}

bool Estaciones::hay_hueco() {
    if (plazas_libres > 0) return true;
    else return false;
}

void Estaciones::mod_libres(const string &ide,const int& c) {
    int act = estaciones[ide].cap();
    plazas_libres = plazas_libres + c - act;
}

void Estaciones::reestructurar_ubis(const BinTree<string>& ids) {
    if (!ids.left().empty()) {
        string valor = ids.value();
        auto iv = estaciones.find(valor);
        auto ie = estaciones.find(ids.left().value());
        auto id = estaciones.find(ids.right().value());

        int bicis_disponibles = ie->second.ocupacion() + id->second.ocupacion();

        while (iv->second.sitios_libres() > 0 && bicis_disponibles > 0) {
            if (ie->second.ocupacion() > id->second.ocupacion()) { //mas bicis en la estacion izquierda que en la derecha
                bicicletas.cambiar_la_ubi(ie->second.primera_bici(), valor);
                Bicicleta bici = bicicletas.bici_concreta(ie->second.primera_bici());
                iv->second.insertar_bici(bici);
                ie->second.borrar_bici(ie->second.primera_bici());
                
            } 
            else if (ie->second.ocupacion() < id->second.ocupacion()) { //mas bicis en la estacion derecha que en la izquierda
                bicicletas.cambiar_la_ubi(id->second.primera_bici(), valor);
                Bicicleta bici = bicicletas.bici_concreta(id->second.primera_bici());
                iv->second.insertar_bici(bici);
                id->second.borrar_bici(id->second.primera_bici());
            }
            else { //mismo numeros de bicis en las dos estaciones
                //id de la primera bici mas pequeño en la de la izquierda que en la derecha
                if (ie->second.primera_bici() < id->second.primera_bici()) { 
                    bicicletas.cambiar_la_ubi(ie->second.primera_bici(), valor);
                    Bicicleta bici = bicicletas.bici_concreta(ie->second.primera_bici());
                    iv->second.insertar_bici(bici);
                    ie->second.borrar_bici(ie->second.primera_bici());
                }
                //id de la primera bici mas pequeño en la de la derecha que en la izquierda
                else {
                    bicicletas.cambiar_la_ubi(id->second.primera_bici(), valor);
                    Bicicleta bici = bicicletas.bici_concreta(id->second.primera_bici());
                    iv->second.insertar_bici(bici);
                    id->second.borrar_bici(id->second.primera_bici());
                }
            }
            --bicis_disponibles;
        }
        reestructurar_ubis(ids.left());
        reestructurar_ubis(ids.right());
    }
}



void Estaciones::assig_est_aux(const BinTree<string>&ids,int&ests,int&libres,double&max_desocup,string&ide) {
    if (ids.empty()) {
        ests = 0;
        libres = 0;
    }
    else {
        int dre,izq,lib_dre,lib_izq;
        assig_est_aux(ids.left(),izq,lib_izq,max_desocup,ide);
        assig_est_aux(ids.right(),dre,lib_dre,max_desocup,ide);
        ests = 1 + izq + dre; //numeros de estaciones recorridas
        libres = estaciones[ids.value()].sitios_libres() + lib_dre + lib_izq; //numero de plazas libres totales de todas las estaciones recorridas
        double desocup = double(libres)/double(ests); //coeficiente de desocupacion actualizado
        if (desocup > max_desocup) { //coeficiente actual mas grande que el el maximo hasta el momento
            ide = ids.value();
            max_desocup = desocup; 
        }
        else if (desocup == max_desocup) {//coeficiente actual igual que el mas grande hasta el momento
            if (ide == " " or ids.value() < ide) ide = ids.value();
        }
    }
}

void Estaciones::assig_est(string& ide) {
    double max_desocup = 0;
    string ide_act = "";
    int ests,libres;
    assig_est_aux(ids_estaciones,ests,libres,max_desocup,ide_act);
    ide = ide_act;
}

void Estaciones::leer(BinTree<string>& a, map<string,Estacion>& m) {
    string x;
    cin >> x;

    if(x != "#") {
        int n;
        cin >> n;
        plazas_libres += n;
        Estacion e(x,n);
        m[x] = e;
        BinTree<string> left,right;
        leer(left,m);
        leer(right,m);
        a = BinTree<string>(x,left,right);
    }
}
