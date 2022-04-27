//
// Created by alex on 4/27/2022.
//

#ifndef OOP_NAVAMARFA_H
#define OOP_NAVAMARFA_H

#include <ostream>
#include "Nava.h"

class NavaMarfa : public Nava {
public:
    virtual void descarcare() = 0;
    virtual NavaMarfa *clone() = 0;
    NavaMarfa(const Port &portCurent, const std::string &denumire, const Tara &pavilion, const int imoNumber) : Nava(portCurent, denumire, pavilion, imoNumber) {}

    friend std::ostream &operator<<(std::ostream &os, const NavaMarfa &marfa);
};


#endif //OOP_NAVAMARFA_H
