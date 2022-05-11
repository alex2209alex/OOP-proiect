//
// Created by alex on 4/27/2022.
//

#include "Nava.h"
#include <iostream>

Nava::Nava(const Port &portCurent, const std::string &denumire, const Tara &pavilion, int imoNumber) : portCurent(portCurent), denumire(denumire), pavilion(pavilion), imoNumber(imoNumber) {}
Nava::Nava(const Nava& other) : portCurent(other.portCurent), denumire(other.denumire), pavilion(other.pavilion), imoNumber(other.imoNumber) {}

void Nava::intrare_port(const Port &port) { // 0 inseamna ca portul e inchis, 1 ca e deschis
    if(this->portCurent.getStarePort() == 0) {
        std::cout << "Portul de plecare e inchis\n";
    }
    if(port.getStarePort() == 1) {
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
