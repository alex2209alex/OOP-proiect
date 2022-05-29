//
// Created by alex on 5/29/2022.
//

#ifndef OOP_PORTBUILDER_H
#define OOP_PORTBUILDER_H

#include "Port.h"

class PortBuilder {
    Port p;
public:
    PortBuilder();
    PortBuilder& tara(const Tara& tara);
    PortBuilder& oras(const std::string& oras);
    PortBuilder& starePort(const char starePort);
    Port build();
};


#endif //OOP_PORTBUILDER_H
