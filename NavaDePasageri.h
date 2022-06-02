//
// Created by alex on 4/27/2022.
//

#ifndef OOP_NAVADEPASAGERI_H
#define OOP_NAVADEPASAGERI_H

#include <ostream>
#include "Nava.h"

class NavaDePasageri : virtual public Nava {
protected:
    int nrMaximPasageri{};
    int nrPasageriCurent{};
public:
    NavaDePasageri();
    NavaDePasageri(std::shared_ptr<Port>&, const std::string&, const TaraTemplate<int>&, int, int, int);
    void adauga_pe_nava(int) override;
    void evacuare();
    void scoate_de_pe_nava() override;
    void afiseaza_ce_e_pe_nava() override;
    std::shared_ptr<Nava> clone() override;
    friend std::ostream &operator<<(std::ostream &os, const NavaDePasageri &pasageri);
    ~NavaDePasageri() override;
};

#endif //OOP_NAVADEPASAGERI_H
