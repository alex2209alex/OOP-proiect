//
// Created by alex on 4/27/2022.
//

#ifndef OOP_PORT_H
#define OOP_PORT_H

#include "Tara.h"

class Port {
    const int STARE_PORT_INCHIS = 0;
    const int STARE_PORT_IN_OPERARE = 1;
    Tara tara;
    std::string oras;
    int starePort; // 1 daca e deschis pentru operare 0 daca e inchis pentru operare
public:
    Port();
    Port(const Tara &tara, const std::string &oras);
    Port(const Port &other);
    Port& operator=(const Port& a);
    void deschiderePort();
    void inchiderePort();
    friend std::ostream& operator<<(std::ostream& os, const Port& port);
    friend bool operator==(const Port& port, const Port& port2);

    int getStarePortInchis() const;

    int getStarePortInOperare() const;

    int getStarePort() const;

    ~Port();

};


#endif //OOP_PORT_H
