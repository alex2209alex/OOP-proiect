//
// Created by alex on 4/27/2022.
//

#include "Tara.h"

Tara::Tara() = default;

Tara::Tara(const std::string &nume, const std::string &continent) : nume(nume), continent(continent) {}

std::ostream& operator<<(std::ostream& os, const Tara& tara) {
    os << "{Nume: " << tara.nume << " Continent: " << tara.continent << "}\n";
    return os;
}

bool operator==(const Tara& tara, const Tara& tara2) {
    return tara.nume == tara2.nume && tara.continent == tara2.continent;
}

Tara::~Tara() = default;