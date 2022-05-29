//
// Created by alex on 5/29/2022.
//

#include "NavaDePasageriSiTransportContainere.h"
#include "erori.h"
#include <numeric>

NavaDePasageriSiTransportContainere::NavaDePasageriSiTransportContainere(std::shared_ptr<Port> &portCurent, const std::string &denumire, const Tara &pavilion, int imoNumber, int capacitateMaxima, int nrMaximPasageri, int nrPasageriCurent) : Nava(portCurent, denumire, pavilion, imoNumber) {
    this->capacitateMaxima = capacitateMaxima;
    this->nrMaximPasageri = nrMaximPasageri;
    this->nrPasageriCurent = nrPasageriCurent;
}

void NavaDePasageriSiTransportContainere::adauga_pe_nava(const int pasageri) {
    if(this->nrPasageriCurent + pasageri > this->nrMaximPasageri) {
        throw incarcare_peste_capacitate();
    }
    this->nrPasageriCurent += pasageri;
}

int functie2(int suma, const Container &a) {
    return suma + a.getTonaj();
}

void NavaDePasageriSiTransportContainere::adauga_pe_nava(Container &container) {
    int suma_tonaj = 0;
    //folosit https://stackoverflow.com/questions/1030608/summing-struct-members-inside-a-vector
    suma_tonaj = accumulate(this->marfuri.begin(), this->marfuri.end(), 0, functie2);
    if(container.getTonaj() + suma_tonaj > this->capacitateMaxima) {
        throw incarcare_peste_capacitate();
    }
    this->marfuri.push_back(container);
}

void NavaDePasageriSiTransportContainere::scoate_de_pe_nava() {
    int n = int(this->marfuri.size() - 1);
    if(n == -1) {
        throw nimic_de_scos();
    }
    //Descarca marfa care are ca destinatie portul in care e
    for(int i = 0; i <= n; ++i) {
        if (this->marfuri[i].getDestinatie() == *this->portCurent) {
            this->marfuri[i] = this->marfuri[n];
            n--;
            i--;//Deoarece ce am pus pe pozitia i poate sa fie tot pt portul acesta
        }
    }
    this->marfuri.resize(n + 1);
    int pasageri = rand() % this->nrPasageriCurent;
    if(this->nrPasageriCurent < pasageri) {
        throw cantitate_de_scos_prea_mare();
    }
    this->nrPasageriCurent -= pasageri;
}

void NavaDePasageriSiTransportContainere::afiseaza_ce_e_pe_nava() {
    std::cout << "Capacitate maxima: " << this->capacitateMaxima << "\n";
    for(auto &it : this->marfuri) {
        std::cout << it;
    }
    std :: cout << "Numar maxim pasageri: " << this->nrMaximPasageri << "\nNumar curent de pasageri: " << this->nrPasageriCurent << "\n";
}

std::shared_ptr<Nava> NavaDePasageriSiTransportContainere::clone() {
    return std::make_shared<NavaDePasageriSiTransportContainere>(NavaDePasageriSiTransportContainere{*this});
}

std::ostream &operator<<(std::ostream &os, const NavaDePasageriSiTransportContainere &pasageriSiTransportContainere) {
    os << "Nava transport pasageri si transport containere: {" << static_cast<const Nava &>(pasageriSiTransportContainere) << " capacitateMaxima: " << pasageriSiTransportContainere.capacitateMaxima
       << " marfuri: ";
    for(auto &it : pasageriSiTransportContainere.marfuri) {
        os << it;
    }
    os << "Nr maxim de pasageri: " << pasageriSiTransportContainere.nrMaximPasageri << "\n";
    os << "Nr curent de pasageri: " << pasageriSiTransportContainere.nrPasageriCurent << "\n";
    os << "}\n";
    return os;
}

NavaDePasageriSiTransportContainere::~NavaDePasageriSiTransportContainere() = default;
