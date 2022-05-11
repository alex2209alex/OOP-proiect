//
// Created by alex on 4/27/2022.
//

#include "Port.h"

Port::Port() {
    this->starePort = 1;
}
Port::Port(const Tara &tara, const std::string &oras) : tara(tara), oras(oras) {
    this->starePort = 1;
}
Port::Port(const Port &other) : tara(other.tara), oras(other.oras), starePort(other.starePort) {}

Port &Port::operator=(const Port &a) {
    if(&a != this) {
        tara = a.tara;
        oras = a.oras;
        starePort = a.starePort;
    }
    return *this;
}

std::ostream& operator<<(std::ostream& os, const Port& port) {
    os << "Port: {" << port.tara << "Oras: " << port.oras << " Stare Port:" << port.starePort <<"}\n";
    return os;
}

bool operator==(const Port& port, const Port& port2) {
    if(port.tara == port2.tara && port.oras == port2.oras)
        return true;
    return false;
}

void Port::deschiderePort() {
    this->starePort = 1;
}

void Port::inchiderePort() {
    this->starePort = 0;
}

int Port::getStarePort() const {
    return starePort;
}

Port::~Port() = default;