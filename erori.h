//
// Created by alex on 5/19/2022.
//

#ifndef OOP_ERORI_H
#define OOP_ERORI_H

#include <exception>

class incarcare_gresita: public std::exception {
public:
    [[nodiscard]] const char* what() const noexcept override {
        return "Nava este incarcata in mod gresit";
    }
};

class incarcare_peste_capacitate: public std::exception {
public:
    [[nodiscard]] const char* what() const noexcept override {
        return "Nava este incarcata peste capacitate";
    }
};

class port_identic: public std::exception {
public:
    [[nodiscard]] const char* what() const noexcept override {
        return "Portul de plecare si portul destinatie sunt identice";
    }
};

class port_sursa_inchis: public std::exception {
public:
    [[nodiscard]] const char* what() const noexcept override {
        return "Portul de plecare e inchis";
    }
};

class port_destinatie_inchis : public std::exception {
public:
    [[nodiscard]] const char* what() const noexcept override {
        return "Portul destinatie e inchis";
    }
};

class cantitate_de_scos_prea_mare : public std::exception {
public:
    [[nodiscard]] const char* what() const noexcept override {
        return "Cantitatea de marfa care trebuie scoasa e prea mare";
    }
};

class nimic_de_scos : public std::exception {
public:
    [[nodiscard]] const char* what() const noexcept override {
        return "Nu e marfa pe nava";
    }
};

class nu_se_descarca_nimic : public std::exception {
public:
    [[nodiscard]] const char* what() const noexcept override {
        return "Nu se descarca nimic de pe nava";
    }
};

class identificator_ne_e_unic : public std::exception {
public:
    [[nodiscard]] const char* what() const noexcept override {
        return "Identidicatorul navei nu e unic";
    }
};

#endif //OOP_ERORI_H
