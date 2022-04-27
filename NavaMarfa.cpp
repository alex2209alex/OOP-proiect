//
// Created by alex on 4/27/2022.
//

#include "NavaMarfa.h"

std::ostream &operator<<(std::ostream &os, const NavaMarfa &marfa) {
    os << static_cast<const Nava &>(marfa);
    return os;
}