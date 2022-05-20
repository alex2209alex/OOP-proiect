//
// Created by alex on 5/18/2022.
//

#include "TransportMaritim.h"
#include "erori.h"

TransportMaritim::TransportMaritim() = default;

void TransportMaritim::adauga_nava(std::shared_ptr<Nava> nava) {
    flota.push_back(nava);
}
void TransportMaritim::adauga_container(std::shared_ptr<Container> container) {
    containere.push_back(container);
}
void TransportMaritim::adauga_port(std::shared_ptr<Port> port) {
    porturi.push_back(port);
}

void TransportMaritim::adauga_elementele() {
    Tara ro{"Romania", "Europa"};
    Tara gr{"Grecia", "Europa"};
    Tara sua{"America", "America de Nord"};
    std::shared_ptr<Port> port_new_york = std::make_shared<Port>(Port{sua, "New York"});
    std::shared_ptr<Port> port_constanta = std::make_shared<Port>(Port{ro, "Constanta"});
    std::shared_ptr<Port> port_atena = std::make_shared<Port>(Port{gr, "Atena"});
    std::shared_ptr<Container> masini_new_york = std::make_shared<Container>(Container{"Masini", 100, *port_new_york});
    std::shared_ptr<Container> pere_constanta = std::make_shared<Container>(Container{"Pere", 50, *port_constanta});
    std::shared_ptr<Container> mere_atena = std::make_shared<Container>(Container{"Mere", 51, *port_atena});
    std::shared_ptr<Nava> nava_tr_cont = std::make_shared<NavaTransportContainere>(NavaTransportContainere{port_constanta, "Transport containere 1", ro, 1, 100});
    std::shared_ptr<Nava> nava_tr_pasageri = std::make_shared<NavaDePasageri>(NavaDePasageri{port_constanta, "Transport pasageri 1", ro, 2, 1000, 10});
    std::shared_ptr<Nava> nava_tr_petrol = std::make_shared<NavaPetrolier>(NavaPetrolier{port_new_york, "Transport petrol 1", ro, 3, 10000, 5000});
    this->adauga_container(mere_atena);
    this->adauga_container(pere_constanta);
    this->adauga_container(masini_new_york);
    this->adauga_nava(nava_tr_cont);
    this->adauga_nava(nava_tr_pasageri);
    this->adauga_nava(nava_tr_petrol);
    this->adauga_port(port_constanta);
    this->adauga_port(port_atena);
    this->adauga_port(port_new_york);
}

void TransportMaritim::ruleaza() {
    std::cout << "//////////////////////////////\n";
    std::cout << "Stare initiala a navelor:\n";
    std::cout << "//////////////////////////////\n";
    for(const auto& it : this->flota) {
        (*it).afiseaza_nava();
        std::cout << "\n";
    }
    std::cout << "//////////////////////////////\n";
    std::cout << "Incercare de a incarca navele:\n";
    std::cout << "//////////////////////////////\n";
    for(const auto& it : this->flota) {
        int r = rand() % 2;
        try {
            if(r == 0) {
                int r2 = rand() % 1000;
                (*it).adauga_pe_nava(r2);
            }
            else {
                int r2 = rand() % 3;
                (*it).adauga_pe_nava(*this->containere[r2]);
            }
            std::cout << "Nava e incarcata in mod corect\n";
        } catch (incarcare_gresita& err) {
            std::cout << err.what() << "\n";
        } catch (incarcare_peste_capacitate& err) {
            std::cout << err.what() << "\n";
        }
    }

    std::cout << "//////////////////////////////\n";
    std::cout << "Stare a navelor dupa incarcare:\n";
    std::cout << "//////////////////////////////\n";

    for(const auto& it : this->flota) {
        (*it).afiseaza_nava();
        std::cout << "\n";
    }

    std::cout << "//////////////////////////////\n";
    std::cout << "Modificam starea porturilor:\n";
    std::cout << "//////////////////////////////\n";

    std::cout << "//////////////////////////////\n";
    std::cout << "Starea initiala a porturilor:\n";
    std::cout << "//////////////////////////////\n";

    for(auto it : this->porturi) {
        std::cout << (*it) << '\n';
    }

    for(const auto& it : this->porturi) {
        int r = rand() % 2;
        if(r == 0)
            (*it).inchiderePort();
        else {
            (*it).deschiderePort();
        }
    }

    std::cout << "//////////////////////////////\n";
    std::cout << "Starea finala a porturilor:\n";
    std::cout << "//////////////////////////////\n";

    for(const auto& it : this->porturi) {
        std::cout << (*it) << '\n';
    }

    std::cout << "//////////////////////////////\n";
    std::cout << "Incercam sa mutam navele:\n";
    std::cout << "//////////////////////////////\n";

    for(auto it : this->flota) {
        int r = rand() % 3;
        try {
            (*it).intrare_port(this->porturi[r]);
            std::cout << "Nava s-a mutat\n";
        } catch(port_sursa_inchis& err) {
            std::cout << err.what() << '\n';
        } catch(port_destinatie_inchis& err) {
            std::cout << err.what() << '\n';
        } catch(port_identic& err) {
            std::cout << err.what() << '\n';
        }
    }

    std::cout << "//////////////////////////////\n";
    std::cout << "Stare a navelor dupa mutare:\n";
    std::cout << "//////////////////////////////\n";

    for(const auto& it : this->flota) {
        (*it).afiseaza_nava();
        std::cout << "\n";
    }

    std::cout << "//////////////////////////////\n";
    std::cout << "Incercare de a descarca navele:\n";
    std::cout << "//////////////////////////////\n";
    for(const auto& it : this->flota) {
        try {
            (*it).scoate_de_pe_nava();
            std::cout << "Nava e descarcata in mod corect\n";
        } catch (nu_se_descarca_nimic& err) {
            std::cout << err.what() << "\n";
        } catch (nimic_de_scos& err) {
            std::cout << err.what() << "\n";
        } catch (cantitate_de_scos_prea_mare& err) {
            std::cout << err.what();
        }
    }

    std::cout << "//////////////////////////////\n";
    std::cout << "Stare finala a navelor:\n";
    std::cout << "//////////////////////////////\n";
    for(const auto& it : this->flota) {
        (*it).afiseaza_nava();
        std::cout << "\n";
    }
}

