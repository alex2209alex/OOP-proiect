//
// Created by alex on 6/2/2022.
//

#include "TaraTemplate.h"
#include <utility>

template<typename T> int TaraTemplate<T>::nrTari = 0;

template <typename T>
TaraTemplate<T>::TaraTemplate() = default;

template <typename T>
TaraTemplate<T>::TaraTemplate(std::string nume, std::string continent, const T& x) : identificator(x), nume(std::move(nume)), continent(std::move(continent)) {
    nrTari++;
}

template <typename T>
TaraTemplate<T>::TaraTemplate(const TaraTemplate &other) : identificator(other.identificator), nume(other.nume), continent(other.continent) {
    nrTari++;
}

template <typename T>
std::ostream& operator<<(std::ostream& os, const TaraTemplate<T>& tara) {
    os << "TaraTemplate: {Nume: " << tara.nume << " Continent: " << tara.continent << " Identificator: " << tara.identificator << "}\n";
    return os;
}

template <typename T>
bool operator==(const TaraTemplate<T>& tara, const TaraTemplate<T>& tara2) {
    return tara.identificator == tara2.identificator && tara.continent == tara2.continent && tara.nume == tara2.nume;
}

template<typename T>
const T &TaraTemplate<T>::getIdentificator() const {
    return identificator;
}

template<typename T>
const std::string &TaraTemplate<T>::getNume() const {
    return nume;
}

template<typename T>
const std::string &TaraTemplate<T>::getContinent() const {
    return continent;
}

template<typename T>
TaraTemplate<T>& TaraTemplate<T>::operator=(const TaraTemplate &a) {
    if(&a != this) {
        nume = a.nume;
        continent = a.continent;
        identificator = a.identificator;
    }
    return *this;
}

template<typename T>
int TaraTemplate<T>::numar_tari() {
    return nrTari;
}

template<typename T>
TaraTemplate<T>::~TaraTemplate() = default;

