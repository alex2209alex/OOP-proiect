//
// Created by alex on 4/27/2022.
//

#include "Port.h"

Port::Port() = default;
Port::Port(const Tara &tara, const std::string &oras) : tara(tara), oras(oras) {}
Port::Port(const Port &other) : tara(other.tara), oras(other.oras) {}

Port &Port::operator=(const Port &a) {
    if(&a != this) {
        tara = a.tara;
        oras = a.oras;
    }
    return *this;
}

std::ostream& operator<<(std::ostream& os, const Port& port) {
    os << "Port: {" << port.tara << "Oras: " << port.oras << "}\n";
    return os;
}

bool operator==(const Port& port, const Port& port2) {
    if(port.tara == port2.tara && port.oras == port2.oras)
        return true;
    return false;
}

Port::~Port() = default;