//
// Created by alex on 4/27/2022.
//

#ifndef OOP_NAVA_H
#define OOP_NAVA_H

#include <ostream>
#include "Port.h"

class Nava {
protected:
    Port portCurent;
    std::string denumire;
    Tara pavilion;
    int imoNumber;
public:
    Nava(const Port &portCurent, const std::string &denumire, const Tara &pavilion, int imoNumber);
    Nava(const Nava&);
    Nava &operator=(const Nava &a);
    void intrare_port(const Port &port);
    friend std::ostream &operator<<(std::ostream &os, const Nava &nava);
    virtual ~Nava() = default;
};


#endif //OOP_NAVA_H