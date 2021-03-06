//
// Created by alex on 4/27/2022.
//

#ifndef OOP_NAVATRANSPORTCONTAINERE_H
#define OOP_NAVATRANSPORTCONTAINERE_H

#include "Nava.h"
#include "Container.h"
#include <iostream>
#include <vector>

class NavaTransportContainere : virtual public Nava {
protected:
    int capacitateMaxima;
    std::vector<Container> marfuri;
public:
    NavaTransportContainere();
    NavaTransportContainere(std::shared_ptr<Port>&, const std::string &denumire, const TaraTemplate<int> &pavilion, int imoNumber, int capcitateMaxima);
    void scoate_de_pe_nava() override;
    void adauga_pe_nava(Container&) override;
    void afiseaza_ce_e_pe_nava() override;
    void afiseazaSpatiuRamas();
    std::shared_ptr<Nava> clone() override;
    friend std::ostream &operator<<(std::ostream &os, const NavaTransportContainere &containere);
    ~NavaTransportContainere() override;
};


#endif //OOP_NAVATRANSPORTCONTAINERE_H
