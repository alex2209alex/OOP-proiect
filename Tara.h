//
// Created by alex on 4/27/2022.
//

#ifndef OOP_TARA_H
#define OOP_TARA_H

#include <string>
#include <ostream>

class Tara {
    std::string nume;
    std::string continent;
    static int nrTari;
public:
    static int numar_tari();
    Tara();
    Tara(const std::string &nume, const std::string &continent);
    Tara(const Tara &other);
    Tara& operator=(const Tara& a);
    friend std::ostream& operator<<(std::ostream& os, const Tara& tara);
    friend bool operator==(const Tara& tara, const Tara& tara2);
    ~Tara();
};

#endif //OOP_TARA_H
