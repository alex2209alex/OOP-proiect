//
// Created by alex on 5/29/2022.
//

#ifndef OOP_NAVADEPASAGERISITRANSPORTCONTAINERE_H
#define OOP_NAVADEPASAGERISITRANSPORTCONTAINERE_H

#include "Nava.h"
#include "NavaDePasageri.h"
#include "NavaTransportContainere.h"

class NavaDePasageriSiTransportContainere : public NavaTransportContainere, public NavaDePasageri {
public:
    NavaDePasageriSiTransportContainere(std::shared_ptr<Port>&, const std::string&, const Tara&, int, int, int, int);
    void adauga_pe_nava(int) override;
    void adauga_pe_nava(Container&) override;
    void scoate_de_pe_nava() override;
    void afiseaza_ce_e_pe_nava() override;
    std::shared_ptr<Nava> clone() override;
    friend std::ostream &operator<<(std::ostream &os, const NavaDePasageriSiTransportContainere &pasageriSiTransportContainere);
    ~NavaDePasageriSiTransportContainere() override;
};


#endif //OOP_NAVADEPASAGERISITRANSPORTCONTAINERE_H
