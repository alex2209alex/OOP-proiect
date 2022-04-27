//
// Created by alex on 4/27/2022.
//

#include "Nava.h"

void Nava::intrare_port(const Port &port) {
    this->portCurent = port;
}

Nava::Nava(const Port &portCurent, const std::string &denumire, const Tara &pavilion, int imoNumber) : portCurent(
        portCurent), denumire(denumire), pavilion(pavilion), imoNumber(imoNumber) {}

std::ostream &operator<<(std::ostream &os, const Nava &nava) {
    os << "portCurent: " << nava.portCurent << " denumire: " << nava.denumire << " pavilion: " << nava.pavilion
       << " imoNumber: " << nava.imoNumber;
    return os;
}
/*
Nava::Nava() = default;
Nava::Nava(const std::string &nume, const Tara &tara, const Port &port) : nume(nume), tara(tara), port(port) {}
Nava::Nava(const Nava &other) : nume(other.nume), tara(other.tara), port(other.port) {}

Nava &Nava::operator=(const Nava &a) {
    if(&a != this) {
        nume = a.nume;
        tara = a.tara;
        port = a.port;
    }
    return *this;
}

std::ostream& operator<<(std::ostream &os, const Nava &nava) {
    os << "Nava: {Nume: " << nava.nume << " " << nava.tara << nava.port << "}\n";
    return os;
}

void Nava::iese_port() {
    this->port = {{"INTERNATIONAL", "INTERNATIONAL"}, "APE INTERNATIONALE"};// Ape internationale
}

Nava::~Nava() = default;
*/