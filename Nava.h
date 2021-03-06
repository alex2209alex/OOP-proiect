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
    TaraTemplate<int> pavilion;
    int imoNumber{};
public:
    Nava(std::shared_ptr<Port> portCurent, std::string denumire, const TaraTemplate<int> &pavilion, int imoNumber);
    Nava(const Nava&);
    Nava();
    virtual std::shared_ptr<Nava> clone() = 0;
    virtual void scoate_de_pe_nava() = 0;
    virtual void adauga_pe_nava(int);
    virtual void adauga_pe_nava(Container&);
    virtual void afiseaza_ce_e_pe_nava() = 0;
    virtual void verificare_traseu(const std::shared_ptr<Port>&, const std::shared_ptr<Port>&);
    void afiseaza_nava();
    void intrare_port(const std::shared_ptr<Port> &port);
    friend std::ostream &operator<<(std::ostream &os, const Nava &nava);
    virtual ~Nava() = default;
};

#endif //OOP_NAVA_H
