//
// Created by alex on 4/27/2022.
//

#ifndef OOP_PORT_H
#define OOP_PORT_H

#include "Tara.h"

class Port {
    Tara tara;
    std::string oras;
    char starePort;
public:
    enum STAREPORT {DESCHIS = '1', INCHIS = '0'};
    Port();
    Port(const Tara &tara, const std::string &oras);
    Port(const Port &other);
    Port& operator=(const Port& a);
    void deschiderePort();
    void inchiderePort();
    friend std::ostream& operator<<(std::ostream& os, const Port& port);
    friend bool operator==(const Port& port, const Port& port2);
    [[nodiscard]] int getStarePort() const;
    ~Port();
};


#endif //OOP_PORT_H
