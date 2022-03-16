#include <iostream>
#include <vector>

class Tara {
    std::string nume;
    std::string continent;
public:
    Tara() {}

    Tara(const std::string &nume, const std::string &continent) : nume(nume), continent(continent) {}

    friend std::ostream& operator<<(std::ostream& os, const Tara& tara) {
        os << "{Nume: " << tara.nume << " Continent: " << tara.continent << "}\n";
        return os;
    }

    friend bool operator==(const Tara& tara, const Tara& tara2) {
        if(tara.nume == tara2.nume && tara.continent == tara2.continent)
            return true;
        return false;
    }
};

class Port {
    Tara tara;
    std::string oras;
public:
    Port() {}

    Port(const Tara &tara, const std::string &oras) : tara(tara), oras(oras) {}

    friend std::ostream& operator<<(std::ostream& os, const Port& port) {
        os << "{Tara: " << port.tara << " Oras: " << port.oras << "}\n";
        return os;
    }

    friend bool operator==(const Port& port, const Port& port2) {
        if(port.tara == port2.tara && port.oras == port2.oras)
            return true;
        return false;
    }
};

Tara INTERNATIONAL{"INTERNATIONAL", "INTERNATIONAL"};
Port APA{INTERNATIONAL, "INTERNATIONAL_WATERS"};


class Marfa {
    std::string tip;
    int tonaj;
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
        for(auto it : this->marfuri)
            std::cout << it << " ";
        std::cout << '\n';
    }

    friend std::ostream& operator<<(std::ostream& os, const Nava& nava) {
        os << "{Nume: " << nava.nume << " Tara: " << nava.tara << " Capacitate: " << nava.capacitate << " Marfuri: ";
        for(auto it : nava.marfuri) {
            os << it << " ";
        }
        os << "}\n";
        return os;
    }

    void iese_port() {
        this->port = APA;
    }

    void intra_port(Port &port) {
        int n = this->marfuri.size() - 1;
        for(int i = 0; i <= n; ++i) {
            if (this->marfuri[i].getDestinatie() == port) {
                this->marfuri[i] = this->marfuri[n];
                n--;
            }
        }
        this->marfuri.resize(n + 1);
    }

    void adauga_marfa(Marfa marfa) {
        int suma_tonaj = 0;
        for(auto it : this->marfuri)
            suma_tonaj += it.getTonaj();
        if(marfa.getTonaj() + suma_tonaj <= this->capacitate)
            this->marfuri.push_back(marfa);
        else {
            std::cout << "Nu are loc marfa:" << marfa << " in nava:" << *this;
        }
    }

    ~Nava() {
        std::cout << "Destructor Nava\n";
    }
};

int main() {
    Tara ro{"Romania", "Europa"};
    Tara it{"Italia", "Europa"};
    Port Constanta{ro, "Constanta"};
    Port Braila{ro, "Braila"};
    Port Roma{it, "Roma"};
    Marfa marfa1{"banane", 1, Constanta};
    Marfa marfa2{"mere", 1, Roma};
    Nava nava1{"Mircea", ro, 1, Braila};

    nava1.adauga_marfa(marfa1);
    nava1.adauga_marfa(marfa2);

    nava1.iese_port();
    nava1.afiseaza_marfuri();
    nava1.intra_port(Constanta);
    nava1.afiseaza_marfuri();


    std::cout << nava1;
    return 0;
}
