//
// Created by alex on 4/27/2022.
//

#include "Firma.h"

Firma::Firma(const std::string &nume) : nume(nume) {nrFirme++;}

int Firma::getNrFirme() {
    return nrFirme;
}

int Firma::nrFirme = 0;

void Firma::cumpara_nava(Nava &nava) {
    flota.push_back(&nava);
}

std::ostream &operator<<(std::ostream &os, const Firma &firma) {
    os << "Nume: " << firma.nume << " Flota: ";
    for(auto const &nava : firma.flota) {
        os << *nava;
    }
    return os;
}

Firma::~Firma() = default;
