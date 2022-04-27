#include <iostream>

#include "Tara.h"
#include "Port.h"
#include "Container.h"
#include "NavaDePasageri.h"
#include "NavaPetrolier.h"
#include "NavaTransportContainere.h"
#include "Firma.h"



int main() {
    Tara ro{"Romania", "Europa"};
    Tara gr{"Grecia", "Europa"};
    Port constanta{ro, "Constanta"};
    Port atena{gr, "Atena"};
    Container mere_atena{"Mere", 10, atena};
    Container mere_constanta{"Mere", 10, constanta};
    NavaTransportContainere nava_tr_cont{constanta, "Transport containere 1", ro, 1, 100};
    for (int i = 1; i <= 3; ++i) {
        nava_tr_cont.adauga_container(mere_atena);
    }
    nava_tr_cont.adauga_container(mere_constanta);
    std::cout << nava_tr_cont;
    std::cout << "//-------------------------------------\n";
    nava_tr_cont.descarcare();
    std::cout << nava_tr_cont;
    std::cout << "//-------------------------------------\n";
    nava_tr_cont.intrare_port(atena);
    std::cout << nava_tr_cont;
    std::cout << "//-------------------------------------\n";
    nava_tr_cont.descarcare();
    std::cout << nava_tr_cont;
    std::cout << "//-------------------------------------\n";
    constanta.inchiderePort();
    nava_tr_cont.intrare_port(constanta);
    std::cout << "//-------------------------------------\n";
    constanta.deschiderePort();
    nava_tr_cont.intrare_port(constanta);
    std::cout << "//-------------------------------------\n";
    NavaDePasageri nava_pas{constanta, "Transport pasageri 1", ro, 2, 100, 50};
    std::cout << nava_pas;
    std::cout << "//-------------------------------------\n";
    nava_pas.imbarcare(100);
    std::cout << "//-------------------------------------\n";
    nava_pas.debarcare(100);
    std::cout << "//-------------------------------------\n";
    nava_pas.imbarcare(10);
    std::cout << nava_pas;
    std::cout << "//-------------------------------------\n";
    nava_pas.debarcare(20);
    std::cout << nava_pas;
    std::cout << "//-------------------------------------\n";
    NavaPetrolier nava_pet{constanta, "Transport pasageri 1", ro, 3, 100000, 50000};
    std::cout << nava_pet;
    std::cout << "//-------------------------------------\n";
    nava_pet.incarcare(1000);
    std::cout << "//-------------------------------------\n";
    nava_pet.descarcare();
    std::cout << nava_pet;
    std::cout << "//-------------------------------------\n";
    nava_pet.descarcare();
    std::cout << "//-------------------------------------\n";
    nava_pet.intrare_port(atena);
    std::cout << "//-------------------------------------\n";
    nava_pet.incarcare(1000000);
    std::cout << "//-------------------------------------\n";
    const NavaMarfa* nava = nava_pet.clone();
    std::cout << *nava;
    std::cout << "//-------------------------------------\n";
    delete nava;
    Firma firma{"Firma1"};
    firma.cumpara_nava(nava_tr_cont);
    std::cout << Firma::getNrFirme() << "\n";
    std::cout << "//-------------------------------------\n";
    std::cout << firma;
    return 0;
}
