//
// Created by alex on 4/27/2022.
//

#ifndef OOP_NAVATRANSPORTCONTAINERE_H
#define OOP_NAVATRANSPORTCONTAINERE_H

#include "Nava.h"
#include "Container.h"
#include <iostream>
#include <vector>

class NavaTransportContainere : public Nava {
    int capacitateMaxima;
    std::vector<Container> marfuri;
public:
    NavaTransportContainere(std::shared_ptr<Port>&, const std::string &denumire, const Tara &pavilion, int imoNumber, int capcitateMaxima);
    void scoate_de_pe_nava() override;
    void adauga_pe_nava(Container&) override;
    void afiseaza_ce_e_pe_nava() override;
    std::shared_ptr<Nava> clone() override;
    friend std::ostream &operator<<(std::ostream &os, const NavaTransportContainere &containere);
    ~NavaTransportContainere() override;
};


#endif //OOP_NAVATRANSPORTCONTAINERE_H
