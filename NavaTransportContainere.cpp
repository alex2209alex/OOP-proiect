//
// Created by alex on 4/27/2022.
//

#include "NavaTransportContainere.h"

NavaTransportContainere::NavaTransportContainere(const Port &portCurent, const std::string &denumire,const Tara &pavilion, const int imoNumber, const int capcitateMaxima) : NavaMarfa(portCurent, denumire, pavilion, imoNumber), capacitateMaxima(capcitateMaxima) {}

void NavaTransportContainere::descarcare() {
    int n = int(this->marfuri.size() - 1);
    //Descarca marfa care are ca destinatie portul in care e
    for(int i = 0; i <= n; ++i) {
        if (this->marfuri[i].getDestinatie() == this->portCurent) {
            this->marfuri[i] = this->marfuri[n];
            n--;
            i--;//Deoarece ce am pus pe pozitia i poate sa fie tot pt portul acesta
        }
    }
    this->marfuri.resize(n + 1);
}
void NavaTransportContainere::adauga_container(const Container& container) {
    int suma_tonaj = 0;
    for(const auto& it : this->marfuri) {
        suma_tonaj += it.getTonaj();
        if(container.getTonaj() + suma_tonaj > this->capacitateMaxima) {
            std::cout << "Nu are loc marfa:" << container << " in nava";
            return;
        }
    }
    if(container.getTonaj() + suma_tonaj > this->capacitateMaxima) {
        std::cout << "Nu are loc marfa:\n" << container << "in nava";
        return;
    }
    this->marfuri.push_back(container);
}

NavaMarfa *NavaTransportContainere::clone() {
    return new NavaTransportContainere(*this);
}

std::ostream &operator<<(std::ostream &os, const NavaTransportContainere &containere) {
    os << "Nava transport containere: {" << static_cast<const NavaMarfa &>(containere) << " capacitateMaxima: " << containere.capacitateMaxima
       << " marfuri: ";
    for(auto &it : containere.marfuri) {
        os << it;
    }
    os << "}\n";
    return os;
}

NavaTransportContainere::~NavaTransportContainere() = default;