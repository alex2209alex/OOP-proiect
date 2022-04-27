//
// Created by alex on 4/27/2022.
//
#include <iostream>
#include "NavaPetrolier.h"

NavaPetrolier::NavaPetrolier(const Port& portCurent, const std::string& denumire, const Tara& pavilion, const int imoNumber, const int tonajMaxim, const int tonajCurent) : NavaMarfa(portCurent, denumire, pavilion, imoNumber), tonajMaxim(tonajMaxim), tonajCurent(tonajCurent) {}

void NavaPetrolier::incarcare(int tonaj) {
    if(this->tonajCurent + tonaj > this->tonajMaxim) {
        std::cout << "Marfa de incarcat + marfa curenta depaseste capacitatea maxima\n";
        return;
    }
    this->tonajCurent += tonaj;
}

void NavaPetrolier::descarcare() {
    if(this->tonajCurent == 0) {
        std::cout << "Nu e marfa de descarcat\n";
        return;
    }
    this->tonajCurent = 0;
}

NavaPetrolier *NavaPetrolier::clone() {
    return new NavaPetrolier(*this);
}

std::ostream &operator<<(std::ostream &os, const NavaPetrolier &petrolier) {
    os << static_cast<const NavaMarfa &>(petrolier) << " tonajMaxim: " << petrolier.tonajMaxim << " tonajCurent: "<< petrolier.tonajCurent << "\n";
    return os;
}

NavaPetrolier::~NavaPetrolier() = default;
