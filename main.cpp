#include <iostream>
#include <vector>

class Marfa {
    std::string tip;
    int tonaj;
public:
    Marfa(const std::string &tip, int tonaj) : tip(tip), tonaj(tonaj) {}

    friend std::ostream& operator<<(std::ostream& os, const Marfa& marfa) {
        os << "{Tip: " << marfa.tip << " Tonaj: " << marfa.tonaj << "}\n";
        return os;
    }
};

Marfa NU_E_MARFA{"Nimic", 0};

class Tara {
    std::string nume;
    std::string continent;
public:
    Tara(const std::string &nume, const std::string &continent) : nume(nume), continent(continent) {}

    friend std::ostream& operator<<(std::ostream& os, const Tara& tara) {
        os << "{Nume: " << tara.nume << " Continent: " << tara.continent << "}\n";
        return os;
    }
};

class Port {
    Tara tara;
    std::string oras;
public:
    Port(const Tara &tara, const std::string &oras) : tara(tara), oras(oras) {}

    friend std::ostream& operator<<(std::ostream& os, const Port& port) {
        os << "{Tara: " << port.tara << " Oras: " << port.oras << "}\n";
        return os;
    }
};

class Nava {
    std::string nume;
    Tara tara;
    int capacitate;
    Marfa marfa;
public:
    Nava(const std::string &nume, const Tara &tara, int capacitate, const Marfa &marfa) : nume(nume), tara(tara),
                                                                                          capacitate(capacitate),
                                                                                          marfa(marfa) {std::cout << "Constructor Nava\n";}

    Nava(const Nava& other) : nume{other.nume}, tara{other.tara},capacitate{other.capacitate}, marfa{other.marfa} {
        std::cout << "Constructor de copiere Nava\n";
    }

    Nava& operator=(const Nava& other) {
        nume = other.nume;
        tara = other.tara;
        capacitate = other.capacitate;
        marfa = other.marfa;
        std::cout << "operator= copiere Nava\n";
        return *this;
    }

    friend std::ostream& operator<<(std::ostream& os, const Nava& nava) {
        os << "{Nume: " << nava.nume << " Tara: " << nava.tara << " Capacitate: " << nava.capacitate << " Marfa: " << nava.marfa << "}\n";
        return os;
    }

    void descarca() {
        Nava::marfa = NU_E_MARFA;
    }

    ~Nava() {
        std::cout << "Destructor Nava\n";
    }
};

int main() {
    Tara ro{"Romania", "Europa"};
    Marfa marfa1{"banane", 1};
    Nava nava1{"Mircea", ro, 100, marfa1};
    nava1.descarca();
    Nava nava2{"Mircea2", ro, 100, marfa1};
    Nava nava3 = nava1;
    nava2 = nava3 = nava1;
    Port port{ro, "Constanta"};
    std::cout << nava1;
    return 0;
}
