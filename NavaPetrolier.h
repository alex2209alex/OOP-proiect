//
// Created by alex on 4/27/2022.
//

#ifndef OOP_NAVAPETROLIER_H
#define OOP_NAVAPETROLIER_H

#include <ostream>
#include "NavaMarfa.h"

class NavaPetrolier : public NavaMarfa {
    int tonajMaxim;
    int tonajCurent;
public:
    NavaPetrolier(const Port&, const std::string&, const Tara&, int, int, int);
    void incarcare(int);
    void descarcare() override;
    NavaPetrolier *clone() override;
    friend std::ostream &operator<<(std::ostream &os, const NavaPetrolier &petrolier);
    ~NavaPetrolier() override;
};


#endif //OOP_NAVAPETROLIER_H
