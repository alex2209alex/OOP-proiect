//
// Created by alex on 5/18/2022.
//

#ifndef OOP_TRANSPORTMARITIM_H
#define OOP_TRANSPORTMARITIM_H

#include "NavaDePasageriSiTransportContainere.h"
#include "NavaTransportContainere.h"
#include "NavaPetrolier.h"
#include "NavaDePasageri.h"
#include <memory>

class TransportMaritim {
    std::vector<std::shared_ptr<Nava> > flota;
    std::vector<std::shared_ptr<Container> > containere;
    std::vector<std::shared_ptr<Port> > porturi;
public:
    TransportMaritim();
    TransportMaritim& operator=(const TransportMaritim& a);
    TransportMaritim(const TransportMaritim&);
    void dynamic_cast_folosire();
    void adauga_elementele();
    void adauga_nava(const std::shared_ptr<Nava> &nava);
    void adauga_container(const std::shared_ptr<Container> &container);
    void adauga_port(const std::shared_ptr<Port> &port);
    void variabila_statica_folosire();
    void ruleaza();
    virtual ~TransportMaritim();
};

#endif //OOP_TRANSPORTMARITIM_H
