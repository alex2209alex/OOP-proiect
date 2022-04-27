//
// Created by alex on 4/27/2022.
//

#include "NavaDePasageri.h"

#include <iostream>

void NavaDePasageri::imbarcare(int pasgeri) {
    if(this->nrPasageriCurent + pasgeri > this->nrMaximPasageri) {
        std::cout << "Pasageri de imbarcat + numar curent de pasageri depaseste capacitatea maxima";
        return;
    }
    this->nrPasageriCurent += pasgeri;
}

void NavaDePasageri::debarcare(int pasgeri) {
    if(this->nrPasageriCurent < pasgeri) {
        std::cout << "Pasageri de debarcat > numar curent de pasageri";
        return;
    }
    this->nrPasageriCurent -= pasgeri;
}