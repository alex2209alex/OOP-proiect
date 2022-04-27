//
// Created by alex on 4/27/2022.
//

#include "NavaDePasageri.h"

#include <iostream>

NavaDePasageri::NavaDePasageri(const Port& portCurent, const std::string& denumire, const Tara& pavilion, const int imoNumber, const int nrMaximPasageri, const int nrPasageriCurent) : Nava(portCurent, denumire, pavilion, imoNumber), nrMaximPasageri(nrMaximPasageri), nrPasageriCurent(nrPasageriCurent) {}

void NavaDePasageri::imbarcare(int pasgeri) {
    if(this->nrPasageriCurent + pasgeri > this->nrMaximPasageri) {
        std::cout << "Pasageri de imbarcat + numar curent de pasageri depaseste capacitatea maxima\n";
        return;
    }
    this->nrPasageriCurent += pasgeri;
}

void NavaDePasageri::debarcare(int pasageri) {
    if(this->nrPasageriCurent < pasageri) {
        std::cout << "Pasageri de debarcat > numar curent de pasageri\n";
        return;
    }
    this->nrPasageriCurent -= pasageri;
}

NavaDePasageri *NavaDePasageri::clone() {
    return new NavaDePasageri(*this);
}

std::ostream &operator<<(std::ostream &os, const NavaDePasageri &pasageri) {
    os << static_cast<const Nava &>(pasageri) << " nrMaximPasageri: " << pasageri.nrMaximPasageri
       << " nrPasageriCurent: " << pasageri.nrPasageriCurent << "\n";
    return os;
}

NavaDePasageri::~NavaDePasageri() = default;
