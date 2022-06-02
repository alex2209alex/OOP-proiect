//
// Created by alex on 4/27/2022.
//

#ifndef OOP_CONTAINER_H
#define OOP_CONTAINER_H

#include "Port.h"

class Container {
    std::string tip;
    int tonaj{0};
    Port destinatie;
public:
    Container();
    Container(std::string tip, int tonaj, const Port &destinatie);
    friend std::ostream& operator<<(std::ostream& os, const Container& container);
    [[nodiscard]] const Port &getDestinatie() const;
    [[nodiscard]] int getTonaj() const;
};

#endif //OOP_CONTAINER_H
