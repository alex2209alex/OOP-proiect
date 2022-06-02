//
// Created by alex on 4/27/2022.
//

#include "Port.h"
#include "PortBuilder.h"
#include <utility>

Port::Port() {
    this->starePort = DESCHIS;
    idPort = 0;
}
Port::Port(const TaraTemplate<std::string> &tara, std::string oras) : tara(tara), oras(std::move(oras)) {
    this->starePort = DESCHIS;
    idPort = PortBuilder::getNextPortId();
}
Port::Port(const Port &other) = default;

Port &Port::operator=(const Port &a) {
    if(&a != this) {
        tara = a.tara;
        oras = a.oras;
        starePort = a.starePort;
        idPort = a.idPort;
    }
    return *this;
}

std::ostream& operator<<(std::ostream& os, const Port& port) {
    os << "Port: { " << "Id port: " << port.idPort << " " << port.tara << "Oras: " << port.oras << " Stare Port:" << port.starePort <<"}\n";
    return os;
}

bool operator==(const Port& port, const Port& port2) {
    if(port.tara == port2.tara && port.oras == port2.oras)
        return true;
    return false;
}

void Port::deschiderePort() {
    this->starePort = DESCHIS;
}

void Port::inchiderePort() {
    this->starePort = INCHIS;
}

int Port::getStarePort() const {
    return starePort;
}

Port::~Port() = default;