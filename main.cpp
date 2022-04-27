#include <iostream>
#include <vector>

#include "Tara.h"
#include "Port.h"

Tara INTERNATIONAL{"INTERNATIONAL", "INTERNATIONAL"};
Port APA{INTERNATIONAL, "INTERNATIONAL_WATERS"};


class Marfa {
    std::string tip;
    int tonaj{0};
    Port destinatie;
public:
    Marfa() {}

    Marfa(const std::string &tip, int tonaj, const Port &destinatie) : tip(tip), tonaj(tonaj), destinatie(destinatie) {}

    friend std::ostream& operator<<(std::ostream& os, const Marfa& marfa) {
        os << "{Tip: " << marfa.tip << " Tonaj: " << marfa.tonaj << " Destinatie: " << marfa.destinatie << "}\n";
        return os;
    }

    const Port &getDestinatie() const {
        return destinatie;
    }

    int getTonaj() const {
        return tonaj;
    }
};

class Nava {
    std::string nume;
    Tara tara;
    int capacitate;
    std::vector<Marfa> marfuri;
    Port port;
public:
    Nava(const std::string &nume, const Tara &tara, int capacitate, const Port &port) : nume(nume), tara(tara),
                                                                                        capacitate(capacitate),
                                                                                        port(port) {}

    Nava(const Nava& other) : nume{other.nume}, tara{other.tara},capacitate{other.capacitate}, marfuri{other.marfuri}, port{other.port} {
        std::cout << "Constructor de copiere Nava\n";
    }

    Nava& operator=(const Nava& other) {
        nume = other.nume;
        tara = other.tara;
        capacitate = other.capacitate;
        marfuri = other.marfuri;
        std::cout << "operator= copiere Nava\n";
        return *this;
    }

    void afiseaza_marfuri() {
        std::cout << "Marfuri:";
        for(const auto& marfa : this->marfuri) {
            std::cout << marfa << " ";
        }
        std::cout << '\n';
    }

    friend std::ostream& operator<<(std::ostream& os, const Nava& nava) {
        os << "{Nume: " << nava.nume << " Tara: " << nava.tara << " Capacitate: " << nava.capacitate << " Marfuri: ";
        for(const auto& marfa : nava.marfuri) {
            os << marfa << " ";
        }
        os << "}\n";
        return os;
    }

    void iese_port() {
        this->port = APA;
    }

    void intra_port(const Port &port_destinatie) {
        int n = int(this->marfuri.size() - 1);
        //Descarca marfa care are ca destinatie portul in care intra
        for(int i = 0; i <= n; ++i) {
            if (this->marfuri[i].getDestinatie() == port_destinatie) {
                this->marfuri[i] = this->marfuri[n];
                n--;
                i--;//Deoarece ce am pus pe pozitia i poate sa fie tot pt portul acesta
            }
        }
        this->port = port_destinatie;
        this->marfuri.resize(n + 1);
    }

    void adauga_marfa(Marfa marfa) {
        int suma_tonaj = 0;
        for(auto it : this->marfuri) {
            suma_tonaj += it.getTonaj();
            if(marfa.getTonaj() + suma_tonaj > this->capacitate) {
                std::cout << "Nu are loc marfa:" << marfa << " in nava:" << *this;
                return;
            }
        }
        this->marfuri.push_back(marfa);

    }

    ~Nava() {
        std::cout << "Destructor Nava\n";
    }
};

int main() {
    Tara ro{"Romania", "Europa"};
    Tara it{"Italia", "Europa"};
    Port ct{ro, "Constanta"};
    std::cout << ct << ro;
    return 0;
}
