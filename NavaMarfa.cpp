//
// Created by alex on 4/27/2022.
//

#include "NavaMarfa.h"

NavaMarfa::NavaMarfa(const Port &portCurent, const std::string &denumire, const Tara &pavilion, const int imoNumber) : Nava(portCurent, denumire, pavilion, imoNumber) {}

std::ostream &operator<<(std::ostream &os, const NavaMarfa &marfa) {
    os << static_cast<const Nava &>(marfa) << "\n";
    return os;
}

NavaMarfa::~NavaMarfa() = default;