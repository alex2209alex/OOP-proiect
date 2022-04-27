//
// Created by alex on 4/27/2022.
//

#ifndef OOP_NAVATRANSPORTCONTAINERE_H
#define OOP_NAVATRANSPORTCONTAINERE_H

#include "NavaMarfa.h"
#include "Container.h"
#include <iostream>
#include <vector>

/*
 Port portCurent;
    std::string denumire;
    Tara pavilion;
    int imoNumber;
 */

class NavaTransportContainere : public NavaMarfa {
    int capacitateMaxima;
    std::vector<Container> marfuri;
public:
    NavaTransportContainere(const Port &portCurent, const std::string &denumire, const Tara &pavilion, const int imoNumber, const int capcitateMaxima) : NavaMarfa(portCurent, denumire, pavilion, imoNumber), capacitateMaxima(capcitateMaxima) {}
    void descarcare() override;
    void adauga_container(Container container);
    NavaMarfa *clone() override {
        return new NavaTransportContainere(*this);
    }

    friend std::ostream &operator<<(std::ostream &os, const NavaTransportContainere &containere);
};


#endif //OOP_NAVATRANSPORTCONTAINERE_H
