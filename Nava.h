//
// Created by alex on 4/27/2022.
//

#ifndef OOP_NAVA_H
#define OOP_NAVA_H

#include <ostream>
#include "Port.h"
#include "Container.h"
#include <memory>
#include <unordered_set>

class Nava {
protected:
    static std::unordered_set<int> imoNumbers;
    std::shared_ptr<Port> portCurent;
    std::string denumire;
    Tara pavilion;
    int imoNumber;
public:
    Nava(const std::shared_ptr<Port> &portCurent, const std::string &denumire, const Tara &pavilion, int imoNumber);
    Nava(const Nava&);
    virtual std::shared_ptr<Nava> clone() = 0;
    virtual void scoate_de_pe_nava() = 0;
    virtual void adauga_pe_nava(int);
    virtual void adauga_pe_nava(Container);
    virtual void afiseaza_ce_e_pe_nava() = 0;
    virtual void verificare_traseu(std::shared_ptr<Port>, std::shared_ptr<Port>);
    void afiseaza_nava();
    void intrare_port(std::shared_ptr<Port> &port);
    friend std::ostream &operator<<(std::ostream &os, const Nava &nava);
    virtual ~Nava() = default;
};


#endif //OOP_NAVA_H