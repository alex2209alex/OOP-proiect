//
// Created by alex on 4/27/2022.
//
#include <iostream>
#include "NavaPetrolier.h"

void NavaPetrolier::incarcare(int tonaj) {
    if(this->tonajCurent + tonaj > this->tonajMaxim) {
        std::cout << "Marfa de incarcat + marfa curenta depaseste capacitatea maxima";
        return;
    }
    this->tonajCurent += tonaj;
}

void NavaPetrolier::descarcare() {
    if(this->tonajCurent == 0) {
        std::cout << "Nu e marfa de descarcat";
        return;
    }
    this->tonajCurent = 0;
}