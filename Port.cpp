//
// Created by alex on 4/27/2022.
//

#include "Port.h"

Port::Port() {
    this->starePort = STARE_PORT_IN_OPERARE;
}
Port::Port(const Tara &tara, const std::string &oras) : tara(tara), oras(oras) {
    this->starePort = STARE_PORT_IN_OPERARE;
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
    this->starePort = this->STARE_PORT_IN_OPERARE;
}

void Port::inchiderePort() {
    this->starePort = this->STARE_PORT_INCHIS;
}

int Port::getStarePortInchis() const {
    return STARE_PORT_INCHIS;
}

int Port::getStarePortInOperare() const {
    return STARE_PORT_IN_OPERARE;
}

int Port::getStarePort() const {
    return starePort;
}

Port::~Port() = default;