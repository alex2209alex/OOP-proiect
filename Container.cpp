//
// Created by alex on 4/27/2022.
//

#include "Container.h"
#include <utility>

Container::Container() = default;

Container::Container(std::string tip, int tonaj, const Port &destinatie): tip(std::move(tip)), tonaj(tonaj), destinatie(destinatie) {}

std::ostream& operator<<(std::ostream& os, const Container& container) {
    os << "Container: {Tip: " << container.tip << " Tonaj: " << container.tonaj << " Destinatie: " << container.destinatie << "}\n";
    return os;
}

const Port& Container::getDestinatie() const {
    return destinatie;
}

int Container::getTonaj() const {
    return tonaj;
}
