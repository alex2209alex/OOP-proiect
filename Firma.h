//
// Created by alex on 4/27/2022.
//

#ifndef OOP_FIRMA_H
#define OOP_FIRMA_H

#include <string>
#include <vector>
#include <ostream>
#include "Nava.h"

class Firma {
    std::string nume;
    std::vector<Nava*> flota;
public:
    static int nrFirme;
    static int getNrFirme();
    explicit Firma(const std::string& nume);
    void cumpara_nava(Nava*);
    friend std::ostream &operator<<(std::ostream &os, const Firma &firma);
    virtual ~Firma();
};

#endif //OOP_FIRMA_H
