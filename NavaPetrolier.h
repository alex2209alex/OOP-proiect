//
// Created by alex on 4/27/2022.
//

#ifndef OOP_NAVAPETROLIER_H
#define OOP_NAVAPETROLIER_H

#include "NavaMarfa.h"

class NavaPetrolier : public NavaMarfa {
    int tonajMaxim;
    int tonajCurent;
public:
    void incarcare(int);
    void descarcare() override;
};


#endif //OOP_NAVAPETROLIER_H
