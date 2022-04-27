//
// Created by alex on 4/27/2022.
//

#ifndef OOP_NAVADEPASAGERI_H
#define OOP_NAVADEPASAGERI_H

#include <ostream>
#include "Nava.h"

class NavaDePasageri : public Nava {
    int nrMaximPasageri;
    int nrPasageriCurent;
public:
    NavaDePasageri(const Port&, const std::string&, const Tara&, int, int, int);
    void imbarcare(int);
    void debarcare(int);
    NavaDePasageri *clone();
    friend std::ostream &operator<<(std::ostream &os, const NavaDePasageri &pasageri);
    ~NavaDePasageri() override;
};


#endif //OOP_NAVADEPASAGERI_H
