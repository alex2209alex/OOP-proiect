//
// Created by alex on 6/2/2022.
//

#include "TaraTemplate.cpp"

template class
TaraTemplate<int>;

template class
TaraTemplate<std::string>;

template
std::ostream& operator<< <>(std::ostream& o, const TaraTemplate<int>& x);

template
std::ostream& operator<< <>(std::ostream& o, const TaraTemplate<std::string>& x);

template
bool operator== <>(const TaraTemplate<std::string>& tara, const TaraTemplate<std::string>& tara2);

template
bool operator== <>(const TaraTemplate<int>& tara, const TaraTemplate<int>& tara2);
