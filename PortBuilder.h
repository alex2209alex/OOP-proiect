//
// Created by alex on 5/29/2022.
//

#ifndef OOP_PORTBUILDER_H
#define OOP_PORTBUILDER_H

#include "Port.h"

class PortBuilder {
    Port p;
    static int nrPorturi;
public:
    PortBuilder();
    static int getNextPortId();
    static void resetIdCount();
    PortBuilder& tara(const TaraTemplate<std::string>& tara);
    PortBuilder& oras(const std::string& oras);
    PortBuilder& starePort(char starePort);
    Port build();
};

#endif //OOP_PORTBUILDER_H
