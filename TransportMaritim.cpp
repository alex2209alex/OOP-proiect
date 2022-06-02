//
// Created by alex on 5/18/2022.
//

#include "TransportMaritim.h"
#include "erori.h"
#include "PortBuilder.h"
#include "FunctiiAfisatColectiiSTL.cpp"

TransportMaritim::TransportMaritim() = default;

void TransportMaritim::adauga_nava(const std::shared_ptr<Nava> &nava) {
    flota.push_back(nava);
}
void TransportMaritim::adauga_container(const Container &container) {
    containere.push_back(container);
}
void TransportMaritim::adauga_port(const std::shared_ptr<Port> &port) {
    porturi.push_back(port);
}

void TransportMaritim::adauga_elementele() {
    TaraTemplate<int> ro{"Romania", "Europa", 1};
    TaraTemplate<int> gr{"Romania", "Europa", 2};
    TaraTemplate<int> sua{"Romania", "Europa", 3};
    TaraTemplate<std::string> ro2{"Romania", "Europa", "ROU"};
    TaraTemplate<std::string> gr2{"Romania", "Europa", "GRE"};
    TaraTemplate<std::string> sua2{"Romania", "Europa", "USA"};
    PortBuilder pb;
    try {
        std::shared_ptr<Port> port_new_york = std::make_shared<Port>(pb.oras("New York").starePort(Port::DESCHIS).tara(sua2).build());
        Container masini_new_york = Container{"Masini", 100, *port_new_york};
        std::shared_ptr<Nava> nava_tr_petrol = std::make_shared<NavaPetrolier>(NavaPetrolier{port_new_york, "Transport petrol 1", ro, 3, 10000, 5000});
        this->adauga_port(port_new_york);
        this->adauga_container(masini_new_york);
        this->adauga_nava(nava_tr_petrol->clone());
    } catch (build_object_invalid& err) {
        std::cout << err.what() << "\n";
    }
    try {
        std::shared_ptr<Port> port_constanta = std::make_shared<Port>(pb.oras("Constanta").starePort(Port::DESCHIS).tara(ro2).build());
        Container pere_constanta = Container{"Pere", 50, *port_constanta};
        std::shared_ptr<Nava> nava_tr_cont = std::make_shared<NavaTransportContainere>(NavaTransportContainere{port_constanta, "Transport containere 1", ro, 1, 100});
        std::shared_ptr<Nava> nava_tr_pasageri = std::make_shared<NavaDePasageri>(NavaDePasageri{port_constanta, "Transport pasageri 1", ro, 2, 1000, 10});
        std::shared_ptr<Nava> nava_tr_pasageri_si_cont = std::make_shared<NavaDePasageriSiTransportContainere>(NavaDePasageriSiTransportContainere{port_constanta, "Transport pasageri si containere 1", ro, 4, 1000, 1000, 100});
        this->adauga_port(port_constanta);
        this->adauga_container(pere_constanta);
        this->adauga_nava(nava_tr_cont->clone());
        this->adauga_nava(nava_tr_pasageri->clone());
        this->adauga_nava(nava_tr_pasageri_si_cont->clone());
    } catch (build_object_invalid& err) {
        std::cout << err.what() << "\n";
    }
    try {
        std::shared_ptr<Port> port_atena = std::make_shared<Port>(pb.oras("Atena").starePort(Port::DESCHIS).tara(gr2).build());
        Container mere_atena = Container{"Mere", 51, *port_atena};
        this->adauga_port(port_atena);
        this->adauga_container(mere_atena);
    } catch (build_object_invalid& err) {
        std::cout << err.what() << "\n";
    }
    try {
        std::shared_ptr<Port> port_gresit = std::make_shared<Port>(pb.oras("Atena").tara(gr2).build());
    } catch (build_object_invalid& err) {
        std::cout << err.what() << "\n";
    }
}

void TransportMaritim::ruleaza() {
    std::cout << "//////////////////////////////\n";
    std::cout << "Stare initiala a navelor:\n";
    std::cout << "//////////////////////////////\n";
    std::cout << flota << "\n";
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
                (*it).adauga_pe_nava(this->containere[r2]);
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
    std::cout << flota << "\n";
    std::cout << "//////////////////////////////\n";
    std::cout << "Modificam starea porturilor:\n";
    std::cout << "//////////////////////////////\n";

    std::cout << "//////////////////////////////\n";
    std::cout << "Starea initiala a porturilor:\n";
    std::cout << "//////////////////////////////\n";

    std::cout << porturi << "\n";

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

    std::cout << porturi << "\n";

    std::cout << "//////////////////////////////\n";
    std::cout << "Incercam sa mutam navele:\n";
    std::cout << "//////////////////////////////\n";

    for(auto it : this->flota) {
        int r = rand() % 3;
        try {
            (*it).intrare_port(this->porturi[r]);
            std::cout << "Nava s-a mutat\n";
        } catch(port_sursa_inchis& err) {
            std::cout << err.what() << "\n";
        } catch(port_destinatie_inchis& err) {
            std::cout << err.what() << "\n";
        } catch(port_identic& err) {
            std::cout << err.what() << "\n";
        }
    }

    std::cout << "//////////////////////////////\n";
    std::cout << "Stare a navelor dupa mutare:\n";
    std::cout << "//////////////////////////////\n";

    std::cout << flota << "\n";

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

    std::cout << flota << "\n";
}

void TransportMaritim::dynamic_cast_folosire() {
    std::cout << "------------------------------\n";
    std::cout << "Dynamic cast";
    std::cout << "\n------------------------------\n";
    Nava *tempNava = new NavaDePasageri{this->porturi[1], "Transport pasageri temp", TaraTemplate<int>{"Romania", "Europa", 1}, 0, 1000, 100};
    tempNava->scoate_de_pe_nava();
    (*tempNava).afiseaza_nava();
    if(auto* tempNava2 = dynamic_cast<NavaDePasageri *>(tempNava)) {
        (*tempNava2).evacuare();
    }
    else {
        std::cout << "Conversie nereusita\n";
    }
    if(auto* tempNava2 = dynamic_cast<NavaPetrolier *>(tempNava)) {
        (*tempNava2).umple();
    }
    else {
        std::cout << "Conversie nereusita\n";
    }
    if(auto* tempNava2 = dynamic_cast<NavaTransportContainere *>(tempNava)) {
        tempNava2->afiseazaSpatiuRamas();
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
        std::shared_ptr<Nava> nava_tr_cont = std::make_shared<NavaTransportContainere>(NavaTransportContainere{porturi[1], "Transport containere 2", TaraTemplate<int>{"Rusia", "Europa", 4}, 1, 100});
        flota.push_back(nava_tr_cont);
        std::cout << "Identificatorul e unic\n";
    }
    catch(identificator_ne_e_unic& err) {
        std::cout << err.what();
        std::cout << "\n";
    }
    try {
        std::shared_ptr<Nava> nava_tr_cont = std::make_shared<NavaTransportContainere>(NavaTransportContainere{porturi[1], "Transport containere 2", TaraTemplate{"Rusia", "Europa", 4}, 4, 100});
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
    int nrNave = 0, nrContainere = 0, nrPorturi = 0;
    for(const auto& it : other.flota) {
        flota.push_back(it->clone());
        nrNave++;
    }
    for(const auto& it : other.containere) {
        containere.push_back((it));
        nrContainere++;
    }
    for(const auto& it : other.porturi) {
        porturi.push_back((it));
        nrPorturi++;
    }
    std::cout << "Au fost copiate " << nrNave << " nave, " << nrContainere << "containere, " << nrPorturi << "porturi\n";
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
