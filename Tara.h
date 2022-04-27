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
public:
    Tara();
    Tara(const std::string &nume, const std::string &continent);
    friend std::ostream& operator<<(std::ostream& os, const Tara& tara);
    friend bool operator==(const Tara& tara, const Tara& tara2);
    ~Tara();
};

#endif //OOP_TARA_H
