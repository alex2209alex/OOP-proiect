//
// Created by alex on 4/27/2022.
//
#include <iostream>
#include "NavaPetrolier.h"
#include "erori.h"

NavaPetrolier::NavaPetrolier(std::shared_ptr<Port>& portCurent, const std::string& denumire, const Tara& pavilion, const int imoNumber, const int tonajMaxim, const int tonajCurent) : Nava(portCurent, denumire, pavilion, imoNumber), tonajMaxim(tonajMaxim), tonajCurent(tonajCurent) {}

void NavaPetrolier::adauga_pe_nava(const int tonaj) {
    if(this->tonajCurent + tonaj > this->tonajMaxim) {
        throw incarcare_peste_capacitate();
    }
    this->tonajCurent += tonaj;
}

void NavaPetrolier::scoate_de_pe_nava() {
    if(this->tonajCurent == 0) {
        throw nimic_de_scos();
    }
    this->tonajCurent = 0;
}

std::shared_ptr<Nava> NavaPetrolier::clone() {
    return std::make_shared<NavaPetrolier>(NavaPetrolier{*this});
}

std::ostream &operator<<(std::ostream &os, const NavaPetrolier &petrolier) {
    os << static_cast<const Nava &>(petrolier) << " tonajMaxim: " << petrolier.tonajMaxim << " tonajCurent: "<< petrolier.tonajCurent << "\n";
    return os;
}

void NavaPetrolier::afiseaza_ce_e_pe_nava() {
    std :: cout << "Tonaj maxim: " << this->tonajMaxim << "\nTonaj curent: " << this->tonajCurent << "\n";
}

NavaPetrolier::~NavaPetrolier() = default;
