//
// Created by alex on 5/29/2022.
//

#include "PortBuilder.h"
#include "erori.h"

PortBuilder::PortBuilder() = default;

PortBuilder &PortBuilder::tara(const TaraTemplate<std::string> &tara) {
    p.tara = tara;
    return *this;
}

PortBuilder &PortBuilder::oras(const std::string &oras) {
    p.oras = oras;
    return *this;
}

PortBuilder &PortBuilder::starePort(const char starePort) {
    p.starePort = starePort;
    return *this;
}

Port PortBuilder::build() {
    if(p.starePort != Port::DESCHIS && p.starePort != Port::INCHIS) {
        throw build_object_invalid();
    }
    if(p.tara.getNume().empty() or p.tara.getContinent().empty() or p.oras.empty() or p.tara.getIdentificator().empty()) {
        throw build_object_invalid();
    }
    auto p2 = p;
    p.tara = TaraTemplate<std::string>();
    p.starePort = 's';
    p.oras = "";
    return p2;
}
