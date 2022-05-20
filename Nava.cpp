//
// Created by alex on 4/27/2022.
//

#include "Nava.h"
#include <iostream>
#include "erori.h"

std::unordered_set<int> Nava::imoNumbers;

Nava::Nava(const Nava& other) : portCurent(other.portCurent), denumire(other.denumire), pavilion(other.pavilion), imoNumber(other.imoNumber) {}

std::ostream &operator<<(std::ostream &os, const Nava &nava) {
    os << "portCurent: " << *nava.portCurent << " denumire: " << nava.denumire << " pavilion: " << nava.pavilion
       << " imoNumber: " << nava.imoNumber << "\n";
    return os;
}

void Nava::afiseaza_nava() {
    std :: cout << *this;
    afiseaza_ce_e_pe_nava();
}

void Nava::adauga_pe_nava(int) {
    throw incarcare_gresita();
}
void Nava::adauga_pe_nava(Container) {
    throw incarcare_gresita();
}

Nava::Nava(const std::shared_ptr<Port> &portCurent, const std::string &denumire, const Tara &pavilion, int imoNumber)
        : portCurent(portCurent), denumire(denumire), pavilion(pavilion), imoNumber(imoNumber) {
    if(imoNumbers.find(imoNumber) != imoNumbers.end()) {
        throw identificator_ne_e_unic();
    }
    imoNumbers.insert(imoNumber);
}

void Nava::intrare_port(std::shared_ptr<Port> &port) {
    verificare_traseu(this->portCurent, port);
    this->portCurent = port;
}

void Nava::verificare_traseu(std::shared_ptr<Port> port1, std::shared_ptr<Port> port2) {
    if(port1->getStarePort() == Port::INCHIS) {
        throw port_sursa_inchis();
    }
    if(port2->getStarePort() == Port::INCHIS) {
        throw port_destinatie_inchis();
    }
    if(port1 == port2) {
        throw port_identic();
    }
}
