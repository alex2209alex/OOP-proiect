//
// Created by alex on 4/27/2022.
//

#ifndef OOP_NAVAMARFA_H
#define OOP_NAVAMARFA_H

#include <ostream>
#include "Nava.h"

class NavaMarfa : public Nava {
public:
    NavaMarfa(NavaMarfa& other) = default;
    virtual void descarcare() = 0;
    NavaMarfa(const Port &portCurent, const std::string &denumire, const Tara &pavilion, int imoNumber);
    friend std::ostream &operator<<(std::ostream &os, const NavaMarfa &marfa);
};


#endif //OOP_NAVAMARFA_H
