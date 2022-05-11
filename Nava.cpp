//
// Created by alex on 4/27/2022.
//

#include "Nava.h"
#include <iostream>

Nava::Nava(const Port &portCurent, const std::string &denumire, const Tara &pavilion, int imoNumber) : portCurent(portCurent), denumire(denumire), pavilion(pavilion), imoNumber(imoNumber) {}
Nava::Nava(const Nava& other) : portCurent(other.portCurent), denumire(other.denumire), pavilion(other.pavilion), imoNumber(other.imoNumber) {}

Nava &Nava::operator=(const Nava &a) {
    if(&a != this) {  // self assignment
        portCurent = a.portCurent;
        denumire = a.denumire;
        pavilion = a.pavilion;
        imoNumber = a.imoNumber;
    }
    return *this;
}

void Nava::intrare_port(const Port &port) {
    if(this->portCurent.getStarePort() == port.getStarePortInchis()) {
        std::cout << "Portul de plecare e inchis\n";
    }
    if(port.getStarePort() == port.getStarePortInOperare()) {
        this->portCurent = port;
    }
    else {
        std::cout << "Port destinatie e inchis\n";
    }
}

std::ostream &operator<<(std::ostream &os, const Nava &nava) {
    os << "portCurent: " << nava.portCurent << " denumire: " << nava.denumire << " pavilion: " << nava.pavilion
       << " imoNumber: " << nava.imoNumber << "\n";
    return os;
}

bool operator==(Nava nava1, Nava nava2) {
    return nava1.imoNumber == nava2.imoNumber;
}
