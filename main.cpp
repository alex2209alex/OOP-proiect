#include "TransportMaritim.h"
#include <iostream>

int main() {
    //functie statica
    std::cout << "\n---------------------\n" << "Numarul de tari al navelor este: " << TaraTemplate<int>::numar_tari() << "\n---------------------\n";
    TransportMaritim transportMaritim;
    transportMaritim.adauga_elementele();
    TransportMaritim transportMaritim1{transportMaritim};//pt constructor de copiere
    TransportMaritim transportMaritim2 = transportMaritim;//pt operator=
    transportMaritim.dynamic_cast_folosire();
    transportMaritim.variabila_statica_folosire();
    for(int i = 1; i <= 5; ++i) {
        std::cout << "\n------------------------------\n";
        std::cout << "Functia e rulata pentru a " << i << "-a oara\n";
        std::cout << "------------------------------\n";
        transportMaritim.ruleaza();
        std::cout << "------------------------------\n";
        std::cout << "Sfarsit pentru a " << i << "-a oara\n";
        std::cout << "------------------------------\n";
    }
    transportMaritim1.ruleaza();
    transportMaritim2.ruleaza();
    std::swap(transportMaritim1, transportMaritim2);
    transportMaritim1.ruleaza();
    transportMaritim2.ruleaza();
    return 0;
}

