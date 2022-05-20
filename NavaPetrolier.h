//
// Created by alex on 4/27/2022.
//

#ifndef OOP_NAVAPETROLIER_H
#define OOP_NAVAPETROLIER_H

#include <ostream>
#include "Nava.h"
#include "TransportMaritim.h"

class NavaPetrolier : public Nava {
    int tonajMaxim;
    int tonajCurent;
public:
    NavaPetrolier(std::shared_ptr<Port>&, const std::string&, const Tara&, int, int, int);
    void adauga_pe_nava(int) override;
    void scoate_de_pe_nava() override;
    void afiseaza_ce_e_pe_nava() override;
    std::shared_ptr<Nava> clone() override;
    friend std::ostream &operator<<(std::ostream &os, const NavaPetrolier &petrolier);
    ~NavaPetrolier() override;
};


#endif //OOP_NAVAPETROLIER_H
