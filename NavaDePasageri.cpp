//
// Created by alex on 4/27/2022.
//

#include "NavaDePasageri.h"
#include "erori.h"
#include <iostream>
#include <cmath>

NavaDePasageri::NavaDePasageri(std::shared_ptr<Port>& portCurent, const std::string& denumire, const TaraTemplate<int>& pavilion, const int imoNumber, const int nrMaximPasageri, const int nrPasageriCurent) : Nava(portCurent, denumire, pavilion, imoNumber), nrMaximPasageri(nrMaximPasageri), nrPasageriCurent(nrPasageriCurent) {}

void NavaDePasageri::adauga_pe_nava(const int pasageri) {
    if(this->nrPasageriCurent + pasageri > this->nrMaximPasageri) {
        throw incarcare_peste_capacitate();
    }
    this->nrPasageriCurent += pasageri;
}

void NavaDePasageri::evacuare() {
    nrPasageriCurent = 0;
    std::cout << "Nava a fost evacuata\n";
}

void NavaDePasageri::scoate_de_pe_nava() {
    int pasageri = rand() % this->nrPasageriCurent;
    if(this->nrPasageriCurent < pasageri) {
        throw cantitate_de_scos_prea_mare();
    }
    this->nrPasageriCurent -= pasageri;
}

std::shared_ptr<Nava> NavaDePasageri::clone() {
    return std::make_shared<NavaDePasageri>(NavaDePasageri{*this});
}

std::ostream &operator<<(std::ostream &os, const NavaDePasageri &pasageri) {
    os << static_cast<const Nava &>(pasageri) << " nrMaximPasageri: " << pasageri.nrMaximPasageri
       << " nrPasageriCurent: " << pasageri.nrPasageriCurent << "\n";
    return os;
}

void NavaDePasageri::afiseaza_ce_e_pe_nava() {
    std :: cout << "Numar maxim pasageri: " << this->nrMaximPasageri << "\nNumar curent de pasageri: " << this->nrPasageriCurent << "\n";
}

NavaDePasageri::NavaDePasageri() = default;

NavaDePasageri::~NavaDePasageri() = default;