void TransportMaritim::dynamic_cast_folosire() {
    std::cout << "------------------------------\n";
    std::cout << "Dynamic cast";
    std::cout << "\n------------------------------\n";
    Nava *tempNava = new NavaDePasageri{this->porturi[1], "Transport pasageri temp", Tara{"Romania", "Europa"}, 0, 1000, 100};
    tempNava->scoate_de_pe_nava();
    (*tempNava).afiseaza_nava();
    if(auto* tempNava2 = dynamic_cast<NavaDePasageri *>(tempNava)) {
        tempNava2->scoate_de_pe_nava();
        (*tempNava2).afiseaza_nava();
    }
    else {
        std::cout << "Conversie nereusita\n";
    }
    if(auto* tempNava2 = dynamic_cast<NavaPetrolier *>(tempNava)) {
        tempNava2->scoate_de_pe_nava();
        (*tempNava2).afiseaza_ce_e_pe_nava();
    }
    else {
        std::cout << "Conversie nereusita\n";
    }
    if(auto* tempNava2 = dynamic_cast<NavaTransportContainere *>(tempNava)) {
        tempNava2->scoate_de_pe_nava();
        (*tempNava2).afiseaza_ce_e_pe_nava();
    }
    else {
        std::cout << "Conversie nereusita\n";
    }
    delete tempNava;
    std::cout << "------------------------------\n";
    std::cout << "Sfarsit dynamic cast";
    std::cout << "\n------------------------------\n";
}

void TransportMaritim::variabila_statica_folosire() {
    std::cout << "------------------------------\n";
    std::cout << "Inceput variabila statica";
    std::cout << "\n------------------------------\n";
    try {
        std::shared_ptr<Nava> nava_tr_cont = std::make_shared<NavaTransportContainere>(NavaTransportContainere{porturi[1], "Transport containere 2", Tara{"Rusia", "Europa"}, 1, 100});
        flota.push_back(nava_tr_cont);
        std::cout << "Identificatorul e unic\n";
    }
    catch(identificator_ne_e_unic& err) {
        std::cout << err.what();
        std::cout << "\n";
    }
    try {
        std::shared_ptr<Nava> nava_tr_cont = std::make_shared<NavaTransportContainere>(NavaTransportContainere{porturi[1], "Transport containere 2", Tara{"Rusia", "Europa"}, 4, 100});
        flota.push_back(nava_tr_cont);
        std::cout << "Identificatorul e unic\n";
    }
    catch(identificator_ne_e_unic& err) {
        std::cout << err.what();
        std::cout << "\n";
    }
    std::cout << "------------------------------\n";
    std::cout << "Sfarsit variabila statica";
    std::cout << "\n------------------------------\n";
}

TransportMaritim::TransportMaritim(const TransportMaritim& other) {
    for(const auto& it : other.flota) {
        flota.push_back(it->clone());
    }
    containere = other.containere;
    porturi = other.porturi;
}

TransportMaritim &TransportMaritim::operator=(const TransportMaritim &a) {
    if(&a != this) {
        flota = a.flota;
        porturi = a.porturi;
        containere = a.containere;
    }
    return *this;
}

TransportMaritim::~TransportMaritim() = default;
