//
// Created by alex on 4/27/2022.
//

#include "NavaTransportContainere.h"
#include "erori.h"
#include <numeric>
NavaTransportContainere::NavaTransportContainere(std::shared_ptr<Port> &portCurent, const std::string &denumire,const TaraTemplate<int> &pavilion, const int imoNumber, const int capcitateMaxima) : Nava(portCurent, denumire, pavilion, imoNumber), capacitateMaxima(capcitateMaxima) {}

void NavaTransportContainere::scoate_de_pe_nava() {
    int n = int(this->marfuri.size() - 1);
    if(n == -1) {
        throw nimic_de_scos();
    }
    bool ver = false;
    //Descarca marfa care are ca destinatie portul in care e
    for(int i = 0; i <= n; ++i) {
        if (this->marfuri[i].getDestinatie() == *this->portCurent) {
            this->marfuri[i] = this->marfuri[n];
            n--;
            i--;//Deoarece ce am pus pe pozitia i poate sa fie tot pt portul acesta
            ver = true;
        }
    }
    if(!ver) {
        throw nu_se_descarca_nimic();
    }
    this->marfuri.resize(n + 1);
}

int functie(int suma, const Container &a) {
    return suma + a.getTonaj();
}

void NavaTransportContainere::afiseazaSpatiuRamas() {
    int suma_tonaj = accumulate(this->marfuri.begin(), this->marfuri.end(), 0, functie);
    std::cout << "Mai sunt " << capacitateMaxima - suma_tonaj << "tone disponibile";
}

std::shared_ptr<Nava> NavaTransportContainere::clone() {
    return std::make_shared<NavaTransportContainere>(NavaTransportContainere{*this});
}

std::ostream &operator<<(std::ostream &os, const NavaTransportContainere &containere) {
    os << "Nava transport containere: {" << static_cast<const Nava &>(containere) << " capacitateMaxima: " << containere.capacitateMaxima
       << " marfuri: ";
    for(auto &it : containere.marfuri) {
        os << it;
    }
    os << "}\n";
    return os;
}

void NavaTransportContainere::afiseaza_ce_e_pe_nava() {
    std::cout << "Capacitate maxima: " << this->capacitateMaxima << "\n";
    for(auto &it : this->marfuri) {
        std::cout << it;
    }
}

void NavaTransportContainere::adauga_pe_nava(Container &container) {
    //folosit https://stackoverflow.com/questions/1030608/summing-struct-members-inside-a-vector
    int suma_tonaj = accumulate(this->marfuri.begin(), this->marfuri.end(), 0, functie);
    if(container.getTonaj() + suma_tonaj > this->capacitateMaxima) {
        throw incarcare_peste_capacitate();
    }
    this->marfuri.push_back(container);
}

NavaTransportContainere::NavaTransportContainere() = default;

NavaTransportContainere::~NavaTransportContainere() = default;