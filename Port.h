//
// Created by alex on 4/27/2022.
//

#ifndef OOP_PORT_H
#define OOP_PORT_H

#include "Tara.h"

class Port {
    Tara tara;
    std::string oras;
public:
    Port();
    Port(const Tara &tara, const std::string &oras);
    Port(const Port &other);
    Port& operator=(const Port& a);
    friend std::ostream& operator<<(std::ostream& os, const Port& port);
    friend bool operator==(const Port& port, const Port& port2);
    ~Port();
};


#endif //OOP_PORT_H
