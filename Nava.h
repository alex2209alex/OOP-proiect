//
// Created by alex on 4/27/2022.
//

#ifndef OOP_NAVA_H
#define OOP_NAVA_H

#include <ostream>
#include "Port.h"

class Nava {
protected:
    Port portCurent;
    std::string denumire;
    Tara pavilion;
    int imoNumber;
public:
    void intrare_port(const Port &port);
    virtual Nava *clone() = 0;
    Nava(const Port &portCurent, const std::string &denumire, const Tara &pavilion, int imoNumber);

    friend std::ostream &operator<<(std::ostream &os, const Nava &nava);
};


#endif //OOP_NAVA_H


/*
 class Nava {
    std::string nume;
    Tara tara;
    int capacitate;
    std::vector<Marfa> marfuri;
    Port port;
public:
    void intra_port(const Port &port_destinatie) {
        int n = int(this->marfuri.size() - 1);
        //Descarca marfa care are ca destinatie portul in care intra
        for(int i = 0; i <= n; ++i) {
            if (this->marfuri[i].getDestinatie() == port_destinatie) {
                this->marfuri[i] = this->marfuri[n];
                n--;
                i--;//Deoarece ce am pus pe pozitia i poate sa fie tot pt portul acesta
            }
        }
        this->port = port_destinatie;
        this->marfuri.resize(n + 1);
    }

    void adauga_marfa(Marfa marfa) {
        int suma_tonaj = 0;
        for(auto it : this->marfuri) {
            suma_tonaj += it.getTonaj();
            if(marfa.getTonaj() + suma_tonaj > this->capacitate) {
                std::cout << "Nu are loc marfa:" << marfa << " in nava:" << *this;
                return;
            }
        }
        this->marfuri.push_back(marfa);

    }

    ~Nava() {
        std::cout << "Destructor Nava\n";
    }
};
 */