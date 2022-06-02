//
// Created by alex on 6/2/2022.
//

#ifndef OOP_TARATEMPLATE_H
#define OOP_TARATEMPLATE_H

#include <iostream>
#include <string>

template <typename T>
class TaraTemplate;

template <typename T>
std::ostream& operator<<(std::ostream& os, const TaraTemplate<T>& tara);

template <typename T>
bool operator==(const TaraTemplate<T>& tara, const TaraTemplate<T>& tara2);

template <typename T>
class TaraTemplate {
    T identificator;
    std::string nume;
    std::string continent;
    static int nrTari;
public:
    TaraTemplate();
    TaraTemplate(std::string nume, std::string continent, const T& x);
    TaraTemplate(const TaraTemplate &other);
    static int numar_tari();
    friend std::ostream& operator<< <>(std::ostream&, const TaraTemplate<T>&);
    TaraTemplate& operator=(const TaraTemplate& a);
    [[nodiscard]] const std::string &getNume() const;
    [[nodiscard]] const std::string &getContinent() const;
    const T &getIdentificator() const;
    friend bool operator== <>(const TaraTemplate<T>& tara, const TaraTemplate<T>& tara2);
    ~TaraTemplate();
};

#endif //OOP_TARATEMPLATE_H
