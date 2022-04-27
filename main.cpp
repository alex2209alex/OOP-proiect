#include <iostream>
#include <vector>

#include "Tara.h"
#include "Port.h"
#include "Container.h"
#include "Nava.h"
#include "NavaMarfa.h"
#include "NavaDePasageri.h"
#include "NavaPetrolier.h"
#include "NavaTransportContainere.h"

int main() {
    const Tara INTERNATIONAL{"INTERNATIONAL", "INTERNATIONAL"};
    const Port APEINTERNATIONALE{INTERNATIONAL, "APE INTERNATIONALE"};
    Tara ro{"Romania", "Europa"};
    Tara gr{"Grecia", "Europa"};
    Port constanta{ro, "Constanta"};
    Port atena{gr, "Atena"};
    Container mere_atena{"Mere", 10, atena};
    Container mere_constanta{"Mere", 10, constanta};
    NavaTransportContainere nava_tr_cont{constanta, "Transport containere 1", ro, 1, 100};
    for (int i = 1; i <= 9; ++i) {
        nava_tr_cont.adauga_container(mere_atena);
    }
    nava_tr_cont.adauga_container(mere_constanta);
    std::cout << nava_tr_cont;
    nava_tr_cont.descarcare();
    std::cout << nava_tr_cont;
    nava_tr_cont.intrare_port(atena);
    std::cout << nava_tr_cont;
    nava_tr_cont.descarcare();
    std::cout << nava_tr_cont;
    return 0;
}
